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
#include <math.h>
#include "entropie.h"
#include "mot.h"

#define LONG 255

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


typedef struct _motpondere{
    char* mot;
    int pond;
}motpondere;


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
node * node_add_all_words(char* nametxt, int len_mot);
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
void node_add_word(node* n1, char* mot, int* idMaxE, int* idMaxN, hash_map* h,int len_word);
void node_get_chemin(int tab[5], node* no, char* mot);
void print_tableau(int tab[5]);
bool node_is_unaccessible(node* n);
void node_remove_unaccessibles(node* n1);
list_edge* list_edge_remove_unaccessibles(list_edge* one_list);


char best_char_simple(node* n);
char* best_word_simple(node* n,int len_mot);
int ponderation_get_by_label(node* n, char c);

motpondere node_best_word(node* n);
motpondere list_edge_best_word(list_edge* one_list);
void node_remove_word(node* n, char* mot);

void chrcat(char* appendTo, char what);
int make_new_graph(node* n1,node* n, char* color,char* mot_tester,int taille_dict);
char* node_get_word(node*n);
char* list_edge_get_word(list_edge* one_list);
char* convert_base_3(int N,int taille_mot);
int test_all_color(char* mot_tester,node* graph,int taille_dict);
char* get_dict_name(int len_mot);


#endif //GRAPH_H
