#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "secrets.h"       // Contient MON_SSID et MON_MDP
#include "SPIFFS.h"
#include <time.h>          // Pour la gestion de l'heure

AsyncWebServer server(80); // Serveur HTTP sur le port 80

// 🔧 Fonction pour initialiser la synchronisation NTP
void initTime() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov"); // UTC brut
  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);   // Fuseau France avec heure d'été/hiver
  tzset(); // Appliquer le fuseau
  Serial.println("🕒 NTP configuré avec fuseau Europe/Paris");
}

// 🔧 Fonction pour récupérer l'heure formatée
String getFormattedTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("⚠️ Erreur récupération NTP");
    return "Erreur NTP";
  }
  char buffer[16];
  strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeinfo);
  return String(buffer);
}

void setup() {
  Serial.begin(115200);
  Serial.println("🚀 Démarrage ESP32");

  // 📁 Initialisation SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Erreur SPIFFS");
    return;
  }
  Serial.println("✅ SPIFFS monté");

  // 📡 Connexion WiFi
  WiFi.begin(MON_SSID, MON_MDP);
  Serial.print("🔌 Connexion au WiFi");

  // Boucle non bloquante avec timeout 10s
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connecté à : " + WiFi.SSID());
    Serial.println("🌐 IP locale : " + WiFi.localIP().toString());

    // 🕰️ Initialisation NTP après WiFi
    initTime();

    // 🌍 Route principale : sert index.html
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/index.html", "text/html");
    });

    // ⏱️ Route /time : renvoie l'heure actuelle
    server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request){
      String currentTime = getFormattedTime();
      request->send(200, "text/plain", currentTime);
    });

    // 🚀 Démarrage du serveur
    server.begin();
    Serial.println("✅ Serveur web lancé");
  } else {
    Serial.println("\n❌ Échec de connexion WiFi");
  }
}

void loop() {
  // Rien ici : tout est géré de façon asynchrone
}
