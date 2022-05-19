//
// Created by lucie on 18/05/22.
//
#include "etat.h"

void test_etat_init(){
    etat e;
    etat_init(&e, 1, true);
    assert(e.id==1);
    assert(e.terminal==true);
    printf("test_etat_init : OK\n");
}


void test_arbre_etat_create_vide(){
    arbre_etat* a = arbre_etat_create();
    assert(a==NULL);
    assert((arbre_etat_est_vide(a)));
    printf("test_arbre_etat_create : OK\n");
    printf("test_arbre_etat_est_vide : OK\n");
    free(a);
}

void test_arbre_etat_insert_delete(){
    etat e;
    etat_init(&e, 1, true);
    arbre_etat* a = arbre_etat_create();
    assert(arbre_etat_hauteur(a)==0);

    a= arbre_etat_insert(a,e);
    assert(arbre_etat_hauteur(a)==1);

    etat_init(&e, 2, true);
    a=arbre_etat_insert(a,e);
    assert(arbre_etat_hauteur(a)==2);

    etat_init(&e, 3, true);
    a=arbre_etat_insert(a,e);
    assert(arbre_etat_hauteur(a)==3);

    arbre_etat_print_2D(a, 2);
    arbre_etat_delete(a);
    printf("test_arbre_etat_insert : OK\n");
}


void all_test_etat(){
    test_etat_init();
    test_arbre_etat_create_vide();
    test_arbre_etat_insert_delete();
    printf("all test : OK\n");
}




