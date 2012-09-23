#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "liste_chainee.h"



// Définition des fonctions de manipulation des listes
LISTE_LEXEME creer_liste(void)
{return NULL ; }

void Ajout_Tete(int type, char* mot, LISTE_LEXEME *L)
{
	LISTE_LEXEME* p=L;
	L=(LISTE_LEXEME*)malloc(sizeof(LISTE_LEXEME));
	(L->suiv)=p;
	(L->type)=type;
	(L->mot)=mot;
	}
                                                                              
int est_vide(LISTE_LEXEME *L)
{ 
	if ((L==NULL)) 
	{ return 1;}
	else
	{ return 0;}
}

void Visualiser_Liste( LISTE_LEXEME *L)
{
	LISTE_LEXEME *p;
	p=L;
	while (!est_vide(p)) {
		if (p == NULL) printf("faux\n");
		printf("%i,%s, \n",p->type,p->mot);
		p=p->suiv;
	}
}

main ()
{
LISTE_LEXEME* L;

L=creer_liste(void) ;

Ajout_Tete (HEXA, "commentaire", L) ;
Visualiser_Liste(L);
} 

