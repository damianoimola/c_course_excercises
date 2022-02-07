#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii_line(int index, int items_per_col);

#define ASCII_COLS 3
#define ASCII_CHARS_PER_COL 85
int print_ascii(char * arg){
	if(arg != NULL){
		int n = atoi(arg);

		if(n < 0 || n > 255){
			printf("Argument out of range");
		} else {
			printf("The ASCII character associated to %d is %c\n", n, (char)n);
		}
		
	} else {
		puts("|\t\t|\t\t|\t\t|");
		puts("|DEC\tCHAR\t|DEC\tCHAR\t|DEC\tCHAR\t|");
		printf("\n");

		// 255 caratteri in 3 colonne
		// = 85 caratteri a colonna
		const int n = ASCII_CHARS_PER_COL;
		for(int i=0; i<ASCII_CHARS_PER_COL; i++){
			print_ascii_line(i, n);
		}
	}
	return 1;
}


// 8 è backspace
// 9 è tab
// 10 è newline
// 13 è delete
void print_ascii_line(int index, int items_per_col){
	printf("|%d\t%c\t|%d\t%c\t|%d\t%c\t|\n", 
			index, (char)index, 
			index+items_per_col, (char)index+items_per_col, 
			index+(2*items_per_col), (char)index+(2*items_per_col));
	return;
}
