#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

char *conversione(int number);
int abs(int number);

int main(int argc, char *argv[]){
	if(argc<2){
		fprintf(stderr, "Provide a valid input number\n");
		exit(1);
	}
	int number = atoi(argv[1]);
	char *stringa = conversione(number);
	printf("INPUT: %d\nOUTPUT: %s\n", number, stringa);
	return 0;
}

char *conversione(int number){
	int counter = 0;
	// returns the lenght of the number in bytes (includes the '\0')
	size_t len = snprintf(NULL, 0, "%d", number) + 1;
	char *strnumb = malloc(len);

	if(number<0){
		strnumb[0] = '-';
		counter += 1;
	}

	int absn = abs(number);
	while(absn>0){
		int remainder = absn%10;
		absn /= 10;
		sprintf(&(strnumb[counter]), "%d", remainder);
		counter += 1;
	}

	return strnumb;
}

int abs(int number){
	if(number>0){
		return number;
	} else {
		return -number;
	}
}
