#include <stdio.h>
#include <string.h>



struct cellule  {
char* mot;
char * etat;
int num_etat;
struct cellule* suiv; };

typedef struct cellule* LISTE_LEXEME ;



LISTE_LEXEME enfiler(char* etat, char* mot,int S, LISTE_LEXEME L);
void visualiser( LISTE_LEXEME L);
LISTE_LEXEME creer_liste(void);

/*
#ifndef _LISTE_OPERANDE
#define _LISTE_OPERANDE

struct cellule {
	char* operande ;		
		};
typedef struct cellule *LISTE_OPERANDE;



#endif
#define STRLEN 80



typedef struct
{	char* nom;
	int num_ligne ;
	int nb_op ;
	LISTE_OPERANDE liste; // Liste des opérandes 
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
} INSTRUCTION ;


union val {
	char octet;
	int mot;
	unsigned int taille;
	}

typedef struct
{	char* nom;
	union val valeur;
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
} DATA;

typedef struct
{	char* nom;
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
} SYMBOLE;


A FAIRE

LISTE_OPERANDE enfiler_op(char* operande, LISTE_OPERANDE L);
void visualiser_op( LISTE_OPERANDE L);
LISTE_OPERANDE creer_liste_op(void);





*/

