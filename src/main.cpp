#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "secrets.h"
#include "SPIFFS.h"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
if (!SPIFFS.begin(true)) {
  Serial.println("Erreur d'initialisation SPIFFS");
  return;
}

  WiFi.begin(MON_SSID, MON_MDP);
  Serial.print("Connexion au WiFi");

  // Boucle non bloquante
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Connecté à : " + WiFi.SSID());
    Serial.println("IP : " + WiFi.localIP().toString());

    // Serveur web
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/index.html", "text/html");
    });

    server.begin();
  } else {
    Serial.println("\n❌ Échec de connexion WiFi");
  }

  // Initialiser SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Erreur SPIFFS");
    return;
  }
}

void loop() {
  // Rien ici, tout est asynchrone
}
