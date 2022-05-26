#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "entropie.h"


//fonctions pour hash_map 
hash_map* create_hashmap()
{
    hash_map* new_map = (hash_map*)calloc(26,sizeof(hash_map));
    if (new_map == NULL)
    {
        err(ENOMEM, "can't allocate a new map");
    }
    else
    {
        return new_map;
    }
}
void destroy_hashmap(hash_map* map)
{
    assert(map!=NULL);
    int length=sizeof(map);
    //printf("%d\n",length);
    for (int i=0; i<length; i++){
        hash_list *current_list = map[i].tete;
        if (current_list!=NULL)
        {
            hash_element* current = current_list->premier;
            hash_element* tmp = NULL;
            while (current != NULL)
            {
                tmp = current;
                current = current->suivant;
                free(tmp);
            }
        }
        
        free(current_list);
            
    }
    free(map);
}

//fonctions  pour hash_list


hash_list* create_hash_list()
{
    hash_list* new_list=(hash_list*)calloc(1,sizeof(hash_list));
    new_list->premier=NULL;
    if (new_list == NULL)
    {
        err(ENOMEM, "can't allocate a new list");
    }
    return new_list;
}
 


void destroy_hash_list(hash_list* list)
{
    assert(list!=NULL);
    hash_element* current=list->premier;
    hash_element *tmp = NULL;
    while (current != NULL)
    {
        tmp = current;
        current = current->suivant;
        free(tmp);
    }
    free(list);
} 


void append_hash_list(hash_list* list, char lettre, int place, int ponderation)
{
    assert(list!=NULL);
    hash_element *new_element = (hash_element*)calloc(1, sizeof(hash_element));
    if (new_element == NULL)
    {
        err(ENOMEM, "can't allocate a new element");
    }
    new_element->lettre=lettre;
    new_element->place=place;
    new_element->ponderation=ponderation;
    new_element->suivant=NULL;
    hash_element* element=list->premier;
    if (element==NULL)
    {
        list->premier=new_element;
    }
    while (element->suivant !=NULL)
    {
        element=element->suivant;
    }
    element->suivant=new_element;


}


