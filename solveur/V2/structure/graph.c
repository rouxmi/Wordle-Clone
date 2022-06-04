//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"
#define LONG 255

edge edge_create(node *n, int id, char label){
    edge e;
    e.node = n;
    e.id = id;
    e.label = label;
    return e;
}

void edge_print(edge *e){
    printf("%d: -%c-> (%d)\n",e->id, e->label, e->node->id);
}

node* node_create(int id){
    node* n = (node*)calloc(1, sizeof(node));
    n->id = id;
    n->terminal = false;
    n->listEdge = NULL;
    n->nbrAretesEntrantes = 0;
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
    if (n !=NULL){
        printf("%d\n", n->id);
        if(n->listEdge!=NULL) list_edge_print_rec(n->listEdge);
    }
}

void node_destroy_all_children(node* n){
    if(n!=NULL){
        if(n->listEdge != NULL){
            n->listEdge = list_edge_destroy(n->listEdge);
        }
        free(n);
    }
}

node* node_get_by_id(list_edge* one_list, int id){
    if(!list_edge_is_empty(one_list)){
        list_edge* tmp= one_list;
        while(tmp != NULL){
            if(tmp->e.node->id == id)
                return tmp->e.node;
            tmp=tmp->next;
        }
    }
    return NULL;
}

node* node_get_by_label(list_edge* one_list, char label){
    if(!list_edge_is_empty(one_list)){
        list_edge* tmp= one_list;
        while(tmp != NULL){
            if(tmp->e.label == label)
                return tmp->e.node;
            tmp=tmp->next;
        }
    }
    return NULL;
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
        node_destroy_all_children(tmp->e.node);
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
    if(one_list == NULL)
        return NULL;
    if(one_list->e.node!=NULL && one_list->e.node->id == id) {
            list_edge *tmp = one_list->next;
            node_destroy_all_children(one_list->e.node);
            free(one_list);
            return tmp;
    } else {
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

void node_add_char(node* n1, char c, int* idMaxE, int* idMaxN, bool terminal){
    if (n1!=NULL){
        list_edge* tmp = n1->listEdge;
        if(node_get_by_label(tmp, c)==NULL){
            node* n3 = node_create(*idMaxN);
            if(terminal) node_switch_terminal(n3);
            *idMaxN+=1;
            node_add_child(n1, n3, c, *idMaxE);

            *idMaxE+=1;
        }else{
            if(terminal) node_switch_terminal(n1->listEdge->e.node);
        }
    }
}
 
void node_add_word(node* n1, char* mot, int* idMaxE, int* idMaxN){
    if(mot[0]){
        bool terminal=false;
        if(!mot[1]){
            terminal= !terminal;
        }
        node_add_char(n1, mot[0], idMaxE, idMaxN, terminal);
        node* child = node_get_by_label(n1->listEdge, mot[0]);
        node_add_word(child, mot+1, idMaxE, idMaxN);
    }
 }


void node_get_chemin(int tab[5], node* no, char* mot){
    int i=0;
    node* noeud;
    node* n = no;
    while(mot[i]){
        noeud = node_get_by_label(n->listEdge,mot[i]);
        int id_i= noeud->id ;
        tab[i]=id_i;
        i+=1;
        n=noeud;
    }

}

void print_tableau(int tab[5]){
    printf("0");
    for(int i=0; i<5;i++){
        printf("->%d", tab[i]);
    }
    printf("\n");
}

bool node_remove_unaccessibles(node* n1){
    if(n1!=NULL){
        if(n1->listEdge != NULL){
            n1->listEdge = list_edge_remove_unaccessibles(n1->listEdge);
        }
        else{
            if(!n1->terminal)
            {
                node_destroy_all_children(n1);
                return 1;
            }  
        }
    }
    return 0;
}

list_edge* list_edge_remove_unaccessibles(list_edge* one_list){
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    bool b;
    while(tmp != NULL){
        tmpnext = tmp->next;
        b=node_remove_unaccessibles(tmp->e.node);
        if(b) free(tmp);
        tmp = tmpnext;
    }
    return one_list;
}





node *node_add_all_words(char* nametxt)
{
    FILE *f=fopen(nametxt,"r");
    assert(f!=NULL);
    int len=0;
    char c;
    while((c=fgetc(f)) != EOF)
    {
        if(c=='\n')
        {
            len++;
        }
    }
    rewind(f);
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1; 
    char ligne[LONG];
    for (int i=0;i<len+1;i++)
    {
    
    
        fgets(ligne, LONG,f);
        char* res = ligne;
        node_add_word(n1, res, &idMaxEdge, &idMaxNode);
       
    }
     
    fclose(f);
    return n1;
}