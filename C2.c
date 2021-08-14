#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>


/// orders three integers
/// \param x
/// \param y
/// \param z
void c2_1_ordina (int * x, int * y, int * z) {
    int arr[3] = {*x, *y, *z};

    for (int i=0; i<(3-1); i++){
        int tmp;
        if(arr[i] > arr[i+1]){
            tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
    }

    (*x) = arr[0];
    (*y) = arr[1];
    (*z) = arr[2];
}

void c2_1()
{
    int x = 3;
    int y = 2;
    int z = 1;
    c2_1_ordina(&x, &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
}




/// Checks if matrix is diagonal
/// \param n
/// \param mat
/// \return
int c2_2_check_diagonal(int n, int mat[n][n]){
    if(n==0 || n ==1){
        return 1;
    }

    for(int i = 0; i<n;i++){
        if(mat[i][i] == 0){
            return 0;
        }
        for (int j=0; j<n; j++){
            if(i!= j && mat[i][j] != 0){
                return 0;
            }
        }
    }

    return 1;
}

/// Checks if matrix is superior/inferior diagonal
/// \param n
/// \param mat
/// \param superior
/// \return
int c2_2_check_diagonal_side(int n, int mat[n][n], int superior){
    if(n==0 || n ==1){
        return 1;
    }

    for(int i = 0; i<n;i++){
        if(mat[i][i] == 0){
            return 0;
        }
        for (int j=0; j<n; j++){
            if(superior == 1){ // superior diagonal
                if(i < j && mat[i][j] != 0){
                    return 0;
                }
            }
            else{ // inferior diagonal
                if(i > j && mat[i][j] != 0){
                    return 0;
                }
            }
        }
    }

    return 1;
}


void c2_2(){
    int n = 5;
    int mat[n][n]; // to be popolate
    printf("0 if is not diagonal, 1 if it is --> %d", c2_2_check_diagonal(n, mat));
    printf("0 if is not superior diagonal, 1 if it is --> %d", c2_2_check_diagonal_side(n, mat, 1));
    printf("0 if is not inferior diagonal, 1 if it is --> %d", c2_2_check_diagonal_side(n, mat, 0));
}


/// Crea un array di puntatori ordinati in ordine crescente
/// \param n
/// \param arr
void c2_3_crea_indice(int n, double arr[n]){
    double ordered[n];

    for(int i=0; i<n-1; i++){
        for (int j=0; j<(n-1-i); j++){
            if(ordered[j] > ordered[j+1]){
                double tmp = ordered[j];
                ordered[j] = ordered[j+1];
                ordered[j+1] = tmp;
            }
        }
    }

    double * pointers[n];
    for(int i=0; i<n; i++){
        pointers[i] = &ordered[i];
    }

    for(int i=0; i<n; i++){
        printf("%lf", *pointers[i]);
    }
}

void c2_3(){

}












