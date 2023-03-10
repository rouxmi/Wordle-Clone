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
            char* dico_mot=get_dict_name(longueur);
            FILE* f=fopen(dico_mot,"r");
            n=node_add_all_words(dico_mot,longueur);
            rewind(f);
            taille_futur=taillefichiertxt(f);
            fclose(f);
            free(dico_mot);
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
            free(n2);
            free(mot_test);
            break;
        }
        else{
            if (i==nbr_essais-1){
                printf("Le solveur a perdu\n");
                free(n2);
                free(mot_test);
                break;
            }
            taille_futur=make_new_graph(n2,n,coloration,mot_test,taille_futur);
        }
         
    free(mot_test);
    }
    node_destroy_all_children(n);
    
    
    //print_tableau(T)
    return 0;
}


