# Répertoire des touches mortes
## Documentation
Les touches mortes sont documentées à la page [Touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) et ses 30 sous-pages, une par touche morte.

Le système de touches mortes prend aussi en charge les [séquences de composition](https://dispoclavier.com/nouvel-azerty/composition/), dont celles des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/).

Les tableaux des touches mortes sont [générés](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/generate-deadkey-table.pl) à partir du fichier `Compose.yml` dans son état actuel tel que reflété dans `compose-1.yml`, `compose-2.yml` et `compose-3.yml`.

## À propos
Pour la maintenabilité, `Compose.yml` est réparti sur trois fichiers : `compose-1.yml`, `compose-2.yml` et `compose-3.yml`, qui reflètent les modifications apportées au répertoire des touches mortes de ce nouvel AZERTY.

Le fichier d’un seul tenant `Compose.yml` dans ce dossier est celui de la dernière version publiée.

Les archives distribuées dont le nom commence par `Nouvel-AZERTY-Linux-` contiennent aussi une copie de ce fichier, placée à la racine.

Ces fichiers ne sont pas au format YAML ; l’extension `.yml` sert uniquement à activer une coloration syntaxique ici et dans les éditeurs de texte automatiquement.
