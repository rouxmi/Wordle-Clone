#include "dictionnaire.c"
#include "whichWord.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
/*
int main(){
    int nbr_essais= 5;
    FILE *fichier=fopen("texte/wsolf.txt","r");
    //int taille_fichier =fread();
    int longueur_mot = 5;
    printf("%d \n",longueur_mot);
    element T[nbr_essais*longueur_mot];
    for (int i =0; i < nbr_essais; i++)
    {
        char* coloration;
        char* mot_test= randomInFile("dicointer1.txt");
        printf("le mot à tester est %s \n",mot_test);
        printf("Entrez la coloration \n");
        scanf("%c",coloration);
        if(coloration=="-1"){
            printf("vous arrêtez de jouer");
            break;
        }
        if(coloration=="22222"){
            printf("le solveur a gagné");
            break;
        }
        else{
            ajout_mot(mot_test,0,T,coloration,longueur_mot);

        }
    }
    fclose(fichier);
    //print_tableau(T)
    return 0;
}

*/
