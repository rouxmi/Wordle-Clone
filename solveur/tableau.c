#include "tableau.h"



void init_tableau(element tab[size*nbessais],element L,int indice){
    for(int i=0; i<size*nbessais; i++){
        if(i==indice){
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
    printf("[");
    printf("%c ", elt.lettre);
    printf(",");
    printf("%d ", elt.place);
    printf(",");
    printf("%d ", elt.coloration);
    printf(",");
    printf("%d ",elt.essai);
    printf("]");
} 

void print_tableau(element tab[size*nbessais]){
    printf("[");
    for(int i=0; i<size*nbessais;i++){
        print_element(tab[i]);
        printf("\n");
    }
    printf("]\n");
}

void ajout_mot(char* mot, int num_essai, element tab[size*nbessais], char* coloration,int taille_mot){
   
   for(int i=0; i<taille_mot;i++){
        element L;
        int color;
        char coloration_i=(int)(coloration[i]);
        sscanf(&coloration_i,"%d",&color);
        init_element(&L,mot[i],i+1,color,num_essai);
        init_tableau(tab,L,i+(num_essai-1)*size);
        }    
}

int main(){
    element  T[size*nbessais] ;
    ajout_mot("hello",0,T,"20202",size);
    ajout_mot("merci",1,T,"01211",size);
    ajout_mot("casse",2,T,"01022",size);
    ajout_mot("tetes",3,T,"02211",size);
    ajout_mot("mains",4,T,"22222",size);
    print_tableau(T);
    return 0;
}

