//
// Created by lucie on 25/05/22.
//


#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "entropie.h"

typedef struct _list_edge list_edge;
typedef struct _node node;
typedef struct _edge edge;



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
    int ponderation;
};
struct _list_edge{
    edge e;
    list_edge *next;
};

//fonctions de base sur la structure edge
edge edge_create(node* n,int id, char label,int p);
void edge_print(edge* e);

//fonctions de base sur la structure node
node* node_create(int id);
void node_switch_terminal(node* n);
void node_add_child(node* n1, node* n2, char label, int id, int p);
void node_print(node* n);
void node_destroy_all_children(node* n);
node* node_get_by_id(list_edge* one_list, int id);
node* node_get_by_label(list_edge* one_list, char label);
node * node_add_all_words(char* nametxt);
//fonctions sur la structure liste_edge
list_edge* list_edge_create();
list_edge* list_edge_destroy(list_edge* one_list);
bool list_edge_is_empty(list_edge * one_list);
edge liste_edge_first(list_edge* one_list);
list_edge* liste_edge_next(list_edge* one_list);
list_edge * list_edge_add_head(edge e, list_edge* one_list);
list_edge* list_edge_copy(list_edge* one_list);
void list_edge_print_rec(list_edge* one_list);

list_edge* list_edge_remove_node_by_id(list_edge* one_list, int id);

bool list_edge_contains_by_label(list_edge* one_list, char valeur);
void node_add_char(node* n1, char c, int* idMaxE, int* idMaxN, bool terminal,int p);
void node_add_word(node* n1, char* mot, int* idMaxE, int* idMaxN, hash_map* h);
void node_get_chemin(int tab[5], node* no, char* mot);
void print_tableau(int tab[5]);
bool node_is_unaccessible(node* n);
void node_remove_unaccessibles(node* n1);
list_edge* list_edge_remove_unaccessibles(list_edge* one_list);


char best_char_simple(node* n);
char* best_word_simple(node* n);
char best_char_recur(node* n);
char* best_word_recur(node* n);
int ponderation_get_by_label(node* n, char c);

#endif //GRAPH_H
