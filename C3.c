#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>

/// Returns if the elements in arrays are same
/// \param m
/// \param row_A
/// \param col_B
/// \return
int c3_1_same_elements(int m, const int row_A[], const int col_B[]){
    for (int i=0; i<m; i++){
        int tmp = row_A[i];

        int found = 0;
        for(int j=0; j<m; j++){
            if(row_A[i] == col_B[i]){
                found = 1;
            }
        }

        if(found == 0){
            return 0;
        }
    }
    return 1;
}

/// Get the column in a specified index of the matrix
/// \param x
/// \param y
/// \param mat
/// \param col_index
/// \return
int * c3_1_get_column(int x, int y, int ** mat, int col_index){
    // the number of elements is equals to the number of rows
    int * col = (int *) malloc(x * sizeof(int));
    for (int i=0; i<x; i++){
        col[i] = mat[i][col_index];
    }
    return col;
}

/// Get the row in a specified index of the matrix
/// \param x
/// \param y
/// \param mat
/// \param row_index
/// \return
int * c3_1_get_row(int x, int y, int ** mat, int row_index){
    return mat[row_index];
}

int c3_1(int n, int m, int ** A, int ** B){
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










