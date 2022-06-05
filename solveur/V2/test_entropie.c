#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "includes/entropie.h"


int main()

{
    /*hash_map* map=create_hashmap();
    //printf("coucou");
    destroy_hashmap(map);*/
   
    /*hash_map* map=initialize_hash_map("texte/test.txt",5);
    hash_list* list=initialize_hash_list("te");
    append_hash_list(list, 0);
    append_hash_list(list, 2);

    int res3=get_ponderation_hash_list(list,4);
    printf("res3 %d\n",res3);
    printf("sortie\n");
    
    destroy_hash_list(list);
    printf("definitive\n");
    //hash_map* map=create_hashmap();
    destroy_hashmap(map);*/
    hash_map* map=initialize_hash_map("../texte/dict.txt",5);
    /*int ans0=get_hash_map(map,0,'Z');
    int ans1=get_hash_map(map,1,'Z');
    int ans2=get_hash_map(map,2,'Z');
    int ans3=get_hash_map(map,3,'Z');
    int ans4=get_hash_map(map,4,'Z');*/
    int ans=get_hash_map(map,0,'J');
    printf("%d\n",ans);
    destroy_hashmap(map);
    printf("jesuistropforte\n");
    return 0;
}