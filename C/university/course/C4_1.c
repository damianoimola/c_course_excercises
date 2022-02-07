#include <stdio.h>
#include <stdlib.h>


// pre-definition of functions
int c4_1(int m, int n, int A[m][n], int B[n][m]);
int * get_col(int m, int n, int M[n][m], int index);
int * get_row(int m, int n, int M[m][n], int index);
int * arrsum(int n, int * arr1, int * arr2);
int arrcmp(int n, int * arr1, int * arr2);
void arrprnt(int n, int * arr);





int main(int argc, char * argv[]){
	int n=3, m=4;
	int A1[4][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{10, 11, 12}
	};

	int B1[3][4] = {
		{1, 4, 7, 10},
		{2, 5, 8, 11},
		{3, 6, 9, 12}
	};

	int res1 = c4_1(m, n, A1, B1);
	printf("La prima matrice rispetta le condizioni? %s\n", res1 == 0 ? "No" : "Si");




	int A2[4][3] = {
		{2, 2, 2},
		{2, 2, 2},
		{2, 2, 2},
		{2, 2, 2}
	};

	int B2[3][4] = {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1}
	};

	int res2 = c4_1(m, n, A2, B2);
	printf("La prima matrice rispetta le condizioni? %s\n", res2 == 0 ? "No" : "Si");
}



// checks if exists at least one column in 'B' that
// is equals to the "row_index" row of matrix 'A'
int check_equality(int m, int n, int A[m][n], int B[n][m], int row_index){
	int * row = get_row(m, n, A, row_index);

	for(int i=0; i<m; i++){
		int * col = get_col(m, n, B, i);

		if(arrcmp(n, row, col)){
			return 1;
		}
	}
	return 0;
}



int check_col_sum(int m, int n, int A[m][n], int B[n][m], int row_index){
	int * row = get_row(m, n, A, row_index);

	for(int i=0; i<m-1; i++){
		for(int j=i+1; j<m; j++){
			int * col1 = get_col(m, n, B, i);
			int * col2 = get_col(m, n, B, j);
			int * sum = arrsum(n, col1, col2);

			if(arrcmp(n, row, sum)){
				return 1;
			}
		}
	}
	return 0;
}


// at least one of consitions
int c4_1(int m, int n, int A[m][n], int B[n][m]){
	for(int i=0; i<m; i++){
		int equality = check_equality(m, n, A, B, i);
		int sum = check_col_sum(m, n, A, B, i);

		if(!equality && !sum){
			return 0;
		}	
	}
	return 1;
}












int * get_row(int m, int n, int M[m][n], int index){
	int * row = (int *) malloc(n * sizeof(int));
	
	if(!row){
		// handle error
	}

	for(int i=0; i<n; i++){
		row[i] = M[index][i];
	}
	return row;
}

int * get_col(int m, int n, int M[n][m], int index){
	int * col = (int *) malloc(n * sizeof(int));

	if(!col){
		// handle error
	}

	for(int i=0; i<n; i++){
		col[i] = M[i][index];
	}
	return col;
}


int arrcmp(int n, int * arr1, int * arr2){
	for(int i=0; i<n; i++){
		if(arr1[i] != arr2[i]){
			return 0;
		}
	}
	return 1;
}

int * arrsum(int n, int * arr1, int * arr2){
	int * sum = (int *) malloc(n * sizeof(int));
	for(int i=0; i<n; i++){
		sum[i] = arr1[i] + arr2[i];
	}
	return sum;
}


void arrprnt(int n, int * arr){
	for(int i=0; i<n; i++){
		printf("%d, ", arr[i]);
	}
	printf("\b\b\n");
}








