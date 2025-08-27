// include/oled_display.h
#pragma once
#include <Arduino.h>

void initOLED();
void displayMessage(const String& message);
void displayTwoLines(const String& l1, const String& l2);
