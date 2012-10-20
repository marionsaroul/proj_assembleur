#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>



int erreur_caractere ( char *ligne , int i );

int action1(char** Tab_mot,int x);

DATA action2(LISTE_LEXEME L2,char** Tab_mot,int x,int size, DICO_DATA** dico_data );

SYMBOLE action3(char** Tab_mot,int num_ligne,int x);

INSTRUCTION action4(char** Tab_mot,DICO_INST* dico_inst, int size);




