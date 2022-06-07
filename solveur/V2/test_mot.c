#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "includes/mot.h"


int main()
{
    char *mot="perte";
    char* mot_test1="porte";
    char* color_test1="20222";
    assert(mot_valid(color_test1,mot,mot_test1,5)==1);
    char* mot_test2="rorte";
    char* color_test2="20222";
    assert(mot_valid(color_test2,mot,mot_test2,5)==0);
    char* mot_test3="sater";
    char* color_test3="00111";
    assert(mot_valid(color_test3,mot,mot_test3,5)==1);
    return 0;
}
