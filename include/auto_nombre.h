
/**
 * @file auto_nombre.h
 * @author François Portet <francois.portet@imag.fr>
 * @date Thu Sep 13 12:00:00 2012
 * @brief En-tete pour l'automate detectant les differents types de représentation de nombre entier.
 *
 */

#include "analyse_lex_syn.h"

int erreur_caractere ( char * , int  , int );
int classifie(char* );
char* traduit_etat(int );
int coupe_ligne(char *, char** );
char * canoniser (char *);


