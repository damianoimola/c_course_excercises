#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>
#include <ctype.h> // per "toupper()"



/// Prints all occurrences of letter in a string
/// \param s
void c6_1(char * s){
    unsigned int len = strlen(s);
    int alpha[26][1]; // 26 = # of letters
    for(int i=0; i<len; i++){
        // 'a' = 'A'
        int lett = toupper(s[i]);
        // 'A' = 65, 'Z' = 90
        if(lett>=65 && lett<=90){
            alpha[65-lett][0] += 1;
        }
    }

    for(int i=0; i<26; i++){
        printf("%c: %d", i+65, alpha[i][0]);
    }
}



// for linked list
struct node {
    int val;
    struct node * next;
};

/// Add an item to the end of linke dlist
/// \param head
/// \param val
void c6_2_push(struct node * head, int val){
    struct node * current = head;
    // read the linked lists until last item
    while (current->next != NULL) {
        current = current->next;
    }

    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    current->next = tmp;
}


void c6_2(int len, int * arr){
    if(len == 0){
        return;
    }

    for (int i=0; i<len-1; i++){
        for (int j=1; j<len-1; j++){
            if(arr[j] < arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    struct node * head = (struct node *) malloc(sizeof(struct node));
    head->val = arr[0];
    head->next = NULL;

    if(len == 1){
        //printf();
        return;
    }

    for(int i=0; i<len; i++){
        c6_2_push(head, arr[i]);
    }
    //printf();

}


/// Rimuove dalla linked list tutti i numeri minori di n (la lista è crescente)
/// \param head
/// \param n
void c6_3(struct node * head, int n){

    struct node * current = head;
    while(current->val >=n){
        current = current->next;
    }

    current->next=NULL;
}







