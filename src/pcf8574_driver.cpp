#include "includes.h"
#include "pcf8574_driver.h"
#include <PCF8574.h>

// L’objet PCF8574 est ici, visible dans tout le .cpp
PCF8574 pcf(&Wire, PCF8574_ADDR);

void pcf_init() {
    Wire.begin(I2C_SDA, I2C_SCL);
    pcf.begin();

    pcf.pinMode(PCF_PIN_RELAY_1, OUTPUT);
    pcf.pinMode(PCF_PIN_RELAY_2, OUTPUT);
    pcf.pinMode(PCF_PIN_RELAY_3, OUTPUT);
    pcf.pinMode(PCF_PIN_RELAY_4, OUTPUT);

    pcf.pinMode(PCF_PIN_BP_SCREEN, INPUT_PULLUP);
    pcf.pinMode(PCF_PIN_MODE_AUTO, INPUT_PULLUP);
    pcf.pinMode(PCF_PIN_MODE_MANU, INPUT_PULLUP);
    pcf.pinMode(PCF_PIN_DEFAUT_MOTEUR, INPUT_PULLUP);

    setRelay(1, false);
    setRelay(2, false);
    setRelay(3, false);
    setRelay(4, false);
}

void setRelay(uint8_t relayNum, bool state) {
    uint8_t pin;
    switch (relayNum) {
        case 1: pin = PCF_PIN_RELAY_1; break;
        case 2: pin = PCF_PIN_RELAY_2; break;
        case 3: pin = PCF_PIN_RELAY_3; break;
        case 4: pin = PCF_PIN_RELAY_4; break;
        default: return;
    }
    pcf.digitalWrite(pin, state ? RELAY_ACTIVE_STATE : RELAY_INACTIVE_STATE);
}

bool readButton(uint8_t pin) {
    return pcf.digitalRead(pin) == LOW;
}

bool readDefautMoteur() {
    return pcf.digitalRead(PCF_PIN_DEFAUT_MOTEUR) == LOW;
}
