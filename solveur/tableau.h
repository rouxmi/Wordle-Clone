#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>

#ifndef __TABLE__H__
#define __TABLE_H__


struct element
{
    char lettre;
    int place;
    int position;
    int essai;
};

typedef struct element element;

void  init_tableau(element tab[30],int nbr_essai, int nbr_lettres); 
void  init_element(element *elt,char lettre1 ,int place1, int position1, int essai1);
void print_element(element elt);
int main();

#endif

