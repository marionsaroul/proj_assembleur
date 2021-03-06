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
	int isdata;
	int nb_op ;
	LISTE_OPERANDE liste; // Liste des opérandes 
	int erreur ; // 0 = pas d'erreur 1=erreur synt 2=erreur nb ope
} INSTRUCTION ;




typedef struct 
{	char* nom;
	union val valeur;
	int num_ligne;
	int isdata;
	int erreur ; //0= pas d'erreur 1=erreur synt 2=erreur nb ope
} DATA_DIRECTIVE;

typedef struct
{	char* nom;
	int num_ligne;
	int isdata;
} ETIQUETTE;


int erreur_caractere2 ( char *ligne, int num_ligne );

int action1(char** Tab_mot,int x,int num_ligne);

DATA_DIRECTIVE action2(char** Tab_mot,int isdata,DICO_DIR* DICO_DIR, int size, int Tab_mot_size,int num_ligne);

ETIQUETTE action3(char** Tab_mot,int num_ligne,int x);

INSTRUCTION action4(char** Tab_mot,DICO_INST* dico_inst, int isdata, int num_ligne,int size);

INSTRUCTION action5(char** Tab_mot,DICO_INST* dico_inst, int isdata, int num_ligne, int size);

INSTRUCTION action6(char** Tab_mot,DICO_INST* dico_inst, int isdata, int num_ligne, int size);

