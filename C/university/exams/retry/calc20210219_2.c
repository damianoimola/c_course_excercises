#include <stdio.h>
#include <stdlib.h>


int func(int n, int m, int M[n][m]){
	int threshold = n*m/2;
	int counter = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j] != 0) counter++;
		}
	}
	return counter<threshold;
}


int main(void){
	int n1=4, m1=4;
	int M1[4][4] = {
		{0,0,0,1},
		{1,0,0,1},
		{0,1,0,0},
		{1,0,1,0}
	};

	int n2=3, m2=5;
	int M2[3][5] = {
		{0,0,0,1,0},
		{1,0,0,1,0},
		{0,1,0,0,0},
	};

	printf("M1 è %s\nM2 è %s\n", func(n1, m1, M1) == 1 ? "sparsa" : "non sparsa", func(n2, m2, M2) == 1 ? "sparsa" : "non sparsa");
	return 0;
}
