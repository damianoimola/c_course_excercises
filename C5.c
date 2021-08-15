#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>



int c5_1_check_palindrome_ric(char * s){
    unsigned int len = strlen(s);
    if(len == 0 || len == 1){
        return 1;
    } else if(s[0] == s[len-1]){
        char tmp[len-2]; // rimuovo primo e ultimo
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
    char first_half[len/2];
    char second_half[len/2];
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

}