
/**
 * @file auto_nombre.h
 * @author François Portet <francois.portet@imag.fr>
 * @date Thu Sep 13 12:00:00 2012
 * @brief En-tete pour l'automate detectant les differents types de représentation de nombre entier.
 *
 */

#ifndef _AUTO_NOMBRE_H_
#define _AUTO_NOMBRE_H_

/* definition des etats */
enum { INIT , PRE_HEXA , DEBUT_HEXA , HEXA , DECIMAL , OCTAL } ;

int erreur_caractere ( char * , int  , int );
int classifie(char* );
char* traduit_etat(int );

#endif /* _AUTO_NOMBRE_H_ */
