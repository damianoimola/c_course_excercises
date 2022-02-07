#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fold(char *fpath, int width);

#define DEFAULT_LINE_LEN 80

int main(int argn, char *argc[]){
	if(argn<2){
		fprintf(stdout, "USAGE: ./%s -w <line_len> -f <file_name>.\n", argc[0]);
		exit(EXIT_FAILURE);
	}

	int width = DEFAULT_LINE_LEN;
	char *fpath;
	
	for(int i=1; i<argn; i++){
		if(strcmp(argc[i], "-w") == 0){
			width = atoi(argc[i+1]);
		}
		else if(strcmp(argc[i], "-f") == 0){
			fpath = argc[i+1];
		}
	}

	fold(fpath, width);

	return 0;
}


void fold(char *fpath, int width){
	FILE *file;
	if(!(file = fopen(fpath, "r"))){
		fprintf(stdout, "Oops, something went wrong with file opening.\n");
		exit(EXIT_FAILURE);
	}

	char c, *out = malloc(sizeof(*out)*width); // sovradim.
	int counter = 0, len = width;
	while((c = fgetc(file)) != EOF){
		out[counter++] = c;

		if(c == '\n' || c == EOF || c == '\0' || c == ' '){
			if(counter >= width){
				out[counter] = '\0';
				counter = 0;
				fprintf(stdout, "%s\n", out);
				free(out);
				out = malloc(sizeof(*out)*width);
				len = width;
			}
		} else if(counter>=width) {
			out = realloc(out, len*=2);
		}
	}
	free(out);
	fclose(file);
}
