#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "dictionnaire.h"
#include "tableau.h"
#include <string.h>
#include <stdbool.h>

int taillefichiertxt ()
{
    int compteur=1;
    FILE *f=fopen("test.txt","rt");
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
bool contains(char *pasceslettres , char* mot) //cette fonction sert à trier les mots contenant les lettres qui ont la valeur 0 lors de la coloration, pasceslettres est une chaine contenant ces caractères 
{
    char *sontpresents;
    assert(mot!=NULL);
    {
        sontpresents = strpbrk(mot,pasceslettres);
        if (sontpresents==NULL)
        { 
            return false;
        }
        else 
        {
            return true;
        }
    }

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

//bool dico(char x, int taillefichier)//pour un mot de longueur 5 taillemot=6
//{
    //FILE *f;
    //FILE *n;
    //char c; 
    //char* mot_actuel=(char *) malloc( taillemot );
    //f=fopen("test.txt","rt");
    //f=fopen("newdico.twt","w");
    
    //if(f != NULL){
        //for (int i=0; i<taillefichier;i++){
                //fgets(mot_actuel,taillemot,f);
                
            
        //}
    //fclose(f);
//}
