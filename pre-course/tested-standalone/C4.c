#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void c4_1();
void c4_2();
void c4_3();

int main(int argn, char ** argv){
	c4_1();
	c4_2();
	c4_3();
}

int * c4_1_get_col(int x, int y, int mat[x][y], int col_index){
	int * col = (int*) malloc(x * sizeof(int));
	for(int i=0; i<x; i++){
		col[i] = mat[i][col_index];
	}
	return col;
}

int * c4_1_get_row(int x, int y, int mat[x][y], int row_index){
	int * row = (int*) malloc(y*sizeof(int));
	for(int i=0; i<y; i++){
		row[i] = mat[row_index][i];
	}
	return row;
}

int c4_1_check_row_sum_col(int m, int n, int row[n], int B[n][m]){
	for(int i=0; i<m; i++){
		for(int j=i; j<m; i++){
			int * coli = (int*) malloc(n*sizeof(int));
			int * colj = (int*) malloc(n*sizeof(int));
			coli = c4_1_get_col(n, m, B, i);
			colj = c4_1_get_col(n, m, B, j);
			// summing two columns
			int * coltot = (int*) malloc(n*sizeof(int));
			for(int p=0; p<n; p++){
				coltot[p] = coli[p] + colj[p];
			}

			for(int p=0; p<n; p++){
				if(coltot[p] != row[p]){
					return 0;
				}
			}
		}
	}
	return 1;
}


int c4_1_second_constraint(int m, int n, int A[m][n], int B[n][m]){
	for(int i=0; i<m; i++){
		// get A's row
		int row[n];
		for(int j=0; j<n; j++){
			row[j] = A[i][j];
		}
		if(c4_1_check_row_sum_col(m, n, row, B) == 0){
			return 0;
		}
	}
	return 1;

}

int c4_1_check_row_col(int m, int n, int row[n], int B[n][m]){
	for(int i=0; i<m; i++){
		// get B's col
		int col[n];
		for(int j=0; j<n; j++){
			col[j] = B[j][i];
		}

		// Checks if are same.
		// This loop can also be removed, using
		// only the previous one, but I hope
		// that in this way it will be brighter
		for(int p=0; p<n; p++){
			if(row[p] != col[p]){
				return 0;
			}
		}
	}
	return 1;
}

int c4_1_first_constraint(int m, int n, int A[m][n], int B[n][m]){
	for(int i=0; i<m; i++){
		// get A's row
		int row[n];
		for(int j=0; j<n; j++){
			row[j] = A[i][j];
		}
		if(c4_1_check_row_col(m, n, row, B) == 0){
			return 0;
		}
	}
	return 1;
}


int c4_1_check(int m, int n, int A[m][n], int B[n][m]){
	int res1=0, res2=0;
	 res1 = c4_1_first_constraint(m, n, A, B);
	 res2 = c4_1_second_constraint(m, n, A, B);

	 if(res1 == 1 || res2 == 1){
		 return 1;
	 }
	 return 0;
}

void c4_1(){
	printf("--- C4_1 ------\n");

}








int c4_2_binary_search(int n, int arr[n], int goal){
	int start = 0;
	int end = n-1;
	while(start <= end){
		// "ceil" is similar to floor and round
		// it approximate to nearest lower if we
		// have a number like x.5
		int middle = ceil((end+start)/2); // both with or without precision
		printf("%d %d %d\n", start, end, middle);

		int val = arr[middle];
		if(val == goal){
			return middle;
		} else if(goal > val){
			start = middle+1;
		} else if (goal < val){
			end = middle-1;
		}	
	}
	return -1;
}

// NOT TESTED
int c4_2_binary_search_recursive(int n, int arr[n], int start, int end int goal){
	assert(n>0);
	if(n == 1){
		return arr[0] == goal;
	} else {
		int middle = ceil((end + start) / 2);
		
		if(arr[middle] == goal){
			return middle;
		} else if(goal < arr[middle]){
			end = middle - 1;
		} else if(goal > arr[middle]){
			start = middle +1;
		}
		
		return c4_2_binary_search_recursive(n, arr, start, end, goal);
	}
}


void c4_2(){
	printf("--- C4_2 ------\n");
	int n1 = 10;
	int goal1 = 4;
	int arr1[] = {1,2,3,4,5,6,7,8,9,10};
	int res1 = -1;

	int n2 = 9;
	int goal2 = 9;
	int arr2[] = {1,3,4,5,8,9,34,56,75};
	int res2 = -1;

	int n3 = 7;
	int goal3 = 6;
	int arr3[] = {1,2,5,7,8,9,10};
	int res3 = -1;

	int n4 = 8;
	int goal4 = 7;
	int arr4[] = {1,2,3,4,5,6,7,8};
	int res4 = -1;

	printf("Starting first binary search\n");
	res1 = c4_2_binary_search(n1, arr1, goal1);
	
	printf("Starting second binary search\n");
	res2 = c4_2_binary_search(n2, arr2, goal2);

	printf("Starting third binary search\n");
	res3 = c4_2_binary_search(n3, arr3, goal3);

	printf("Starting fourth binary search\n");
	res4 = c4_2_binary_search(n4, arr4, goal4);

	printf("Lista 1 --> %d\nLista 2 --> %d\nLista 3 --> %d\nLista 4 --> %d\n", res1, res2, res3, res4);
}






struct interval {
	double a;
	double b;
};

int c4_3_check(int n, struct interval intervals[n], double x){
	for(int i=0; i<n; i++){
		struct interval tmp = intervals[i];
		if(tmp.a < x && tmp.b > x){
			return i;
		}
	}
	return -1; // not found
}

void c4_3(){
	printf("--- C4_3 ------\n");
	double x = 3.45;
	int n = 5;

	struct interval intervals1[] = {
		{3, 3.44},
		{3.46, 4},
		{1, 2},
		{5, 7},
		{3.44, 3.46}
	};

	struct interval intervals2[] = {
		{3, 3.45},
		{3.45, 4},
		{1, 2},
		{5, 7},
		{3.45, 3.45}
	};

	int res1 = -1;
	int res2 = -1;

	res1 = c4_3_check(n, intervals1, x);
	res2 = c4_3_check(n, intervals2, x);

	printf("L'elemento %d e' presente nella posizione %d della prima lista", x, res1);
	printf("L'elemento %d e' presente nella posizione %d della seconda lista", x, res2);
	
}



















