#include "tableau.h"

list_t * crea_tableau(int nbr_essai, int nbr_lettres){
    int size= nbr_essai * nbr_lettres;
    list_t * tableau[size][sizeof(list_t)] ;
    for(int i=0; i<size+1; i++){
        tableau[i][0]= crea_element("R",1,3,5)->lettre;
        tableau[i][1]= crea_element("R",1,3,5)-> place;
        tableau[i][2]= crea_element("R",1,3,5)-> position;
        tableau[i][3]= crea_element("R",1,3,5)-> essai;
    }
    return tableau;
}

list_t * crea_element(char lettre1 ,int place1, int position1, int essai1){
    list_t *element = malloc(sizeof(list_t));
    element->lettre =lettre1 ;
    element ->place= place1 ;
    element->position =position1;
    element->essai= essai1 ;
    return element ;
}

int main(){
    char lettre="R";
    int place=1;
    int position =2;
    int essai= 2;
    list_t * L= crea_element(lettre ,place , position,essai);
    list_t * T= crea_tableau(1,1);
    printf("%p",T);
    return 0;
}