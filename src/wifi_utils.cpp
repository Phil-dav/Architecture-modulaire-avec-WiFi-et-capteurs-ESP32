// src/wifi_utils.cpp
#include "includes.h"
#include "wifi_utils.h"

void initWiFi(const char* ssid, const char* password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("WiFi: connexion a ");
    Serial.println(ssid);
    uint8_t retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 60) {
        delay(500);
        Serial.print(".");
        retries++;
    }
    Serial.println();
    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("WiFi OK, IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("WiFi KO: timeout");
    }
}
