/**
 * @file includes.h
 * @brief Centralisation des bibliothèques utilisées dans le projet ESP32 piscine
 */

#pragma once

/************************************************
 * Base Arduino & communication
 ************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <time.h>
#include <SPIFFS.h>

/************************************************
 * Réseau & serveur web
 ************************************************/
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

/************************************************
 * Gestion I2C & périphériques
 ************************************************/
#include <PCF8574.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pcf8574_config.h"
#include "oled_display.h"
/************************************************
 * Capteurs
 ************************************************/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHTesp.h>

/************************************************
 * GPS
 ************************************************/
#include <TinyGPSPlus.h>

/************************************************
 * Fichiers de configuration
 ************************************************/
#include "config.h"

