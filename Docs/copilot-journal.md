# 📘 Copilot Journal – Architecture modulaire ESP32 avec WiFi et capteurs

---

## 📅 25 août 2025 — Initialisation du projet

**🎯 Objectif du jour :**  
Mettre en place la structure de base du projet ESP32 modulaire.

**📂 Arborescence créée :**
- `include/secrets.h` → stockage des identifiants WiFi (non versionné)
- `lib/` → dossier pour les bibliothèques modulaires
- `Docs/copilot-journal.md` → journal de bord
- `.vscode/extensions.json` → configuration VSCode
- `.gitignore` → exclusion des fichiers sensibles
- `platformio.ini` → configuration PlatformIO
- `README.md` → documentation du projet

**✅ Actions réalisées :**
- Initialisation du dépôt Git avec `git init`
- Premier commit : `Initialisation du projet ESP32 modulaire`
- Publication sur GitHub : [Architecture-modulaire-avec-WiFi-et-capteurs-ESP32](https://github.com/Phil-dav/Architecture-modulaire-avec-WiFi-et-capteurs-ESP32)
- Configuration de VSCode en français
- Connexion réussie au compte GitHub `phil-dav`

**🧠 Remarques :**
- Attention aux fins de ligne CRLF/LF sur Windows (configuré avec `core.autocrlf`)
- Le fichier `secrets.h` est bien exclu du dépôt grâce au `.gitignore`
- Le dépôt est prêt à être cloné sur le second PC (la cave)

---

## 📅 Prochaine étape — Module WiFi

**🔧 Objectif :**  
Créer une classe `WiFiManager` pour gérer la connexion réseau.

**📌 À faire :**
- Créer `lib/WiFiManager/WiFiManager.cpp` et `.h`
- Lire SSID et mot de passe depuis `secrets.h`
- Implémenter une logique de reconnexion automatique
- Ajouter une LED de statut pour indiquer l’état de la connexion

**🧪 Tests prévus :**
- Connexion à un réseau local
- Gestion des erreurs de connexion
- Fallback en mode Access Point si échec

---

