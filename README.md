# Convertisseur de Base en C

## Description
Ce programme en C permet de convertir un nombre d'une base donnée à une autre. Il prend en entrée un nombre dans une base source, le convertit en base décimale, puis le convertit dans une base de destination choisie. Les bases prises en charge vont de 2 à 36.

## Fonctionnalités
- **Conversion de base** : Permet de convertir un nombre d'une base à une autre (par exemple de la base 16 à la base 2).
- **Vérification de validité** : Vérifie si le nombre est valide dans la base source spécifiée et si les bases source et destination sont dans la plage autorisée (2 à 36).
- **Gestion des erreurs** : Notifie l'utilisateur en cas de format ou de base invalide.

## Pré-requis
- **Compilateur C** : GCC ou tout autre compilateur compatible.

## Installation
1. Clonez le dépôt :
   ```bash
   git clone <lien_du_dépôt>
   cd <nom_du_dossier>
   ```
2. Compilez le programme :
   ```bash
   gcc main.c -o convertisseur
   ```
3. Exécutez le programme :
   ```bash
   ./convertisseur
   ```

## Utilisation
Lors de l'exécution, le programme demande les informations suivantes :
1. **Nombre à convertir** : Entrez un nombre alphanumérique dans la base source.
2. **Base source** : Entrez la base d'origine (entre 2 et 36).
3. **Base de destination** : Entrez la base dans laquelle vous souhaitez convertir le nombre (entre 2 et 36).

Exemple d'exécution :
```plaintext
Entrez le nombre à convertir: 1A
Entrez la base du nombre: 16
Entrez la base de destination: 2
Le nombre 1A en base 16 est 11010 en base 2
```

## Explications Techniques

### Fonctions principales

- **`en_decimal(const char *nombre, int base)`** : Convertit un nombre d'une base spécifiée en base décimale. Parcourt chaque caractère du nombre et calcule la valeur décimale.
- **`de_decimal(int decimal, int base, char *resultat)`** : Convertit un nombre décimal en une base donnée. Les chiffres sont stockés en ordre inverse, puis réarrangés pour obtenir le bon résultat.
- **`est_valide_dans_base(const char *nombre, int base)`** : Vérifie si tous les caractères du nombre sont valides dans la base spécifiée.
- **`est_nombre_valide(const char *nombre)`** : Valide que le nombre est composé uniquement de caractères alphanumériques.
- **`est_base_valide(int base)`** : Vérifie que la base est dans la plage autorisée (2 à 36).
- **`demander_entrees(char *nombre, int *base_source, int *base_destination)`** : Gère les entrées utilisateur et valide le format et la plage des bases.

## Structure des fichiers
- **main.c** : Contient le code source principal du programme.
- **README.md** : Documentation détaillée du programme.

## Contributeurs
- [Klaynight](https://github.com/Klaynight-dev)

## Licence
Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.

## Remerciements
Merci aux développeurs et aux projets open source qui ont permis la réalisation de ce convertisseur de base.
