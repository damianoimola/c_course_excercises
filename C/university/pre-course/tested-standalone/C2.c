#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


void c2_1();
void c2_2();
void c3_3();


int main(int argn, char ** argv){

}


void c2_1_ordina(int x, int y, int z){
	if(x>y){
		int tmp = y;
		y = x;
		x = tmp;
	} else if(x>z){
		int tmp = z;
		z = x;
		x = tmp;
	} else if(y>z){
		int tmp = z;
		z = y;
		t = tmp;
	}
}

void c2_1(){
	printf("--- C2_1 ------\n");
	int x = 15;
	int y = 8;
	int z = 11;

	ordina(&x, &y, &z);

	printf("x=%d, y=%d, z=%d", x, y, z);
}




int c2_2_check_diag(int n, int mat[n][n]){
	for (int i=0; i<n; i++){
		if(mat[i][i] != 0){
			return 0;
		}
	}
	return 1;
}


int c2_2_check_side_diag(int n, int mat[n][n], int superior){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(superior == 1 && i<j && mat[i][j]!=0){
				return 0;
			} else if (superior == 0 && i>j && mat[i][j]!=0){
				// this could be placed also in "or" (||)
				// inside previous "if"
				return 0;
			}
		}
	}
	return 1;
}



void c2_2(){
	printf("--- C2_2 ------\n");
	int n = 3;
	int mat[n][n] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	
	int res1 = c2_2_check_diag(n, mat);
	int res2 = c2_2_check_side_diag(n, mat, 1);
	int res3 = c2_2_check_side_diag(n, mat, 0);
	printf("e' diagonale --> %d\ne' diagonale superiore--> %d\n� diagonale inferiore --> %d\n", res1, res2, res3);

}




int * c2_3_crea_indice(int n, double arr[n]){
	for(int i=0; i<n; i++){
		for (int j=i; j<n; j++){
			if(arr[i]>arr[j]){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	int * pointer_arr = (int*) malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		pointer_arr[i] = &arr[i];
	}
	return pointer_arr;
}

void c2_3(){
	printf("--- C2_3 ---\n");
	int n = 5;
	int arr[n] = {5,4,3,2,1};

	int * pointer_arr = c2_3_crea_indice(n, arr);
	for(int i=0; i<n; i++){
		printf("%d", &pointer_arr);
	}
}











