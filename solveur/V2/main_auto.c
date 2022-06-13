#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include "includes/graph.h"
#include <time.h>
//doit dépendre du dict
#define nb_essais 15
#define FILENAME_SIZE 1024
#define MAX_LINE 7048



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




char* coloration(char * mot_a_test,char * mot_a_dev,int size_mot){	
	char* copy_test=malloc(sizeof(char)*(size_mot+2));
	char* copy_dev=malloc(sizeof(char)*(size_mot+2));
	strcpy(copy_test, mot_a_test);
	strcpy(copy_dev, mot_a_dev);
    if (strlen(copy_dev) == strlen(copy_test)) {
		int i, n = strlen(mot_a_test);

		int ix;
		char *ptr;
		//on copie la liste pour enlever les caractères
		//pour gérer les lettres doubles
		
		char* res=malloc(sizeof(char)*(size_mot+1));
		res[size_mot] = 0;
		//les positions correctes
		for (i = 0; i < n; ++i) {
			if (mot_a_test[i] == copy_dev[i]) {
				copy_dev[i] = '\v';
				res[i] = '2';
        	}
			else{
				res[i]='0';
			}
		}
		for (i = 0; i < n; ++i) {
			if ((ptr = strchr(copy_dev, mot_a_test[i])) != NULL && res[i]!='2') {
				ix = ptr - copy_dev;
				copy_dev[ix] = '\v';
				res[i] = '1';
        	}
			
		}
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



void solvauto() {

	FILE *fichier=fopen("../texte/wsolf.txt","r");
    char* longueur_mot=contentofline(fichier);
    fclose(fichier);
    //printf("%s \n",longueur_mot);
    int len_mot=strtol(longueur_mot,NULL,10);
    //printf("%d \n",longueur);
    free(longueur_mot);
	rewind(fichier);
	for (int g=0;g<20;g++){
		for (int t=5;t<6;t++){
			clock_t debuttime;
    		debuttime = clock();
			len_mot=t;
			
			int essai_vict[nb_essais];
			for (int f=0;f<nb_essais;f++){
				essai_vict[f]=0;
			}
			int compt_victoire=0;
			FILE* ptr;
			char word_dev[len_mot + 1];
			char len_motstr[5];
			sprintf( len_motstr, "%d", len_mot);
			char txt[7]=".txt";
			char dicoauto[100]="../texte/Dictionnaire/dictauto";;
			char* namedictauto=malloc(sizeof("../texte/Dictionnaire/dictauto20.txt"));
			strcpy(namedictauto,dicoauto);
			strcat(namedictauto, len_motstr);
			strcat(namedictauto, txt);
			ptr = fopen(namedictauto, "r");	

			
			int tailledict;
			tailledict=taillefichiertxt(ptr);
			rewind(ptr);
			if (NULL == ptr) {
				printf("file can't be opened \n");
			}
			srand( time( NULL ) );
			free(namedictauto);
			for (int j=0;j<tailledict;j++){

				//cherche le prochain mot à faire deviner
				char* copy_word=contentofline(ptr);
				str_slice(copy_word, word_dev, 0, len_mot-1);
				free(copy_word);
				printf("word dev:%s\n",word_dev);
                node* n;
                node* n2=node_create(0);
                
				//va chercher le dict
                int taille_futur;
				int i=0;
				while(i<nb_essais){
                    if (i==0){
                        char* dico_mot=get_dict_name(t);
						FILE* f=fopen(dico_mot,"r");
						n=node_add_all_words(dico_mot,t);
						rewind(f);
						taille_futur=taillefichiertxt(f);
						//free(dico_mot);
						fclose(f);
                    }
                    else{
                        n=n2;
                        n2 = node_create(0);
                    }
					char* mot_test = malloc(sizeof(char)*t);
                    mot_test=node_best_word(n).mot;

                    char oui[t+2];
                    char l='2';
                    for (int r=0;r<t;r++){
                        oui[r]=l;
                    }
                    oui[t]=0;
                    

                                
					//colore le mot donnée
					char* color=malloc(sizeof(char)*len_mot);
					color=coloration(mot_test,word_dev,len_mot);
					
					if (!strcmp(color,oui)){
						essai_vict[i]++;
						compt_victoire++;
						free(color);
						i=nb_essais;

					}
					else{
                    	taille_futur=make_new_graph(n2,n,color,mot_test,taille_futur);
						free(color);
					}
					free(mot_test);
					i++;
				}
				//met à jour avec la coloration
            
			
			
			}
			fclose(ptr);
			int sum=0;
			float moyenne=0;
			FILE *fp = fopen("../texte/stats3.txt", "a");
			if (fp == NULL)
			{
				printf("Error opening the file %s", "stat.txt");
			}
			printf("test n°%d sur les mot de longeur:%d\n",g+1,t);
			char temps[200];
			sprintf( temps, "test n°%d sur les mot de longeur:%d\n",g+1,t);
			fputs(temps,fp);
			for (int i=0;i<nb_essais+1;i++){
				if (i==nb_essais){
					printf("nombre de mot non trouvé: %d\n",tailledict-sum);
					char temps2[200];
					sprintf( temps2, "nombre de mot non trouvé: %d\n",tailledict-sum);
					fputs(temps2,fp);
					printf("moyenne d'essais:%f\n",moyenne/tailledict);
					char temps3[200];
					sprintf( temps3, "moyenne d'essais:%f\n",moyenne/tailledict);
					fputs(temps3,fp);
					printf("%d\n",compt_victoire);
					char temps4[200];
					sprintf( temps4,"%d\n",compt_victoire);
					fputs(temps4,fp);
					debuttime = clock() - debuttime;
					double time_taken = ((double)debuttime)/CLOCKS_PER_SEC; // in seconds
					char temps6[200];
					sprintf( temps6,"test sur le tout le dico de cette taille en %f secondes\n", time_taken);
					fputs(temps6,fp);
					printf("test sur le tout le dico de cette taille en %f secondes\n", time_taken);
				}
				else{
					moyenne=moyenne+(essai_vict[i]*(i+1));
					sum=sum+essai_vict[i];	
					printf("nombre de mot trouvé à l'essai n°%d:%d\n",i+1,essai_vict[i]);
					char temps5[200]	;
					sprintf( temps5,"nombre de mot trouvé à l'essai n°%d:%d\n",i+1,essai_vict[i]);
					fputs(temps5,fp);
					
				}
                
            
			}
			fclose(fp);
        
			
		}
		
	}
}

int main(){
	solvauto();
}
	
	
    
    
    
    
    
	/*
    FILE *fp;

    char buff2[255];

    fp = fopen("texte/stats.txt", "rw");
    fgets(buff2, 255, (FILE*)fp);
    printf("%s\n",buff2);
    if (strcmp(buff2,"Stats du solveur V1")==1){
        fputs("Stats du solveur V1\n", fp);
    };
    fclose(fp);
	*/

    


