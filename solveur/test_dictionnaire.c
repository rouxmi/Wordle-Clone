#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dictionnaire.c"
#include <stdbool.h>

#include <string.h>


int main()

{
    printf("%d\n",taillefichiertxt());
    printf("la réponse est 5\n");
    char *non="bou";
    char *mot="motus";
    printf("%d\n",contains(non,mot));
    printf("la réponse est vrai \n");
    char * oui="zyeh";
    printf("%d\n",contains(oui,mot));
    printf("la réponse est fausse \n");

    printf("%d\n",acetteplace(1,'o',mot));
    printf("la réponse est vraie\n");
    printf("%d\n",acetteplace(4,'s',mot));
    printf("la réponse est vraie\n");
    printf("%d\n",acetteplace(2,'o',mot));
    printf("la réponse est faux\n"); //marche
    return 0;
}