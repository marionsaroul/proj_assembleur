#include <stdio.h>
#include <string.h>



struct cellule  {
char* mot;
char * etat;
int num_etat;
struct cellule* suiv; };

typedef struct cellule* LISTE_LEXEME ;


struct cellule2  {
char* mot;
struct cellule2* suiv; };
typedef struct cellule2* LISTE_OPERANDE ;

LISTE_LEXEME enfiler(char* etat, char* mot,int S, LISTE_LEXEME L);
LISTE_LEXEME defiler (LISTE_LEXEME* pL);
int est_vide(LISTE_LEXEME L);
void visualiser( LISTE_LEXEME L);
void visualiser_ope( LISTE_OPERANDE L);
LISTE_LEXEME creer_liste(void);
LISTE_OPERANDE enfiler_ope(char* mot, LISTE_OPERANDE L);


