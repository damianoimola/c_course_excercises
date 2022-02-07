#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_odd(int *v, int n);


int elementi = 10;

int main(void){
	int *v = malloc(sizeof(*v)*elementi);	
	for(int i=0; i<elementi; i++){
		v[i]=i;
	}

	remove_odd(v, elementi);
	puts("VEETTORE");
	for(int i=0; i<elementi; i++){
		printf("%d, ", v[i]);
	}
	puts(" ");
	return 0;
}


void remove_odd(int *v, int n){
	// sovradimensionato
	int *indexes = malloc(sizeof(*indexes)*n);
	int counter=0;
	for(int i=0; i<n; i++){
		if(v[i]%2 != 0){
			elementi--;
			indexes[counter++]=i;
		}
	}
	puts("INDICI");
	for(int i=0; i<counter; i++){
		printf("%d, ", indexes[i]);
	}
	puts(" ");

	int deleted = 0;
	for(int i=0; i<counter; i++){
		char *from = (char *)v+((indexes[i]+1-deleted)*4);
		char *to = from - 4;
		size_t size = (n - (v[i]+1))*4;
		memmove(to, from, size);
		deleted++;
	}

}


