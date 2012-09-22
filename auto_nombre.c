
/**
 * @file auto_nombre.c
 * @author François Portet <francois.portet@imag.fr>
 * @date Thu Sep 13 12:00:00 2012
 * @brief Fonction de l'automate détectant les différents types de représentation de nombre entier.
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "auto_nombre.h"



/**
 * @param ligne chaîne de caractères à analyser
 * @param i index du caractère en faute
 * @param c code ascii du caractère en faute
 * @return -1
 * @brief message d'erreur généré lorsqu'une erreur de décodage apparaît
 *
 *
 */
int erreur_caractere ( char *ligne , int i , int c) {

    printf("erreur au %de caractere %c de la chaine %s\n",i,c,ligne);
    return -1;
}


/**
 * @param S entier codant l'état de l'automate
 * @return une chaîne de caractères représentant l'état S
 * @brief traduit un état donné sous forme de valeur numérique en chaîne de caractères
 *
 *
 */

char* traduit_etat(int S) {
    char* etat_string[] = {	"init",
                            "pre_hexa",
                            "debut_hexa",
                            "hexadecimal",
                            "decimal",
                            "octal"
                          };
    if (S>-1 && S<6)
        return etat_string[S];

    return "erreur";
}


/**
 * @param ligne chaîne de caractères à classifier
 * @return l'état de l'automate en cas de succès, -1 sinon
 * @brief fonction qui met en œuvre l'automate de classification de chaîne de caractères
 *
 *
 */


int classifie(char* ligne) {
    int S = INIT;
    int i=0;

    for (i=0; i<strlen(ligne); i++) {
        char c=ligne[i];
        switch (S) {
        case INIT :
            if (isdigit(c)) {            /* si c est un chiffre */
                S = ( c== '0' ) ? PRE_HEXA : DECIMAL ;
                if(S==PRE_HEXA && (i== strlen(ligne)-1 || isspace(ligne[i+1]))) {
                    S = DECIMAL ;/* cas ou le nombre est 0*/
                }
            }
            else if ( isspace(c)) S=INIT ;
            else return erreur_caractere (ligne , i , c );
            break ;
        case PRE_HEXA: /* repérage du préfixe de l hexa */
            if ( c == 'x' || c == 'X' ) S=HEXA ;
            else if (isdigit(c) && c < '8' ) /* c est un octal */
                S=OCTAL ;

            else return erreur_caractere (ligne, i , c );
            break ;
        case DEBUT_HEXA : /* il faut au moins un chiffre après x */
            if (isxdigit(c)) S=HEXA ;
            else return erreur_caractere (ligne, i , c );
            break ;
        case HEXA : /* tant que c est un chiffre hexa */
            if ( isxdigit(c)) S=HEXA ;
            else if ( isspace(c) ) {
                return S;
            }
            else return erreur_caractere ( ligne , i , c );
            break ;
        case DECIMAL : /* tant que c est un chiffre */
            if (isdigit(c))      S=DECIMAL ;
            else if ( isspace(c) ) {
                return S;
            }
            else
                return erreur_caractere ( ligne , i , c );
            break ;
        case OCTAL: /* tant que c est un chiffre */
            if ( isdigit(c)&& c < '8') S=OCTAL ;
            else if ( isspace(c)) {
                return S;
            }
            else
                return erreur_caractere ( ligne , i , c );
            break;
        }
    }
    return -1;
}
