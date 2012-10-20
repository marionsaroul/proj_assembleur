#include "auto_nombre.h"


/* On veut tester si la fonction coupe des qu'il y a un espace dans le cas general et qu'elle ne coupe pas a partir du moment ou elle rencontre un # dans une ligne qui indique un commentaire.
On test aussi que la fonction ajoute un espace a chaque mot qu'elle a coupe.
L'objectif de ce test est de recuperer le tableau contenant tous les mots de la lignes, coupes, avec un espace a la fin.
*/

int main ( void)
{


char *mot[1000] ;// Creation d'un tableau de mots
int i,j;
// On passe en parametre, une ligne canonisee qui reprend certains caracteres qui sont des lexemes d'eux-même ainsi qu'un commentaire.
char string[]="add $6 , $5 .directive ( addition ) # additiondumot1 ";
 
j=coupe_ligne(string, mot);


for (i=0;i<j;i++)
{
printf("le mot dans la case %i est %ss \n",i, mot[i]);
//Le mot de la ieme case est affiche. On rajoute un 's' en fin de mot pour etre sur qu'il y a bien un espace en fin de mot
}


}
