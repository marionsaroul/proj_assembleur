#include "liste_chainee.h"



/* test de la fonction enfiler, création d'une liste vide puis premier élément insérer dans la liste, on visualise la liste. Deuxième test où plusieurs élements sont insérés. On vérifie avec visualiser s'ils sont bien insérés en queue de liste . */


int main (void)
{

// test 1 :
char* string=".debut";
char* type="directive";
LISTE_LEXEME L;

L=creer_liste() ;

L=enfiler(type, string , L) ;
visualiser(L);


//test 2, plusieurs enfilages

char* string1=".debut1";
char* string2=".debut2";
char* string3=".debut3";	
	
		L=enfiler(type, string1 , L) ;
		L=enfiler(type, string2 , L) ;
		L=enfiler(type, string3 , L) ;
		
			
		visualiser(L);


return 0;
} 

