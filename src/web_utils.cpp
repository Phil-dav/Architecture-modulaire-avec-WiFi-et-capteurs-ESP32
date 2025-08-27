#include "includes.h"
#include "time_utils.h"
#include "web_utils.h"

static AsyncWebServer server(80);

void startWebServer() {
    // Page principale -> envoie index.html
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", "text/html");
    });

    // API pour récupérer l'heure en JSON
    server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = "{";
        json += "\"datetime\":\"" + getFormattedTime() + "\"";
        json += "}";
        request->send(200, "application/json", json);
    });

    // Sert aussi les fichiers statiques (CSS, JS, images...)
    server.serveStatic("/", SPIFFS, "/");

    server.begin();
    Serial.println("✅ Serveur Web démarré sur http://" + WiFi.localIP().toString());
}
