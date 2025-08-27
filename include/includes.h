// include/includes.h
#pragma once

/******** Base Arduino ********/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <time.h>

/******** Réseau & Web ********/
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

/******** FS ********/
#include <FS.h>
#include <SPIFFS.h>   // passe à <LittleFS.h> si tu passes à LittleFS

/******** I2C & affichage ********/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/******** Capteurs ********/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHTesp.h>

/******** GPS ********/
#include <TinyGPSPlus.h>

/******** Config projet ********/
#include "config.h"
#include "pcf8574_config.h"
