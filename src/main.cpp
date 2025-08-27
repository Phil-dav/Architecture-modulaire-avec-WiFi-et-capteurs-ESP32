#include "includes.h"
#include "wifi_utils.h"
#include "time_utils.h"
#include "pcf8574_driver.h"
#include "oled_display.h"
#include "secrets.h"

void setup() {
    Serial.begin(115200);
    delay(100);

    // Initialisation bus I²C centrale
    Wire.begin(I2C_SDA, I2C_SCL);

    pcf_init();
    initOLED();
    displayMessage("Boot...");

    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS KO (formatage force)");
    } else {
        Serial.println("SPIFFS OK");
    }

    initWiFi(WIFI_SSID, WIFI_PASSWORD);
    initTime();
    startWebServer();


    displayTwoLines("WiFi: " + String(WiFi.isConnected() ? "OK" : "KO"),
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
