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

    int nbr_essais= 5;
    char *list_dico[6]={"texte/dico0.txt","texte/dico1.txt","texte/dico2.txt","texte/dico3.txt","texte/dico4.txt","texte/dico5.txt"};
    FILE *fichier=fopen("texte/wsolf.txt","r");
    char* longueur_mot=contentofline(fichier);
    fclose(fichier);
    //printf("%s \n",longueur_mot);
    int longueur=strtol(longueur_mot,NULL,10);
    //printf("%d \n",longueur);
    free(longueur_mot);
    element T[nbr_essais*longueur];
    srand( time( NULL ) );
    for (int i =0; i < nbr_essais; i++)
    {
        char coloration[longueur+2];
        //char* mot_test=malloc(sizeof(mot_test[longueur]));
        char* mot_test= randomInFile(list_dico[i]);
        printf("le mot à tester est %s \n",mot_test);
        printf("Entrez la coloration \n");
        scanf("%s",coloration);
        printf("%s\n",coloration);
        if (coloration=="-1"){
            printf("vous arrêtez de jouer");
            break;
        }
        if (coloration=="22222"){
            printf("le solveur a gagné");
            break;
        }
        else{
            ajout_mot(mot_test,i,T,coloration,longueur);
            dico(T,i,longueur);

        }
    }
    
    
    //print_tableau(T)
    return 0;
}


