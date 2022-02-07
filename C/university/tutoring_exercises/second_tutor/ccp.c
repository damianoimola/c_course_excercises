#include <stdio.h>
#include <stdlib.h>


void ccp(char *src, char *dest);

int main(int argn, char *argc[]){
	if(argn < 3){
		fprintf(stderr, "USAGE: ...");
		exit(EXIT_FAILURE);
	}

	ccp(argc[1], argc[2]);
	return 0;
}



void ccp(char *src, char *dest){
	FILE *source, *destination;

	if(!(source = fopen(src, "r+"))){
		fprintf(stderr, "Oops, ...");
		exit(EXIT_FAILURE);
	}


	if(!(destination = fopen(dest, "w+"))){
		fprintf(stderr, "Oops, ...");
		exit(EXIT_FAILURE);
	}
	char c;
	while((c = fgetc(source)) != EOF){
		fprintf(destination, "%c", c);
	}

	fclose(source);
	fclose(destination);
}
