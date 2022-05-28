#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "entropie.h"


int main()

{
    /*hash_map* map=create_hashmap();
    //printf("coucou");
    destroy_hashmap(map);*/
    int res=get_ponderation("texte/test.txt",5,'a',3);
    printf("1: %d\n",res);
    int res1=get_ponderation("texte/test.txt",5,'a',0);
    printf("4: %d\n",res1);
    int res2=get_ponderation("texte/test.txt",5,'r',2);
    printf("6: %d\n",res2);
    hash_list* list=initialize_hash_list("texte/test.txt",5,'a');
    printf("sortie\n");
    
    destroy_hash_list(list);
    printf("definitive\n");
    //hash_map* map=create_hashmap;
    //destroy_hashmap(map);
    return 0;
}