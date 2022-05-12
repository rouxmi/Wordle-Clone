#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>

void randomInFile(){
    FILE *f;
    char c;
    f=fopen("test.txt","rt");
    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }
}



int main(){
    
    randomInFile();

    return 0;
}