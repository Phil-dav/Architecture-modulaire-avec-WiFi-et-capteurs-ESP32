#include "wifi_utils.h"

void initWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.print("🔌 Connexion au WiFi");
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connecté à : " + WiFi.SSID());
    Serial.println("🌐 IP locale : " + WiFi.localIP().toString());
  } else {
    Serial.println("\n❌ Échec de connexion WiFi");
  }
}
