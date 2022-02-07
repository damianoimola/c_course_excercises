#include <stdio.h>
#include <stdlib.h>




int func(int n){
	int sum = 0;
	for(int i=1; i<=n; i++){
		sum += i*i;
	}
	return sum;
}



int main(void){
	printf("La somma dei primi n quadrati e': %d\n",func(10));
	return 0;
}
