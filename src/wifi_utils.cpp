#include "includes.h"
#include "wifi_utils.h"
#include "secrets.h"

void connectToWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connecté");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());
}
