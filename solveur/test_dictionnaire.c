#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dictionnaire.h"
#include <stdbool.h>
#include <string.h>


int main()

{

   /* char *non="bou";
    char *mot="motus";
    printf("%d\n",contains(non,mot,5));
    printf("la réponse est vrai \n");
    char * oui="zyeh";
    printf("%d\n",contains(oui,mot,5));
    printf("la réponse est fausse \n");
    printf("%d\n",acetteplace(1,'o',mot));
    printf("la réponse est vraie\n");
    printf("%d\n",acetteplace(4,'s',mot));
    printf("la réponse est vraie\n");
    printf("%d\n",acetteplace(2,'o',mot));
    printf("la réponse est faux\n"); 
    char* lucie="abdtjut";
    printf("%d\n",containsexceptposition(lucie,'t',3,7));
    printf("la réponse est vraie\n");
    char* lola="abdtju";
    printf("%d\n",containsexceptposition(lucie,'t',3,6));
    printf("la réponse est faux\n");
    char str[7]="rémi";
    char x='l';
    append(str,x);
    printf("%s\n",str);
    FILE *f=fopen("/texte/test.txt","r");
    char *jeveuxsavoir=contentofline(f, 3, 5,6);
    printf("%s\n",jeveuxsavoir);
    free(jeveuxsavoir);
    fclose(f);
    FILE *p=fopen("/texte/test.txt","a");
    char * ajout="ajout";
    addintofile(p, ajout,taillefichiertxt(p));
    fclose(p);*/
    /*FILE *f=fopen("/texte/test.txt","r");
    int len=taillefichiertxt(f);
    printf("%d\n",len);

    fclose(f);*/
    /*char* right_place="abc";
    int positions[3]={0,1,2};
    char *mot="abcde";
    char* mot2="dbabc";
    char* mot3="deabc";
    int index=2;
    printf("%d\n",positions[index]);
    printf("%d\n",containsexceptposition(mot,right_place,positions,3,5));
    printf("%d\n",containsexceptposition(mot2,right_place,positions,3,5));
    printf("%d\n",containsexceptposition(mot3,right_place,positions,3,5));
    //printf("%d\n",acetteplace(right_place,mot2,positions,3));*/
    int len=19;
    element  T[30] ;
    ajout_mot("merci",0,T,"00000",5);
    print_tableau(T);
    dico(T,0,5);
    /*FILE * test=fopen("dicointer2.txt","r");
    int te=taillefichiertxt(test);
    printf("%d\n",te);*/
    /*ajout_mot("mazed",1,T,"22010",5);
    print_tableau(T);
    dico(T,1,5);*/
    //il faut vider dicointer1 et dicointer2 après chaque essai
    
    //printf("%s","coucou");
    return 0;
}
