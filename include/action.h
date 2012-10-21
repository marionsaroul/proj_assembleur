#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "liste_chainee.h"
#include "dictionnaire.h"



typedef struct
{	char* nom;
	int num_ligne ;
	int nb_op ;
	LISTE_OPERANDE liste; // Liste des opérandes 
	int erreur ; // 0 = pas d'erreur 1=erreur synt 2=erreur nb ope
} INSTRUCTION ;




typedef struct 
{	char* nom;
	union val valeur;
	int num_ligne;
	int segment;
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
} DATA_DIRECTIVE;

typedef struct
{	char* nom;
	int num_ligne;
	int segment;
} ETIQUETTE;


int erreur_caractere2 ( char *ligne );

int action1(char** Tab_mot,int x);

DATA_DIRECTIVE action2(char** Tab_mot,int isdata,DICO_DIR* DICO_DIR, int size);

ETIQUETTE action3(char** Tab_mot,int num_ligne,int x);

INSTRUCTION action4(char** Tab_mot,DICO_INST* dico_inst, int isdata, int num_ligne);




