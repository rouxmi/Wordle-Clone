#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>



#ifndef __ENTROPIE__H__
#define __ENTROPIE__H__

struct _hash_element
{
    char lettre;
    int place;
    int ponderation;
    struct _hash_element* suivant;
};
typedef struct _hash_element hash_element;

struct _hash_list
{
    hash_element* premier;
};
typedef struct _hash_list hash_list;

struct _hash_map
{
    hash_list* tete;
};
typedef struct _hash_map hash_map;


hash_map* create_hashmap();
void destroy_hashmap(hash_map* map);
#endif 