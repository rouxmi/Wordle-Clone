#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "includes/mot.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define FILENAME_SIZE 7048
#define MAX_LINE 7048

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
bool containsexceptposition(char* mot,char lettre,char *color,int position)
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

void str_slice(const char * str, char * word_coupe, size_t start, size_t end)
{
    
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        word_coupe[j++] = str[i];
    }
    word_coupe[j] = 0;
 
}



bool mot_valid(char* color, char* mot_donne, char* mot_a_test,int longueur_mot)
{
    bool mot_possible=true;
    for (int j=0;j<longueur_mot;j++){
            int colorj=0;
            char cj=color[j];
            sscanf(&cj, "%d", &colorj);
            if (colorj==2)
            {
                if (!acetteplace(mot_donne[j],mot_a_test,j+1)){
                    mot_possible=false;
                }
                
            }
            else{if (colorj==0){
                    int nb_pos2=0;
                    int nb_pos=0;
                    for (int g=0;g<longueur_mot;g++){
                        int colorg=0;
                        char cg=color[g];
                        sscanf(&cg, "%d", &colorg);
                        if (mot_donne[g]==mot_donne[j] && colorg!=0){
                            nb_pos++;
                        }
                    }
                    for (int h=0;h<longueur_mot;h++){
                        if (mot_a_test[h]==mot_donne[j]){
                            nb_pos2++;
                        }
                    }
                    if (nb_pos!=nb_pos2){
                        mot_possible=false;

                    }
                }   
                else{if (colorj==1){
                    if (!containsexceptposition(mot_a_test,mot_donne[j],color,j+1)){
                        mot_possible=false;
                    }
                }
                
            }  
        }
        }
    return mot_possible;

        
        
    }

