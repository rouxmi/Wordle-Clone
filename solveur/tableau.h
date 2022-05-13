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

void crea_tableau(); 

#endif