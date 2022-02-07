#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void){
	char *T = "";
	char *P = "";
	int lenT = strlen(T);
	int lenP = strlen(P);

	int res = conta(T, lent, P, lenP);
	printf();
	return;
}


int conta(char *T, int lenT, char *P, int lenP){
	int counter = 0;
	if(lenT<lenP){
		fprintf("Non va bene");
		exit(1);
	}
	for(int i=0; i<lenT-lenP; i++){
		if(T[i]!=P[i]){
			continue;
		}

		for(int j=i; j<i+lenP; j++){
			if(T[i]!=P[i]){
				counter -=1;
				break;
			}
		}
		counter+=1;
	}
	return counter;
}
