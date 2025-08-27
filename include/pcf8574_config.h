// include/pcf8574_config.h
#pragma once

// Adresse I2C du PCF8574 (ajuste selon A0/A1/A2)
#define PCF8574_ADDR 0x20

// Mapping des broches PCF8574
#define PCF_PIN_RELAY_1        0
#define PCF_PIN_RELAY_2        1
#define PCF_PIN_RELAY_3        2
#define PCF_PIN_RELAY_4        3
#define PCF_PIN_BP_SCREEN      4
#define PCF_PIN_MODE_AUTO      5
#define PCF_PIN_MODE_MANU      6
#define PCF_PIN_DEFAUT_MOTEUR  7

// Logique des relais (inverse si besoin)
#define RELAY_ACTIVE_STATE   LOW
#define RELAY_INACTIVE_STATE HIGH
