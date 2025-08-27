#include "includes.h"
#include "oled_display.h"


AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
    pcf_init();
    connectToWiFi();
    initTime();
  // Initialisation du système de fichiers SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Erreur SPIFFS");
    return;
  }

  // Connexion WiFi et synchronisation NTP
  initWiFi(WIFI_SSID, WIFI_PASSWORD);
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

  Wire.begin(21, 22); // SDA, SCL
  initDisplay();      // Initialisation OLED

   /* Serial.println("\nI2C Scanner");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(address, HEX);
    }
  }*/
}

void loop() {
  String heure = getFormattedTime();
  updateDisplay(heure);
  delay(1000); // Mise à jour toutes les secondes
}

