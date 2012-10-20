

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


DATA_DIRECTIVE action2 (char** Tab_mot,int isdata,DICO_DIR* DICO_DIR )
{
DATA_DIRECTIVE dir;
return dir;
}
/*
char * mot=Tab_mot[2];
char * dico;

for(i=0;i<size;i++)
	{
		dico = DICO_DIR[i];
		if (strcmp(mot,dico)==0) //on vérifie que notre directive est bien dans le dico
	 	x=1;
	}
		if (x==1)
		{
		data.nom=Tab_mot[2];
		//data.val=Tab_mot[3]; comment faire avec union val ???
		}
		else 
		data.erreur=1;	
return data ;

}*/


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
		printf("Le nombre d'opérandes associees a %s est incorrect",instruction.nom);
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

/*pb car ne rentre pas dans symbole */

/* main pour tester ACTION4 */
/*
int main(void)
{

//DICO_INST* Dico;
//Dico=lecture_inst();
printf("je suis dans le main");
int i=1;
char* Tab_mot[5];
Tab_mot[1]="ADD";
Tab_mot[2]="$1";
Tab_mot[3]="$2";
Tab_mot[4]="$3";

for(i=1;i<6;i++)

	{ 	printf("%s",Tab_mot[i]);}
//action4(Tab_mot,Dico,Dico.size);
*/
//return 0;
//}

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
