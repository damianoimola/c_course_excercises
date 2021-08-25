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








int c7_2_search_vertical(int n, int m, char ** mat, const char * s, int i, int j);
int c7_2_search_horizontal(int n, int m, char ** mat, const char * s, int i, int j);
int c7_2_search_diagonal(int n, int m, char ** mat, const char * s, int i, int j);


int c7_2(int n, int m, char ** mat, const char * s){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(&mat[i][j] == s){
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

/// Search vertically through matrix
/// \param n
/// \param m
/// \param mat
/// \param s
/// \param i
/// \param j
/// \return
int c7_2_search_vertical(int n, int m, char ** mat, const char * s, int i, int j){
    int counter = 0;
    for(int p=i; p<n; p++){
        if(&mat[p][j] != s+counter){
            return 0;
        }
    }
    for(int p=i; p>=0; p--){
        if(&mat[p][j] != s+counter){
            return 0;
        }
    }
    return 1;
}

/// Search horizontally through matrix
/// \param n
/// \param m
/// \param mat
/// \param s
/// \param i
/// \param j
/// \return
int c7_2_search_horizontal(int n, int m, char ** mat, const char * s, int i, int j){
    int counter = 0;
    for(int q=j; q<m; q++){
        if(&mat[i][q] != s+counter){
            return 0;
        }
    }
    for(int q=j; q>=0; q--){
        if(&mat[i][q] != s+counter){
            return 0;
        }
    }
    return 1;
}

/// Search diagonally through matrix
/// \param n
/// \param m
/// \param mat
/// \param s
/// \param i
/// \param j
/// \return
int c7_2_search_diagonal(int n, int m, char ** mat, const char * s, int i, int j){
    int counter = 0;

    for(int h=i; (i+h<n) || (j+h<m); h++){
        if(&mat[i+h][j+h] != s+counter){
            return 0;
        }
    }
    for(int h=i; (i+h>=0) || (j+h>=0); h--){
        if(&mat[i+h][j+h] != s+counter){
            return 0;
        }
    }

    return 1;
}








void c7_3_push(l_node * head, int val);
void c7_3_sort(int n, l_node * head);
int c7_3_is_sorted(l_node * head);
l_node * c7_3_top(int n, l_node * head);


// int main(int argc, char **argv) --> per recuperare i parametri dalla riga di comando
// argc: number of argument > 1
// **argv is a pointer to char *; is an array of char *
void c7_3(int n, int * arr){
    l_node * head = (l_node*) malloc(sizeof(l_node));
    head->val = arr[0];
    head->next = NULL;

    for(int i=0; i<n; i++){
        c7_3_push(head, arr[i]);
    }

    c7_3_sort(n, head);
    c7_3_top(n, head);
}

/// Push an element to the end of linked-list
/// \param head
/// \param val
void c7_3_push(l_node * head, int val){

    l_node * current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = (l_node*) malloc(sizeof(l_node));
    current->next->next=NULL;
    current->next->val = val;
}

/// Sort linked list in Decrescent order (max-to-min)
/// \param n
/// \param head
void c7_3_sort(int n, l_node * head){
    int * arr = (int*) malloc(n*sizeof(int));
    int counter = 0;

    // extracting ll to array
    l_node * current = head;
    while(current->next != NULL){
        arr[counter] = current->val;
        current = current->next;
        counter+=1;
    }

    // sorting
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            if(arr[j] < arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    // rebuilding ll
    l_node * new_list = (l_node*) malloc(sizeof(l_node));
    for(int i=0; i<n; i++){
        c7_3_push(new_list, arr[i]);
    }
    head=new_list;
}

/// Checks if the linked list id ordered
/// \param head
/// \return
int c7_3_is_sorted(l_node * head){
    l_node * current = head;
    int prev = current->val;
    while(current->next != NULL){
        if(prev < current->val){
            return 0;
        }
        prev = current->val;
        current = current->next;
    }
    return 1;
}

/// Gets the top firsts n values in a linked list
/// \param n
/// \param head
/// \return
l_node * c7_3_top(int n, l_node * head){
    l_node * current = head;
    if(c7_3_is_sorted(current) == 0) {
        c7_3_sort(n, current);
    }

    // building
    l_node * new_list = (l_node*) malloc(sizeof(l_node));
    int counter = 0;
    while(current->next != NULL && counter < n){
        c7_3_push(new_list, current->val);
        current = current->next;
        counter+=1;
    }

    return new_list;
}





typedef struct cnode {
    char * str;
    struct cnode * next;
} l_cnode;

void c7_4_push_string(l_cnode * head, char * str);
void c7_4_group(l_cnode * head);
l_cnode * c7_4_list_by_letter(l_cnode * head, char l);


// int main(int argc, char **argv) --> per recuperare i parametri dalla riga di comando
// argc: number of argument > 1
// **argv is a pointer to char *; is an array of char *
void c7_4(int n, char ** strings){
    l_cnode * head = (l_cnode*) malloc(sizeof(l_cnode));
    for (int i=0; i<n; i++){
        c7_4_push_string(head, strings[i]);
    }
}

/// Push a string to the end of linked list
/// \param head
/// \param str
void c7_4_push_string(l_cnode * head, char * str){
    l_cnode * current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = (l_cnode*) malloc((sizeof(l_cnode)));
    current->next->str = str;
    current->next->next = NULL;
}

/// Cretes groups of words starting with the sape letter
/// \param head
void c7_4_group(l_cnode * head){
    int number_of_letters = 36;
    int min_letter_number = 65;
    int max_letter_number = 90;
    l_cnode * list[26];
    for(int i=min_letter_number; i<=max_letter_number; i++){
        char c = (char) i;
        list[65-i] = c7_4_list_by_letter(head, c);
    }
}

/// Create a list with the fords starting by l
/// \param head
/// \param l
/// \return
l_cnode * c7_4_list_by_letter(l_cnode * head, char l){
    l_cnode * current = head;
    l_cnode * new_list = (l_cnode*) malloc(sizeof(l_cnode));
    while(current->next != NULL){
        if(*(current->str) == l){
            c7_4_push_string(new_list, current->str);
        }
    }
    return new_list;
}







