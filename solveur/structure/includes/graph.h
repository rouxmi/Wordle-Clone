//
// Created by lucie on 25/05/22.
//


#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _list_edge list_edge;
typedef struct _node node;
typedef struct _edge edge;

struct _list_edge{
    edge *e;
    list_edge *next;
};

struct _node {
    list_edge* listEdge;
    int  id;
    bool terminal;
    int nbrAretesEntrantes;
};

struct _edge {
    node* node;
    int id;
    char label;
};


//fonctions de base sur la structure edge
edge edge_create(node* n,int id, char label);
void edge_print(edge* e);

//fonctions de base sur la structure node
node node_create(int id);
void node_switch_terminal(node* n);
void node_add_child(node* n1, node* n2, char label, int id);
void node_print(node* n);

//fonctions sur la structure liste_edge
list_edge* list_edge_create();
void list_edge_destroy(list_edge* one_list);
bool list_edge_is_empty(list_edge * one_list);
edge * liste_edge_first(list_edge* one_list);
list_edge* liste_edge_next(list_edge* one_list);
list_edge * list_edge_add_head(edge* e, list_edge* one_list);
void list_edge_print_rec(list_edge* one_list);

list_edge* list_edge_remove_node_by_id(list_edge* one_list, int id);

node* node

#endif //GRAPH_H
