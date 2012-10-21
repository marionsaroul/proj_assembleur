
/**
 * @file auto_nombre.c
 * @author François Portet <francois.portet@imag.fr>
 * @date Thu Sep 13 12:00:00 2012
 * @brief Fonction de l'automate détectant les différents types de représentation de nombre entier.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>



#include <ctype.h>


#include "auto_nombre.h"




/*
 * @param ligne chaîne de caractères à analyser
 * @param i index du caractère en faute
 * @param c code ascii du caractère en faute
 * @return -1
 * @brief message d'erreur généré lorsqu'une erreur de décodage apparaît
 *
 */
int erreur_caractere ( char *ligne , int i , int c) {

    printf("erreur au %d caractere %c de la chaine %s\n",i,c,ligne);
    return -1;
}


/*
 * @param S entier codant l'état de l'automate
 * @return une chaîne de caractères représentant l'état S
 * @brief traduit un état donné sous forme de valeur numérique en chaîne de caractères
 *
 *
 */

char* traduit_etat(int S) {
    char* etat_string[] = {	"INIT",
                            "PRE_HEXA",
                            "DEBUT_HEXA",
                            "HEXADECIMAL",
                            "DECIMAL",
                            "OCTAL",
                            "NL" ,
                            "SYMBOLE" ,
                            " DEUX_PTS" , 
                            "VIRGULE" ,
			    "DEBUT_REGISTRE",	
                            " REGISTRE ",
                            " PARENTHESE_OUVRANTE", 
                            "PARENTHESE_FERMANTE", 
                            "COMMENT",
			     " DEBUT_DIRECTIVE" ,
			    " DIRECTIVE",
			     " PLUS", 
			      "MOINS",
                          };
    if (S>-1 && S<19)
        return etat_string[S];

    return "erreur";
}


/**
 * @param ligne chaîne de caractères à classifier
 * @return l'état de l'automate en cas de succès, -1 sinon
 * @brief fonction qui met en œuvre l'automate de classification de chaîne de caractères
 *
 *
 */


int classifie(char* ligne) {
    int S = INIT;
    uint32_t i=0;

    for (i=0; i<=strlen(ligne); i++) 
	{
        char c=ligne[i];
        switch (S) {

	case COMMENT : /* si premier caractère est, # alors commentaire, peut importe ce qu'il y a en */
                return S;
		
		
	case NL : 
		
	        if ( c==0 || isspace(c)  ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;		

	case SYMBOLE : 
		if (isalpha(c) || isdigit(c)) S=SYMBOLE; /* tant que c'est une lettre */
		else if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;
		
	case DEBUT_REGISTRE :  /* il faut au moins un chiffre après $ */
		if (isdigit(c)) S=REGISTRE;
		else return erreur_caractere ( ligne , i , c );
            break ;		

	case REGISTRE :
	        if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;	
		
	case VIRGULE :
		if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;		

	case DEUX_PTS :
		
		if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;		
		
	case PARENTHESE_OUVRANTE :
		 if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;

	case PARENTHESE_FERMANTE:
		if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;

	case 	DEBUT_DIRECTIVE:    /* il faut au moins une lettre après le . */
		if (isalpha(c)) {S=DIRECTIVE;}
		else return erreur_caractere ( ligne , i , c );
            break ;

	case DIRECTIVE: /* tant que s'est une lettre */
		if (isalpha(c) || isdigit(c)) { S=DIRECTIVE;  }
		else if ( c==0 || isspace(c) ) { 
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;
            
        case 	PLUS:
		if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;
            
       case 	MOINS:
		if ( c==0 || isspace(c) ) {
                return S; }
		else return erreur_caractere ( ligne , i , c );
            break ;
            

        case INIT :
		
            if (isdigit(c)) {  
                   /* si c est un chiffre */
                S = ( c== '0' ) ? PRE_HEXA : DECIMAL ;
                if(S==PRE_HEXA && (i== strlen(ligne)-1 || isspace(ligne[i+1]))) {
                      S = DECIMAL ;/* cas ou le nombre est 0*/
                }
            }
            	
                else if (c == '\n') S=NL ; /*\n = isspace(c) donc test pour \n avant test isspace(c) */
		else if ( isspace(c)) S=INIT ;
		else if (c == '#')  S=COMMENT ;
		else if (c == ':') S=DEUX_PTS;
		else if (c == ',') S=VIRGULE ;
		else if (c == '$') S=DEBUT_REGISTRE;
		else if (isalpha(c)) S=SYMBOLE;
		else if (c == '(') S=PARENTHESE_OUVRANTE;
		else if (c == ')') S=PARENTHESE_FERMANTE ;
		else if (c == '.') {S=DEBUT_DIRECTIVE;  }
		else if (c == '+') S=PLUS ;
		else if (c == '-') S=MOINS ;
	    
            else return erreur_caractere (ligne , i , c );
            break ;
 
       case PRE_HEXA: /* repérage du préfixe de l hexa */
            if ( c == 'x' || c == 'X' ) S=HEXA ;
            else if (isdigit(c) && c < '8' ) /* c est un octal */
                S=OCTAL ;

            else return erreur_caractere (ligne, i , c );
            break ;
      
  case DEBUT_HEXA : /* il faut au moins un chiffre après x */
            if (isxdigit(c)) S=HEXA ;
            else return erreur_caractere (ligne, i , c );
            break ;
        case HEXA : /* tant que c est un chiffre hexa */
            if ( isxdigit(c)) S=HEXA ;
            else if ( c==0 || isspace(c) ) {
                return S;
            }
            else return erreur_caractere ( ligne , i , c );
            break ;

       case DECIMAL : /* tant que c est un chiffre */
            
		if (isdigit(c))      S=DECIMAL ;
            else if ( c==0 || isspace(c) ) {
                return S;
            }
            else
                return erreur_caractere ( ligne , i , c );
            break ;


        case OCTAL: /* tant que c est un chiffre */
            if ( isdigit(c)&& c < '8') S=OCTAL ;
            else if ( c==0 || isspace(c)) {
                return S;
            }
            else
                return erreur_caractere ( ligne , i , c );
            break;
        }
    }
    return -1;
}


char* canoniser (char *ligne)

{ 
char s[1000];
s[0]=0;  	 // On prend une chaine assez longue pour pas etre depassee
int i ;
	
	for (i=0; i<strlen(ligne); i++) 

		{char c=ligne[i];
         
       
	

		if (c!= '\n')                             // c n'est pas un pointeur mais un caratere, on arrete au 									caractere de fin de ligne
			{	
				if (c == ',') 		     // CAS DE LA VIRGULE : on met un espace avant et aprs la virgule
					{
					strcat(s," , ");
					}


				else if ( c == '(')	    // CAS DE LA PARENTHESE OUVRANTE
					{
					strcat(s," ( ");
					}

				else if ( c == ')')	    // CAS DE LA PARENTHESE FERMANTE
					{
					strcat(s," ) ");
					}

				else if ( c == ':')	    // CAS DES DEUX POINTS
					{
					strcat(s," : ");
					}

				else if ( c == '+')	    // CAS DU PLUS
					{
					strcat(s," + ");
					}

				else if ( c == '-')	    // CAS DU MOINS
					{
					strcat(s," - ");
					}

				else if ( c == '\t')	    // CAS DE LA TABULATION
 
					{
					strcat(s," ");
					}


				else 
					{
					s[strlen(s)+1]='\0';	//on rajoute un 0 a la suite de la chaine. Permet de 									toujours garder un 0 en fin de chaine pour que les 									conditions de la boucles fonctionnent
					s[strlen(s)] = c;	// Avant le 0 ajoute, on ajoute le caracter a concatener.
					}
					
       					// Pour tous les autres cas on concatène le caractere avec s
			}
				
// On ne s'occupe pas des espaces multiples, non necessaire pour la fonction coupe_mot

	}	
	return strdup(s);  // On alloue la memoire necessaire a la chaine creer et on la duplique dedans. Si on avait 				       retourner s, on aurait pu perdre l'information (ce n'est pas nous qui avions allouer la 				       memoire necessaire.
}




int coupe_ligne(char * ligne,char* mot[1000] )
{
	int i=0;
	char* p;	
	
	char* save=strdup(ligne);
	char* psave=strstr(save,"#");
	p=strtok(ligne," ");

	
	
	while (p != NULL)
	{	
		if (p[0] == '#') {     // cas du commentaire: dès que le caractère # est lu on copie tout le reste de la phrase et on arrète la fonction coupe ligne
			mot[i]= strdup(psave);
			i=i+1;
			mot[i]=strdup("\n");
			break;
		} else {
			mot[i]=strdup(p);     // On aloue la memoire, on dupplique p et on le stock dans la i eme case de mot
			p=strtok(NULL, " ");
			i++;
			if (p == NULL) {
				// cas fin de la ligne
				mot[i]=strdup("\n");
			}

		}
	}
	
return i;

}





