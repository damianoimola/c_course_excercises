#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int n);

int main(int argc, char *argv[]){
	if(argc<2){
		fprintf(stderr, "Too few arguments, provide a valid input number\n");
		exit(1);
	}
	int number = atoi(argv[1]);
	printf("il valore di f(%d) e' %d\n", number, f(number));
}

int f(int n){
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(sum+(i*i) > INT_MAX){
			fprintf(stderr, "Integer becomes too large to be handled\n");
			exit(1);
		}
		sum+=(i*i);
	}
	return sum;
	//return n*(n+1)*(2*n+1)/6;
}
