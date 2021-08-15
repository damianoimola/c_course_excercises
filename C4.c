#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>
#include "C3.h"


/// Returns if arrays are same (1) or not (0)
/// \param m
/// \param row_A
/// \param col_B
/// \return
int c4_1_are_equals(int m, const int row_A[m], const int col_B[m]){
    for (int i=0; i<m; i++){
        if(row_A[i] != col_B[i]){
            return 0;
        }
    }
    return 1;
}

/// Checks if there is any row that is equal to a B's column
/// \param n
/// \param m
/// \param A
/// \param B
/// \return
int c4_1_same_row_col(int n, int m, int A[m][n], int B[n][m]){
    for(int i=0; i<m; i++){
        int * col = (int*) malloc(m*sizeof(int));
        int * row = (int*) malloc(m*sizeof(int));
        col = c3_1_get_column(n, m, B, i);
        row = c3_1_get_row(n, m, A, i);

        if(c4_1_are_equals(m, row, col)){
            return 1;
        }
    }
    return 0;
}

/// Get the sum of two vectors
/// \param x
/// \param arr1
/// \param arr2
/// \return
int * c4_1_sum_array(int x, const int arr1[x], const int arr2[x]){
    int * sum = (int*) malloc(x*sizeof(int));

    for(int i=0; i<x; i++){
        sum[i] = arr1[i] + arr2[i];
    }

    return sum;
}

/// Check if the row of A is equal to a sum of two B's columns
/// \param n
/// \param m
/// \param row
/// \param B
/// \return
int c4_1_row_from_sum_col(int n, int m, int row[n], int B[n][m]){
    for(int i=0; i<m; i++){
        for(int j=i; i<m; i++){
            int * col1 = (int*) malloc(m*sizeof(int));
            col1 = c3_1_get_column(n, m, B, i);

            int * col2 = (int*) malloc(m *sizeof(int));
            col2 = c3_1_get_column(n, m, B, j);

            int * sum = (int*) malloc(m*sizeof(int));
            sum = c4_1_sum_array(n, col1, col2);

            if(c4_1_are_equals(m, row, sum)){
                return 1;
            }
        }
    }
    return 0;
}

/// Check if exists any row in A that is equal to a sum of V's columns
/// \param n
/// \param m
/// \param A
/// \param B
/// \return
int c4_1_any_row_from_sum_col(int n, int m, int A[m][n], int B[n][m]){
    for(int i=0; i<m; i++){
        int * row = (int*) malloc(m*sizeof(int));
        row = c3_1_get_row(n, m, A, i);

        if(c4_1_row_from_sum_col(n, m, row, B) == 1){
            return 1;
        }
    }
    return 0;
}


void c4_1(int n, int m, int A[m][n], int B[n][m]){
    if(c4_1_same_row_col(n, m, A, B)==1){
        printf("Esiste una riga di A che è uguale ad una colonna di B");
    }

    if(c4_1_any_row_from_sum_col(n, m, A, B)==1){
        printf("Esiste una riga di A che è uguale alla somma di due colonne di B");
    }
}