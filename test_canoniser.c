#include "auto_nombre.h"




/* Le but est de tester la fonction canoniser. On veut savoir si pour les caracteres tels que 
	- deux points
	- virgule
	- parenthese ouvrante
	- parenthese fermante
	- '+'
	- '-'
la fonction ajoute un espace avant et apres le caractere
Pour la tabulation, on veut la remplacer par un espace.
Le cas des espaces multiples n'est pas traite, car la fonction coupe_ligne ne tient pas compte du nombre de separateurs

*/

int main ( void)
{
char *ligne;

ligne=canoniser ("add $6,$5 .directive (addition) # additiondumot1");
// On test dans cette ligne tous les cas cites precedemment ainsi que la ponctuations, les carateres speciaux et les chiffres
printf("%s \n",ligne);
return 0;
}


	

	
