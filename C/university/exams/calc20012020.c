#include <stdio.h>
#include <stdlib.h>



int * function(int m, int n, int M[m][n], int R[m][2]);


int main(void){
	int m=3, n=3;
	int M[3][3] = {
		{7,2,3},
		{5,-1,2},
		{1,4,2}
	};
	int R[3][2] = {
		{1,2},
		{0,1},
		{-1,4}
	};



	int *res;
	res = function(m, n, M, R);

	for(int i=0; i<m; i++){
		printf("%d, ", res[i]);
	}

}


int * function(int m, int n, int M[m][n], int R[m][2]){
	int *V = malloc(sizeof(*V)*m);
	for(int j=0; j<m; j++){
		int Lindex = R[j][0] <= 0 ? 0 : R[j][0];
		int Rindex = R[j][1] >= n ? n-1 : R[j][1];
		int max = M[j][Lindex];
		for(int i=Lindex+1; i<=Rindex; i++){
			if(M[j][i] > max){
				max = M[j][i];
			}
		}
		V[j] = max;
	}
	return V;
}
