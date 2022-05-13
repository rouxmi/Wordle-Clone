#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dictionnaire.h"
#include "tableau.h"
#include <string.h>


int main()

{
    printf("%d",taillefichiertxt());
    printf("la réponse est 2");
    char non[]="bou";
    char mot[]="motus";
    printf("%d",contains(non,mot));
    printf("la réponse est faux");
    printf("%d",acetteplace(2,"o",mot));
    printf("la réponse est vraie");
    printf("%d",acetteplace(3,"o",mot));
    printf("la réponse est faux");
    return 0;
}