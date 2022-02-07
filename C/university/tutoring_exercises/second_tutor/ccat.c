#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ccat(char *path);

int main(int argn, char *argc[]){
	if(argn < 2){
		fprintf(stderr, "USAGE: TODO");
		exit(EXIT_FAILURE);
	}

	ccat(argc[1]);
}


void ccat(char *path){
	FILE *file;

	if(!(file = fopen(path, "r+"))){
		fprintf(stderr, "Oops, something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}

	char c;
	while((c = fgetc(file)) != EOF){
		printf("%c", c);
	}

	fclose(file);
}

