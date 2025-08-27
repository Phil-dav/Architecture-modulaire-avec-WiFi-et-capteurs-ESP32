#pragma once
#define PCF8574_ADDR 0x20  // ou l'adresse réelle de ton module

// État logique des relais (LOW = actif si câblage inverse)
#define RELAY_ACTIVE_STATE LOW
#define RELAY_INACTIVE_STATE HIGH

// Mapping des broches PCF8574
#define PCF_PIN_RELAY_1       0
#define PCF_PIN_RELAY_2       1
#define PCF_PIN_RELAY_3       2
#define PCF_PIN_RELAY_4       3
#define PCF_PIN_BP_SCREEN     4
#define PCF_PIN_MODE_AUTO     5
#define PCF_PIN_MODE_MANU     6
#define PCF_PIN_DEFAUT_MOTEUR 7

