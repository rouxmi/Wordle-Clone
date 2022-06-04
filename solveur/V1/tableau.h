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
    int coloration;
    int essai;
};

typedef struct element element;

void  init_tableau(element *tab,element L,int indice,int size_mot,int nb_essais); 
void  init_element(element *elt,char lettre1 ,int place1, int coloration1, int essai1);
void print_element(element elt);
void print_tableau(element *tab,int size_mot,int nb_essais);
void ajout_mot(char* mot, int num_essai, element *tab, char* coloration,int size_mot,int nb_essais);
int main();

#endif

