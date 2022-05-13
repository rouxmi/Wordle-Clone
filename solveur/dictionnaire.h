#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>

#ifndef __DICTIONNAIRE__H__
#define __DICTIONNAIRE__H__

int taillefichiertxt ();
bool contains(char* pasceslettres, char* mot);
bool acetteplace(int position, char x, char* mot);


#endif
