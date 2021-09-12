#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void c3_1();
void c3_2();

int main(int argn, char ** argv){
	c3_1();
	c3_2();
}


int * c3_1_get_row(int x, int y, int mat[x][y], int row_index){
	int * row = (int*) malloc(y*sizeof(int));
	for(int i=0; i<y; i++){
		row[i] = mat[row_index][i];
	}
	return row;
}

int * c3_1_get_col(int x, int y, int mat[x][y], int col_index){
	int * col = (int*) malloc(x*sizeof(int));
	for(int i=0; i<x; i++){
		col[i] = mat[i][col_index];
	}
	return col;
}

int c3_1_are_same(int x, int row[x], int col[x]){
	for(int i=0; i<x; i++){
		if(row[i] != col[i]){
			return 0;
		}
	}
	return 1;
}

int c3_1_check_row_col(int m, int n, int row[n], int B[n][m]){
	int res = 0;
	for(int i=0; i<n; i++){
		int col[n];
	        // col = c3_1_get_col(m, n, B, i);
		// getting column
		for(int j=0; j<m; j++){
			col[i] = B[j][i];
		}

		if(c3_1_are_same(n, row, col) == 1){
			res = 1;
		}
	}
	return res;
}

int c3_1_check(int m, int n, int A[m][n], int B[n][m]){
	for(int i=0; i<m; i++){
		int row[m];
	        // row = c3_1_get_row(m, n, A, i);
		// getting row
		for(int j=0; j<n; j++){
			row[i] = A[i][j];
		}

		if(c3_1_check_row_col(m, n, row, B) == 0){
			return 0;
		}
	}
	return 1;
}

void c3_1(){
	printf("--- C3_1 ------\n");
	int m = 3;
	int n = 4;
	int A[4][3] = {
		{1,1,1},
		{2,2,2},
		{3,3,3},
		{4,4,4}
	};
	int B[3][4] = {
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	};

	int res = c3_1_check(m, n, A, B);
	printf("Esiste? --> %d\n", res);
}












struct punto {
	double x;
	double y;
};


int c3_2_dist(struct punto p1, struct punto p2){
	int m1 = p1.x - p2.x;
	int m2 = p1.y - p2.y;
	return sqrt(m1*m1 + m2*m2);
}


int * c3_2_check_dist(int n, struct punto punti[n]){
	int max_dist = -1;
	int * indexes = (int*) malloc (2*sizeof(int));
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int d = c3_2_dist(punti[i], punti[j]);
			if(d>max_dist){
				max_dist = d;
				indexes[0] = i;
				indexes[1] = j;
			}
		}
	}
	return indexes;
}


void c3_2(){
	printf("--- C3_2 ------\n");

	int n = 5;
	struct punto punti[] = {
		{0,0},
		{1,2},
		{3,4},
		{1,1},
		{10,20}
	};

	int * res = (int*) malloc(2*sizeof(int));
	res = c3_2_check_dist(n, punti);
	printf("L'indice dei punti a distanza massima nell'array e': (%d, %d)", res[0], res[1]);
}






