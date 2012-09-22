
/**
 * @file test_auto_nombre.c
 * @author François Portet <francois.portet@imag.fr>
 * @date Thu Sep 13 14:00:00 2012
 * @brief Code pour tester l'automate de detection de nombres.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto_nombre.h"



#define TAILLE_LIGNE 512

/**
 * @param argc Nombre de parametres
 * @param argv Valeur des parametres
 * @return Valeur de retour du programme
 * @brief Code pour tester l'automate de detection de nombres.
 *
 *
 */

int main ( int argc, char *argv[] ) {

    FILE *fic;
    int nb_lignes;
    char ligne[TAILLE_LIGNE];
    char* nom_fic;


    /* le programme doit avoir un seul argument*/
    if(argc != 2) {
        printf("Usage : %s nom_fichier\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    /* on copie le nom du fichier dans la variable*/
    nom_fic = malloc(strlen(argv[1])+1);
    strcpy(nom_fic,argv[1]);

    /* ouverture du fichier*/
    fic = fopen(nom_fic, "r"); /* ouvrir en lecture*/
    if(fic == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
        exit(EXIT_FAILURE);
    }

    puts("");
    /* appliquer l'automate sur chaque ligne et compter le nombre de lignes*/
    nb_lignes = 0;
    while(fgets(ligne, TAILLE_LIGNE, fic) != NULL) {
        printf("%-12s\t%15s", traduit_etat(classifie(ligne)),ligne);
        nb_lignes++;
    }
    printf("\nle fichier %s comporte %d lignes\n", nom_fic, nb_lignes);


    /* fermeture du fichier*/
    if(fclose(fic) == EOF) {
        printf("Probleme de fermeture du fichier %s", nom_fic);
        exit(EXIT_FAILURE);
    }

    /* on libere la memoire */
    free(nom_fic);

    exit( EXIT_SUCCESS );
}
