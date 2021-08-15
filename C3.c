#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>
#include "C3.h"

int c3_1(int n, int m, int A[m][n], int B[n][m]){
    for(int i=0; i<=m; i++){
        int * col = (int*) malloc(m * sizeof(int));
        col = c3_1_get_column(n, m, B, i);

        int * row = (int*) malloc(m * sizeof(int));
        row = c3_1_get_row(n, m, A, i);

        if(c3_1_same_elements(m, row, col) == 1){
            return 1;
        }
    }
    return 0;
}


struct punto {
    double x;
    double y;
};

/// return the square of a number
/// \param x
/// \return
double c3_2_square(double x);

/// Returns the Euclidian distance between two points
/// \param p1
/// \param p2
/// \return
double c3_2_compute_distance(struct punto p1, struct punto p2);

void c3_2(){
    int len = 5;
    struct punto * parr = malloc(len * sizeof(struct punto)); // need to be filled

    int * indexes = (int*) malloc(2 * sizeof(int));
    double max_distance = -1;

    for (int i=0; i<len; i++){
        for (int j=i; j<len; j++){
            double distance = -1;
            distance = c3_2_compute_distance(parr[i], parr[j]);

            if (distance > max_distance){
                max_distance = distance;
                indexes[0] = i;
                indexes[1] = j;
            }
        }
    }

    printf("I punti con la distanza maggiore sono quelli aventi come indici: %d e %d", indexes[0], indexes[1]);
}

double c3_2_square(double x){
    return x*x;
}

double c3_2_compute_distance(struct punto p1, struct punto p2){
    return sqrt(c3_2_square(p1.x - p2.x) + c3_2_square(p1.y - p2.y));
}










