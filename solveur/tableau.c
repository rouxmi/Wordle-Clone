#include "tableau.h"


// Cette fonction permet d'ajouter chaque element au tableau
void init_tableau(element tab[size*nbessais],element L,int indice){
    for(int i=0; i<size*nbessais; i++){
        if(i==indice){
            tab[i]=L;
        }
    }
}


// Cette fonction crée un élément qui a 4 composants: le lettre du mot tenté, la place de la lettre dans le mot,
// la coloration de cette lettre et le numéro de l'essai qui commence à 0
void  init_element(element *elt,char lettre1 ,int place1, int coloration1, int essai1){
    elt->lettre =lettre1 ;
    elt->place= place1 ;
    elt->coloration =coloration1;
    elt->essai= essai1 ;
    
}


// Chaque composants d'un élement est afficher
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

//la fonction affiche le tableau composé d'éléments, elle appelle la fonction print_element à chaque itérations
void print_tableau(element tab[size*nbessais]){
    printf("[");
    for(int i=0; i<size*(nbessais-1);i++){
        print_element(tab[i]);
        printf("\n");
    }
    printf("]\n");
}

// la fonction fait une boucle par rapport à la taille du mot , et à chaque itération elle crée un élément
// grace à la fonction element et apres ajoute au tableau cette élement. 
//Avec un mot de taille 5, la fonction va créer 5 éléments qu'elle ajoute successivement au tableau
void ajout_mot(char* mot, int num_essai, element tab[size*nbessais], char* coloration,int taille_mot){
    for(int i=0; i<taille_mot;i++){
        element L;
        int color;
        char coloration_i=(int)(coloration[i]);
        sscanf(&coloration_i,"%d",&color);
        init_element(&L,mot[i],i+1,color,num_essai);
        init_tableau(tab,L,i+num_essai*taille_mot);
        }    
}

/*int main(){
    element  T[size*nbessais] ;
    ajout_mot("hello",0,T,"20202",size);
    ajout_mot("merci",1,T,"01211",size);
    ajout_mot("casse",2,T,"01022",size);
    ajout_mot("tetes",3,T,"02211",size);
    ajout_mot("mains",4,T,"22222",size);
    print_tableau(T);
    return 0;
} */

