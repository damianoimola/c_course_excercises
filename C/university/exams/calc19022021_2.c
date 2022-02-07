#include <stdio.h>
#include <stdlib.h>



// signatures
int check(size_t m, size_t n, int M[m][n]);


// MAIN
void main(int argc, char * argv[]){

}

int check(size_t m, size_t n, int M[n][m]){
	unsigned int counter = 0;
	int threshold = (m*n)/2;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]==0){
				// early stop
				if(++counter >= threshold){
					return 1;
				}
			}
		}
	}
	return 0;
}
