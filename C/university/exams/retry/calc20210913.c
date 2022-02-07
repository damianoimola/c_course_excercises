#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct listelem {
	char *word;
	int counter;
};
typedef struct listelem elem_t;



void count(char *fpath, char *ifpath);
bool is_inside(char *word, char **iwlst, int iwcounter);
void add_or_increment(char *word, elem_t *mat, int len);
void print_list(int len, elem_t list[len]);

	
	
int main(int argn, char *argc[]){
	if(argn<3){
		fprintf(stderr, "USAGE: %s <text_file>.txt <ignore_file>.txt\n", argc[0]);
		exit(EXIT_FAILURE);
	}

	count(argc[1], argc[2]);
	return 0;
}


#define DEF_MAX_LEN_W 64
#define DEF_MAX_NUM_W 64

void count(char *fpath, char *ifpath){
	int maxlenw = DEF_MAX_LEN_W;
	int maxnumw = DEF_MAX_NUM_W;

	FILE *file;
	if(!(file = fopen(fpath, "r+"))){
		fprintf(stderr, "Oops, something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}

	FILE *ignore;
	if(!(ignore = fopen(ifpath, "r+"))){
		fprintf(stderr, "Oops, something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}
	

	// ignore word list
	char **iwlst = malloc(sizeof(*iwlst)*maxnumw);
	for(int i=0; i<maxnumw; i++){
		iwlst[i] = malloc(sizeof(**iwlst)*maxlenw);
	}


	if(fseek(ignore, 0L, SEEK_END) == -1){
		fprintf(stderr, "Oops, failed to file seek.\n");
		exit(EXIT_FAILURE);
	}
	int iflen = ftell(ignore);
	rewind(ignore);
	int iindex = 0;
	char itext[iflen];
       	fgets(itext, iflen, ignore);
	itext[iflen]='\0';
	printf("IGNORE:\n %s\n", itext);

	char *iw = strtok(itext, " ");
	while(iw != NULL){
		iwlst[iindex++] = iw;
		iw = strtok(NULL, " ");
	}




	// word list
	char **wlst = malloc(sizeof(*wlst)*maxnumw);
	for(int i=0; i<maxnumw; i++){
		wlst[i] = malloc(sizeof(**wlst)*maxlenw);
	}

	if(fseek(file, 0L, SEEK_END) == -1){
		fprintf(stderr, "Oops, failed to file seek.\n");
		exit(EXIT_FAILURE);
	}
	int flen = ftell(file);
	rewind(file);
	int index = 0;
	char text[flen+1];
       	fgets(text, flen, file);
	text[flen]='\0';
	printf("FILE:\n %s\n", text);

	char *w = strtok(text, " ");
	while(w != NULL){
		wlst[index++] = w;
		w = strtok(NULL, " ");
	}
	// realloc(wlst, index);



	// word list
	elem_t *retmat = calloc(maxnumw, sizeof(*retmat));


	// POSSO CONTINUARE CON IL PROGRAMMA VERO E PROPRIO
	for(int i=0; i<index; i++){
		char *word = wlst[i];
		if(!is_inside(word, iwlst, iindex)){
			add_or_increment(word, retmat, maxnumw);
		}
	}

	print_list(maxnumw, retmat);

	free(retmat);
//	for(int i=0; i<maxnumw; i++){
//		free(iwlst[i]);
//		free(wlst[i]);
//	}
//	free(iwlst);
//	free(wlst);
}





void print_list(int len, elem_t list[len]){
	for(int i=0; i<len; i++){
		printf("\t %s:%d\n", list[i].word, list[i].counter);
	}
}



bool is_inside(char *word, char **iwlst, int iindex){
	for(int i=0; i<iindex; i++){
		if((strcmp(word, iwlst[i])) == 0) return true;
	}
	return false;
}



void add_or_increment(char *word, elem_t *mat, int len){
	bool incremented = false;
	int lastindex = 0;
	elem_t *current = mat;
	
	for(int i=0; i<len; i++){
		if(current[i].word){
			if(strcmp(word, current[i].word) == 0){
				mat[i].counter+=1;
				incremented = true;
			}
			lastindex = i+1;
		} else break;
	}

	if(!incremented){
		mat[lastindex].word = word;
		mat[lastindex].counter = 1;
	}
}
