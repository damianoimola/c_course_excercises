//
// Created by Damiano I on 15/08/2021.
//

#ifndef ESERCIZICALCOLATORIELETTRONICI_C3_H
#define ESERCIZICALCOLATORIELETTRONICI_C3_H


/// Returns if the elements in arrays are same
/// \param m
/// \param row_A
/// \param col_B
/// \return
int c3_1_same_elements(int m, const int row_A[m], const int col_B[m]){
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
int * c3_1_get_column(int x, int y, int mat[x][y], int col_index){
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
int * c3_1_get_row(int x, int y, int mat[x][y], int row_index){
    return mat[row_index];
}


#endif //ESERCIZICALCOLATORIELETTRONICI_C3_H
