#include <stdio.h>
#include <stdlib.h>


typedef struct maillon {
        void           *pval;
        struct maillon *suiv;
} *LISTE2;


//C â est dasn l â utilisation que cela differe:il faut allouer dynamiquement par calloc un ELEMENT.

// SI ELEMENT1 est int;
typedef int     ELEMENT1;
typedef double  ELEMENT2;
typedef struct {
        double          x;
        int             z;
} ELEMENT3;

void aff1(void *px);
void aff2(void *px);
void aff3(void *px);
void aff4(void *px);

LISTE2 ajout(void *p_e, LISTE2 l); 
void visualiser_listegen(LISTE2 l, void (*aff) (void *)) ;


