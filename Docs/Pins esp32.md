Voici la **proposition de mapping GPIO ESP32 (sécurisé au boot)**, entièrement mise à jour selon tes directives, Phil :  
– utilisation du **PCF8574** pour centraliser les E/S logiques  
– capteurs analogiques et spécifiques connectés directement à l’ESP32  
– choix de GPIO **stables au démarrage** pour éviter les déclenchements intempestifs des relais ou parasites

---

### 🧭 Tableau de mapping GPIO ESP32

| Fonction                          | Type         | GPIO ESP32       | Détails techniques / Sécurité boot |
|----------------------------------|--------------|------------------|-------------------------------------|
| **Bus I²C SDA**                  | Sortie       | `21`             | SDA pour OLED + PCF8574 (pull-up 4.7kΩ) |
| **Bus I²C SCL**                  | Sortie       | `22`             | SCL pour OLED + PCF8574 (pull-up 4.7kΩ) |
| **DS18B20 (température eau)**    | 1-Wire       | `4`              | Résistance 4.7kΩ vers 3.3V requise |
| **DHT11 (température/air)**      | Entrée       | `32`             | GPIO stable au boot |
| **Niveau d’eau (analogique)**    | ADC          | `34`             | ADC1_CH6 – entrée pure, pull-up externe |
| **GPS RX**                       | UART RX2     | `16`             | Lecture des trames NMEA |
| **GPS TX**                       | UART TX2     | `17`             | Envoi vers GPS si nécessaire |
| **PCF8574 SDA/SCL**              | I²C partagé  | `21 / 22`        | Même bus que OLED |
| **OLED SSD1306**                 | I²C partagé  | `21 / 22`        | Adresse 0x3C ou 0x3D |
| **Relais 1 à 4**                 | Sorties via PCF8574 | `P0 à P3` sur PCF8574 | LOW trigger, sécurisés via I²C |
| **Bouton écran (commutation)**   | Entrée via PCF8574 | `P4`            | Lecture logique via I²C |
| **Sélecteur Auto**              | Entrée via PCF8574 | `P5`            | Lecture logique via I²C |
| **Sélecteur Manu**              | Entrée via PCF8574 | `P6`            | Lecture logique via I²C |
| **Défaut moteur (NF)**           | Entrée via PCF8574 | `P7`            | Lecture logique via I²C |

---

### ✅ Pourquoi ce mapping est sécurisé

- **GPIO physiques choisis** : aucun conflit avec les pins de strapping (0, 2, 12, 15, etc.)
- **Relais déportés sur PCF8574** : évite les activations intempestives au boot
- **Entrées analogiques sur ADC1** : évite les conflits avec Wi-Fi ou flash
- **I²C partagé** : simplifie le câblage OLED + PCF8574
- **Modularité** : si tu changes de PCB ou de câblage, tu modifies uniquement `config.h` et `pcf8574_config.h`

# 🔄 Tableau de migration ESP8266 → ESP32

| N° Pin ESP8266 | Nom ESP8266 | Désignation                        | GPIO ESP32 recommandé | Remarques techniques                              |
|----------------|-------------|------------------------------------|-----------------------|---------------------------------------------------|
| 1              | A0          | Capteur niveau eau (analogique)    | 34                    | Entrée ADC1_CH6, stable au boot                   |
| 29             | D1          | SCL (bus I²C)                      | 22                    | Bus I²C standard ESP32                            |
| 28             | D2          | SDA (bus I²C)                      | 21                    | Bus I²C standard ESP32                            |
| 19             | TX0         | Liaison série TX                   | 17                    | TX2 (UART2) pour GPS                              |
| 18             | RX0         | Liaison série RX                   | 16                    | RX2 (UART2) pour GPS                              |
| 15             | VIN         | Alimentation 3                     | 5V ou Vin             | ESP32 alimenté en 5V régulé                       |
| 22             | D6          | DS18B20 (température eau)          | 4                     | GPIO stable, supporte 1-Wire                      |
| —              | D5          | DHT11 (température/air)            | 32                    | GPIO stable, compatible avec DHTesp               |
