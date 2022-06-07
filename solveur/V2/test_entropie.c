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
    hash_map* map=initialize_hash_map("test_node_add_word.txt",5);
    int ans0=get_hash_map(map,0,'F');
    int ans1=get_hash_map(map,1,'O');
    int ans2=get_hash_map(map,2,'U');
    int ans3=get_hash_map(map,3,'R');
    int ans4=get_hash_map(map,4,'N');
    int ans=get_hash_map(map,0,'J');
    printf("%d\n",ans);
    printf("%d\n",ans0);
    printf("%d\n",ans1);
    printf("%d\n",ans2);
    printf("%d\n",ans3);
    printf("%d\n",ans4);
    destroy_hashmap(map);
    printf("jesuistropforte\n");
    return 0;
}
