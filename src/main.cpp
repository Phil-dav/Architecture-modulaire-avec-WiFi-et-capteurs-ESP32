#include "includes.h"
#include "wifi_utils.h"
#include "time_utils.h"
#include "pcf8574_driver.h"

void setup() {
    Serial.begin(115200);
    pcf_init();
    connectToWiFi();
    initTime();
}

void loop() {
    // Boucle principale
}
