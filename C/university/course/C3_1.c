#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int c3_1(int m, int n, int A[m][n], int B[m][n]);

int main(int argc, char * argv[]){
	int m = 4;
	int n = 3;
	
	int A[4][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12}
	};

	int B[3][4] = {
		{1,4,7,10},
		{2,5,8,11},
		{3,6,9,12}
	};

	int C[3][4] = {
		{1,1,1,1},
		{2,5,8,11},
		{0,0,0,0}
	};

	int res1 = c3_1(m, n, A, B);

	puts("Tra A e B");
	printf(res1 == 0 ? "Non esiste\n\n" : "Esiste\n\n");

	int res2 = c3_1(m, n, A, C);
	puts("Tra A e C");
	printf(res2 == 0 ? "Non esiste\n\n" : "Esiste\n\n");
	return 0;
}





int * get_col(int m, int n, int M[n][m], int index){
	// we should loop through rows (n)
	// and store row-num (n) integers
	int * retcol = (int *) malloc(n * sizeof(int));
	
	if(!retcol){
		// manage error
	}

	for(int i=0; i<n; i++){
		retcol[i] = M[i][index];
	}
	return retcol;
}

int * get_row(int m, int n, int M[m][n], int index){
	// we should loop through cols (n)
	// and stor col-num (n) values
	int * retrow = (int *) malloc(n * sizeof(int));

	if(!retrow){
		// manage error
	}

	for(int i=0; i<n; i++){
		retrow[i] = M[index][i];
	}
	return retrow;
}


int check(int m, int n, int A[m][n], int B[n][m], int index){
	int * row = get_row(m, n, A, index);
	int * col = get_col(m, n, B, index);
	
	// looping through entries
	for(int i=0; i<n; i++){
		if(row[i] != col[i]){
			return 0;
		}
	}
	return 1;
}

int c3_1(int m, int n, int A[m][n], int B[n][m]){
	// looping through row and col
	for(int i=0; i<m; i++){
		if(!check(m, n, A, B, i)){
			return 0;
		}
	}

	return 1;
}






// service funcion
// prints array
void prnt(int m, int * arr){
	for(int i=0; i<m; i++){
		printf("%d, ", arr[i]);
	}
	printf("\b\b\n");
}





// alternative c3_1 func
// 'c3_1' and 'check' function together
// NOT TESTED
int c3_1_bis(int m, int n, int A[m][n], int B[n][m]){
	for(int i=0; i<m; i++){
		int * row = get_row(m, n, A, i);
		int * col = get_col(m, n, B, i);

		for(int j=0; j<n; j++){
			if(row[i] != col[i]){
				return 0;
			}
		}
	}
	return 1;
}

