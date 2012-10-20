#include "dictionnaire.h"

void lecture_inst(DICO_INST* tab) {

int pnb=0;

int i =0 ;
int a,b;

FILE *fichier = NULL;
fichier=fopen("instructions.txt","r");

 if (fichier != NULL)
    {
        fscanf(fichier, "%d", &pnb);
        //printf("La taille du dico est: %d", pnb);
 
        
    }
 
// premier ligne du fichier texte indique le nombre de ligne pnb ie le nombre d'instruction

//DICO_INST tab[pnb];
char tmp[512];

	tab[0].size=pnb ; 	
	for (i=0; i<pnb;i++)
	{
 		if (fichier != NULL)
   		 {
        		fscanf (fichier,"%s %d %d", tmp,&a,&b);
        		tab[i].nom=strdup(tmp);
			//printf(" tab.nom = %s \n",tab[i].nom);
        		tab[i].type=a;
        		tab[i].nb_op=b;
        		//printf("type %d %d \n", tab[i].type , b);
		} else {
			fprintf(stderr,"le fichier n'existe pas.\n");
		}
	}
	
}







void lecture_dir(DICO_DIR* tab) {

int pnb;

int i =0 ;

FILE *fichier = NULL;
fichier=fopen("dir.txt","r");

 if (fichier != NULL)
    {
        fscanf(fichier, "%d\n", &pnb);
        printf("la taille du dico est %d\n", pnb);
    }
 
// premier ligne du fichier texte indique le nombre de ligne pnb ie le nombre d'instruction


char tmp[512];
char* tmp2;

tab[0].size=pnb ;
for (i=0; i<pnb;i++)
	{
 		if (fichier != NULL)
   		 {
        		fgets(tmp,511,fichier);
        		tab[i].nom=strtok(tmp," ");
        		printf("type %s, i : %i  \n", tab[i].nom );
			tmp2 = strtok(NULL," ");
			if (strcmp(tmp2,"\n")==1) {
				// cas de set noreorder
				tab[i].valeur.option = strdup(tmp2);
				printf("option : %s\n",tmp2);
			} 
		} else {
			fprintf(stderr,"le fichier n'existe pas.\n");
		}
	}
}



/*
int main (void)
{ DICO_DATA* tab;
printf("ok ok ok");
tab = lecture_data ();
return 0;
}
*/
/*
int main (void)
{ DICO_DIR* tab = calloc(100,sizeof(DICO_INST));
//printf("ok ok ok");
lecture_dir(tab);
return 0;
}
*/


char* strdup(char *str)
{
  char  *dup;

  dup = malloc(strlen(str));
  return (dup ? strcpy(dup, str) : NULL);
}

