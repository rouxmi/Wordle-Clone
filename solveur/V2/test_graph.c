//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"

void test_edge_base(){
    edge e = edge_create(NULL, 1, 'a',5);
    assert(e.id == 1);
    assert(e.label == 'a');
}

void test_node_base(){
    node *n = node_create(1);
    assert(n->id == 1);
    assert(!n->terminal);
    assert(n->nbrAretesEntrantes==0);
    node_destroy_all_children(n);
}

void test_list_base(){
    list_edge* l = list_edge_create();

    assert(list_edge_is_empty(l));

    node* n1 = node_create(1);
    node* n2 = node_create(2);
    edge e1 = edge_create(n1, 1, 'a',5);
    edge e2= edge_create(n2, 2, 'b',5);

    l= list_edge_add_head(e1, l);
    l= list_edge_add_head(e2, l);

    //list_edge_remove_node_by_id(l, 2);

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
    node_add_child(n1, n2, 'a', idMaxEdge,5);
    idMaxEdge+=1;
    node_add_child(n1, n3, 'b', idMaxEdge,5);
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

    node_add_char(n1, 'c', &idMaxEdge, &idMaxNode, false,5);
    node* child = node_get_by_label(n1->listEdge, 'c');
    node_add_char(child, 'a', &idMaxEdge, &idMaxNode, true,5);
    node_destroy_all_children(n1);
}

void test_node_add_word(){
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1;

    hash_map* h = initialize_hash_map("test_node_add_word.txt", 5);

    node_add_word(n1, "LUCIE", &idMaxEdge, &idMaxNode,h);
    node_add_word(n1, "LUCAS", &idMaxEdge, &idMaxNode,h);
    node_add_word(n1, "FABRI", &idMaxEdge, &idMaxNode,h);
    node* child = node_get_by_label(n1->listEdge, 'L');
    node* child2 = node_get_by_label(child->listEdge, 'U');
    node* child3 = node_get_by_label(child2->listEdge, 'C');
    node* child4 = node_get_by_label(child3->listEdge, 'I');
    node* child5 = node_get_by_label(child4->listEdge, 'E');
    assert(!child2->terminal);
    assert(!child3->terminal);
    assert(child5->terminal);
    node_destroy_all_children(n1);
    destroy_hashmap(h);
}


void test_node_get_chemin(){
    int idMaxEdge=0;
    int idMaxNode=0;
    node *n1 = node_create(idMaxNode);
    idMaxNode+=1;
    hash_map* h = initialize_hash_map("test_node_add_word.txt", 5);
    node_add_word(n1, "LUCIE", &idMaxEdge, &idMaxNode,h);
    node_add_word(n1, "LUCIS", &idMaxEdge, &idMaxNode,h);
    node_add_word(n1, "FABRI", &idMaxEdge, &idMaxNode,h);
    node* child = node_get_by_label(n1->listEdge, 'L');
    node* child2 = node_get_by_label(child->listEdge, 'U');
    node* child3 = node_get_by_label(child2->listEdge, 'C');
    node* child4 = node_get_by_label(child3->listEdge, 'I');
    node* child5 = node_get_by_label(child4->listEdge, 'E');
    int p= ponderation_get_by_label(n1,'P');
    int tab[5];
    node_get_chemin(tab, n1, "LUCIE");
    //print_tableau(tab);
    printf("%d c'est moi \n",p);
    node_switch_terminal(child5);
    node_print(child4);
    assert(node_is_unaccessible(child5));
    node_remove_unaccessibles(n1);
    node_print(child4);
    node_destroy_all_children(n1);
    destroy_hashmap(h);
}

void test_node_add_all_words()
{
    char *name="../texte/dict.txt";
    node * n=node_add_all_words(name);
    int tab1[5];
    node_get_chemin(tab1, n, "WHICH");
    print_tableau(tab1);
    int tab2[5];
    node_get_chemin(tab2, n, "PUPAL");
    print_tableau(tab2);
    node_destroy_all_children(n);

}

void test_best_word()
{
    char *name="test_node_add_word.txt";
    node * n=node_add_all_words(name);
    char c=best_char_simple(n);
    char* s = best_word_simple(n);
    printf("ok");
    printf("%c \n",c);
    printf("%s \n",s);
    node_destroy_all_children(n);
}

void test_best_word_recur(){
    char *name="test_node_add_word.txt";
    node * n=node_add_all_words(name);
    motpondere mp;
    mp = node_best_word(n);
    printf("%s \n",mp.mot);
    free(mp.mot);
    node_destroy_all_children(n);
}

void test_node_remove_word(){
    char *name="test_node_add_word.txt";
    node * n=node_add_all_words(name);
    node_remove_word(n, "PUCIS");
    node_destroy_all_children(n);
}

void test_get_word(){
    char *name="test_node_add_word.txt";
    node * n=node_add_all_words(name);
    node* n1=node_create(0);
    int futur_taille=get_best_word_from_color(n1,n,"02220","PUCIS",4);
    printf("%d\n",futur_taille);
    node_print(n1);
    node_destroy_all_children(n1);
}

void test_entropie(){
    char *name="../texte/Dictionnaire/dico03.txt";
    node * n=node_add_all_words(name);
    FILE *f=fopen("../texte/Dictionnaire/dico03.txt","r");
    int taille_dict=taillefichiertxt(f);
    int moy=test_all_color("PROUT",n,taille_dict);
    printf("%d\n",moy);
}

void all_test_list(){
    //test_edge_base();   
    //test_node_base();
    //test_list_base();
    //test_node_add_word();
    //test_node_get_by_id();
    //test_node_get_chemin();
    //test_node_add_all_words();
    //test_best_word();
    //test_best_word_recur();
    //test_get_word();
    test_entropie();
    //test_node_remove_word();
}

