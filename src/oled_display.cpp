// src/oled_display.cpp
#include "includes.h"
#include "oled_display.h"

static Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void initOLED() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println("OLED non detecte");
        return;
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("OLED OK");
    display.display();
}

void displayMessage(const String& message) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(message);
    display.display();
}

void displayTwoLines(const String& l1, const String& l2) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(l1);
    display.setCursor(0, 16);
    display.println(l2);
    display.display();
}
