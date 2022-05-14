#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <time.h>

#define LONG 255

/* RandomInFile
@param char* name : le nom d'un fichier
@return un mot aléatoire contenu dans le fichier
*/
char* randomInFile(char* name);