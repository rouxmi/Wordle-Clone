#include "tableau.h"

void init_tableau(element tab[30],int nbr_essai, int nbr_lettres){
    int size= nbr_essai * nbr_lettres;

    for(int i=0; i<30; i++){

        element L;
        init_element(&L,'R',1,3,5);
        tab[i]=L;

    }
}

void  init_element(element *elt,char lettre1 ,int place1, int position1, int essai1){
    elt->lettre =lettre1 ;
    elt->place= place1 ;
    elt->position =position1;
    elt->essai= essai1 ;
    
}

void print_element(element elt){
    printf("%c ", elt.lettre);
    printf("%d ", elt.place);
    printf("%d ", elt.essai);
    printf("%d ",elt.essai);
} 

void print_tableau(element tab[30]){
    for(int i=0; i<30;i++){
        print_element(tab[i]);
    }
}

int main(){
    char lettre='R';
    int place=1;
    int position =2;
    int essai= 2;
    element L;
    init_element(&L,lettre ,place , position,essai);
    element  T[30] ;
    init_tableau(T,1,1);
    print_tableau(T);
    return 0;
}

