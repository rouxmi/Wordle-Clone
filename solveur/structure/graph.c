//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"

edge edge_create(node *n, int id, char label){
    edge e;
    e.node = n;
    e.id = id;
    e.label = label;
    return e;
}

void edge_print(edge *e){
    printf("%d : %c\n", e->id, e->label);
}

node node_create(int id){
    node n;
    n.id = id;
    n.terminal = false;
    n.listEdge = NULL;
    return n;
}

void node_switch_terminal(node* n){
    n->terminal = !(n->terminal);
}

void node_add_child(node* n1, node* n2, char label, int id){
    edge e = edge_create(n2, id, label);
    n2->nbrAretesEntrantes +=1;
    list_edge_add_head(&e, n1->listEdge);

}

void node_print(node* n){
    printf("%d\n", n->id);
}

list_edge* list_edge_create() {
    list_edge* one_list = (list_edge*)malloc(sizeof(list_edge));
    one_list->e = NULL;
    one_list->next= NULL;
    return one_list;
}

void list_edge_destroy(list_edge* one_list)
{
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    while(tmp != NULL){
        tmpnext = tmp->next;
        free(tmp);
        tmp = tmpnext;
    }
    free(tmp);
}

bool list_edge_is_empty(list_edge * one_list) {
    return one_list->e == NULL;
}

edge* liste_edge_first(list_edge* one_list){
    return one_list->e;
}

list_edge* liste_edge_next(list_edge* one_list){
    return one_list->next;
}


 list_edge* list_edge_add_head(edge* e, list_edge* one_list){
    list_edge * nouvelElement = (list_edge*) malloc(sizeof(list_edge));
    nouvelElement->e = e;
    nouvelElement->next = one_list;
    return nouvelElement;
}

void list_edge_print_rec(list_edge* one_list){
    if(!list_edge_is_empty(one_list)){
        edge_print(liste_edge_first(one_list));
        list_edge_print_rec(liste_edge_next(one_list));
    }
}

list_edge* list_edge_remove_node_by_id(list_edge* one_list, int id)
{
    /* one_list vide, il n'y a plus rien à supprimer */
    if(one_list == NULL)
        return NULL;

    /* Si l'élément en cours de traitement doit être supprimé */
    if(one_list->e!=NULL && one_list->e->node!=NULL && one_list->e->node->id == id) {
            /* On le supprime en prenant soin de mémoriser
            l'adresse de l'élément suivant */
            list_edge *tmp = one_list->next;
            free(one_list);
            return tmp;
    } else {
        /* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la one_list finale commencera par cet élément et suivra une one_list ne contenant
        plus d'élément ayant la valeur recherchée */
        one_list->next = list_edge_remove_node_by_id(one_list->next, id);
        return one_list;
    }
}
