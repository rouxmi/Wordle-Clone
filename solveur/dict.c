#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dict.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define len_mot 5
#define FILENAME_SIZE 7048
#define MAX_LINE 7048

int taillefichiertxt (FILE *f)
{   
    int compteur=0;
    char c;
    while((c=fgetc(f)) != EOF)
    {
        if(c=='\n')
        {
            compteur++;
        }
    }

    return compteur;
}
bool contains(char lettre , char* mot) //cette fonction sert à trier les mots contenant les lettres qui ont la valeur 0 lors de la coloration, pasceslettres est une chaine contenant ces caractères 
{
    assert(mot!=NULL);
    bool valid=false;
    int n=(int)strlen(mot);
    
    for (int i=0;i<n;i++)
    {
        if (mot[i]==lettre)
            { 
                valid=true;
            }
    }
    return valid;
    

}
bool acetteplace(char lettre, char *mot, int position)
{
    bool valid=false;
    if (mot[position-1]==lettre)
    {
            valid=true;

    }
    return valid;

}
bool containsexceptposition(char* mot,char lettre,char color[len_mot],int position)
{

    bool valid=false;
    //printf("coucou");
    if (contains(lettre,mot)==true)
    {
        int n=strlen(mot);
        for (int j=0;j<n;j++)
        {
            if (j!=position-1){
                if (mot[j]==lettre && color[j]!=2)
                {
                    valid=true;
                }
            }
        }
    
    }   
    return valid;
}




char * contentofline(FILE *f)
{
    assert(f!=NULL);
    char *buffer=(char*)calloc(MAX_LINE, sizeof(char));
    fgets(buffer,MAX_LINE,f);
    return buffer;
    
    
}




void addintofile(char* futurdico, char *word_to_add)
{
    FILE *futurdict=fopen(futurdico,"a");
    char buffer[MAX_LINE];
  
    // exit if there is an error opening the file
    if (futurdict == NULL)
    {
        printf("Error opening file.\n");

    }
    int n=strlen(word_to_add);
    for (int u=0;u<n;u++){
        buffer[u]=word_to_add[u];
    }
    fputs(word_to_add, futurdict);
    fclose(futurdict);

}

void resetdict(char* name){
    FILE* reset = fopen(name, "w");
    ftruncate(fileno(reset), 0);
    fclose(reset);
}

void str_slice(const char * str, char * word_coupe, size_t start, size_t end)
{
    
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        word_coupe[j++] = str[i];
    }
    word_coupe[j] = 0;
 
}



void dico(element tab[size*nbessais],int nb_essai, int longueur_mot)
{
    char *list_dico[6]={"texte/dico0.txt","texte/dico1.txt","texte/dico2.txt","texte/dico3.txt","texte/dico4.txt","texte/dico5.txt"};
    element current;
    resetdict(list_dico[nb_essai+1]);
    char * name=list_dico[nb_essai+1];
    FILE *anciendico=fopen(list_dico[nb_essai],"r");
    int n=taillefichiertxt(anciendico);
    rewind(anciendico);
    char* mot_actuel=malloc(sizeof(char)*(longueur_mot+2));
    for (int i=0;i<n;i++){

        bool mot_possible=true;
        char* current_word=contentofline(anciendico);
        strcpy(mot_actuel,current_word);
        free(current_word); 
        for (int j=0;j<longueur_mot;j++){
            current=tab[nb_essai*longueur_mot+j];
            if (current.coloration==2)
            {
                if (i==0){
                    print_element(current);
                }
                if (!acetteplace(current.lettre,mot_actuel,current.place)){
                    mot_possible=false;
                }
                
            }
            else{if (current.coloration==0){
                    int nb_pos2=0;
                    int nb_pos=0;
                    for (int g=0;g<longueur_mot;g++){
                        if (tab[nb_essai*longueur_mot+g].lettre==current.lettre && tab[nb_essai*longueur_mot+g].coloration!=0){
                            nb_pos++;
                        }
                    }
                    for (int h=0;h<longueur_mot;h++){
                        if (mot_actuel[h]==current.lettre){
                            nb_pos2++;
                        }
                    }
                    if (nb_pos!=nb_pos2){
                        mot_possible=false;

                    }
                }   
                else{if (current.coloration==1){
                    int color=7;
                    char scolor[longueur_mot+2];
                    char stcolor[longueur_mot+1];
                    for (int m=0;m<longueur_mot;m++){
                        element o=tab[nb_essai*longueur_mot+m];
                        color=color*10+o.coloration;

                    }
                    sprintf( scolor, "%d", color);
                    str_slice(scolor,stcolor,1,longueur_mot);
                    if (!containsexceptposition(mot_actuel,current.lettre,stcolor,current.place)){
                        mot_possible=false;
                    }
                }
                
            }  
        }
        }

        if (mot_possible){
            addintofile(name,mot_actuel);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            
        }
        
        
    }
    free(mot_actuel);
    fclose(anciendico);

}
