#include "tableau.h"


int main(){
    int nombre_lettres = 0;
    int nombre_essais = 0;

    //lecture dans wsolf.txt le nombre de lettre du mot à deviné
    FILE *f = fopen("wsolf.txt","r");
    if ( f== NULL ) {
        printf( "Cannot open file %s\n", "wsolf.txt" );
        exit( 0 );
    }
    char c = (int)(fgetc(f));
    fclose(f);
    sscanf(&c,"%d",&nombre_lettres); // char to int

    element information[nombre_lettres*6];
    
    
    return 0;
}
