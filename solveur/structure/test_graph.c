//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"

void test_edge_base(){
    edge e = edge_create(NULL, 1, 'a');
    assert(e.id == 1);
    assert(e.label == 'a');
    //edge_print(&e);
}

void test_node_base(){
    node *n = node_create(1);
    assert(n->id == 1);
    //node_print(&n);
    node_destroy(n);
}

void test_list_base(){
    list_edge* l = list_edge_create();

    assert(list_edge_is_empty(l));

    node* n1 = node_create(1);
    node* n2 = node_create(2);
    edge e1 = edge_create(n1, 1, 'a');
    edge e2= edge_create(n2, 2, 'b');

    l= list_edge_add_head(e1, l);
    l= list_edge_add_head(e2, l);

    //list_edge_print_rec(l);
    //list_edge_remove_node_by_id(l, 2);
    //list_edge_print_rec(l);
    l=list_edge_destroy(l);
}




void test_node_get_by_id(){
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1;
    node *n2 = node_create(idMaxNode);
    idMaxNode+=1;
    node *n3 = node_create(idMaxNode);
    idMaxNode+=1;
    node_add_child(n1, n2, 'a', idMaxEdge);
    idMaxEdge+=1;
    node_add_child(n1, n3, 'b', idMaxEdge);
    idMaxEdge+=1;
    node *n4 = node_get_by_id(n1->listEdge, 1);
    assert(n4->id == 1);
    assert(n4->nbrAretesEntrantes == 1);
    node *n5 = node_get_by_id(n1->listEdge, 2);
    assert(n5->id == 2);
    assert(n5->nbrAretesEntrantes == 1);
    node_destroy_all_children(n1);
}

void test_node_add_char(){
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1;

    node_add_char(n1, 'c', &idMaxEdge, &idMaxNode);
    node* child = node_get_by_label(n1->listEdge, 'c');
    node_add_char(child, 'a', &idMaxEdge, &idMaxNode);
    node_destroy_all_children(n1);
}

void test_node_add_word(){
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1;

    node_add_word(n1, "lucie", &idMaxEdge, &idMaxNode);
    node_add_word(n1, "lucal", &idMaxEdge, &idMaxNode);
    node_add_word(n1, "fabri", &idMaxEdge, &idMaxNode);
    node* child = node_get_by_label(n1->listEdge, 'l');
    node* child2 = node_get_by_label(child->listEdge, 'u');
    node* child3 = node_get_by_label(child2->listEdge, 'c');
    node* child4 = node_get_by_label(child3->listEdge, 'i');
    node_print(n1);
    node_print(child);
    node_print(child2);
    node_print(child3);
    node_print(child4);
    node_destroy_all_children(n1);
}

void all_test_list(){
    test_edge_base();
    test_node_base();
    test_list_base();
    test_node_add_word();
    test_node_get_by_id();
}

