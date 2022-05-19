#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "tableau.h"

#ifndef __DICTIONNAIRE__H__
#define __DICTIONNAIRE__H__

int taillefichiertxt ();//
bool contains(char *ceslettres , char* mot, int longueur_mot);//
bool acetteplace(int position, char x, char mot[]);//
bool containsexceptposition(char* mot,char x,int position, int longueur_mot);//
char * contentofline(FILE *f, int linenumber, int longueur_mot, int longueur_dico);//
void str_slice(char * str, char * word_coupe, size_t start, size_t end);//
void dico(element* tab[30], int nb_essai, int longueur_mot, int longueur_fichier);
char * add(char *str, char x);//
char* createplace(int longueur_mot);
void addintofile(FILE *f, char *word_to_add,int longueur_fichier);

#endif
