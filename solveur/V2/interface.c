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
    node* n2=NULL;
    int taille_futur;
    for (int i =0; i < nbr_essais; i++)
    {
        char coloration[longueur+2];
        char txt[7]=".txt";
        char strdico[100]="../texte/Dictionnaire/dico0";
        char* dico_mot=malloc(sizeof("../texte/Dictionnaire/dicoimpair.txt"));
        strcpy(dico_mot,strdico);
        char strlong[5];
        sprintf(strlong,"%d",longueur+1);
        strcat(dico_mot,strlong);
        strcat(dico_mot, txt);
        //dico_mot="test_node_add_word.txt";
        FILE* f=fopen(dico_mot,"r");
        printf("%s\n",dico_mot);
        if (i==0){
            n=node_add_all_words(dico_mot);
            printf("ok");
            node_print(n);
            rewind(f);
            taille_futur=taillefichiertxt(f);
            printf("d'accord:%d\n",taille_futur);
        }
        else{
            node*n=n2;
        }
        char* mot_test=node_best_word(n).mot;
        printf("le mot à tester est %s \n",mot_test);
        printf("Entrez la coloration \n");
        scanf("%s",coloration);
        if (!strcmp(coloration,"-1")){
            printf("vous arrêtez de jouer");
            break;
        }
        char oui[longueur+2];
        char l='2';
        for (int r=0;r<longueur;r++){
            oui[r]=l;
        }
        oui[longueur]=0;
        if (!strcmp(coloration,oui)){
            printf("le solveur a gagné");
            break;
        }
        else{
            if (i==nbr_essais-1){
                printf("Le solveur a perdu");
            }
            node* n2=node_create(0);
            printf("la totale:%s,%s,%d",coloration,mot_test,taille_futur);
            node_print(n);
            node_print(n2);
            int taille_futur1=taille_futur+1-1;
            taille_futur=get_best_word_from_color(n2,n,coloration,mot_test,taille_futur1);
            printf("taille_futur:%d\n",taille_futur);
            node_print(n2);
        }
        fclose(f);
        free(mot_test); 

    }
    free(n2);
    
    
    //print_tableau(T)
    return 0;
}


