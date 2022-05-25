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

    fclose(f);*/
    
    int len=11;
    element  T[30] ;
    ajout_mot("merci",1,T,"20202",5);
    dico(T, 0, 5, len);
    //printf("%s","coucou");
    return 0;
}
