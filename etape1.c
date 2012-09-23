
//TODO: fgetc prend le premier caractère !

#include "etape1.h"

int main ()
{

	
	FILE *Fichier;
	Fichier=fopen("assembleur.txt","r"); 
	//char* Lexeme ;
	//int S ;

	char* ligne ; 
	ligne = malloc (sizeof( char * ));
		
	while (fgetc(Fichier) != EOF){
		fgets(ligne,511,Fichier);
		printf("La ligne est : %s \n", ligne );
		//ligne=canoniser (*ligne ) ;
		
		// while ligne != null 
			//	Lexeme = coupe_ligne (*ligne ) ;
			// 	S=classifie( Lexeme );
			// 	ajout_tete ( S ,liste_L) ;
		//}
	
	}

	return 0;


}
