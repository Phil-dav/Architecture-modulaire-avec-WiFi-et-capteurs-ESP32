// include/config.h
#pragma once

// Broches ESP32
#define I2C_SDA 21
#define I2C_SCL 22

// Capteurs
#define DS18B20_PIN 4     // 1-Wire
#define DHT_PIN     32    // DHT11/DHT22

// GPS (UART2 conseillé)
#define GPS_RX_PIN 16     // RX2
#define GPS_TX_PIN 17     // TX2

// OLED
#define OLED_WIDTH   128
#define OLED_HEIGHT  64
#define OLED_ADDRESS 0x3C

// Fuseau horaire (France)
#define TZ_EUROPE_PARIS "CET-1CEST,M3.5.0/2,M10.5.0/3"
