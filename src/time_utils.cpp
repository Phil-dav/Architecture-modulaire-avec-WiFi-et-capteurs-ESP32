// src/time_utils.cpp
#include "includes.h"
#include "time_utils.h"

void initTime() {
    configTzTime(TZ_EUROPE_PARIS, "pool.ntp.org", "time.google.com");
}

String getFormattedTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo, 2000)) return "NTP ?";
    char buf[20];
    strftime(buf, sizeof(buf), "%d/%m %H:%M:%S", &timeinfo);
    return String(buf);
}
