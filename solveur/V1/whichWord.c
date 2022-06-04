#include "whichWord.h"

char* randomInFile(char* name){
    FILE *f = fopen(name,"r");
    if ( f== NULL ) {
        printf( "Cannot open file %s\n", name );
        exit( 0 );
    }
    rewind(f);
    char ligne[LONG];
    int max = 0;
    while (fgets(ligne, LONG,f)!=NULL)
    {   
        max++;
    }
    fclose(f);
    int indiceLigne = rand() % max;

    f = fopen(name,"r");
    if ( f== NULL ) {
        printf( "Cannot open file %s\n", name );
        exit( 0 );
    }

    while (indiceLigne!=0)
    {   
        indiceLigne--;
        fgets(ligne, LONG,f);
    }
    fgets(ligne, LONG,f);
    fclose(f);

    char* res = ligne;
    return res;
}

/**
int main(){
    char* mot = randomInFile("/texte/test.txt");
    printf("%s", mot);
    return 0
}
**/

