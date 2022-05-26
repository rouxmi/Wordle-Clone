//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"

void test_edge_base(){
    edge e = edge_create(NULL, 1, 'a');
    edge_print(&e);
}

void test_node_base(){
    node n = node_create(1);
    node_print(&n);
}

void test_list_base(){
    list_edge* l = list_edge_create();
    assert(list_edge_is_empty(l));
    node n1 = node_create(1);
    node n2 = node_create(2);
    edge e1 = edge_create(&n1, 1, 'a');
    edge e2= edge_create(&n2, 2, 'b');
    l= list_edge_add_head(&e1, l);
    l= list_edge_add_head(&e2, l);
    list_edge_print_rec(l);
    l = list_edge_remove_node_by_id(l, 2);
    list_edge_print_rec(l);
    list_edge_destroy(l);
}




void all_test_list(){
    //test_edge_base();
    //test_node_base();
    test_list_base();
}
