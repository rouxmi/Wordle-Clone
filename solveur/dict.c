#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dict.h"
#include <string.h>
#include <stdbool.h>

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
    if (mot[position]==lettre)
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
            if (j!=position){
                if (mot[j]==lettre && color[j]!=2)
                {
                    valid=true;
                }
            }
        }
    
    }   
    return valid;
}


char * contentofline(FILE *f, int linenumber, int longueur_dico)
{
    assert(f!=NULL);
    assert(longueur_dico>=linenumber);
    char *buffer=(char*)calloc(MAX_LINE, sizeof(char));
    //printf("dans content\n"); 
 //   do
 //   {
        //printf("on entre: %d %p\n", MAX_LINE, f);
    fgets(buffer,MAX_LINE,f);
        //printf("buffer: %s\n", buffer);
   // } while (keep_reading);
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
    printf("dak:%s",buffer);  
    fputs(word_to_add, futurdict);
    fclose(futurdict);

}



void dico(element tab[size*nbessais],int nb_essai, int longueur_mot)
{
    char *list_dico[6]={"texte/dico0.txt","texte/dico1.txt","texte/dico2.txt","texte/dico3.txt","texte/dico4.txt","texte/dico5.txt"};
    element current;
    char * name=list_dico[nb_essai+1];
    FILE *anciendico=fopen(list_dico[nb_essai],"r");
    int n=taillefichiertxt(anciendico);
    rewind(anciendico);
    char *current_word=malloc(sizeof(char)*longueur_mot);
    for (int i=0;i<n;i++){

        bool mot_possible=true;
        current_word=contentofline(anciendico,i+1,n);
        for (int j=0;j<longueur_mot;j++){
            current=tab[nb_essai*longueur_mot+j];
            
            if (current.coloration==2)
            {
                if (!acetteplace(current.lettre,current_word,current.place)){
                    mot_possible=false;
                }
                
            }
            else{if (current.coloration==0){
                    if (contains(current.lettre,current_word)){
                        mot_possible=false;
                    }
                }
                else{if (current.coloration==1){
                    char color[longueur_mot];
                    for (int m=0;m<longueur_mot;m++){
                        element o=tab[nb_essai*longueur_mot+m];
                        color[m]=o.coloration;
                    }
                    if (!containsexceptposition(current_word,current.lettre,color,current.place)){
                        mot_possible=false;
                    }
                }
                
            }  
        }
        }
        if (mot_possible){
            
            printf("%s",current_word);
            addintofile(name,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            
        }
        
        
    }
    free(current_word);
    fclose(anciendico);

}
