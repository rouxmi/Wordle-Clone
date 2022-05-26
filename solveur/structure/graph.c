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
    n1->listEdge = list_edge_add_head(e, n1->listEdge);
}

void node_print(node* n){
    printf("%d\n", n->id);
    list_edge_print_rec(n->listEdge);
}

void node_destroy(node* n){
    n->listEdge = list_edge_destroy(n->listEdge);
}

void node_destroy_all_children(node* n){
    list_edge* tmp= n->listEdge;
    while(tmp != NULL){
        node_destroy_all_children(tmp->e.node);
        tmp=tmp->next;
    }
    n->listEdge = list_edge_destroy(n->listEdge);
}


list_edge* list_edge_create() {
    return NULL;
}

list_edge* list_edge_destroy(list_edge* one_list)
{
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    while(tmp != NULL){
        tmpnext = tmp->next;
        free(tmp);
        tmp = tmpnext;
    }
    free(tmp);
    return NULL;
}

bool list_edge_is_empty(list_edge * one_list) {
    return one_list == NULL;
}

edge liste_edge_first(list_edge* one_list){
    return one_list->e;
}

list_edge* liste_edge_next(list_edge* one_list){
    return one_list->next;
}


 list_edge* list_edge_add_head(edge e, list_edge* one_list){
    list_edge * nouvelElement = (list_edge*) malloc(sizeof(list_edge));
    nouvelElement->e = e;
    nouvelElement->next = one_list;
    return nouvelElement;
}

void list_edge_print_rec(list_edge* one_list){
    if(one_list != NULL){
        if(!list_edge_is_empty(one_list)){
            edge e = liste_edge_first(one_list);
            edge_print(&e);
            list_edge_print_rec(liste_edge_next(one_list));
        }
    }
}

list_edge* list_edge_remove_node_by_id(list_edge* one_list, int id)
{
    /* one_list vide, il n'y a plus rien à supprimer */
    if(one_list == NULL)
        return NULL;

    /* Si l'élément en cours de traitement doit être supprimé */
    if(one_list->e.node!=NULL && one_list->e.node->id == id) {
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

bool list_edge_contains_by_label(list_edge* one_list, char valeur)
{
    list_edge* tmp=one_list;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        if(tmp->e.label == valeur)
        {
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void node_add_word(node* n1, char* mot){
    if(n1 != NULL && n1->listEdge!=NULL){
        bool f = false;
        list_edge* tmp=n1->listEdge;
        /* Tant que l'on n'est pas au bout de la liste */
        while(tmp != NULL)
        {
            if(mot != NULL && tmp->e.label == mot[0] )
            {
                if(&(*(mot+1)) ==NULL){
                node_switch_terminal(n1->listEdge->e.node);
                }
                node_add_word(n1->listEdge->e.node, &(*(mot+1)));
                f=true;
            }
            tmp = tmp->next;
        }
        if(!f && mot != NULL){
            int id = 4;
            node n2 = node_create(id);
            if(&(*(mot+1)) ==NULL){
                node_switch_terminal(&n2);
            }
            node_add_child(n1, &n2, mot[0], id);
            node_add_word(&n2, &(*(mot+1)));
        }
    }
}




