//data/script.js
function updateDateTime() {
  const now = new Date();

  // Format date en français (ex: lundi 25 août 2025)
  const optionsDate = { weekday: 'long', day: 'numeric', month: 'long', year: 'numeric' };
  const dateStr = now.toLocaleDateString('fr-FR', optionsDate);

  // Récupération heures, minutes, secondes avec zéro devant si besoin
  const heures = String(now.getHours()).padStart(2, '0');
  const minutes = String(now.getMinutes()).padStart(2, '0');
  const secondes = String(now.getSeconds()).padStart(2, '0');

  // Seul le premier séparateur clignote
  const timeStr = `${heures}<span class="blink">:</span>${minutes}:${secondes}`;

  // Injection dans le HTML
  document.querySelector('#datetime .date').textContent = dateStr;
  document.querySelector('#datetime .time').innerHTML = timeStr; // innerHTML pour interpréter le span
}

// Mise à jour immédiate puis toutes les secondes
updateDateTime();
setInterval(updateDateTime, 1000);
