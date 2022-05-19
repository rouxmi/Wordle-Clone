//
// Created by lucie on 18/05/22.
//

#ifndef ETAT_H
#define ETAT_H

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

typedef struct etat{
    int id;
    bool terminal;
} etat;

typedef struct arbre_etat{
    etat node;
    struct arbre_etat* gauche;
    struct arbre_etat* droit;

} arbre_etat;

void etat_init(etat *e, int id, bool ter);
void etat_print(etat e);

arbre_etat* arbre_etat_create();

arbre_etat* arbre_etat_composee(etat n, arbre_etat* g, arbre_etat* d);

bool arbre_etat_est_vide(arbre_etat* a);

void arbre_etat_delete (arbre_etat* a);

void arbre_etat_print(arbre_etat* a);

void arbre_etat_print_2D (arbre_etat* a, int niveau);

arbre_etat* arbre_etat_insert(arbre_etat* a, etat data);

int max(int a, int b);

int arbre_etat_hauteur(arbre_etat* a);



#endif //ETAT_H
