#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





char *func(int n){
	size_t nlen = log10(n)+2;
	char *str = malloc(nlen);
	sprintf(str, "%d", n);
	puts(str);

	char *rev = malloc(nlen);
	for(int i=1; i<nlen; i++){
		// se avessimo messo i=0, come primo carattere avremmo copiato
		// il terminatore di stringa '\0', così facendo, avremmo avuto
		// una stringa che inizia per '\0' e continua, ma in questo caso
		// la printf in stampa avrebbe ignorato tutto il resto dopo '\0'
		// ovvero il primo carattere, così non stampava nulla
		printf("iterazione %d, carattere %c\n", i, *(str+(nlen-1-i)));
		//*(rev + i-1) = *(str+(nlen-1-i));
		rev[i-1] = str[nlen-1-i];
	}
	rev[nlen-1] = '\0';
	free(str);
	return rev;
}

char *func2(int n){
	// arrotondamento + termiantore
	size_t len = log10(n)+2;
	char *str = malloc(len);
	sprintf(str, "%d", n);

	char *rev = malloc(len);
	rev += len-1; // mi posiziono all'ultimo carattere
	*rev = '\0';

	while(*str)
		*(--rev) = *(str++);

	return rev;
}



int main(void){
	int n = 12345;
	char *res = func(n);
	printf("\nIl numero in stringa e': %s\n", res);
}
