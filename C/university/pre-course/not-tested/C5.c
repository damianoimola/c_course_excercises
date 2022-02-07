#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>
#include <ctype.h> // per "isspace()"



int c5_1_check_palindrome_ric(char * s){
    unsigned int len = strlen(s);
    if(len == 0 || len == 1){
        return 1;
    } else if(s[0] == s[len-1]){
        char * tmp = (char*) malloc((len-2) * sizeof(char)); // rimuovo primo e ultimo
        for(int i=1; i<(len-1); i++){
            tmp[i-1] = s[i];
        }
        return c5_1_check_palindrome_ric(tmp);
    } else {
        return 0;
    }
}


int c5_1_check_palindrome(char * s){
    unsigned int len = strlen(s);
    char * first_half = (char*) malloc((len-2) * sizeof(char));
    char * second_half = (char*) malloc((len-2) * sizeof(char));
    for (int i=0; i<(len/2); i++){
        first_half[i] = s[i];
        second_half[i] = s[len-i];
    }

    if (strcmp(first_half, second_half) == 0){
        return 1;
    }
    return 0;
}

void c5_1(){
    char * s1 = "Test";
    char * s2 = "osso";
    char * s3 = "non";
    printf("%d", c5_1_check_palindrome_ric(s1));
    printf("%d", c5_1_check_palindrome(s1));
    printf("%d", c5_1_check_palindrome_ric(s2));
    printf("%d", c5_1_check_palindrome(s2));
    printf("%d", c5_1_check_palindrome_ric(s3));
    printf("%d", c5_1_check_palindrome(s3));
}


void c5_2(int m, int n, int ** A){
    int cols = 3;
    int max_rows = m*n;

    // declaring and dynamic allocating a matrix
    int **ret_mat = (int **)malloc(max_rows * sizeof(int*));
    for(int i = 0; i < max_rows; i++){
        ret_mat[i] = (int *)malloc(cols * sizeof(int));
    }

    int counter = 0;
    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(A[i][j] != 0){
                ret_mat[counter][0] = A[i][j];
                ret_mat[counter][1] = i;
                ret_mat[counter][2] = j;
                counter+=1;
            }
        }
    }

    for (int i=0; i<counter; i++){
        printf("(%d, %d, %d)\n", ret_mat[counter][0], ret_mat[counter][1], ret_mat[counter][2]);
    }

}


void c5_3(char * s){
    unsigned int len = strlen(s);
    char ** str_vec  = (char**) malloc(len*len * sizeof(char));;
    int counter = 0;
    for(int i=0; i<len; i++){
        int check = isspace(s[i]);
        if(check == 0){
            str_vec[counter][i] =  s[i];
        } else {
            counter +=1;
        }
    }

    for(int i=0; i<counter; i++){
        printf("%s", str_vec[i]);
    }
}














