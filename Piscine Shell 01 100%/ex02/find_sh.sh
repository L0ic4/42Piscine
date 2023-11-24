#!/bin/sh

# On utilise find pour trouver tous les fichiers avec l'extension .sh
# dans le répertoire courant et dans tous les sous-dossiers
fichiers=$(find . -type f -name "*.sh")

# On parcourt la liste des fichiers trouvés
for fichier in $fichiers; do

  # On extrait le nom du fichier sans l'extension
  nom=$(basename "$fichier" .sh)

  # On affiche le nom du fichier
  echo "$nom"

done
