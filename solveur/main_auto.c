#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "whichWord.h"
#include "dictionnaire.h"
//doit dépendre du dict
#define len_mot 5
#define FILENAME_SIZE 1024
#define MAX_LINE 7048
#define nbessais 5


int lettrepos(const char * str, char lettre) {
	int i = 0;
	if (str != NULL) {
		while (str[i]) {
			if (str[i] == lettre) {
				return i;
			}
			++i;
		}
	}
	return -1;
}


char* coloration(const char * mot_a_test,const char * mot_a_dev){
	printf("ok\n");
	char* copy_test=malloc(sizeof(char)*(len_mot+2));
	char* copy_dev=malloc(sizeof(char)*(len_mot+2));
	strcpy(copy_test, mot_a_test);
	strcpy(copy_dev, mot_a_dev);
    printf("%s,%s\n",mot_a_dev,mot_a_test);	
	printf("%lu,%lu\n",strlen(copy_dev),strlen(copy_test));
    if (strlen(copy_dev) == strlen(copy_test)) {
		int i = 0;
		int pos = -1;
		//on copie la liste pour enlever les caractères
		//pour gérer les lettres doubles
		
		char* res=malloc(sizeof(char)*(len_mot+1));
		res[len_mot] = 0;
		//les positions correctes
		while (copy_test[i]) {
			if (copy_test[i] == copy_dev[i]) {
				//lettre bonne et à la bonne place
				res[i] = '2';
				copy_test[i] = '_';
			} else {
				//on met des zéros partout ailleurs
				res[i] = '0';
			}
			++i;
		}
		i = 0;
		while (copy_test[i]) {
			pos = lettrepos(copy_test, copy_dev[i]);
			//la lettre doit exister mais ne dois pas remplacer un bon choix
			if (pos >= 0 && res[i] != '2') {
				//lettre trouver mais position fausse
				res[i] = '1';
				copy_test[pos] = '_';
			}
			++i;
		}
		printf("%s\n", res);
		char* result=res;
		free(copy_dev);
		free(copy_test);
		return result;
	}
	free(copy_dev);
	free(copy_test);
	char* result="00000";
	return result;
}

void str_slice(const char * str, char * word_coupe, size_t start, size_t end)
{
    
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        word_coupe[j++] = str[i];
    }
    word_coupe[j] = 0;
 
}

int main() {
    
    FILE* ptr;
    char word_dev[len_mot + 1];
	char word_test[len_mot + 1];
    ptr = fopen("texte/dictauto.txt", "a+");

	
	int tailledict;
	tailledict=taillefichiertxt(ptr);
	rewind(ptr);
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
	element  T[size*nbessais] ;
	srand( time( NULL ) );
    for (int j=0;j<tailledict-1;j++){
		printf("Début nouveau nouveau à deviner\n");

		//cherche le prochain mot à faire deviner
		char* copy_word=contentofline(ptr,j,len_mot+1,tailledict);
		char* word;
		printf("%s\n",copy_word);
        str_slice(copy_word, word_dev, 0, len_mot-1);
		free(copy_word);
		//va chercher le dict
		for (int i=0;i<6;i++){
			if (i>=1){
				printf("Mise a jour dico\n");
				print_tableau(T);
				dico(T,i-1,len_mot);
			}
			char istr[5];
			sprintf( istr, "%d", i);
			char txt[7]=".txt";
			char dico[100]="texte/dico";
			char* name=malloc(sizeof("texte/dico6.txt"));
			strcpy(name,dico);
			strcat(name, istr);
			strcat(name, txt);
			printf("filename: %s\n",name);

			//va chercher un mot random
			
			word=randomInFile(name);
			str_slice(word,word_test,0, len_mot-1);
			printf("mot a dev: %s\n",word_dev);
			free(name);
		
			//colore le mot donnée
			char* color;
			printf("mot a test: %s\n",word_test);
			color=coloration(word_test,word_dev);
			printf("%s\n",color);
			ajout_mot(word_test,i,T,color,len_mot);
			free(color);
			if (i<=1){
				remove("dicointer1.txt");
				remove("dicointer2.txt");
			}
		}
		//met à jour avec la coloration
    }
	fclose(ptr);
 
    
    
    
    
    

    FILE *fp;

    char buff2[255];

    fp = fopen("texte/stats.txt", "rw");
    fgets(buff2, 255, (FILE*)fp);
    printf("%s\n",buff2);
    if (strcmp(buff2,"Stats du solveur V1")==1){
        fputs("Stats du solveur V1\n", fp);
    };
    fclose(fp);

    return 0;

}
