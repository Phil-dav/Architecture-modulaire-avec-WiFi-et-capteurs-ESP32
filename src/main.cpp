#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include "secrets.h"
#include "wifi_utils.h"
#include "time_utils.h"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Initialisation du système de fichiers SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Erreur SPIFFS");
    return;
  }

  // Connexion WiFi et synchronisation NTP
  initWiFi(MON_SSID, MON_MDP);
  initTime();

  // Route principale : page HTML
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // Route pour l'heure
  server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", getFormattedTime());
  });

  // Route pour le fichier CSS
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  // Route pour le fichier JavaScript
  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/script.js", "application/javascript");
  });

  // Démarrage du serveur
  server.begin();
  Serial.println("🌐 Serveur web lancé");
}

void loop() {
  // Rien à faire ici, tout est géré de façon asynchrone
}
