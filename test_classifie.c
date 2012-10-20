#include "auto_nombre.h"



/* on test dans cette fonction tout les lexèmes possibles puis un cas d'erreur */



 
int main (void)
{

// TEST HEXA 
int S1;
char* ligne1="0x0A0 ";
char *etat1;

S1=classifie(ligne1);
etat1=traduit_etat(S1);
printf(" %s est de type %s \n",ligne1,etat1);


// TEST DECIMAL 
int S2;
char* ligne2="5 ";
char *etat2;

S2=classifie(ligne2);
etat2=traduit_etat(S2);
printf(" %s est de type %s \n",ligne2,etat2);

// OCTAL 

int S3;
char* ligne3="013 ";
char *etat3;

S3=classifie(ligne3);
etat3=traduit_etat(S3);
printf(" %s est de type %s \n",ligne3,etat3);

//NL 

int S4;
char* ligne4="\n ";
char *etat4;

S4=classifie(ligne4);
etat4=traduit_etat(S4);
printf(" %s est de type %s \n",ligne4,etat4);

//SYMBOLE 

int S5;
char* ligne5="debut ";
char *etat5;

S5=classifie(ligne5);
etat5=traduit_etat(S5);
printf(" %s est de type %s \n",ligne5,etat5);

//DEUX_PTS 

int S6;
char* ligne6=": ";
char *etat6;

S6=classifie(ligne6);
etat6=traduit_etat(S6);
printf(" %s est de type %s \n",ligne6,etat6);

// VIRGULE 

int S7;
char* ligne7=", ";
char *etat7;

S7=classifie(ligne7);
etat7=traduit_etat(S7);
printf(" %s est de type %s \n",ligne7,etat7);


// REGISTRE 

int S8;
char* ligne8="$6 ";
char *etat8;

S8=classifie(ligne8);
etat8=traduit_etat(S8);
printf(" %s est de type %s \n",ligne8,etat8);


// PARENTHESE_OUVRANTE

int S9;
char* ligne9="( ";
char *etat9;

S9=classifie(ligne9);
etat9=traduit_etat(S9);
printf(" %s est de type %s \n",ligne9,etat9);


// PARENTHESE_FERMANTE

int S10;
char* ligne10=") ";
char *etat10;

S10=classifie(ligne10);
etat10=traduit_etat(S10);
printf(" %s est de type %s \n",ligne10,etat10);


// COMMENT

int S11;
char* ligne11="# ";
char *etat11;

S11=classifie(ligne11);
etat11=traduit_etat(S11);
printf(" %s est de type %s \n",ligne11,etat11);

// DIRECTIVE

int S12;
char* ligne12=".debut ";
char *etat12;

S12=classifie(ligne12);
etat12=traduit_etat(S12);
printf(" %s est de type %s \n",ligne12,etat12);


//PLUS

int S13;
char* ligne13="+ ";
char *etat13;

S13=classifie(ligne13);
etat13=traduit_etat(S13);
printf(" %s est de type %s \n",ligne13,etat13);

// MOINS 
int S14;
char* ligne14="- ";
char *etat14;

S14=classifie(ligne14);
etat14=traduit_etat(S14);
printf(" %s est de type %s \n",ligne14,etat14);


// CAS D'ERREUR

int S15;
char* ligne15=". debut ";
char *etat15;

S15=classifie(ligne15);
etat15=traduit_etat(S15);
printf(" %s est de type %s \n",ligne15,etat15);

return 0;
}
