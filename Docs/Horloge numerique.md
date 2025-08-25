
```markdown
# 🕒 Horloge LED en HTML / CSS / JavaScript

Ce projet affiche une horloge numérique au style LED rouge avec fond noir, contour bleu ciel et date en français.  
Le séparateur central (entre heures et minutes) clignote pour imiter une vraie horloge murale.

---

## 📋 Prérequis

- Un navigateur web moderne (Chrome, Firefox, Edge…)
- Git (facultatif, pour cloner le projet)
- Un éditeur de code (VS Code, Sublime Text…)

---

## 📂 Structure du projet


.
├── index.html   # Structure HTML
├── style.css    # Styles et animations
└── script.js    # Logique d'affichage de la date et de l'heure


---

## ⚙️ Installation

1. **Cloner le dépôt** (ou télécharger le ZIP) :
   ```bash
   git clone https://github.com/ton-utilisateur/horloge-led.git
   cd horloge-led
   ```

2. **Ouvrir `index.html`** dans votre navigateur.

---

## 🖥️ Contenu des fichiers

### 1. `index.html`
Structure de base avec deux éléments :
```html
<div id="datetime">
  <div class="date"></div>
  <div class="time"></div>
</div>
```

### 2. `style.css`
- Fond blanc global
- Bloc horloge noir avec contour bleu ciel
- Texte rouge façon LED avec lueur
- Animation `blink` pour le séparateur central

Extrait :
```css
.blink {
  animation: blink 1s steps(1, start) infinite;
}

@keyframes blink {
  50% { visibility: hidden; }
}
```

### 3. `script.js`
- Récupère la date et l’heure en français
- Formate heures, minutes, secondes
- Ajoute `<span class="blink">:</span>` entre heures et minutes
- Met à jour toutes les secondes

Extrait :
```javascript
const timeStr = `${heures}<span class="blink">:</span>${minutes}:${secondes}`;
document.querySelector('#datetime .time').innerHTML = timeStr;
```

---

## 📸 Aperçu

![Aperçu de l'horloge](images\Horloge_numerique.png)

---

## 🚀 Personnalisation

- **Couleur LED** : modifier `color` dans `#datetime`
- **Vitesse clignotement** : ajuster `animation: blink 1s ...`
- **Police** : changer l’`@import` Google Fonts

---

## 📄 Licence

Projet libre d’utilisation et de modification.
```
