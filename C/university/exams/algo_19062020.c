#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void){
	char *s = "941538723547796";
	int res = conta(s);
	printf("%d\n", res);
	return 0;
}



int conta(char *str, int k){
	int len = strlen(str);
	int counter = 0;
	for(int i=0; i<len; i++){
		counter += check(str, i, k);
	}
	return counter;
}

int check(char *str, int i, int k){
	int len = strlen(str);
	for(int j=0; j<
}
