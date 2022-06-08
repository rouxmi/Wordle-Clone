#include "includes/graph.h"
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
    node* n;
    node* n2=node_create(0);
    char* mot_test = NULL;
    int taille_futur;
    for (int i =0; i < nbr_essais; i++)
    {
        char coloration[longueur+2];
        if (i==0){
            char txt[7]=".txt";
            char strdico[100]="../texte/Dictionnaire/dico0";
            char* dico_mot=calloc(60,sizeof(char));
            strcpy(dico_mot,strdico);
            char strlong[5];
            sprintf(strlong,"%d",longueur);
            strcat(dico_mot,strlong);
            strcat(dico_mot, txt);
            FILE* f=fopen(dico_mot,"r");
            n=node_add_all_words(dico_mot);
            rewind(f);
            taille_futur=taillefichiertxt(f);
            //free(dico_mot);
            fclose(f);
        }
        else{
            n=n2;
            n2 = node_create(0);
        }
        mot_test=node_best_word(n).mot;
        printf("le mot à tester est %s \n",mot_test);
        
        printf("Entrez la coloration \n");
        scanf("%s",coloration);
        if (!strcmp(coloration,"-1")){
            printf("vous arrêtez de jouer\n");
            break;
        }
        char oui[longueur+2];
        char l='2';
        for (int r=0;r<longueur;r++){
            oui[r]=l;
        }
        oui[longueur]=0;
        if (!strcmp(coloration,oui)){
            printf("le solveur a gagné\n");
            break;
        }
        else{
            if (i==nbr_essais-1){
                printf("Le solveur a perdu\n");
            }
            printf("color%s,%s,%d",coloration,mot_test,taille_futur);
            printf("n avant:\n");
            node_print(n);
            printf("n2 avant:\n");
            node_print(n2);
            taille_futur=get_best_word_from_color(n2,n,coloration,mot_test,taille_futur);
            printf("taille_futur:%d\n",taille_futur);
            printf("n2 apres:\n");
            node_print(n2);
        }
         

    }
    node_destroy_all_children(n);
    
    
    //print_tableau(T)
    return 0;
}


