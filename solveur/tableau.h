#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>

#ifndef __TABLE__H__
#define __TABLE_H__


struct _list_t
{
    char lettre;
    int place;
    int position;
    int essai;
};

typedef struct _list_t list_t;

list_t * crea_tableau(int nbr_essai, int nbr_lettres); 
list_t * crea_element(char lettre1 ,int place1, int position1, int essai1);

#endif