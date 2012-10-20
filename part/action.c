#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int erreur_caractere ( char *ligne) 
{

    printf("erreur à la chaine %s \n",ligne);
    return -1;
}

int action1(char** Tab_mot,int x)
{ 
 						/*si .data on met à x=1, si .text on met à x=0*/						/*le point est range en tab_mot[1] on ne s'occupe pas de la case 0*/
char* data = "data";
char* text = "text";
char* mot = strdup(Tab_mot[2]);

/*printf("comparaison %d",strcmp(mot,data))*/

	if (strcmp(mot,data)==0)
	{	
		x=1;
		/*printf("la directive est un .data et x = %d \n",x);*/
		return x;
	}
	else if (strcmp(mot,text)==0)
	{
		x=0;
		/*printf("la directive est un .text et x = %d \n",x);*/
		return x;
	}
	else return erreur_caractere (mot);

}


DATA action2 (LISTE_LEXEME L2,char** Tab_mot,int x,int size, DICO_DATA** dico_data ) 
{
int i ;
DATA data;
char * mot=Tab_mot[2];

	for(i=0;i<size;i++)
	{char * dico=dico_data[i];
		if (strcmp(mot,dico)==0) //on vérifie que notre directive est bien dans le dico
	 	x=1;
	}
		if (x==1)
		{
		data->nom=Tab_mot[2];
		//data->val=Tab_mot[3]; comment faire avec union val ???
		}
		else 
		data->erreur=1;	
return data ;

}


SYMBOLE action3(char** Tab_mot,int num_ligne,int x)
{ 

SYMBOLE symbole;
symbole.nom=Tab_mot[2];
symbole.num_ligne=num_ligne;
symbole.segment=x; 
return symbole;
}


INSTRUCTION action4(char** Tab_mot,DICO_INST* dico_inst, int size)
{
	/*Comparaison de la premiere case avec les noms dans le dico des instructions message d'erreur*/

INSTRUCTION instruction;
int i=0;
int j=0;
int x=0;
char* nom = Tab_mot[1];

for (i=0;i<size;i++)
	{
		char* dico_insti = dico_inst[i].nom;
		if (strcmp(nom,dico_insti)==0)
		{x=1;
		i=j;	
		}	
	}

if (x==1)
{instruction.nom=nom;}

if (x==0)
{erreur_caractere(nom);}

	/*Comparaison nombre d'operandes, il en faut une seule dans l'action 4*/

if ( dico_inst[j].nb_op == 1)
	{
	instruction.nb_op=Tab_mot[2];
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

int main(void)
{
/*
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
return 0;
}


/* main pour tester ACTION1
int main (void)   
{

int i=1;
	char* Tab_mot[7];
	//char* data = "data";  // intruction data
	Tab_mot[0]="o";
	Tab_mot[1]=".";
	Tab_mot[2]="data";


	char* Tab_mot2[7];   // instruction text
	Tab_mot2[1]=".";
	Tab_mot2[2]="text";

	char* Tab_mot3[7];     // intruction erreur
	Tab_mot3[1]=".";
	Tab_mot3[2]="dapa";


for (i==1;i<3;i++)
{
	printf(" La ligne entree est %s \n", Tab_mot [i]);
}

int x;
action1(Tab_mot,x);
action1(Tab_mot2,x);
action1(Tab_mot3,x);

return 0;
}
*/
