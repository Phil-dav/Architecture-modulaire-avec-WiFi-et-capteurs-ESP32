#include "includes.h"
//#include "oled_display.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void initOLED() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("OLED prêt !");
    display.display();
}

void displayMessage(const String& message) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(message);
    display.display();
}
