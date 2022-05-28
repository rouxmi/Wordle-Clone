#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "tableau.c"


#ifndef __DICTIONNAIRE__H__
#define __DICTIONNAIRE__H__

int taillefichiertxt (FILE *f);
//renvoie le nombre de ligne d'un fichier txt 
bool contains(char* ceslettres, char* mot, int longueur_mot);
//cette fonction renvoie true si mot contient des lettres du char * ceslettres et false sinon
bool acetteplace(char ceslettres[], char *mot, int positions[],int index);
//renvoie true si mot[position]==x et false sinon
bool containsexceptposition(char* mot,char *ceslettres,int positions[], int index,int longueur_mot);
//renvoie true si le char x est présent dans mot sauf à la position position
char * contentofline(FILE *f, int linenumber, int longueur_mot, int longueur_dico);//
//attention: contentofline est une fonction dit "à responsabilité", cad que il faut faire char*str=contentofline(...) puis free(str)
//cette fonction renvoie le contenu de la ligne numéro linenumber, il faut ouvrir le file avant la fonction et le fermer après 

void coloration0(element tab[size*nbessais],int nb_essai, int longueur_mot);
void coloration1(element tab[size*nbessais],int nb_essai, int longueur_mot);
void coloration2(element tab[size*nbessais],int nb_essai, int longueur_mot);
void dico(element tab[size*nbessais], int nb_essai, int longueur_mot);
//épuration du dico

void addintofile(FILE *f, char *word_to_add);
//écrit à la fin d'un fichier, attention fopen en a 


#endif
