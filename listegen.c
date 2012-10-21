#include "listegen.h"

/* C'est le meme code que precedemment */
LISTE2 ajout(void *p_e, LISTE2 l) 
{
        //Allocation d â 63 ™ un maillon dont la taille est celle de e + 1 pointeur
        LISTE2 p = calloc(1, sizeof(*p));
        
        //On copie la valeur interessante dans le maillon
        p->pval = p_e;
        //On chaine avec la suite de la liste
        p->suiv = l;
        //On retourne la nouvelle liste
        return p;
}

void visualiser_listegen(LISTE2 l, void (*aff) (void *)) 
{
        LISTE2 p;
        for (p = l; p != NULL; p = p->suiv) {
                printf("un tour\n");
                aff(p->pval);
        }
        puts("");
}



void aff1(void *px) {
        printf("%d ", *((ELEMENT1 *) px));
}
void aff2(void *px) {
        printf("%lf ", *((ELEMENT2 *) px));
}
void aff3(void *px) {
        printf("%lf %d ", ((ELEMENT3 *) px)->x, ((ELEMENT3 *) px)->z);
}
/*
main() {
        LISTE2          m1 = NULL, m2 = NULL, m3 = NULL;
        int             i;
        //m1 sera une liste d â 63 ™ entier, m2 une liste de double et m3 une liste de structure
        ELEMENT1 * pe1;
        ELEMENT2       *pe2;
        ELEMENT3       *pe3;
        //Allocation des ELEMENT
        pe1 = calloc(1, sizeof(*pe1));
        pe2 = calloc(1, sizeof(*pe2));
        pe3 = calloc(1, sizeof(*pe3));
        //Remplissage des elements
        * pe1 = 67;
        *pe2 = 3.1415927;
        pe3->x = 2.98;
        pe3->z = 101;

        //Ajout des Elements Ã  leurs listes respectives
        // C â 119 ™ EST LA MEME FONCTION ajout
        // Et vous pouvez faire de meme avec ajout_queue, ajout_trie, supprimer, enfilern defile empiler et depiler.

        m1 = ajout((void *) pe1, m1);
        m2 = ajout((void *) pe2, m2);
        m3 = ajout((void *) pe3, m3);

        visualiser(m1, aff1);
        visualiser(m2, aff2);
        visualiser(m3, aff3);
        //ATTENTION:ce code compile, peut sembler s â 63 ™ executer correctement mais est faux,
        ELEMENT1 e1;
        e1 = 89;
        m1 = ajout((void *) &e1, m1);

        //car les ELEMETNS e1 sont partages
        for (i = 0; i < 10; i++) {
                e1 = i;
                m1 = ajout((void *) &e1, m1);
        }
        visualiser(m1, aff1);

}*/
