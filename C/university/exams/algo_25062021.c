#include <stdio.h>
#include <stdlib.h>

int main(int argn, char * argc[]){
	int v[7] = {1,2,3,2,4,1,3}
	int res = start(v, 7);
	fprintf(stdout, "Il risultato è %d\n", res)
	return 0;
}


int start(int *v, int n){
	int *dummy = malloc(sizeof(*dummy)*n);
	int counter = 0, start = 0, end = 0;
	for(int i=0; i<n; i++){
		int res = is_in(v[i], dummy);
		if(res != -1){
			start = res;
		}
		end++;
	}
}


