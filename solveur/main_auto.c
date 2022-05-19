#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//booléen basique 
#define bool int
#define false (0)
#define true (!false)
//doit dépendre du dict
#define len_mot 5


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

bool coloration(char * mot_a_test,const char * mot_a_dev){
    printf("%s,%s\n",mot_a_dev,mot_a_test);
    if (strlen(mot_a_dev) == strlen(mot_a_test)) {
		int i = 0;
		int pos = -1;
		//on copie la liste pour enlever les caractères
		//pour gérer les lettres doubles
		char copy[len_mot + 1];
		char result[len_mot + 1];
		result[len_mot] = 0;
		strcpy(copy, mot_a_test);
		//les positions correctes
		while (copy[i]) {
			if (copy[i] == mot_a_dev[i]) {
				//lettre bonne et à la bonne place
				result[i] = '2';
				copy[i] = '_';
			} else {
				//on met des zéros partout ailleurs
				result[i] = '0';
			}
			++i;
		}
		i = 0;
		while (copy[i]) {
			pos = lettrepos(copy, mot_a_dev[i]);
			//la lettre doit exister mais ne dois pas remplacer un bon choix
			if (pos >= 0 && result[i] != '2') {
				//lettre trouver mais position fausse
				result[i] = '1';
				copy[pos] = '_';
			}
			++i;
		}
		printf("%s\n", result);
		return true;
	}
	return false;
}

char * str_slice(const char * str, char * word_coupe, size_t start, size_t end)
{
    
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        word_coupe[j++] = str[i];
    }
    word_coupe[j] = 0;
 
}

int main() {
    
    FILE* ptr;
    char word[50];
    char word_coupe[len_mot + 1];
    ptr = fopen("texte/dict.txt", "a+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    while (fgets(word, 50, ptr) != NULL) {
        str_slice(word, word_coupe, 0, len_mot-1);
        bool y=coloration("terre",word_coupe);
        printf("%d\n",y);
    }
 
    fclose(ptr);
    
    
    
    

    FILE *fp;

    char buff2[255];

    fp = fopen("texte/stats.txt", "rw");
    fgets(buff2, 255, (FILE*)fp);
    printf("%s\n",buff2);
    if ((char *)buff2==(char *)"Stats du solveur V1"){
        fputs("Stats du solveur V1\n", fp);
    };
    fclose(fp);

    return 0;

}
