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
#define MAX_LINE 7048

int taillefichiertxt (FILE *f)
{
    int compteur=1;
    char c;
    while((c=fgetc(f)) != EOF)
    {
        if(c=='\n')
        {
            //printf("coucou");
            compteur++;
        }
    }

    return compteur;
}
bool contains(char *ceslettres , char* mot, int longueur_mot) //cette fonction sert à trier les mots contenant les lettres qui ont la valeur 0 lors de la coloration, pasceslettres est une chaine contenant ces caractères 
{
    assert(mot!=NULL);
    int compteur=0;
    int len=(int)strlen(ceslettres);
    
    for (int i=0;i<longueur_mot;i++)
    {
        for (int j=0;j<len;j++){
            if (mot[i]==ceslettres[j])
            { 
                compteur++;
            }
        }

        
        
    }
    if (compteur==0)
    {
        return false;
    }
    else
    {
        return true;
    }
    

}
bool acetteplace(char ceslettres[], char *mot, int positions[],int index)
{
    int compteur=0;
    //printf("coucou");
    for (int j=0;j<index;j++)
    {
        int p=positions[j];
        char c=ceslettres[j];
        if (mot[p]==c)
        {
            compteur++;
        }

    }
    if (compteur==index)
    {
        return true;
    }
    else{
        return false;
    }

}
bool containsexceptposition(char* mot,char *ceslettres,int positions[], int index,int longueur_mot)
{

    int compteur=0;
    //printf("coucou");
    if (contains(ceslettres,mot,longueur_mot)==true)
    {
        for (int j=0;j<index;j++)
        {
            int p=positions[j];
            char c=ceslettres[j];
            if (mot[p]==c)
            {
                compteur++;
            }

        }
        if (compteur==0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


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




void addintofile(FILE *f, char *word_to_add)
{
    
    fprintf(f,"%s",word_to_add);
}
    


/*char* add_char_to_chararray(char *mot, char ca, int longueur_mot, int position)
{
    mot[position]=ca;
}*/

void coloration0(element tab[30],int nb_essai, int longueur_mot)
{
   
    char not_here  [100];
    int index=0;
    int nb_not_here=0;
    element current;
    char *list_dico[7]={"texte/dico0.txt","texte/dico1.txt","texte/dico2.txt","texte/dico3.txt","texte/dico4.txt","texte/dico5.txt","texte/dico6.txt"};
    FILE *dico=fopen(list_dico[nb_essai],"r");
    FILE *intermediaire1=fopen("dicointer1.txt","a");
    for (int i=0;i<longueur_mot;i++)
    {
        current=tab[nb_essai+i];
        
        if (current.coloration==0)
        {
            not_here[index]=current.lettre;
            index++;
            nb_not_here++;
            //printf("%s\n",not_here);
              
        }
    
    }
    if (nb_not_here==0)
    {
        int len=taillefichiertxt(dico);
        rewind(dico);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(dico,j,longueur_mot+1,len);
            addintofile(intermediaire1,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            free(current_word);
        }

    }
    else{
        int len=taillefichiertxt(dico);
        rewind(dico);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(dico,j,longueur_mot+1,len);
            if (contains(not_here, current_word,longueur_mot)==false)
            {
                addintofile(intermediaire1,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            }
            free(current_word);
        }
    }
    //printf("%s\n",not_here);
    

    fclose(intermediaire1);
    fclose(dico);
    

}

void coloration2(element tab[30],int nb_essai, int longueur_mot)
{
   
    char right_place[10];
    int positions_rp[10];
    int index=0;
    int nb_here=0;
    element current;
    FILE *intermediaire1=fopen("dicointer1.txt","r");
    FILE *intermediaire2=fopen("dicointer2.txt","a");
    for (int i=0;i<longueur_mot;i++)
    {
        current=tab[nb_essai+i];
        
        if (current.coloration==2)
        {
            right_place[index]=current.lettre;
            positions_rp[index]=current.place-1;
            index++;
            nb_here++;
            //printf("%s\n",not_here);
              
        }
    
    }
    if (nb_here==0)
    {
        int len=taillefichiertxt(intermediaire1);
        //printf("%d\n",len);
        rewind(intermediaire1);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(intermediaire1,j,longueur_mot+1,len);
            addintofile(intermediaire2,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            free(current_word);
        }
    }
    /*printf("%s\n",right_place);
    for (int i=0;i<index;i++)
    {
        printf("%d\n",positions_rp[i]);
    }*/
    else{
        int len=taillefichiertxt(intermediaire1);
        //printf("%d\n",len);
        rewind(intermediaire1);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(intermediaire1,j,longueur_mot+1,len);
            if (acetteplace(right_place,current_word,positions_rp,index)==true)
            {
                //printf("%s\n",current_word);
                addintofile(intermediaire2,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            }
            free(current_word);
        }
    
    }
    
    fclose(intermediaire1);
    

}

void coloration1(element tab[30],int nb_essai, int longueur_mot)
{
   
    char wrong_place[10];
    int positions_wp[10];
    int index=0;
    int nb_notexactly=0;
    element current;
    FILE *intermediaire2=fopen("dicointer2.txt","r");
    char *list_dico[7]={"texte/dict.txt","texte/dico1.txt","texte/dico2.txt","texte/dico3.txt","texte/dico4.txt","texte/dico5.txt","texte/dico6.txt"};
    FILE *dico=fopen(list_dico[nb_essai+1],"a");
    for (int i=0;i<longueur_mot;i++)
    {
        current=tab[nb_essai+i];
        
        if (current.coloration==1)
        {
            wrong_place[index]=current.lettre;
            positions_wp[index]=current.place-1;
            index++;
            nb_notexactly++;
            //printf("%s\n",not_here);
              
        }
    
    }

    if (nb_notexactly==0)
    {
        int len=taillefichiertxt(intermediaire2);
        rewind(intermediaire2);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(intermediaire2,j,longueur_mot+1,len);
    
            printf("%s\n",current_word);
            addintofile(dico,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
     
            free(current_word);
        }
    }
    else{
        int len=taillefichiertxt(intermediaire2);
        rewind(intermediaire2);
        for (int j=0;j<len;j++)
        {
            char *current_word=contentofline(intermediaire2,j,longueur_mot+1,len);
            if (containsexceptposition(current_word, wrong_place, positions_wp,index,longueur_mot)==true)
            {
                //printf("jesuisla");
                addintofile(dico,current_word);//faire une fonction pour écrire dans un nouveau dico, on écrit dans intermédiaire1
            }
            free(current_word);
        }
    }

    fclose(dico);
    fclose(intermediaire2);
}

void dico(element tab[30], int nb_essai, int longueur_mot)
{
    printf("debut dict\n");
    coloration0(tab, nb_essai,longueur_mot);
    coloration2(tab, nb_essai,longueur_mot);
    coloration1(tab, nb_essai,longueur_mot);
    printf("Fin dict\n");
}


