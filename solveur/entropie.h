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
    int place;
    int ponderation;
    struct _hash_element* suivant;
};
typedef struct _hash_element hash_element;

typedef struct _hash_list
{
    hash_element* premier;
}hash_list;

typedef struct _hash_map
{
    hash_list* tete;
}hash_map;



hash_map *create_hashmap();
void destroy_hashmap(hash_map* map);
int get_ponderation(char* name_txt, int length_word, char letter,int position);
hash_element create_hash_element(int place, int ponderation);
hash_list *create_hash_list();
void destroy_hash_list(hash_list *list);
void append_hash_list(hash_list* list, hash_element element);
hash_list* initialize_hash_list(char *name_txt,int length_word,char lettre);
int get_ponderation_hash_list(int position, hash_list* list);
#endif 