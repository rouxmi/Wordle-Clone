#include "tableau.h"

void init_tableau(element tab[30],element L){
    for(int i=0; i<30; i++){
        if(sizeof(tab[i])==0){
            tab[i]=L;
        }
    }
}

void  init_element(element *elt,char lettre1 ,int place1, int coloration1, int essai1){
    elt->lettre =lettre1 ;
    elt->place= place1 ;
    elt->coloration =coloration1;
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

void ajout_mot(char* mot, int num_essai, element tab[30], char* coloration,int taille_mot){
    //printf("%c",mot[1]);
    
    for(int i=0; i<taille_mot;i++){
        element L;
        int color;
        char coloration_i=(int)(coloration[i]);
        sscanf(&coloration_i,"%d",&color);
        //printf("%d\n",color);
        init_element(&L,mot[i],i+1,coloration_i,num_essai);
        print_element(L);
        printf("\n");
        init_tableau(tab,L);
        //print_tableau(tab);
        
    }
}

int main(){
    element  T[30] ;
    ajout_mot("merci",1,T,"20202",5);
    //print_tableau(T);
    return 0;
}

