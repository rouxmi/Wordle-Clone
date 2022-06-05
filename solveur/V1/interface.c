#include "dict.h"
#include "whichWord.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <string.h>


int main(){

    int nbr_essais= 6;
    
    FILE *fichier=fopen("../texte/wsolf.txt","r");
    char* longueur_mot=contentofline(fichier);
    fclose(fichier);
    //printf("%s \n",longueur_mot);
    int longueur=strtol(longueur_mot,NULL,10);
    //printf("%d \n",longueur);
    free(longueur_mot);
    element T[nbr_essais*longueur];
    char word_test[longueur + 1];
    srand( time( NULL ) );
    for (int i =0; i < nbr_essais; i++)
    {
        char coloration[longueur+2];
        //char* mot_test=malloc(sizeof(mot_test[longueur]));
        
		char txt[7]=".txt";
		char strdico[100]="../texte/Dictionnaire/dico";
		char* dico_mot=malloc(sizeof("../texte/Dictionnaire/dicoimpair.txt"));
		strcpy(dico_mot,strdico);
        if (i==0){
            char istr[5];
		    sprintf( istr, "%d", i);
            strcat(dico_mot, istr);
            char strlong[5];
            sprintf(strlong,"%d",longueur);
            strcat(dico_mot,strlong);
        }
        else{
            if (i%2==0){
            char pair[5]="pair";
            strcat(dico_mot, pair);
            }
            else{
                
                char impair[5]="imp";
                strcat(dico_mot, impair);
            }
        }
		strcat(dico_mot, txt);
        char* mot_test= randomInFile(dico_mot);
        str_slice(mot_test,word_test,0,longueur-1);
        free(dico_mot);
        printf("le mot à tester est %s \n",mot_test);
        printf("Entrez la coloration \n");
        scanf("%s",coloration);
        if (!strcmp(coloration,"-1")){
            printf("vous arrêtez de jouer");
            break;
        }
        char* color="00000";
        color=coloration(word_test,word_dev,longeur_mot);
        char oui[longueur_mot+2];
        char l='2';
        for (int r=0;r<longueur_mot;r++){
            oui[r]=l;
        }
        oui[longueur_mot]=0;
        if (!strcmp(coloration,oui)){
            printf("le solveur a gagné");
            break;
        }
        else{
            if (i==nbr_essais-1){
                printf("Le solveur a perdu")
            }
            ajout_mot(word_test,i,T,coloration,longueur,nbr_essais);
            dico(T,i,longueur);

        }
    }
    
    
    //print_tableau(T)
    return 0;
}


