#include "tableau.h"

element * crea_tableau(int nbr_essai, int nbr_lettres){
    int size= nbr_essai * nbr_lettres;
    element  tableau[size];
    for(int i=0; i<size+1; i++){
        tableau[i]= crea_element('R',1,3,5);
    }
    element * res=tableau;
    return res;
    }

element  crea_element(char lettre1 ,int place1, int position1, int essai1){
    element element;
    element.lettre =lettre1 ;
    element.place= place1 ;
    element.position =position1;
    element.essai= essai1 ;
    return element;
}

void print_element(element elt){
    printf("%c ", elt.lettre);
    printf("%d ", elt.place);
    printf("%d ", elt.essai);
    printf("%d",elt.essai);
} 


int main(){
    char lettre='R';
    int place=1;
    int position =2;
    int essai= 2;
    element  L= crea_element(lettre ,place , position,essai);
    element * T =crea_tableau(1,1);

    return 0;
}

