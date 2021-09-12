#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


/*
 *
 *  THIS FILE IS RUNNED AND COMPILED WITH GCC, NOT WITH VISUAL
 *  STUDIO C/C++ COMPILER (as all the rest of project)
 *  SO, COMPILE THIS WITH THE FOLLOWING COMMAND (VIM):
 *          gcc "%" -o <exec path>
 *  AND RUN IT WITH
 *          <exec path>
 *
 */



void c1_1();
void c1_2();
void c1_3();
void c1_4();
void c1_5();
void c1_6();


int main(int argn, char ** argv){
	c1_1();
	c1_2();
	c1_3();
	c1_4();
	c1_5();
	c1_6();
}



double c1_1_function(int x, int y){
	if (y != 0){
		return 2*x + floor(x/ (double)y);
	} else if (x > 5){
		return x*x + 5;
	} else {
		return x*x - x*10 + 10;
	}
}


void c1_1(){
	double res1, res2, res3;
	printf("--- C1_1 ------\n");
	res1 = c1_1_function(3,4);
	res2 = c1_1_function(7, 0);
	res3 = c1_1_function(2, 0);
	printf("%f; %f; %f\n", res1, res2, res3);
}






int c1_2_mcd(int a, int b){
	if (b>a){
		int tmp = a;
		a=b;
		b=tmp;
	}

	while(b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void c1_2(){
	double res1, res2, res3;
	printf("--- C1_2 ------\n");
	res1 = c1_2_mcd(3,4);
	res2 = c1_2_mcd(4, 8);
	res3 = c1_2_mcd(3, 0);
	printf("%f; %f; %f\n", res1, res2, res3);
}







void c1_3_fibo(int n, int arr[n]){
	assert(n>=2);

	arr[0] = 1;
	arr[1] = 1;

	for(int i=2; i<n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}

	for(int i=0; i<n; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int c1_3_fibo_rec(int n){
	assert(n>=2);

	if(n <= 2){
		return 1;
	} else {
		return c1_3_fibo_rec(n-1) + c1_3_fibo_rec(n-2);
	}
}

void c1_3(){
	int n1=3, n2=5, n3=7;
	int arr1[n1];
	int arr2[n2];
	int arr3[n3];

	printf("--- C1_3 ------\n");
	c1_3_fibo(n1, arr1);
	c1_3_fibo(n2, arr2);
	c1_3_fibo(n3, arr3);
}







int c1_4_verifica_ordinamento(int n, double arr[n]){
	for(int i=1; i<n; i++){
		if(arr[i-1]>arr[i]){
			return 0;
		}
	}
	return 1;
}

int c1_4_verifica_ordinamento_ric(int n, double arr[n]){
	int len = n-1;
	if(n==1){
		return 1;
	} else if(arr[len]<arr[len-1]) {
		return 0;
	} else {
		return c1_4_verifica_ordinamento_ric(n-1, arr);
	}
}

int c1_4_sequenza_ordinata(int n, double arr[n]){
	int counter = 0;
	int max_counter = 0;
	for (int i=0; i<n-1; i++){
		if(arr[i] < arr[i+1]){
			counter += 1;
			if(max_counter < counter){
				max_counter = counter;
			}
		} else {
			counter = 0;
		}
	}
	return max_counter;
}

void c1_4(){
	printf("--- C1_4 ------\n");
	int n = 9;
	double arr1[] = {1,2,3,4,5,6,7,8,9};
	double arr2[] = {1,2,3,4,5,6,7,8,7};
	double arr3[] = {1,2,3,4,5,3,4,1,6};

	
	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento(n, arr1));
	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento_ric(n, arr1));
	printf("Lunghezza sottosequenza piu' ordinata -->%d\n", c1_4_sequenza_ordinata(n, arr1));

	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento(n, arr2));
	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento_ric(n, arr2));
	printf("Lunghezza sottosequenza piu' ordinata -->%d\n", c1_4_sequenza_ordinata(n, arr2));
	
	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento(n, arr3));
	printf("La sequenza e' ordinata -->%d\n", c1_4_verifica_ordinamento_ric(n, arr3));
	printf("Lunghezza sottosequenza piu' ordinata -->%d\n", c1_4_sequenza_ordinata(n, arr3));
}







void c1_5_flip_array_halfs(int n, char * A){
	assert(n%2 == 0);

	char * res = (char*) malloc(n * sizeof(char));
	
	for(int i=0; i<n/2; i++){
		res[i] = A[n/2 + i];
		res[n/2 + i] = A[i];
	}

	// displaying result
	printf("L'array iniziale era -->:");
	for(int i=0; i<n; i++){
		printf("%c", A[i]);
	}

	printf("\nMentre dopo il flip, il risultato è -->:");
	for(int i=0; i<n; i++){
		printf("%c", res[i]);
	}
	printf("\n");
}

void c1_5(){
	printf("--- C1_5 ------\n");
	int n1 = 12;
	int n2 = 14;
	char * arr1 = "CIAO A TUTTI";
	char * arr2 = "AILATID'ITALIA";

	c1_5_flip_array_halfs(n1, arr1);
	c1_5_flip_array_halfs(n2, arr2);
}






int * c1_6_revert_rec(int n, int * arr){
	assert(n>0);
	int lastIndex = n-1;
	if (n == 1){
		return arr;
	} else {
		// tmp for the array without the last elem
		// rec_res is the result of recursion
		// ret_arr is the array to return
		int first = arr[lastIndex];
		int * tmp = (int*) malloc((n-1)*sizeof(int));
		
		for(int i=0; i<n-1; i++){
			tmp[i] = arr[i];
		}

		int * rec_res = (int*) malloc(n-1 * sizeof(int));
		rec_res = c1_6_revert_rec(n-1, tmp);
		
		int * ret_arr = (int*) malloc(n*sizeof(int));

		ret_arr[0] = first;
		for(int i=1; i<n; i++){
			ret_arr[i] = rec_res[i-1];
		}

		return ret_arr;
	}
}




void c1_6(){
	printf("--- C1_6 ------\n");
	int n1 = 5;
	int n2 = 10;
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {0,1,2,3,4,5,6,7,8,9};

	int * res1 = (int*) malloc(n1*sizeof(int));
	int * res2 = (int*) malloc(n2*sizeof(int));

	res1 = c1_6_revert_rec(n1, arr1);
	res2 = c1_6_revert_rec(n2, arr2);

	for(int i=0; i<n1; i++){
		printf("%d", res1[i]);
	}
	printf("\n");
	for(int i=0; i<n2; i++){
		printf("%d", res2[i]);
	}
	printf("\n");

}





