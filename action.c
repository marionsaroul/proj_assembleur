#include "action.h"

int erreur_caractere2 ( char *ligne) 
{

    printf("erreur à la chaine %s \n",ligne);
    return -1;
}


int action1(char** Tab_mot,int isdata)
{ 					/*si .data on met à x=1, si .text on met à x=0*/
					/*le point est range en tab_mot[1] on ne s'occupe pas de la case 0*/
char* data = "data";
char* text = "text";
char* mot = strdup(Tab_mot[1]);

//printf("comparaison %d",strcmp(mot,data));

	if (strcmp(mot,data)==0)
	{	
		isdata=1;
		/*printf("la directive est un .data et x = %d \n",x);*/
		return 0;
	}
	else if (strcmp(mot,text)==0)
	{
		isdata=0;
		/*printf("la directive est un .text et x = %d \n",x);*/
		return 0;
	}
	else return erreur_caractere2(mot);
}


DATA_DIRECTIVE action2 (char** Tab_mot,int isdata,DICO_DIR* dico_dir )
{
char * mot=Tab_mot[1];
char * dico;
DATA_DIRECTIVE directive ;
int i,x;
int k=0;
int j=0;


for(i=0;i<dico_dir[0].size;i++)
	{
		dico = dico_dir[i].nom;
		if (strcmp(mot,dico)==0) //on vérifie que notre directive est bien dans le dico
	 	{
		x=1;
		break;
		}
	}
		if (x==1)
		{
		directive.nom=Tab_mot[1];
			// cas de .set
			if(dico_dir[i].valeur.option!= NULL)
			{
				directive.valeur.option=Tab_mot[3];
			}//cas de .byte
			else if(strcmp(directive.nom,".byte")==0)
			{	int a=2;
				while (Tab_mot[a]!=NULL)
				{
				directive.valeur.octet[j]=strdup(Tab_mot[a]);
				j=j+1;
				a++;
				}
			}
			//cas de .word
			else if (strcmp(directive.nom,".word")==0)
			{int b=2;
				while (Tab_mot[b]!=NULL)
				{
				directive.valeur.mot[k]=strdup(Tab_mot[b]);	
				k=k+1;
				b++;
				}
			}
		}
	else 
			{  exit(erreur_caractere2(mot));
			 }

					
return directive;

}


ETIQUETTE action3(char** Tab_mot,int num_ligne,int x)
{ 

ETIQUETTE symbole;
symbole.nom=Tab_mot[2];
symbole.num_ligne=num_ligne;
symbole.segment=x; 
return symbole;
}


INSTRUCTION action4(char** Tab_mot,DICO_INST* dico_inst, int isdata, int num_ligne)
{
	/*Comparaison de la premiere case avec les noms dans le dico des instructions message d'erreur*/

INSTRUCTION instruction;
int i=0;
int x=0;

char* nom = Tab_mot[1];
// TODO: changer size
printf("size = %i \n",dico_inst[0].size );

for (i=0;i<dico_inst[0].size;i++)
	{
		char* dico_insti = dico_inst[i].nom;
		if (strcmp(nom,dico_insti)==0)
		{
		
			x=1;
			break;	
		}	
	}

if (x==1)
{instruction.nom=nom;}

if (x==0)
{erreur_caractere2(nom);}

/*Comparaison nombre d'operandes, il en faut une seule dans l'action 4 */

if ( dico_inst[i].nb_op == 1)
	{
		instruction.liste = enfiler_ope(Tab_mot[2],instruction.liste);
		instruction.erreur = 0;
		instruction.num_ligne = num_ligne;
	}
else 
	{
		printf("Le nombre d'opérandes associees a %s est incorrect \n",instruction.nom);
	}

return instruction;
}



/*

INSTRUCTION action5(LISTE_LEXEME L2,char* Tab_mot)
{


}

INSTRUCTION action6(LISTE_LEXEME L2,char* Tab_mot)
{


}
*/



/* main pour tester ACTION4 */

int main(void)
{
DICO_INST* Dico = calloc(100,sizeof(DICO_INST));
lecture_inst(Dico);
int i=1;
char* Tab_mot[5];
Tab_mot[1]="J";
Tab_mot[2]="$1";

int isdata=1;
int num_ligne=3;
INSTRUCTION inst;


inst=action4(Tab_mot,Dico,isdata,num_ligne);


printf("inst->nom = %s ", inst.nom);
visualiser_ope(inst.liste); 
return 0;
}

// main pour tester ACTION1

/*
int main (void)   
{
int x=0;
int i=1;
char* Tab_mot[7];
// intruction data
Tab_mot[0]="o";
Tab_mot[1]=".data";


	char* Tab_mot2[7];   // instruction text
	Tab_mot2[1]=".text";

	char* Tab_mot3[7];     // intruction erreur
	Tab_mot3[1]=".dapa";


	printf(" La ligne entree est %s \n", Tab_mot[i]);
	action1(Tab_mot,x);
printf(" isdata : %i\n", x);
action1(Tab_mot2,x);
printf(" isdata : %i\n", x);
action1(Tab_mot3,x);
printf(" isdata : %i\n", x);

return 0;
}
*/
