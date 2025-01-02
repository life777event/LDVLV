# GIT

## Usage

Pour faire du **contrôle de version**.

## Installation

Sans IDE ni third-party tools (only git binaries + bash).

## Setup

### Github repository

La clef SSH est générée directement à travers de [l'onglet dédié sur github](https://github.com/settings/keys).

Afin d'associer cette clef sur l'environnement local, en utilisant *git bash*:
1. `eval $(ssh-agent)`
2. `ssh-add ~/.ssh/id_life`

*(1)* permet d'évaluer l'agent SSH de windows, et (2) d'y ajouter la clé privée.

Il faudrait d'ailleurs penser à automatiser ça.