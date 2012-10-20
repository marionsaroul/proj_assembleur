#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


typedef struct 
{
	char* nom; // ADD...
	int type; // r,j,i
	int nb_op;// nombre d'operandes
	int size;
}DICO_INST;


#ifndef _union
#define _union



union val {
	char* option ; // .set instruction à l'assembleur , ici seulement noreorder considéré 
	char* octet;  // tableau de n valeurs sur 8 bits .byte
	int* mot; // tableau de n mots .word
	unsigned int taille; //.space
	};
#endif


typedef struct 
{
	char *nom; 
	union val valeur;
	int num_ligne; 
	int size;	
}DICO_DIR;


typedef struct
{
	char *nom; 
	int type; 
	int nb_op;
}DICO_SYMB;



void lecture_inst(DICO_INST* tab);
void lecture_dir(DICO_DIR* tab);
char * lecture_symb (void);



char* strdup(char *str);
