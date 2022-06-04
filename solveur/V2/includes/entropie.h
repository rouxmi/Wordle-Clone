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
hash_map* initialize_hash_map(char* name_txt, int length_word);
void destroy_hashmap(hash_map* map);
int get_hash_map(hash_map* map, int position, char lettre);



int get_ponderation(char* name_txt, char letter,int position);
hash_element create_hash_element(int ponderation);
hash_list *create_hash_list();


void destroy_hash_list(hash_list *list);
void append_hash_list(hash_list* list, int ponderation);
hash_list* initialize_hash_list(char *name_txt,int length_word,char lettre);
int get_ponderation_hash_list(hash_list* list, int position);

#endif 

