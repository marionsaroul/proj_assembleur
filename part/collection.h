#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


#ifndef _ENUM
#define _ENUM


/*classifier_lexeme (char* lexeme ) ;*/

enum { INIT , DEBUT_DIRECTIVE, DIR_1, DIR_2, DEBUT_SYMBOLE ,ETIQUETTE, INST_1,INST_2,INST_3,INST_4,INST_5 };

#endif

struct cellule  {
char* mot;
char * etat;
int num_etat;
struct cellule* suiv; };


typedef struct cellule* LISTE_LEXEME ;

typedef struct INSTRUCTION instruction
struct 
{	char* nom;
	int num_ligne ;
	int nb_op ;
	//LISTE_OPERANDE liste; // Liste des opérandes 
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
}; INSTRUCTION ;


#ifndef _union
#define _union



union val {
	char octet;
	int mot;
	unsigned int taille;
	};
#endif

typedef struct data
{	char* nom;
	//union val valeur;
	int num_ligne;
	int segment;
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
}; DATA;

typedef struct symbole
{	char* nom;
	int num_ligne;
	int segment;
}; SYMBOLE;


	
int collection(LISTE_LEXEME L) ;

	


void visualiser( LISTE_LEXEME L);


LISTE_LEXEME enfiler(char* etat, char* mot,int S, LISTE_LEXEME L);

LISTE_LEXEME creer_liste(void);






