#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "entropie.h"
#include "dictionnaire.h"

//fonctions de pondération 
hash_map* initialize_hash_map(char* name_txt, int length_word)
{
    hash_map* map=create_hashmap();
    char alphabet[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
}





hash_list* initialize_hash_list(char *name_txt,int length_word,char lettre)
{
    hash_list* list=create_hash_list();
    printf("salut\n");
    for (int i=0;i<length_word;i++)
    {
        printf("dans la bouvle\n");
        int ponderation=get_ponderation(name_txt,length_word,lettre,i);
        printf("p: %d\n",ponderation);
        hash_element current=create_hash_element(i,ponderation);
        append_hash_list(list,current);
    
    }
    printf("fini\n");
    return list;

}

int get_ponderation(char* name_txt, int length_word, char letter, int position)
{
    int ponderation=0;
    FILE*f=fopen(name_txt, "r");
    int len= taillefichiertxt(f);
    rewind(f);
    for (int j=0;j<len+1;j++)
    {
        char* current_word=contentofline(f,j,length_word,len);
       
        if (current_word[position]==letter)
        {
            //printf("%s\n",current_word);
            ponderation++;
        }

        free(current_word);
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
    assert(map!=NULL);
    int length= sizeof(map);
    for (int i=0; i<length; i++){
        hash_list *current_list = map[i].tete;
        destroy_hash_list(current_list);
            
    }
    free(map);
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

    /*hash_element *current = list->premier;
    hash_element *tmp = NULL;
    while (current ->suivant!= NULL)
    {
        printf("dans la boucle destroy\n");
        tmp = current;
        current = current->suivant;
        //free(tmp);
    }*/
    free(list);


} 


void append_hash_list(hash_list* list, hash_element element)
{
    if (list->premier==NULL)
    {
        list->premier = &element;
    }
    else{
        hash_element* current=list->premier;
        while (current->suivant!=NULL)
        {
            current=current->suivant;

        }
        current->suivant=&element;

    }
}

int get_ponderation_hash_list(int position, hash_list* list)
{
    if (list->premier==NULL)
    {
        printf("hola");
        return -1;
    }
    else
    {
        hash_element* current=list->premier;
        while (current->suivant!=NULL)
        {
            if (current->place==position)
            {
                return current->ponderation;
            }
            current=current->suivant;
        }
        if (current->place==position)
        {
            return current->ponderation;
        }
        return -1;
    }
    
    

}
//fonctions pour hash_element

hash_element create_hash_element(int place, int ponderation)
{
    hash_element new_element;
  
    new_element.place=place;
    new_element.ponderation=ponderation;
    new_element.suivant=NULL;
    return new_element;
}

