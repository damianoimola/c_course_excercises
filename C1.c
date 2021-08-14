#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>


/// Print a function
/// \param x
/// \param y
void c1_1(int x, int y){
    if(y!= 0){
        int f = 2*x + floor(x/ (double)y);
        printf("y != 0 -> f(%d)=%d", x, f);
    } else if(x>5){
        int f = x*x +5;
        printf("y == 0 and x>5 -> f(%d)=%d", x, f);
    } else {
        int f = x*x - 10*x + 10;
        printf("y==0 and x<=5 -> f(%d)=%d", x, f);
    }
}


/// Euclide's Algorithm
/// \param a
/// \param b
void c1_2(int a, int b){
    if(b>a){
        int tmp = b;
        a=b;
        b=a;
    }

    while(b != 0){
        int r = a%b;
        a=b;
        b=r;
    }

    printf("Il risultato dell'algoritmo è: %d", a);
}

/// Fibonacci's sequence
/// \param len
void c1_3(int len){
    int fib[len];

    fib[0] = 1;
    fib[1] = 1;

    for (int i=2; i<len; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    // printing values
    for(int i = 0; i < len; i++){
        printf("%d ", fib[i]);
    }
}


/// Checks if the array is ordered (low to high)
/// \param num
/// \param len
/// \return
int c1_4_verifica_ordinamento(const double num[], int len){
    for (int i = 1; i<len; i++){
        if(num[i-1]>num[i]){
            return 0;
        }
    }
    return 1;
}

/// Checks if the array is ordered (low to high) recursively
/// \param num
/// \param len
/// \return
int c1_4_verifica_ordinamento_ric(const double num[], int len){
    int last = len - 1;

    if(len == 2){
        return num[last]<=num[last-1];
    }
    else if(num[last]<=num[last-1]) {
        return 0;
    }
    else {
        double newNum[last];

        for (int i=0; i<last; i++){
            newNum[i] = num[i];
        }
        return c1_4_verifica_ordinamento_ric(newNum, last);
    }
}

/// Get the lenght of the highest ordered subsequence
/// \param num
/// \param len
/// \return
int c1_4_sequenza_ordinata(const double num[], int len){
    int bestCounter = 0, counter = 0;

    if(len==1){
        return 1;
    }

    for(int i=1; i<len; i++){
        if(num[i]<=num[i-1]){
            counter += 1;
        }
        else {
            if(counter > bestCounter){
                bestCounter = counter;
            }
            counter=1;
        }
    }

    return bestCounter;
}

/// calls the c1_4_xxxxx methods
void c1_4(){
    int len = 10;
    double array[10]; // need to populate

    c1_4_verifica_ordinamento(array, len);
    c1_4_verifica_ordinamento_ric(array, len);
    c1_4_sequenza_ordinata(array, len);
}


/// exchange the first half chars with the second half
/// \param arr
/// \param len
void c1_5(const char arr[], int len){
    if(len%2 != 0){
        return; // stops
    }

    // second half chars
    char tmpArr[len/2];
    for(int i=0; i<=len/2; i++){
        tmpArr[i%(len/2)] = arr[i];
    }

    // rebuilding
    char retArr[len];
    for(int i=0; i<len; i++){
        if(i<len/2){
            retArr[i] = tmpArr[i];
        }
        else{
            retArr[i] = arr[i % (len/2)];
        }
    }

    for(int i=0;i<len;i++){
        printf("%c", retArr[i]);
    }
}

/// Revert the array
/// \param arr
/// \param len
void c1_6(const int arr[], int len){
    int tmpArr[len/2];

    for(int i=0; i<=len; i++){
        tmpArr[i] = arr[len-1-i];
    }

    for(int i=0;i<len;i++){
        printf("%d", tmpArr[i]);
    }
}




















