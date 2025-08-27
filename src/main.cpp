// src/main.cpp
#include "includes.h"
#include "wifi_utils.h"
#include "time_utils.h"
#include "pcf8574_driver.h"
#include "oled_display.h"
#include "secrets.h"  // définis WIFI_SSID / WIFI_PASSWORD

void setup() {
    Serial.begin(115200);
    delay(100);

    // I2C + PCF
    pcf_init();

    // OLED
    initOLED();
    displayMessage("Boot...");

    // FS
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS KO (formatage force)");
    } else {
        Serial.println("SPIFFS OK");
    }

    // WiFi + NTP
    initWiFi(WIFI_SSID, WIFI_PASSWORD);
    initTime();

    displayTwoLines("WiFi: " + String(WiFi.status() == WL_CONNECTED ? "OK" : "KO"),
                    getFormattedTime());
}

void loop() {
    static uint32_t last = 0;
    if (millis() - last > 1000) {
        last = millis();
        displayTwoLines("IP: " + (WiFi.isConnected() ? WiFi.localIP().toString() : String("…")),
                        getFormattedTime());
    }
}
