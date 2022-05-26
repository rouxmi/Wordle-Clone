#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "entropie.h"


int main()

{
    hash_map* map=create_hashmap();
    //printf("coucou");
    destroy_hashmap(map);
    return 0;
}