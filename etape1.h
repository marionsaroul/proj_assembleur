
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


//#include "auto_nombre.h"


struct cellule  {
char* mot;
int type;
struct cellule* suiv; };

typedef struct cellule LISTE_LEXEME ;

//classifier_lexeme (char* lexeme ) ;

enum { INIT , PRE_HEXA , DEBUT_HEXA , HEXA , DECIMAL , OCTAL , NL ,SYMBOLE , DEUX_PTS , VIRGULE , REGISTRE , PARENTHESE_OUVRANTE, PARENTHESE_FERMANTE, COMMENT } ;
#ifndef _AJOUT_TETE
#define _AJOUT_TETE

/*
void Ajout_Tete(int type, char* mot, LISTE_LEXEME *L);
void Visualiser_Liste( LISTE_LEXEME *L);
LISTE_LEXEME creer_liste(void);
*/

#endif 

