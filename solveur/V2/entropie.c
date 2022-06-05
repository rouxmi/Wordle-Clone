#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "includes/entropie.h"
#define LONG 255

//fonctions de pondération 
hash_map* initialize_hash_map(char* name_txt, int length_word)
{
    hash_map* map=create_hashmap();
    char alphabet[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i=0;i<26;i++)
    {
        map[i].tete=initialize_hash_list(name_txt,length_word,alphabet[i]);
        //printf("%c\n",alphabet[i]);
       
    }
    return map;
}





hash_list* initialize_hash_list(char *name_txt,int length_word,char lettre)
{
    hash_list* list=create_hash_list();
    //printf("salut\n");
    for (int i=0;i<length_word;i++)
    {
        //printf("dans la bouvle\n");
        int ponderation=get_ponderation(name_txt,lettre,i);
        //printf("p: %d\n",ponderation);
        append_hash_list(list,ponderation);
    
    }
    //printf("fini\n");
    return list;
}

int get_ponderation_hash_list(hash_list* list,int position)
{
    if (list==NULL)
    {
        return -1;
    }
    else
    {
        hash_element* current=list->premier;
        int compteur=0;
        if (current!=NULL)
        {
            while (current->suivant!=NULL)
            {
                if (compteur==position)
                {
                    return current->ponderation;
                }
                current=current->suivant;
                compteur++;
            }
            if (compteur==position)
            {
                return current->ponderation;
            }
            return -1;
        }
    }
    return -1;
}

int get_ponderation(char* name_txt, char letter, int position)
{
    int ponderation=0;
    FILE*f=fopen(name_txt, "r");
    int len=0;
    char c;
    while((c=fgetc(f)) != EOF)
    {
        if(c=='\n')
        {
            len++;
        }
    }
    rewind(f);
    char ligne[LONG];
    for (int j=0;j<len+1;j++)
    {
        fgets(ligne, LONG,f);
        char* res = ligne;
       
        if (res[position]==letter)
        {
            //printf("%s\n",current_word);
            ponderation++;
        }

    
    }
    fclose(f);
    return ponderation;

}



//fonctions pour hash_map 
hash_map* create_hashmap()
{
    hash_map *new_tab = calloc(27,sizeof(hash_map));
    if (new_tab == NULL)
    {
        err(ENOMEM, "can't allocate a new list");
    }
    return new_tab;

}
void destroy_hashmap(hash_map* map)
{

    for (int i=0;i<26;i++)
    {
 
        destroy_hash_list(map[i].tete);
        
    }
   
    free(map);
   
}

int get_hash_map(hash_map* map, int position, char lettre)
{
    char alphabet[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int liste=0;
    int res=0;
    for (int i=0;i<26;i++)
    {
        if (alphabet[i]!=lettre)
        {
            liste++;
        }
        else{
            hash_list* current_list=map[liste].tete;
            res=get_ponderation_hash_list(current_list,position);
            //destroy_hash_list(current_list);
        }

    }
    return res;
}



//fonctions  pour hash_list

hash_list* create_hash_list()
{
    hash_list* new_list = (hash_list*) calloc(1, sizeof(hash_list));

    if (new_list == NULL)
    {
        err(ENOMEM, "can't allocate a new list");
    }
    return new_list;
}
 


void destroy_hash_list(hash_list* list)
{
    assert(list != NULL);

    hash_element*current = list->premier;
    hash_element *tmp = NULL;
    while (current != NULL)
    {
        tmp = current;
        current = current->suivant;
        free(tmp);
    }
    free(current);
    free(list);
}





void append_hash_list(hash_list* list, int ponderation)
{
    
    assert(list != NULL);

    hash_element *new_element = calloc(1, sizeof(hash_element));
    if (new_element == NULL)
    {
        err(ENOMEM, "can't allocate a new element");
    }
    new_element->ponderation = ponderation;
    new_element->suivant = NULL;

    hash_element *current = list->premier;
    if (current == NULL)
    {
        list->premier = new_element;
        return;
    }
    else {
        while (current->suivant != NULL)
        {
            current = current->suivant;
        }
        current->suivant = new_element;
    }
    
}





//fonctions pour hash_element

hash_element create_hash_element(int ponderation)
{
    hash_element new_element;
    new_element.ponderation=ponderation;
    new_element.suivant=NULL;
    return new_element;
}

