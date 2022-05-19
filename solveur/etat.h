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

typedef struct liste_etat{
    etat actuel;
    struct liste_etat* suivant;
} liste_etat;



#endif //GRAPH_ETAT_H
