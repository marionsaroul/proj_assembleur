#include "collection.h"



LISTE2 collection (LISTE_LEXEME L)
{


        LISTE_LEXEME lexeme;
        LISTE2 Liste_instructions;

        /*LISTE2 l2;*/
        int num_ligne=0;
        char* nl="\n";
        char* Tab_mot[1000];
        int i;
        int isdata=0;

        DATA_DIRECTIVE data_dir;
        ETIQUETTE symbole;
        INSTRUCTION instruction ;

        // initialisation des dictionnaires

        int size_inst, size_dir;
        DICO_INST* dico_inst = calloc(100,sizeof(DICO_INST));;
        size_inst=lecture_inst(dico_inst);
        DICO_DIR* dico_dir = calloc(100,sizeof(DICO_DIR));;
        size_dir=lecture_dir(dico_dir);




        while(! est_vide(L))  
        {
                num_ligne =num_ligne +1 ;
                i=0;
                int F = INIT2;
                char* mot="ok"; // permet de passer le test du premier while

                while(strcmp(mot,nl)!= 0)  // tant qu'on est pas à la fin de ligne 
                {  
                        // Tab_mot commencera à l'indice 1
                        i++; 
                        lexeme=defiler(&L); // on récupère le premier mot du lexème 
                        mot=lexeme->mot;
                        printf(" etat : %i mot : %s F= %i comparaison de %i \n", lexeme->num_etat, mot, F, strcmp(mot,nl));



                        switch (F) {	
                                case INIT2: 
                                        // test si symbole 
                                        if (lexeme->num_etat==8)
                                        {Tab_mot[i]=strdup(mot);

                                                F=DEBUT_SYMBOLE; }

                                        //test si directive
                                        else if (lexeme->num_etat==17)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_DIRECTIVE2;}

                                        //test si fin de ligne ou commentaire
                                        else if(lexeme->num_etat==7 || lexeme->num_etat==15 )
                                        {break;}

                                        else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }
                                        break;

                                case DEBUT_DIRECTIVE2 :

                                        //test si fin de ligne 
                                        if (strcmp(mot,nl)==0)  
                                        {
                                                action1(Tab_mot,isdata);
                                        }

                                        //test si nombre ou symbole
                                        else if (lexeme->num_etat==8 || lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
                                        {	
                                                Tab_mot[i]=strdup(mot);
                                                F=DIR_1;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }

                                        break;

                                case DIR_1 :

                                        if (strcmp(mot,nl)==1) 
                                        {Tab_mot[i]=strdup(mot);
                                                F=DIR_1;}


                                        else if (strcmp(mot,nl)==0)
                                        {
                                                data_dir=action2(Tab_mot,isdata,dico_dir,size_dir,i-1 );
                                                // on ajoute data_dir à la liste renvoyée
                                                Liste_instructions = ajout((void*) &data_dir,Liste_instructions);
                                                printf("data ajouté !\n");
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }

                                        break;

                                case DEBUT_SYMBOLE : 
                                        //test si deux points

                                        if (lexeme->num_etat==9)
                                        {Tab_mot[i]=strdup(mot);
                                                F=ETIQUETTE2 ;}

                                        //test si registre ou hexa ou octal ou decimal (ou étiquette ?) *
                                        else  if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_1 ;
                                        } 

                                        break;

                                case ETIQUETTE2 :
                                        //test si symbole 
                                        if (lexeme->num_etat==8)
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; }

                                        //test fin de ligne
                                        else if (strcmp(mot,nl)==0) 
                                        { 
                                                symbole=action3(Tab_mot,num_ligne,isdata);
                                        } 

                                        break;

                                case INST_1 :
                                        //test fin de ligne après 1er opérande
                                        if (strcmp(mot,nl)==0) 
                                        {
                                                instruction=action4(Tab_mot,dico_inst,isdata,num_ligne,size_inst);
                                                //printf("instruction.nom = %s \n", instruction.nom);
                                                //visualiser_ope(instruction.liste);
                                        }

                                        // test virgule

                                        else if(lexeme->num_etat==10) {
                                                F=INST_2;}

                                        //test si étiquette
                                        else if (lexeme->num_etat==8)
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; 
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }

                                        break;

                                case INST_2 :
                                        // test si registre ou hexa ou octal ou decimal 
                                        if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_3;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }
                                        break;

                                case INST_3 :
                                        //test fin de ligne après 2eme opérande 
                                        if (strcmp(mot,nl)==0) 
                                        {// I2=action5(L,tab_mot) ;
                                                printf("action5"); }

                                        //test virgule

                                        else if(lexeme->num_etat==10)
                                        {
                                                F=INST_4;}

                                        // test si étiquette 
                                        else if (lexeme->num_etat==8)
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; 

                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }
                                        break;


                                case INST_4 :
                                        //test si registre ou hexa ou octal ou decimal 
                                        if (lexeme->num_etat==12 || lexeme->num_etat==4 || lexeme->num_etat==5 || lexeme->num_etat==6 )
                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_5;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }

                                        break;

                                case INST_5 :
                                        //test fin de ligne après 3eme opérande 
                                        if (strcmp(mot,nl)==0) 
                                        { //I3=action6(L,tab_mot) ;
                                                printf("action6"); }

                                        //test si étiquette 
                                        else if (lexeme->num_etat==8)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                exit(0);
                                        }


                                        break; 
                        }
                }

        }

        return Liste_instructions ;

}





//pb car ne rentre pas dans symbole 


int main (void) 
{
        LISTE_LEXEME L=NULL;
        L=enfiler("DIRECTIVE",".data",17,L);
        L=enfiler("NL","\n",7,L);
        visualiser(L);
        LISTE2 Liste_instructions = NULL;
        Liste_instructions = collection(L);
        //visualiser_listegen(Liste_instructions, aff1) ;
}	


//teste avec :gcc -std=c99 -Wall -Wextra -o ion collection.c	
//puis  ./collection

