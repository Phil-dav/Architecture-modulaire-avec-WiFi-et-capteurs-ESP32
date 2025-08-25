#include "time_utils.h"
#include <time.h>

void initTime() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
  tzset();
  Serial.println("🕒 NTP configuré avec fuseau Europe/Paris");
}

String getFormattedTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return "Erreur NTP";
  char buffer[16];
  strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeinfo);
  return String(buffer);
}
