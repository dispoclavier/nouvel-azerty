# Répertoire des touches mortes
## Documentation
Les touches mortes sont documentées à la page [Touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) et ses 30 sous-pages, une par touche morte.

Un [tableau tout-en-un](https://dispoclavier.com/ressources/touches-mortes/) existe aussi.

Les tableaux des touches mortes sont [générés](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/generate-deadkey-table.pl) à partir du fichier `Compose.yml` dans son état actuel tel que reflété dans `compose-1.yml` et `compose-2.yml`.

## À propos
Pour la maintenabilité, `Compose.yml` est divisé en deux parties, `compose-1.yml` et `compose-2.yml`, qui reflètent les modifications apportées au répertoire.

Le fichier d’un seul tenant `Compose.yml` dans ce dossier sert d’exemple seulement. Sa mise à jour est sporadique.

Les archives distribuées contiennent aussi un tel fichier `Compose.yml`, mais pas celui-ci. Une copie du fichier à jour est placée à la racine de l’archive.

Ce répertoire n’est pas au format YAML ; l’extension `.yml` sert uniquement à activer une coloration syntaxique ici, et dans les éditeurs de texte automatiquement.
