#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


char *get_previous_directory();
void print_files(char *parent);


int main(int argn, char *argv[]){
	print_files(get_previous_directory());
	return 0;
}


char *get_previous_directory(){
	char cwd[FILENAME_MAX];
	// getting current working directory
	getcwd(cwd, sizeof(cwd));

	
	char *parent = malloc(128), 
	     *current = malloc(128),
	     *iterator = strtok(cwd, "/");
	while(iterator){
		strcat(parent, "/");
		current = iterator;
		if(iterator = strtok(NULL, "/")){
			strcat(parent, current);
		}
	}

	free(parent);
	free(iterator);

	return current;
}



void print_files(char *parent){
	char *tmp = malloc(128);
	strcpy(tmp, "../");
	strcat(tmp, parent);

	puts(tmp);

	/*
	 * TODO: You cant opening dir as a file
	 * you need a DIR data type
	 */
	FILE *dir;
	if(!(dir = fopen(tmp, "r+"))){
		fprintf(stderr, "Something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}

	char c;
	while((c = fgetc(dir)) != EOF){
		printf("%c", c);
	}
	fclose(dir);
	free(tmp);
}
