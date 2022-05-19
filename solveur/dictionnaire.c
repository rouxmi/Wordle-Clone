#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dictionnaire.h"
#include <string.h>
#include <stdbool.h>

#define len_mot 5
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int taillefichiertxt (FILE *f)
{
    int compteur=1;
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
bool contains(char *ceslettres , char* mot, int longueur_mot) //cette fonction sert à trier les mots contenant les lettres qui ont la valeur 0 lors de la coloration, pasceslettres est une chaine contenant ces caractères 
{
    char *sontpresents;
    int longueur=strlen(ceslettres);
    assert(mot!=NULL);
    {
        for (int i=0;i<longueur_mot;i++)
        {
            for (int j=0; j<longueur;j++)
            {
                if (mot[i]==ceslettres[j])
                {
                    return true;
                }
            }
        }
    }
    return false;

}
bool acetteplace(int position, char x, char *mot)
{
    if (mot[position]==x)
    {
        return true; 
    }
    else
    {
        return false;
    }


}
bool containsexceptposition(char* mot,char x,int position, int longueur_mot)
{
    for (int i=0;i<longueur_mot;i++)
    {
        if (i!=position)
        {
            if (mot[i]==x)
            {
                return true;
            }
        }
    }
    return false;
}
void str_slice(char * str, char * word_coupe, size_t start, size_t end)
{
    
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        word_coupe[j++] = str[i];
    }
    word_coupe[j] = 0;
}

char* createplace(int longueur_mot)
{
    char* place;
    char espace=' ';
    for (int i=0;i<longueur_mot;i++)
    {
        place=place+espace;
    }
    return place;
}

char * contentofline(FILE *f, int linenumber, int longueur_mot, int longueur_dico)
{
    assert(f!=NULL);
    assert(longueur_dico>linenumber);
    char FILENAME[FILENAME_SIZE];
    char *buffer=(char*)malloc(sizeof(char)*MAX_LINE);
    bool keep_reading=true;
    int current_line=1;
    do
    {
        fgets(buffer,MAX_LINE,f);
        if (current_line==linenumber)
        {
            keep_reading=false;

        }
        current_line++;
    } while (keep_reading);
    return buffer;
    
    
}


void append(char* s, char c) {

        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void addintofile(FILE *f, char *word_to_add,int longueur_fichier)
{
    if(longueur_fichier>1)
    {
        fprintf(f,"\n%s",word_to_add);
    }
    else{
        fprintf(f,"%s",word_to_add);
    }
    

}



void dico(element *tab[30], int nb_essai, int longueur_mot, int longueur_fichier)
{
    char *right_place=createplace(longueur_mot);
    char *wrong_place=createplace(longueur_mot);
    char not_here[100];
    int position;
    char espace=' ';
    element *current;
    FILE *f=fopen("test.txt","rt");
    FILE *d1=fopen("dico1txt","a");
    FILE *d2=fopen("dico2.txt","a");
    FILE *d3=fopen("dico3.txt","a");
    FILE *d4=fopen("dico4.txt","a");
    FILE *d5=fopen("dico5.txt","a");
    FILE *intermediaire1=fopen("dicointer1.txt","a");
    FILE *intermediaire2=fopen("dicointer3.txt","a");
    FILE *list_dico[6]={f,d1,d2,d3,d4,d5};
    for (int i=0; i<6; i++)
    {
        current = tab[nb_essai+i];
        position=current->place;
        if (current->coloration==2)
        {
            
            right_place[position]=current->lettre;

        }
        else if (current->coloration==1)
        {
            wrong_place[position]=current->lettre;
        }
        else{
            append(not_here,current->lettre);
        }

    }//faire des dicos intermédiaire  
    for (int j=0; j<longueur_fichier;j++)
    {
        FILE *current_dico=list_dico[nb_essai];
        int len=taillefichiertxt(current_dico);
        char* current_word=contentofline(current_dico,j,longueur_mot,len);
        if (!contains(not_here,current_word,longueur_mot))
        {
            addintofile(intermediaire1,current_word,len);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
        }
        for (int j=0;j<strlen(right_place);j++)
        {
            if (right_place[j]!=espace)
            {
                char find=right_place[j];
                {
                    for (int i=0;i<longueur_fichier;i++)

                    {
                        FILE *current_dico=intermediaire1;
                        int len1=taillefichiertxt(current_dico);
                        char* current_word=contentofline(current_dico,j,longueur_mot,len1);
                        if (acetteplace(j,find,current_word))
                        {
                            addintofile(intermediaire2,current_word, len1);//ecrire dans intermediaire 2
                        }
                
                    }
                }
            }
        }
        for (int j=0;j<strlen(wrong_place);j++)
        {
            if (wrong_place[j]!=espace)
            {
                char notfind=wrong_place[j];
                {
                    for (int i=0;i<longueur_fichier;i++)

                    {
                        FILE *current_dico=intermediaire2;
                        int len2=taillefichiertxt(current_dico);
                        FILE *next_dico=list_dico[nb_essai+1];
                        int lenf=taillefichiertxt(next_dico);
                        char* current_word=contentofline(current_dico,j,longueur_mot,len2);
                        if (containsexceptposition(current_word,notfind,j,longueur_mot))
                        {
                            addintofile(next_dico,current_word,lenf);//ecrire dans dico(nb_essai+1)
                        }
                
                    }
                }
            }
        }

        // free les dicos intermediaires et close les fichiers a close 
    }
    free(intermediaire1);
    free(intermediaire2);
    for (int k=0;k<sizeof(list_dico);k++)
    {
        fclose(list_dico[k]);
    }


}


