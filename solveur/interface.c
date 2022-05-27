#include "dictionnaire.c"
#include "whichWord.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

int main(){
    int nbr_essais= 5;
    FILE *fichier=fopen("texte/wsolf.txt","r");
    char* longueur_mot=contentofline(fichier,0,1,0);
    //printf("%s \n",longueur_mot);
    int longueur=strtol(longueur_mot,NULL,10);
    //printf("%d \n",longueur);
    
    element T[nbr_essais*longueur];
    for (int i =0; i < nbr_essais; i++)
    {
        int coloration;
        char* mot_test=malloc(sizeof(mot_test[longueur]));
        mot_test= randomInFile("dicointer1.txt");
        printf("le mot à tester est %s \n",mot_test);
        printf("Entrez la coloration \n");
        scanf("%c",coloration);
        if(coloration== -1){
            printf("vous arrêtez de jouer");
            break;
        }
        if(coloration==22222){
            printf("le solveur a gagné");
            break;
        }
        else{
            char* color;
            sprintf(color,"%c",coloration);
            ajout_mot(mot_test,0,T,color,longueur);
            dico(T,i,longueur);

        }
    }
    
    fclose(fichier);
    //print_tableau(T)
    return 0;
}


