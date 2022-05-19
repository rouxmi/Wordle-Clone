//
// Created by lucie on 18/05/22.
//

#ifndef GRAPH_ETAT_H
#define GRAPH_ETAT_H

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


#endif //GRAPH_ETAT_H
