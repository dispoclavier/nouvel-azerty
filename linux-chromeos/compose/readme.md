# Compose

Le fichier Compose.yml contient les chaînes de caractères pour touches vives, et le contenu des touches mortes, dont celui de la touche morte de composition éponyme.

## Documentation

Les touches mortes sont documentées sur la page [Touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) et ses 30 sous-pages, une par touche morte, et sur celle des [séquences de composition](https://dispoclavier.com/nouvel-azerty/composition/), avec une sous-page sur les [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/).

Les tableaux des touches mortes sont [générés](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/generate-deadkey-table.pl) à partir du fichier `Compose.yml` dans son état actuel tel que reflété dans `compose-1.yml`, `compose-2.yml` et `compose-3.yml`.

## Versionnage

Le numéro de version sur trois nombres est précisé à l’aide du numéro de build, aussi pour Linux (depuis le build 6.0.7.03) parce que le fichier Compose.yml est aussi le code source du contenu transpilé de touches mortes pour Windows.

## À propos

Pour la mise en ligne sur GitHub, `Compose.yml` est réparti sur trois fichiers : `compose-1.yml`, `compose-2.yml` et `compose-3.yml`.

Le fichier d’un seul tenant `Compose.yml` dans ce dossier est celui de la dernière version publiée ou un fichier mis à jour en cours de développement.

Les paquetages distribués dont le nom commence par `Un-nouvel-AZERTY-Linux-` contiennent aussi une copie de ce fichier, placée à la racine.

Ces fichiers ne sont pas au format YAML. L’extension `.yml` sert à la coloration syntaxique, et sous Windows elle facilite l’ouverture.

L’historique des versions 1.0.0 à 1.6.0 a été restauré de [c6c939f](https://github.com/dispoclavier/nouvel-azerty/commit/c6c939f1ec1a84dc4a1ec4aaf49df552b887e5dd) à [bebf6f8](https://github.com/dispoclavier/nouvel-azerty/commit/bebf6f8e44270b5623bf4eae95454b8b657497e2).
