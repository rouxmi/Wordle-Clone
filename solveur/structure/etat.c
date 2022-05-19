//
// Created by lucie on 18/05/22.
//
#include "etat.h"


void etat_init(etat *e, int id, bool ter){
    e->id  = id;
    e->terminal = ter;
}

void etat_print(etat e){
    printf("%d, ",e.id);
}


arbre_etat* arbre_etat_create() {
    return NULL;
}

arbre_etat* arbre_etat_composee(etat n, arbre_etat* g, arbre_etat* d){
    arbre_etat* a = (arbre_etat*) malloc(sizeof(arbre_etat));
    if(!a) return NULL;
    a->droit=d;
    a->gauche=g;
    a->node=n;
    return a;
}

bool arbre_etat_est_vide(arbre_etat* a){
    return a==NULL;
}


void arbre_etat_delete (arbre_etat* a) {
    if (!arbre_etat_est_vide(a)) {
        arbre_etat_delete (a->gauche) ;
        arbre_etat_delete (a->droit) ;
        free (a) ;
    }
}


void arbre_etat_print(arbre_etat* a){
    if (a == NULL)
        printf("NULL");
    else{
        etat_print(a->node);
        arbre_etat_print(a->gauche);
        arbre_etat_print(a->droit);
    }
}
void arbre_etat_print_2D (arbre_etat* a, int niveau) {
    int i ;

    if (!arbre_etat_est_vide(a)) {
        for (i=0 ; i<niveau ; i++)
            printf("      ") ;
        etat_print(a->node);
        arbre_etat_print_2D (a->droit, niveau+1) ;
        arbre_etat_print_2D (a->gauche, niveau-1) ;
    }
}

arbre_etat* arbre_etat_insert(arbre_etat* a, etat data){
    arbre_etat* prec;
    arbre_etat* head=a;
    if(!a){
        return arbre_etat_composee(data, arbre_etat_create(), arbre_etat_create());
    }
    while(a){
        prec=a;
        if(data.id<a->node.id){
            a=a->gauche;
        }
        else{
            a=a->droit;
        }
    }

    if(data.id<prec->node.id){
        prec->gauche=arbre_etat_composee(data, arbre_etat_create(), arbre_etat_create());
    }
    else{
        prec->droit=arbre_etat_composee(data, arbre_etat_create(), arbre_etat_create());
    }
    return head;

}

int max(int a, int b){
    if(a<b) return b;
    return a;
}

int arbre_etat_hauteur(arbre_etat* a){
    if(arbre_etat_est_vide(a)) return 0;
    return 1+max(arbre_etat_hauteur(a->droit), arbre_etat_hauteur(a->gauche));
}




