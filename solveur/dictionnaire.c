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
bool contains(char lettre , char* mot, int longueur_mot) //cette fonction sert à trier les mots contenant les lettres qui ont la valeur 0 lors de la coloration, pasceslettres est une chaine contenant ces caractères 
{
    assert(mot!=NULL);
    {
        for (int i=0;i<longueur_mot;i++)
        {
            if (mot[i]==lettre)
            { 
                return true;
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

/*char* createplace(int longueur_mot)
{
    char* place=(char*)calloc(longueur_mot+1,sizeof(char));
    char espace='a';
    for (int i=0;i<longueur_mot;i++)
    {
        append(place,espace);
    }
    return place;
}*/

char * contentofline(FILE *f, int linenumber, int longueur_mot, int longueur_dico)
{
    assert(f!=NULL);
    assert(longueur_dico>=linenumber);
    char FILENAME[FILENAME_SIZE];
    char *buffer=(char*)calloc(MAX_LINE, sizeof(char));
    //printf("dans content\n"); 
    bool keep_reading=true;
    int current_line=1;
 //   do
 //   {
        //printf("on entre: %d %p\n", MAX_LINE, f);
        fgets(buffer,MAX_LINE,f);
        //printf("buffer: %s\n", buffer);
        if (current_line==linenumber)
        {
            keep_reading=false;
            //printf("IF TROUVE\n");
        }
        current_line++;
   // } while (keep_reading);
    return buffer;
    
    
}


void append(char* s, char c) {

    int len = (int)strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void addintofile(FILE *f, char *word_to_add,int longueur_fichier)
{
    if(longueur_fichier>1)
    {
        fprintf(f,"%s",word_to_add);
    }
    else{
        fprintf(f,"%s",word_to_add);
    }
    

}

/*char* add_char_to_chararray(char *mot, char ca, int longueur_mot, int position)
{
    mot[position]=ca;
}*/

void dico(element tab[30],int nb_essai, int longueur_mot, int longueur_fichier)
{
    char *right_place="m r i";
    char * wrong_place="    c ";
    int index=0;
    element current;
    FILE *f=fopen("texte/test.txt","r");
    FILE *d1=fopen("texte/dico1txt","a");
    FILE *d2=fopen("texte/dico2.txt","a");
    FILE *d3=fopen("texte/dico3.txt","a");
    FILE *d4=fopen("texte/dico4.txt","a");
    FILE *d5=fopen("texte/dico5.txt","a");
    FILE *intermediaire1=fopen("dicointer1.txt","a");
    FILE *intermediaire2=fopen("dicointer2.txt","a");
    FILE *list_dico[6]={f,d1,d2,d3,d4,d5};
    int nb_alabonneplace=0;
    int nb_pasalabonneplace=0;
    int pasla=0;
    for (int i=0;i<longueur_mot;i++)
    {
        current=tab[nb_essai+i];
        //printf("%s\n","ici");
        if (current.coloration==2)
        {
            nb_alabonneplace++;
        }
        else if (current.coloration==1)
        {
            nb_pasalabonneplace++;
        }
        else if (current.coloration==0)
        {
            pasla++;
            printf("%c\n",current.lettre);
            FILE *current_dico=list_dico[nb_essai];
            int len=taillefichiertxt(current_dico);
            rewind(current_dico);
            int len1=taillefichiertxt(intermediaire1);
            rewind(intermediaire1);
            printf("%d\n",len1);
            for (int j=0;j<len;j++)
            {
                char *current_word=contentofline(current_dico,j,longueur_mot+1,len);
                if (contains(current.lettre, current_word,longueur_mot)==false)
                {
                    addintofile(intermediaire1,current_word,len1);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
                }
                free(current_word);
            }
        


    
        }
    
    }
    printf("%d\n%d\n%d\n", nb_alabonneplace,nb_pasalabonneplace,pasla);
    fclose(intermediaire1);
    fclose(intermediaire2);
    for (int k=0;k<6;k++)
    {
        fclose(list_dico[k]);
    }
    

}




/*void dico(element tab[30], int nb_essai, int longueur_mot, int longueur_fichier)
{
    //char *right_place=(char*)calloc(longueur_mot+5,sizeof(char));
    //printf("right_place %s\n",right_place);
    //char *wrong_place=(char*)calloc(longueur_mot+1,sizeof(char));
    //char not_here[100];
    char *right_place="m r i";
    char * wrong_place="    c ";
    char *not_here="e";
    int index=0;
    int position;
    char espace=' ';
    element current;
    FILE *f=fopen("texte/test.txt","r");
    FILE *d1=fopen("texte/dico1txt","a");
    FILE *d2=fopen("texte/dico2.txt","a");
    FILE *d3=fopen("texte/dico3.txt","a");
    FILE *d4=fopen("texte/dico4.txt","a");
    FILE *d5=fopen("texte/dico5.txt","a");
    FILE *intermediaire1=fopen("dicointer1.txt","a");
    FILE *intermediaire2=fopen("dicointer2.txt","a");
    FILE *list_dico[6]={f,d1,d2,d3,d4,d5};
    for (int i=0; i<longueur_mot; i++)
    {
        current = tab[nb_essai+i];
        //printf("%d\n",current.place);
        position=current.place;
        if (current.coloration==2)
        {
            printf("position: %d\n", position);
            printf("lettre: %c\n", current.lettre);
            right_place[position]=current.lettre; 
            printf("right_place %s\n",right_place);

        }
        else if (current.coloration==1)
        {
            wrong_place[position]=current.lettre;
        }
        else{
            not_here[index]=current.lettre;
            index++;
        }

    }
    printf("right_place: %s\n",right_place);
    //faire des dicos intermédiaire 
    //printf("%s\n","hola");
    FILE *current_dico=list_dico[nb_essai];
    int len=taillefichiertxt(current_dico);
    printf("%d\n",len);
    rewind(current_dico);
    printf("%s\n",not_here);
    for (int j=0; j<longueur_fichier+1;j++)
    {
        printf("%s\n","jesuisla");
        char* current_word=contentofline(current_dico,j,longueur_mot+1,len);
        printf("current: %s\n", current_word);
        if (contains(not_here,current_word,longueur_mot)==false)
        {
            printf("%s\n","jevaisécrire");
            addintofile(intermediaire1,current_word,len);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
        }

        
        for (int k=0;k<longueur_mot;k++)
        {
            if (right_place[k]!=espace)
            {
                char find=right_place[k];
                {
                    for (int i=0;i<longueur_fichier;i++)

                    {
                        FILE *current_dico=intermediaire1;
                        int len1=taillefichiertxt(current_dico);
                        rewind(current_dico);
                        char* current_word=contentofline(current_dico,k,longueur_mot,len1);
                        if (acetteplace(k,find,current_word))
                        {
                            addintofile(intermediaire2,current_word, len1);//ecrire dans intermediaire 2
                        }
                
                    }
                }
            }
        }
        
        
        for (int j=0;j<(int)strlen(wrong_place);j++)
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
        free(current_word);

        // free les dicos intermediaires et close les fichiers a close 
    }

    //free(right_place);
    //free(wrong_place);
    free(intermediaire1);
    free(intermediaire2);
    for (int k=0;k<6;k++)
    {
        fclose(list_dico[k]);
    }
    


}*/


