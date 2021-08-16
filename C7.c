#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>


// for linked list
typedef struct node {
    int val;
    struct node * next;
} l_node;


void c7_1_pop_index(l_node * head, int i);

void c7_1_pop_multiples(l_node * head, int p, int n);

/// Sieve of Eratosthenes (Crivello di Erastotene)
/// \param n
void c7_1(l_node * head, int n){
    for(int i=2; i<=n; i++){
        c7_1_pop_multiples(head, i, n);
    }
}

/// Removes all multiples of a number p
/// \param head
/// \param p
/// \param n
void c7_1_pop_multiples(l_node * head, int p, int n){
    int start_number = 2;
    // devo mantenere almeno il primo (quindi parto dal doppio del primo) -> i=p*2
    // vado a step di p -> i=i+p
    for (int i=p*2; i<=n; i=i+p){
        c7_1_pop_index(head, p-start_number);
    }
}

/// Removes the number in index i
/// \param head
/// \param i
/// \param n
void c7_1_pop_index(l_node * head, int i){
    l_node * current = head;
    int counter = 0;

    while(counter< i-1){
        current = current->next;
        counter = counter+1;
    }

    if(current->next->next != NULL){
        l_node * following = (l_node*) malloc(sizeof(l_node));
        following = current->next->next;
        current->next = following;
    }
}





//TODO: both senses for each method
int c7_2_search_vertical(int n, int m, char * mat[n][m], const char * s, int i, int j);
int c7_2_search_horizontal(int n, int m, char * mat[n][m], const char * s, int i, int j);
int c7_2_search_diagonal(int n, int m, char * mat[n][m], const char * s, int i, int j);


int c7_2(int n, int m, char * mat[n][m], const char * s){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(mat[i][j] == s){
                if(c7_2_search_vertical(n, m, mat, s, i, j) == 1
                || c7_2_search_horizontal(n, m, mat, s, i, j) == 1
                || c7_2_search_diagonal(n, m, mat, s, i, j) == 1){
                    return 1; // found
                }
            }
        }
    }
    return 0; // not found
}

int c7_2_search_vertical(int n, int m, char * mat[n][m], const char * s, int i, int j){
    int counter = 0;
    for(int p=i; p<n; p++){
        if(mat[p][j] != s+counter){
            return 0;
        }
    }
    return 1;
}

int c7_2_search_horizontal(int n, int m, char * mat[n][m], const char * s, int i, int j){
    int counter = 0;
    for(int q=j; q<m; q++){
        if(mat[i][q] != s+counter){
            return 0;
        }
    }
    return 1;
}

int c7_2_search_diagonal(int n, int m, char * mat[n][m], const char * s, int i, int j){
    int counter = 0;
    for(int h=i; h<n; h++){
        if(mat[i+h][j+h] != s+counter){
            return 0;
        }
    }
    return 1;
}




