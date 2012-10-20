#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "collection.h"
#include "dictionnaire.h"
#include "action.h"

int erreur_caractere ( char *ligne , int i ) {

    printf("erreur au %d caractere de la chaine %s\n",i,ligne);
    return -1;
}


LISTE_LEXEME creer_liste(void)
	{return NULL ; }



LISTE_LEXEME enfiler(char* etat, char* mot,int S, LISTE_LEXEME L)
	{
	LISTE_LEXEME p=calloc(1,sizeof(*p));
	  (p->etat)=etat;
	  (p->mot)=mot;
	  (p->num_etat)=S;
		if (L==NULL)
			 p->suiv=p; /* quand elle est vide on boucle sur elle m*/
	 	else
	 	{
	 	p->suiv=L->suiv;
	 	L->suiv=p;
		}
	return p;
}

LISTE_LEXEME defiler (LISTE_LEXEME* pL)
	{LISTE_LEXEME p;
	p= (*pL)->suiv;
	if (*pL == (*pL)->suiv) *pL=NULL;
	else (*pL)->suiv =p->suiv;
	return p;
/*
p->mot=L->mot;
p->num_etat=L->num_etat;
p->etat=L->etat;
free(L);
return p;*/
	}

	int est_vide(LISTE_LEXEME L)
	{return !L;
	}

	void visualiser( LISTE_LEXEME L)
	{LISTE_LEXEME Liste;

	  for(Liste=L->suiv;Liste!=L;Liste=Liste->suiv)
		  {  printf("[%s ] : %s \n",Liste->etat,Liste->mot);
}
     printf("[%s ] : %s \n",L->etat,L->mot);
}


//LISTE2 collection(LISTE_LEXEME L) ;

int collection (LISTE_LEXEME L)
{


LISTE_LEXEME lexeme,lexeme2;

/*LISTE2 l2;*/
int num_ligne=0;
/*int etat_data ;*/
/*DATA d ;*/
/*INSTRUCTION I1,I2,I3;*/
/*SYMBOLE S;*/
char* nl="\n";
/*char* mot="add";*/
char* Tab_mot[1000];
int i,x;
DATA data;
SYMBOLE symbole;
INSTRUCTION instruction ;

DICO_INST* dico_inst;
dico_inst = lecture_inst ();


/* a tester
DICO_DATA* dico_data;
dico_data= lecture_data ();
*/

/* enum { INIT 1 , PRE_HEXA 2, DEBUT_HEXA 3, HEXA 4, DECIMAL 5, OCTAL 6, NL 7,SYMBOLE 8, DEUX_PTS 9, VIRGULE 10, DEBUT_REGISTRE 11, REGISTRE 12, PARENTHESE_OUVRANTE 13, PARENTHESE_FERMANTE 14, COMMENT   15, DEBUT_DIRECTIVE   16, DIRECTIVE    17, PLUS 18, MOINS   19} ;*/


	
	
	while(! est_vide(L))   /* est_vide à faire*/
	{num_ligne =num_ligne +1 ;
	i=0;
	int F = INIT;
		char* mot="ok"; /* permet de passer le test du premier while*/

		while(strcmp(mot,nl)!= 0)  /* tant qu'on est pas à la fin de ligne */
			{  
  			i=i+1;
			lexeme=defiler(&L);
			mot=lexeme->mot;
			/*visualiser(L);*/
			/*lexeme2=enfiler(lexeme->etat,mot,lexeme->num_etat,L);*/
			printf(" etat : %i mot : %s F= %i comparaison de %i \n", lexeme->num_etat, mot,F, strcmp(mot,nl));
			
		
			
      					  switch (F) {	

						case INIT: 
							/* test si symbole */
							 if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);

							 F=DEBUT_SYMBOLE; }
							 
							 /*test si directive*/
							 else if (lexeme->num_etat==17)
							 {Tab_mot[i]=strdup(mot);
							 F=DEBUT_DIRECTIVE;}
							 
							 /*test si fin de ligne ou commentaire*/
							 else if(lexeme->num_etat==7 || lexeme->num_etat==15 )
							 {break;}
							 
							 else {
							 	return erreur_caractere ( lexeme->mot );
							}
						break;
						
						case DEBUT_DIRECTIVE :
						
							/*test si symbole */
						 	if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);
							   F=DIR_1; }
							 
							 /*test si nombre*/
							 else if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
							 {Tab_mot[i]=strdup(mot);
							F=DIR_2;}
						
							else return erreur_caractere ( lexeme->mot );
						break;
						
						case DIR_1 :

							/*test fin de ligne */
							 if (strcmp(mot,nl)==0) 
							 
							{printf("action1");
							x=action1(Tab_mot,x);
							}
								
							else return erreur_caractere ( lexeme->mot );
							
						break;
						
						case DIR_2 :
						
							 if (strcmp(mot,nl)==0) 
							{data=action2(Tab_mot,x,dico_data.size,dico_data );
							/*L2=ajout(d,L);*/
							 printf("action2");
							 }	
							else return erreur_caractere ( lexeme->mot );
						break;
						
						case DEBUT_SYMBOLE : 
							/*test si deux points*/
						
							if (lexeme->num_etat==9)
							 {Tab_mot[i]=strdup(mot);
							 F=ETIQUETTE ;}
							 
							 /* test si registre ou hexa ou octal ou decimal (ou étiquette ?) */ 
							 else  if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
							 {Tab_mot[i]=strdup(mot);
							 	F=INST_1 ;} 
						
						break;
						
          					case ETIQUETTE :
          						/*test si symbole */
          						if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);
							F=DEBUT_SYMBOLE; }
							 
							 /*test fin de ligne*/
							 else if (strcmp(mot,nl)==0) 
							 { symbole=action3(Tab_mot,num_ligne,x);
							 printf("action3"); } /*action3 à faire*/
							 
						break;
							 
						case INST_1 :
							/*test fin de ligne après 1er opérande */
							 if (strcmp(mot,nl)==0) 
							 {instruction=action4(Tab_mot,dico_inst,dico_inst.size);
							 printf("action4"); }
							 
							 /*sinon test virgule*/
							 
							 else if(lexeme->num_etat==10)
								 {F=INST_2;}
							
							/*test si étiquette */
							else if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);
							F=DEBUT_SYMBOLE; }
							 
							 else return erreur_caractere ( lexeme->mot );
						 
						 break;
						 
						 case INST_2 :
							 /* test si registre ou hexa ou octal ou decimal */ 
							 if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
								 {Tab_mot[i]=strdup(mot);
								F=INST_3;}
							 else return erreur_caractere ( lexeme->mot );
						
						
						break;
						
						case INST_3 :
							/*test fin de ligne après 2eme opérande */
							 if (strcmp(mot,nl)==0) 
							 {/* I2=action5(L,tab_mot) ;*/
							 printf("action5"); }
							 
							 /*sinon test virgule*/
							 
							 else if(lexeme->num_etat==10)
								 {
								F=INST_4;}
							
							/*test si étiquette */
							else if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);
							F=DEBUT_SYMBOLE; }
							 
							 else return erreur_caractere ( lexeme->mot );
						break;
						
						
						  case INST_4 :
							 /* test si registre ou hexa ou octal ou decimal */ 
							 if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
								 {Tab_mot[i]=strdup(mot);
								F=INST_5;}
							 else return erreur_caractere ( lexeme->mot );
						
						break;
						
						case INST_5 :
							/*test fin de ligne après 3eme opérande */
							 if (strcmp(mot,nl)==0) 
							 { //I3=action6(L,tab_mot) ;
							 printf("action6"); }
							
							/*test si étiquette */
							else if (lexeme->num_etat==8)
							 {Tab_mot[i]=strdup(mot);
							F=DEBUT_SYMBOLE;
								 }
							 
							 else return erreur_caractere ( lexeme->mot );
							
							
						break; 
						 }
				}
							 
	}

}
	

	
	

//pb car ne rentre pas dans symbole 

/*

int main (void) 
{
LISTE_LEXEME L=creer_liste();
L=enfiler("SYMBOLE","add",8,L);
L=enfiler("REGISTRE","$6",12,L);
L=enfiler("NL","\n",7,L);
L=enfiler("DIRECTIVE",".",17,L);
L=enfiler("DECIMAL","6",5,L);
L=enfiler("NL","\n",7,L);
visualiser(L);
collection(L);
}	
*/

//teste avec :gcc -std=c99 -Wall -Wextra -o ion collection.c	
//puis  ./collection

