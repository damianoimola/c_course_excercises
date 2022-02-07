#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct punto {
	double x;
	double y;
};

typedef struct punto dot;

// pre-definiton of funcs
int * c3_2(int n, dot arr[n]);

int main(int argc, char * argv[]){
	const int n1=5, n2=7;

	dot arr1[] = {
		{2.0, 5.0},
		{3.0, 9.0},
		{1.0, 2.0},
		{10.0, 12.0},
		{10.0, 20.0}
	};

	dot arr2[] = {
		{2.0, 5.0},
		{3.0, 9.0},
		{1.0, 2.0},
		{10.0, 12.0},
		{10.0, 20.0},
		{3.0, 4.0},
		{0.0, 0.0}
	};

	int * res1 = (int *) malloc(2 * sizeof(int));
	int * res2 = (int *) malloc(2 * sizeof(int));

	res1 = c3_2(n1, arr1);
	res2 = c3_2(n2, arr2);

	printf("Nel primo vettore l'indice dei punti con distanza massima è: (%d, %d)", res1[0], res1[1]);
	printf("Nel secondo sono: (%d, %d)", res2[0], res2[1]);

	return 0;
}

int distance(dot a, dot b){
	int t1 = a.x - b.x;
	int t2 = a.y - b.y;
	return sqrt(t1*t1 + t2*t2);
}

int * c3_2(int n, dot arr[n]){
	int max_dist = distance(arr[0], arr[1]);
	int * indexes = (int *) malloc(2 * sizeof(int));

	// we didn't le first cycle hit
	// the last element, so in this
	// way we can exclude one comparison
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int dist = distance(arr[i], arr[j]);

			if(dist > max_dist){
				max_dist = dist;
				indexes[0] = i;
				indexes[1] = j;
			}
		}
	}
	return indexes;
}









