# Compose

Le fichier Compose.yml contient les chaînes de caractères pour touches vives et le contenu des touches mortes, dont celui de la touche morte de composition éponyme, pour les dispositions de clavier définies dans le dépôt [dispoclavier/nouvel-azerty](https://github.com/dispoclavier/nouvel-azerty/). Son nom avec majuscule est calqué sur des noms de fichier dans /usr/share/X11/locale/ sous Linux.

Ce fichier n’est pas au format YAML. L’extension ".yml" sert à la coloration syntaxique, et sous Windows elle facilite l’ouverture.

## Documentation

Les touches mortes sont documentées sur la page [Touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) et ses 30 sous-pages, une par touche morte, et sur celle des [séquences de composition](https://dispoclavier.com/nouvel-azerty/composition/), avec une sous-page pour les [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/).

Ces tableaux de touches mortes sont générés à partir du fichier Compose.yml par les trois [scripts](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/) dont les noms commencent par "generate-" et se terminent par "-tables" ou "-table".

## Versionnage

Dans Compose.yml, le numéro de version est inclus sous la forme d’une chaîne de caractères pour touche vive parce que ces dispositions de clavier sortent leur version par AltGr + Échap.

Le numéro de version sur trois nombres est complété par le numéro de build, aussi pour Linux (depuis le build 6.0.7.03) parce que le fichier Compose.yml sert aussi de code source au contenu de touches mortes transpilé pour Windows.

L’historique des versions 1.0.0 à 1.6.0 a été restauré de [c6c939f](https://github.com/dispoclavier/nouvel-azerty/commit/c6c939f1ec1a84dc4a1ec4aaf49df552b887e5dd) à [bebf6f8](https://github.com/dispoclavier/nouvel-azerty/commit/bebf6f8e44270b5623bf4eae95454b8b657497e2).

## À propos

Le contenu de Compose.yml est réparti sur les trois fichiers compose-1.yml, compose-2.yml et compose-3.yml pour la mise en ligne sur GitHub. Ces partiels ne dépassent pas 2 Mo afin de bénéficier des fonctionnalités de github.com, absentes de github.dev qui affiche Compose.yml en entier.

Le fichier d’un seul tenant Compose.yml dans ce dossier est celui de la dernière version publiée ou un fichier mis à jour en cours de développement.

Les paquetages distribués dont le nom commence par "Un-nouvel-AZERTY-Linux-" contiennent aussi une copie de ce fichier, placée à la racine.
