#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct round{
	char *word;
	int len;
	int premium;
	int toguess;
}

#define DEFAULT_LIVES 3
#define DEFAULT_ROUNDS 10;
#define MAX_W_LEN 64


int lives = 0;
int words = 0;
int corrects = 0;


struct round *get_rounds(char *path){
	FILE *file;

	if(!(file = fopen(file, "r+"))){
		puts(" ");
		exit(1);
	}

	int index = 0, size = DEFAULT_ROUNDS;
	struct round *rounds = malloc(sizeof(*rounds) * size);
	char *str;
	while(fgets(str, MAX_W_LEN, file)){
		if(index >= size){
			rounds = realloc(rounds, size*=2);
			if(!rounds){
				puts("something bas has happend");
				exit(1);
			}
		}
		char *word = strtok(str, ";");
		rounds[index]->word = word;
		rounds[index]->len = strlen(word);
		rounds[index]->premium = strtok(NULL, ";");
		index++;
	}
}


void display_hint(struct round *round){
	for(int i=0; i<round->len; i++){
		char c = round->word[i];
		if(isupper(c)){
			printf("%c", c);
		} else {
			printf("_");
			(*round).togess++;
		}
	}
	puts(" ");
}

void display_char(struct round *round, char inserted){
	bool guessed = false;
	for(int i=0; i<round->len; i++){
		char c = round->word[i];
		if(isupper(c)){
			printf("%c", c);
		} else if (toupper(inserted) == toupper(c)){
			guessed = true;
			printf("%c", toupper(c));
		} else {
			printf("_");
			(*rounds).toguess--;
		}
	}
	puts(" ");

	if(toguess == 0){
		return 2;
	}

	return (int) guessed;
}




char get_char(){
	char *c;
	fgets(c, 1, stdin);
	return c[0];
}

void handle_lives(int premium, int res){
	if(res == 0){
		lives--;
	} else if(res == 2){
		lives += premium;
		corrects++;
	}
}

int main(int argc, char *argv[]){
	if(argc<2){
		puts("Usage: ..");
		exit(1);
	}


	struct round *rounds = get_rounds(argv[1]);

	for(int i=0; i<words; i++){
		display_hint(rounds[i]);
		int res;
		while(lives != 0 && res != 2){
			char c = get_char();
			// 0 = non corretto
			// 1 = corretto
			// 2 = completo
			res = display_char(rounds[i], c);
			handle_lives(rounds[i]->premium, res);
		}
	}
}
