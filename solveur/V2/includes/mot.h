#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>


#ifndef __MOT__H__
#define __MOT__H__

//renvoie le nombre de ligne d'un fichier txt 
bool contains(char lettre, char* mot);
//cette fonction renvoie true si mot contient des lettres du char * ceslettres et false sinon
bool acetteplace(char lettre, char *mot, int position);
//renvoie true si mot[position]==x et false sinon
bool containsexceptposition(char* mot,char lettre,char *color,int position);

void str_slice(const char * str, char * word_coupe, size_t start, size_t end);
//renvoie true si le char x est présent dans mot sauf à la position position
//attention: contentofline est une fonction dit "à responsabilité", cad que il faut faire char*str=contentofline(...) puis free(str)
//cette fonction renvoie le contenu de la ligne numéro linenumber, il faut ouvrir le file avant la fonction et le fermer après 

bool mot_valid(char* color, char* mot_donne, char* mot_a_test,int longueur_mot);
//dis si un mot est possible ou non


#endif
