#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "liste_chainee.h"




/*Définition des fonctions de manipulation des listes*/

LISTE_LEXEME creer_liste(void)
{return NULL ; }



LISTE_LEXEME enfiler(char* etat, char* mot,int S, LISTE_LEXEME L)
{
        LISTE_LEXEME p=calloc(1,sizeof(*p));
        (p->etat)=etat;
        (p->mot)=mot;
        (p->num_etat)=S;
        if (L==NULL)
                p->suiv=p; /* quand elle est vide on boucle sur elle m*/
        else
        {
                p->suiv=L->suiv;
                L->suiv=p;
        }
        return p;
}

LISTE_LEXEME defiler (LISTE_LEXEME* pL)
{LISTE_LEXEME p;
        p= (*pL)->suiv;
        if (*pL == (*pL)->suiv) *pL=NULL;
        else (*pL)->suiv =p->suiv;
        return p;

}

int est_vide(LISTE_LEXEME L)
{ 
        return !L;
}


void visualiser_ope( LISTE_OPERANDE L)
{
        LISTE_OPERANDE Liste;
        if (L->suiv != NULL) {
                for(Liste=L->suiv;Liste!=L;Liste=Liste->suiv)
                {  
                        printf("opérande : %s \n",Liste->mot);
                }
        }
       printf("opérande: %s \n",L->mot);
}

void visualiser( LISTE_LEXEME L)
{LISTE_LEXEME Liste;

        for(Liste=L->suiv;Liste!=L;Liste=Liste->suiv)
        {  printf("[%s ] : %s \n",Liste->etat,Liste->mot);
        }
        printf("[%s ] : %s \n",L->etat,L->mot);
}


LISTE_OPERANDE enfiler_ope(char* mot, LISTE_OPERANDE L)
{
        LISTE_OPERANDE p=calloc(1,sizeof(*p));
        (p->mot)=mot;
        if (L==NULL) {
                p->suiv=p; /* quand elle est vide on boucle sur elle m*/
        } else {
                p->suiv=L->suiv;
                L->suiv=p;
        }
        return p;
}

