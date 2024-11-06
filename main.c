#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/**
 * Convertit un nombre de n'importe quelle base en décimal.
 *
 * @param nombre Le nombre à convertir.
 * @param base La base du nombre.
 * @return La valeur décimale du nombre.
 */
int en_decimal(const char *nombre, int base) {
    size_t longueur = strlen(nombre);  // Longueur du nombre
    int decimal = 0;  // Valeur décimale du nombre
    int puissance = 1;  // Initialisation de la puissance

    for (int i = 0; i < longueur; i++) {
        char chiffre = nombre[longueur - i - 1];  // Chiffre courant du nombre
        if (chiffre >= '0' && chiffre <= '9') {
            decimal += (chiffre - '0') * puissance;  // Ajoute la valeur du chiffre à la valeur décimale
        } else if (chiffre >= 'A' && chiffre <= 'Z') {
            decimal += (chiffre - 'A' + 10) * puissance;  // Ajoute la valeur du chiffre à la valeur décimale
        } else if (chiffre >= 'a' && chiffre <= 'z') {
            decimal += (chiffre - 'a' + 10) * puissance;  // Ajoute la valeur du chiffre à la valeur décimale
        }

        puissance *= base;  // Multiplie la puissance par la base
    }
    return decimal;  // Retourne la valeur décimale du nombre
}

/**
 * Convertit un nombre décimal en n'importe quelle base.
 *
 * @param decimal Le nombre décimal à convertir.
 * @param base La base vers laquelle convertir le nombre décimal.
 * @param resultat Le résultat de la conversion sous forme de chaîne de caractères.
 */
void de_decimal(int decimal, int base, char *resultat) {
    char chiffres[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Tableau des chiffres utilisés dans la base
    int index = 0;  // Index pour parcourir le tableau resultat
    while (decimal > 0) {
        resultat[index++] = chiffres[decimal % base];  // Ajoute le chiffre correspondant au reste de la division décimale par la base
        decimal /= base;  // Divise le nombre décimal par la base
    }
    resultat[index] = '\0';  // Ajoute le caractère nul à la fin de la chaîne de caractères
    // Inverse le résultat
    for (int i = 0; i < index / 2; i++) {
        char temp = resultat[i];  // Variable temporaire pour échanger les caractères
        resultat[i] = resultat[index - i - 1];  // Échange le caractère courant avec son homologue symétrique
        resultat[index - i - 1] = temp;  // Réassigne le caractère symétrique à sa position d'origine
    }
}

/**
 * Vérifie si un nombre est valide dans une base donnée.
 *
 * @param nombre Le nombre à vérifier.
 * @param base La base à vérifier.
 * @return 1 si le nombre est valide dans la base donnée, 0 sinon.
 */
int est_valide_dans_base(const char *nombre, int base) {
    size_t longueur = strlen(nombre); // Longueur du nombre
    for (int i = 0; i < longueur; i++) {
        char chiffre = nombre[i]; // Chiffre courant du nombre
        if (chiffre >= '0' && chiffre <= '9') {
            if (chiffre - '0' >= base) return 0; // Vérifie si le chiffre est valide dans la base
        } else if (chiffre >= 'A' && chiffre <= 'Z') {
            if (chiffre - 'A' + 10 >= base) return 0; // Vérifie si le chiffre est valide dans la base
        } else if (chiffre >= 'a' && chiffre <= 'z') {
            if (chiffre - 'a' + 10 >= base) return 0; // Vérifie si le chiffre est valide dans la base
        } else {
            return 0; // Caractère invalide
        }
    }
    return 1; // Tous les chiffres sont valides dans la base
}

/**
 * Vérifie si le nombre est dans un format valide (alphanumérique).
 * @param nombre La chaîne de caractères à vérifier.
 * @return 1 si le nombre est valide, 0 sinon.
 */
int est_nombre_valide(const char *nombre) {
    size_t longueur = strlen(nombre);
    for (int i = 0; i < longueur; i++) {
        char c = nombre[i];
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return 0; // Si le caractère n'est pas alphanumérique
        }
    }
    return 1;
}

/**
 * Vérifie si la base est valide (entre 2 et 36).
 * @param base La base à vérifier.
 * @return 1 si la base est valide, 0 sinon.
 */
int est_base_valide(int base) {
    return base >= 2 && base <= 36; // Bases valides entre 2 et 36
}

/**
 * Demande à l'utilisateur d'entrer un nombre, une base source et une base de destination.
 * 
 * @param nombre Le pointeur vers une chaîne de caractères où sera stocké le nombre à convertir.
 * @param base_source Le pointeur vers un entier où sera stockée la base du nombre.
 * @param base_destination Le pointeur vers un entier où sera stockée la base de destination.
 */
void demander_entrees(char *nombre, int *base_source, int *base_destination) {
    printf("Entrez le nombre à convertir: ");
    scanf("%s", nombre);
    // Vérifie si le nombre est dans le bon format
    if (!est_nombre_valide(nombre)) {
        printf("Le nombre n'est pas dans le bon format.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez la base du nombre: ");
    scanf("%d", base_source);
    // Vérifie si la base source est dans le bon format
    if (!est_base_valide(*base_source)) {
        printf("La base source n'est pas dans le bon format.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez la base de destination: ");
    scanf("%d", base_destination);
    // Vérifie si la base de destination est dans le bon format
    if (!est_base_valide(*base_destination)) {
        printf("La base de destination n'est pas dans le bon format.\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief La fonction principale du programme.
 * 
 * @return Le code de sortie du programme.
 */
int main() {
    char nombre[100];
    int base_source, base_destination;
    char resultat[100];

    demander_entrees(nombre, &base_source, &base_destination);

    if (!est_valide_dans_base(nombre, base_source)) {
        printf("Le nombre %s n'est pas valide dans la base %d\n", nombre, base_source);
        return EXIT_FAILURE;
    }

    int decimal = en_decimal(nombre, base_source);
    de_decimal(decimal, base_destination, resultat);

    printf("Le nombre %s en base %d est %s en base %d\n", nombre, base_source, resultat, base_destination);

    return EXIT_SUCCESS;
}
