//
// Created by lucie on 25/05/22.
//
#include "includes/graph.h"

edge edge_create(node *n, int id, char label, int p){
    edge e;
    e.node = n; 
    e.id = id;
    e.label = label;
    e.ponderation=p;
    return e;
}

void edge_print(edge *e){
    printf("%d: -%c-%d-> (%d)\n",e->id, e->label,e->ponderation, e->node->id);
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


void node_add_child(node* n1, node* n2, char label, int id, int p){
    edge e = edge_create(n2, id, label,p);
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

void node_add_char(node* n1, char c, int* idMaxE, int* idMaxN, bool terminal, int p){
    if (n1!=NULL){
        list_edge* tmp = n1->listEdge;
        if(node_get_by_label(tmp, c)==NULL){
            node* n3 = node_create(*idMaxN);
            if(terminal) node_switch_terminal(n3);
            *idMaxN+=1;
            node_add_child(n1, n3, c, *idMaxE, p);

            *idMaxE+=1;
        }else{
            if(terminal) node_switch_terminal(n1->listEdge->e.node);
        }
    }
}
 
void node_add_word(node* n1, char* mot, int* idMaxE, int* idMaxN, hash_map* h){
    if(mot[0]){
        bool terminal=false;
        if(!mot[1]){
            terminal= !terminal;
        }
        int p = get_hash_map(h,size-((int)(strlen(mot))),mot[0]);
        node_add_char(n1, mot[0], idMaxE, idMaxN, terminal,p);
        node* child = node_get_by_label(n1->listEdge, mot[0]);
        node_add_word(child, mot+1, idMaxE, idMaxN, h);
    }
 }


void node_get_chemin(int tab[size], node* no, char* mot){
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

void print_tableau(int tab[size]){
    printf("0");
    for(int i=0; i<size;i++){
        printf("->%d", tab[i]);
    }
    printf("\n");
}

bool node_is_unaccessible(node* n){
    if(!n->listEdge && !n->terminal){
        return true;
    }
    return false;
}


void node_remove_unaccessibles(node* n1){
    if(n1!=NULL){
        if(node_is_unaccessible(n1)){
            node_destroy_all_children(n1);
        }
        else{
            n1->listEdge = list_edge_remove_unaccessibles(n1->listEdge);
        }  
    }
    
}

list_edge* list_edge_remove_unaccessibles(list_edge* one_list){
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    while(tmp != NULL){
        tmpnext = tmp->next;
        if(node_is_unaccessible(tmp->e.node)){
            one_list= list_edge_remove_node_by_id(one_list, tmp->e.node->id);
        }
        else{
            tmp->e.node->listEdge = list_edge_remove_unaccessibles(tmp->e.node->listEdge);
        }
        tmp = tmpnext;
    }
    return one_list;
}





node *node_add_all_words(char* nametxt)
{

    hash_map* h = initialize_hash_map(nametxt, size);
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
    for (int i=0;i<len;i++)
    {
    
    
        fgets(ligne, LONG,f);
        char* res = ligne;
        size_t taille_mot = strlen(res);
        if (taille_mot > 0 && res[taille_mot-1] == '\n') res[--taille_mot] = '\0';
        node_add_word(n1, res, &idMaxEdge, &idMaxNode, h);
       
    }
    destroy_hashmap(h);
    fclose(f);
    return n1;
}

char best_char_simple(node* n){
    char c='\0';
    int p=0;
    if(n!= NULL){
        list_edge* current_elt= n->listEdge;
        while (current_elt != NULL)
        {
            if(p<current_elt->e.ponderation){
                p=current_elt->e.ponderation;
                c=current_elt->e.label;
            }
            current_elt=current_elt->next;
        }
    }
    return c;
    
}

char* best_word_simple(node* n){
    char bestword[size];
    if(n!=NULL){
        node* tmp=n;
        int i=0;
        while(i<size){
            char lettre= best_char_simple(tmp);
            bestword[i]=lettre;
            tmp= node_get_by_label(tmp->listEdge,lettre);
            i++;
        }
    }
    char* res = &(bestword[0]);
    return res;
}


int ponderation_get_by_label(node* n, char c){
    int p=0;
    if(n !=NULL){
        node* tmp=n;
        list_edge* liste=tmp->listEdge;
        while (liste->next !=NULL)
        {
           char lettre= liste->e.label;
           if(c==lettre){
               p= liste->e.ponderation;
           }
           else{
               liste=liste->next;
           }
        }
    }
    return p;
}


/*char* best_word_recur(node* n){
    char bestword[size];
    int p=0;
    if(n!=NULL){
        node* tmp=n;
        int i=0;
        list_edge* liste= tmp->listEdge;
        while (liste->next!=NULL)
        {
            while (i<size)
            {
                int pb=0;
                char word[size];
                char lettre=best_char_simple(tmp);
                pb= pb + ponderation_get_by_label(tmp,lettre);
                word[i]=lettre;
                tmp= node_get_by_label(tmp->listEdge,lettre);
                i++;
                if (pb>p)
                {
                    p=pb;
                    for(int j=0;j<size;j++){
                        bestword[j]=word[j];
                    } 
                }
            }
            liste=liste->next;

        }
    }
    char* res= &(bestword[0]);
    return res;
}*/

char* get_dict_name(int len_mot){
    char txt[7]=".txt";
    char strdico[100]="../texte/Dictionnaire/dico0";
    char* dico_mot=malloc(sizeof("../texte/Dictionnaire/dicoimpair.txt"));
    strcpy(dico_mot,strdico);
    char strlong[5];
    sprintf(strlong,"%d",len_mot);
    strcat(dico_mot,strlong);
    strcat(dico_mot, txt);
    return dico_mot;
}

int get_best_word_from_color(node* n1,node* n, char* color,char* mot_tester,int taille_dict){
    
    int len_mot=strlen(color);
    char * dico_mot=get_dict_name(len_mot);
    hash_map* h = initialize_hash_map(dico_mot, len_mot);
    FILE *f=fopen(dico_mot,"r");   
    free(dico_mot); 
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
    int idMaxNode=1;
    int comp=0;
    for (int u=0;u<taille_dict;u++){
        char* s=node_get_word(n);
        if (mot_valid(color,mot_tester,s,len_mot)){
            node_add_word(n1, s, &idMaxEdge, &idMaxNode, h);
            comp++;
        }
        node_remove_word(n,s);
        free(s);
    }
    destroy_hashmap(h);
    return comp;
}

char* node_get_word(node*n){
    if(n!=NULL){
        if(n->terminal){
            char* mot=NULL;
            mot=calloc(20, sizeof(char));
            return mot;
        }
        else{
            return list_edge_get_word(n->listEdge);
        }  
    }
    char* mot=NULL;
    return mot;
}
void node_remove_word(node* n, char* mot){
    int i=0;
    node* noeud;
    node* no=n;
    while(mot[i]){
        noeud = node_get_by_label(no->listEdge,mot[i]);
        i+=1;
        no=noeud;
        if(i==size){
            node_switch_terminal(no);
        }
    }
    i=0;
    node_remove_unaccessibles(n);
    while(i<size){
        node_remove_unaccessibles(n);
        i+=1;
    }
}


/*char* get_best_word_from_color(node* n, char* color,char* mot_tester){
    int len_mot=strlen(color);
}*/

char* list_edge_get_word(list_edge* one_list){
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    char * tmpmot=NULL;
    if (tmp!=NULL){
        tmpnext = tmp->next;
        tmpmot = node_get_word(tmp->e.node);
        chrcat(tmpmot, tmp->e.label);
        tmp = tmpnext;
    }
    return tmpmot;
}

motpondere node_best_word(node* n){
    if(n!=NULL){
        if(n->terminal){
            motpondere mp;
            mp.mot=calloc(20, sizeof(char));
            mp.pond=0;
            return mp;
        }
        else{
            return list_edge_best_word(n->listEdge);
        }  
    }
    motpondere mp;
    mp.mot=NULL;
    mp.pond=0;
    return mp;
}


void chrcat(char* appendTo, char what) {
    int taille = strlen(appendTo);
    int i = 1;
    char tmp=appendTo[0];
    appendTo[0]=what;
    char tmp2 = appendTo[1];
    while(i<=taille){
       
        appendTo[i]=tmp;
        tmp=tmp2;
        tmp2 = appendTo[i+1];
        i++;
    }
}

char* convert_base_3(int N,int taille_mot){
    
    char* result = malloc(sizeof(char)*(taille_mot+1));
    int i=0;
    char remstr[3];
    int max = ceil(log(N+1)/log(3));
    while(N>0){
        int rem = N%3;
        N = N/3;
        sprintf(remstr,"%d",rem);
        result[i] = remstr[0];
        i++;
    }
    for (int r=0;r<taille_mot-max;r++){
        result[taille_mot-r-1] = '0';
    }
    result[taille_mot]='\0';
    return result;

}


//test toute les couleurs sur un mot et renvoie la moyenne sur ce mot
int test_all_color(char* mot_tester,node* graph,int taille_dict){
    node* copy;
    node* copy2=graph;
    int taille_mot=strlen(mot_tester);
    int comp=0;
    char * dico_mot=get_dict_name(taille_mot);
    hash_map* h = initialize_hash_map(dico_mot, taille_mot);
    for (int i=0;i<pow(3,taille_mot);i++){ 
        char* color= convert_base_3(i,taille_mot);
        copy=copy2;
        copy2=node_create(0);
        int idMaxEdge=0;
        int idMaxNode=1;
        for (int u=0;u<taille_dict;u++){
            char* s=node_get_word(copy);
            if (mot_valid(color,mot_tester,s,taille_mot)){
                comp++;
            }
            node_remove_word(copy,s);
            node_add_word(copy2,s,&idMaxEdge,&idMaxNode,h);
            free(s);
        }
        free(color);
    }
    destroy_hashmap(h);
    free(dico_mot);
    node_destroy_all_children(copy2);
    return comp;
}


motpondere list_edge_best_word(list_edge* one_list){
    list_edge* tmp = one_list;
    list_edge* tmpnext;
    motpondere tmpmotp;
    motpondere bestmot;
    bestmot.mot = NULL;
    bestmot.pond = 0;
    while(tmp != NULL){
        tmpnext = tmp->next;
        tmpmotp = node_best_word(tmp->e.node);
        chrcat(tmpmotp.mot, tmp->e.label);
        tmpmotp.pond += tmp->e.ponderation;
        if(tmpmotp.pond > bestmot.pond){
            free(bestmot.mot);
            bestmot = tmpmotp;
        } else {
            free(tmpmotp.mot);
        }
        tmp = tmpnext;
    }
    return bestmot;
}





