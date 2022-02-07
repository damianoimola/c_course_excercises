#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *f(char *s1, char *s2){
	int maxlen = 0;
	if(strlen(s1)>strlen(s2)){
		maxlen = strlen(s2);
	} else {
		maxlen = strlen(s1);
	}

	char *comm = malloc(maxlen);
	if(!comm){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation.\n");
		exit(1);
	}


	for(int i=0; i<maxlen; i++){
		if(s1[i] == s2[i]){
			comm[i] = s1[i];
		} else{
			return comm;
		}
	}
	return comm;
}

char *f2(int n){
	int maxlen = 0;
	if(strlen(s1)>strlen(s2)){
		maxlen = strlen(s2);
	} else {
		maxlen = strlen(s1);
	}

	char *comm = malloc(maxlen);
	if(!comm){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation.\n");
		exit(1);
	}

	int counter = 0;
	while(*s1 && *s2){
		if(*s1 == *s2){
			printf("carattere: %c\n", *s1);
			*(comm++) = *(s1++);
			s2++;
			counter++;
		}else{
			s1++;
			s2++;
		}
	}
	*comm = '\0'; // imposto il terminatore di strigna
	comm-=counter; // reimposto il puntatore a carattere
	return comm;
}

int main(void){
	char *s1 = "dipartita";
	char *s2 = "dipartimento";
	printf("Il prefisso più lungo e': %s\n", f(s1, s2));
	return 0;
}
