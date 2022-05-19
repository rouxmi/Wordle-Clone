#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "tableau.h"

#ifndef __DICTIONNAIRE__H__
#define __DICTIONNAIRE__H__

int taillefichiertxt (FILE *f);
//renvoie le nombre de ligne d'un fichier txt 
bool contains(char *ceslettres , char* mot, int longueur_mot);
//cette fonction renvoie true si mot contient des lettres du char * ceslettres et false sinon
bool acetteplace(int position, char x, char mot[]);
//renvoie true si mot[position]==x et false sinon
bool containsexceptposition(char* mot,char x,int position, int longueur_mot);
//renvoie true si le char x est présent dans mot sauf à la position position
char * contentofline(FILE *f, int linenumber, int longueur_mot, int longueur_dico);//
//attention: contentofline est une fonction dit "à responsabilité", cad que il faut faire char*str=contentofline(...) puis free(str)
//cette fonction renvoie le contenu de la ligne numéro linenumber, il faut ouvrir le file avant la fonction et le fermer après 
void str_slice(char * str, char * word_coupe, size_t start, size_t end);
//
void dico(element* tab[30], int nb_essai, int longueur_mot, int longueur_fichier);
//épuration du dico
char * add(char *str, char x);
//concatène un str et x, attention à la taille de str 
char* createplace(int longueur_mot);
//créer des char * composé d espaces seulement
void addintofile(FILE *f, char *word_to_add,int longueur_fichier);
//écrit à la fin d'un fichier, attention fopen en a 
#endif
