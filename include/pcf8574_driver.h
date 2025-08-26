#pragma once

void pcf_init();
void setRelay(uint8_t relayNum, bool state);
bool readButton(uint8_t pin);
bool readDefautMoteur();
