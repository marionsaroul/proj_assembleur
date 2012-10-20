

#include "analyse_lex_syn.h"
#include "auto_nombre.h"
#include "liste_chainee.h"

int main ()
{

	
	FILE *Fichier;
	 
	Fichier=fopen("Test_general.txt","r"); 
	
	int S ;
	LISTE_LEXEME L;
	L=creer_liste() ;
	char *mot[1000];
	int i;
        char* nl="\n";
	char *etat ;
        int nbrmot_total=0;
        char ligne[512];
        char* ligne2;
			
		while (fgets(ligne,511,Fichier) != NULL){  //fgets renvoie null quand il n'a plus rien à lire 
			if(strcmp(ligne,nl) != 0) {   // permet de ne pas prendre en compte le saut de ligne dans le code assembleur

				/*printf("La ligne est : %s \n", ligne );*/

				ligne2=canoniser(ligne) ;
				
		
				
				  int nbrmot = coupe_ligne (ligne2 , mot) ;
				  nbrmot_total=nbrmot_total+nbrmot;
					
					for (i=0;i<=nbrmot;i++) { 
						
						if (mot[i] != NULL) 
						{ 
					
							S=classifie(mot[i]);
							
								/*if(S==-1)			CAS D'ERREUR : ARRET DU PROGRAMME
									{return 0 ; }		MIS EN COMMENTAIRE POUR LE TEST */

							etat=traduit_etat(S);
							L=enfiler(etat, mot[i],S , L) ;
						}

					}
					free(ligne2);

			}
		}
	visualiser(L);	
	
	/*
	
	collection(L) ; 
	
	*/
	
	
	return 0;
}

