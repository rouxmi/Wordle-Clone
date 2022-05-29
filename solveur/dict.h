#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "tableau.h"

#define len_mot 5

#ifndef __DICT__H__
#define __DICT__H__

int taillefichiertxt (FILE *f);
//renvoie le nombre de ligne d'un fichier txt 
bool contains(char lettre, char* mot);
//cette fonction renvoie true si mot contient des lettres du char * ceslettres et false sinon
bool acetteplace(char lettre, char *mot, int position);
//renvoie true si mot[position]==x et false sinon
bool containsexceptposition(char* mot,char lettre,char color[len_mot],int position);

void str_slice(const char * str, char * word_coupe, size_t start, size_t end);
//renvoie true si le char x est présent dans mot sauf à la position position
char * contentofline(FILE *f);//

void resetdict(char* name);
//attention: contentofline est une fonction dit "à responsabilité", cad que il faut faire char*str=contentofline(...) puis free(str)
//cette fonction renvoie le contenu de la ligne numéro linenumber, il faut ouvrir le file avant la fonction et le fermer après 

void dico(element tab[30], int nb_essai, int longueur_mot);
//épuration du dico

void addintofile(char* futurdico, char *word_to_add);
//écrit à la fin d'un fichier, attention fopen en a 


#endif
