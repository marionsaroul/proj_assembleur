#include "collection.h"



LISTE2 collection (LISTE_LEXEME L)
{


        LISTE_LEXEME lexeme;
        LISTE2 l2=NULL;

        /*LISTE2 l2;*/
        int num_ligne=0;
        char* nl="\n";
        char* Tab_mot[1000];
        int i;
        int isdata=0;

        DATA_DIRECTIVE data;
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

                        //printf(" etat : %i mot : %s, F= %i comparaison de %i \n", lexeme->num_etat, mot,F, strcmp(mot,nl));



                        switch (F) {	

                                case INIT2: 
                                        // test si symbole 
                                        if (lexeme->num_etat==7)
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; 
                                        }

                                        //test si directive
                                        else if (lexeme->num_etat==16)
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                F=DEBUT_DIRECTIVE2;
                                        }

                                        //test si fin de ligne ou commentaire
                                        else if(lexeme->num_etat==6 || lexeme->num_etat==14)
                                        {
                                                break;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }
                                        break;

                                case DEBUT_DIRECTIVE2 :

                                        //test si fin de ligne 
                                        if (strcmp(mot,nl)==0)  
                                        {
                                                action1(Tab_mot,isdata);
                                        }

                                        //test si nombre ou symbole ou registre
                                        else if (lexeme->num_etat==7 || lexeme->num_etat==11 || lexeme->num_etat==3 || lexeme->num_etat==4 || lexeme->num_etat==5 )
                                        {	
                                                Tab_mot[i]=strdup(mot);
                                                F=DIR_1;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }
                                        break;

                                case DIR_1 :

                                        if (strcmp(mot,nl)!=0) 
                                        {
                                                Tab_mot[i]=strdup(mot);
                                                printf("            i : %i, mot : %s\n",i, mot);
                                                F=DIR_1;
                                        }


                                        else 
                                        {
                                                printf("i : %i\n",i);
                                                data=action2(Tab_mot,isdata,dico_dir,size_dir,i-1 ,num_ligne);
                                                l2 = ajout(&data, l2);
                                                printf("un ajout\n");
                                        }
                                        break;

                                case DEBUT_SYMBOLE : 
                                        //test si deux points

                                        if (lexeme->num_etat==8)
                                        {Tab_mot[i]=strdup(mot);
                                                F=ETIQUETTE2 ;}

                                        //test si registre ou hexa ou octal ou decimal (ou étiquette ?) *
                                        else if (lexeme->num_etat==7 || lexeme->num_etat==11 || lexeme->num_etat==3 || lexeme->num_etat==4 || lexeme->num_etat==5 )

                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_1 ;
                                        } 

                                        break;

                                case ETIQUETTE2 :
                                        //test si symbole 
                                        if (lexeme->num_etat==7)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; }

                                        //test fin de ligne
                                        else if (strcmp(mot,nl)==0) 
                                        { 
                                                symbole=action3(Tab_mot,num_ligne,isdata);
                                                l2 = ajout(&symbole, l2);
                                        } 

                                        break;

                                case INST_1 :
                                        //test fin de ligne après 1er opérande
                                        if (strcmp(mot,nl)==0) 
                                        {
                                                instruction=action4(Tab_mot,dico_inst,isdata,num_ligne,size_inst);
                                                l2 = ajout(&instruction, l2);
                                                //printf("instruction.nom = %s \n", instruction.nom);
                                                //visualiser_ope(instruction.liste);
                                        }

                                        // test virgule

                                        else if(lexeme->num_etat==9)
                                        {F=INST_2;}

                                        //test si étiquette
                                        else if (lexeme->num_etat==7)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; 
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }


                                        break;

                                case INST_2 :
                                        // test si registre ou hexa ou octal ou decimal 
                                        if (lexeme->num_etat==7 || lexeme->num_etat==11 || lexeme->num_etat==3 || lexeme->num_etat==4 || lexeme->num_etat==5 )

                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_3;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }


                                        break;

                                case INST_3 :
                                        //test fin de ligne après 2eme opérande 
                                        if (strcmp(mot,nl)==0) 
                                        {// I2=action5(L,tab_mot) ;
                                                printf("action5"); }

                                        //test virgule

                                        else if(lexeme->num_etat==9)
                                        {
                                                F=INST_4;}

                                        // test si étiquette 
                                        else if (lexeme->num_etat==7)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE; 
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }

                                        break;


                                case INST_4 :
                                        //test si registre ou hexa ou octal ou decimal 
                                        if (lexeme->num_etat==7 || lexeme->num_etat==11 || lexeme->num_etat==3 || lexeme->num_etat==4 || lexeme->num_etat==5 )

                                        {Tab_mot[i]=strdup(mot);
                                                F=INST_5;
                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }

                                        break;

                                case INST_5 :
                                        //test fin de ligne après 3eme opérande 
                                        if (strcmp(mot,nl)==0) 
                                        { //I3=action6(L,tab_mot) ;
                                                printf("action6"); }

                                        //test si étiquette 
                                        else if (lexeme->num_etat==7)
                                        {Tab_mot[i]=strdup(mot);
                                                F=DEBUT_SYMBOLE;


                                        } else {
                                                erreur_caractere2 ( lexeme->mot );
                                                break;
                                        }


                                        break; 
                        }
                }

        }
        return l2;
}





//pb car ne rentre pas dans symbole 


int main (void) 
{
        LISTE_LEXEME L = NULL;

        //test action 4
        L=enfiler("SYMBOLE","J",7,L);
        L=enfiler("REGISTRE","$6",11,L);
        L=enfiler("NL","\n",6,L);
        //test action 2
        L=enfiler("DIRECTIVE",".byte",16,L);
        L=enfiler("DECIMAL","6",4,L);
        L=enfiler("DECIMAL","7",4,L);
        L=enfiler("DECIMAL","8",4,L);
        L=enfiler("DECIMAL","9",4,L);
        L=enfiler("DECIMAL","10",4,L);
        L=enfiler("NL","\n",6,L);
        //test action 1
        //        L=enfiler("DIRECTIVE",".data",16,L);
        //        L=enfiler("NL","\n",6,L);
        //        //test action 3
        //        L=enfiler("SYMBOLE","etiqu1",7,L);
        //        L=enfiler("DEUX_PTS",":",8,L);
        //        L=enfiler("NL","\n",6,L);
        //        //test erreur action4
        //        L=enfiler("SYMBOLE","J1",6,L);
        //        L=enfiler("REGISTRE","$6",11,L);
        //        L=enfiler("NL","\n",6,L);
        //        L=enfiler("SYMBOLE","J",7,L);
        //        L=enfiler("REGISTRE","$6",12,L);
        //        L=enfiler("REGISTRE","7",12,L);
        //        L=enfiler("NL","\n",7,L);
        visualiser(L);

        LISTE2 l2 = collection(L);
        printf("\nOn visualise la liste créée \n");
        visualiser_listegen(l2,aff1);
        visualiser_listegen(l2,aff2);
        visualiser_listegen(l2,aff3);
}	
