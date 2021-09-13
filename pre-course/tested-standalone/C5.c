#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>


void c5_1();
void c5_2();
void c5_3();


int main(int argn, char ** argv){
	c5_1();
	c5_2();
	c5_3();
}




int c5_1_is_palindrome(char * s){
	int len = strlen(s);
	int end = len-1;
	for(int i=0; i<ceil(end/2); i++){
		if(s[i] != s[end-i]){
			return 0;
		}
	}
	return 1;
}

// not tested
int c5_1_is_palindrome_ric_1(char * s){
	int len = strlen(s);
	int end = len-1;
	assert(len>0);
	if(len == 1){
		return 1;
	} else if(len == 2){
		return s[0] == s[1];
	} else {
		if(s[0] == s[end]){
			char * new_str;
			for(int i=1; i<end-1; i++){
				new_str[i-1] = s[i];
			}
			return c5_1_is_palindrome_ric_1(new_str);
		}
		return 0;
	}
}

// not tested
int c5_1_is_palindrome_ric_2(char * s, int left, int right){
	int len = left-right;
	assert(left <= right);
	if(len == 0 || len == 1 || left == right){
		return 1;
	} else {
		if(s[left] == s[right]){
			left +=1;
			right -=1;
			return c5_1_is_palindrome_ric_2(s, left, right);
		}
		return 0;
	}
}


void c5_1(){
	printf("--- C5_1 ------\n");

	char * s1 = "ciao a tutti";
	char * s2 = "osso";
	char * s3 = "ailatiditalia";

	int res1 = -1, res2 = -1, res3 = -1;

	res1 = c5_1_is_palindrome(s1);
	res2 = c5_1_is_palindrome(s2);
	res3 = c5_1_is_palindrome(s3);

	printf("La prima stringa e' palindroma --> %d\nLa seconda stringa e' palindroma --> %d\nLa terza stringa e' palindroma %d\n", res1, res2, res3);

}




struct coordinata{
	int val;
	int row;
	int col;
};

struct coordinata * c5_2_get_coordinates(int m, int n, int A[m][n]){
	int counter = 0;
	struct coordinata * coordinate = (struct coordinata *) malloc(m*n*sizeof(struct coordinata));

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if (A[i][j] != 0){
				struct coordinata c;
				c.val = A[i][j];
				c.row = i;
				c.col = j;
				coordinate[counter] = c;
				counter += 1;
			}
		}
	}
	return coordinate;
}

int c5_2_get_numbers(int m, int n, int A[m][n]){
	int counter = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(A[i][j] != 0){
				counter += 1;
			}
		}
	}
	return counter;
}

void c5_2(){
	printf("--- C5_2 ------\n");

	int A[4][4] = {
		{0, 0, 0, 0},
		{5, 8, 0, 0},
		{0, 0, 3, 0},
		{0, 6, 0, 0}
	};

	int numbers = c5_2_get_numbers(4, 4, A);
	struct coordinata * coordinate = (struct coordinata *) malloc(numbers*sizeof(struct coordinata));

	coordinate = c5_2_get_coordinates(4, 4, A);

	for(int i=0; i<numbers; i++){
		printf("(%d, %d, %d) ->", coordinate[i].val, coordinate[i].row, coordinate[i].col);
	}
}








struct tuple{
	char ** string_mat;
	int number_of_strings;
};



char * c5_3_get_string(char * str, int start_index, int end_index){
	char * tmp = (char*) malloc ((end_index-start_index) * sizeof(char));
	for(int i = start_index; i<end_index; i++){
		tmp[i-start_index] = str[i];
	}
	//printf("%d %d %s --- %s\n", start_index, end_index, tmp, str);
	return tmp;
}


struct tuple c5_3_split(char * s){
	int len = strlen(s);
	int start = 0;
	int end = 0;
	int counter = 0;
	char ** matret = (char**) malloc(len * sizeof(char*));
	// <= instead < to catch EOL character
	for(int i=0; i<=len; i++){
		// 32 == SPACE
		// 10 == EOL
		if(s[i] == 32 || s[i] == '\0'){
			if(i>0 && s[i-1] != 32){
				end = i;
				char * word = (char*) malloc((end-start) * sizeof(char) +1);
				word = c5_3_get_string(s, start, end);
				matret[counter] = word;
				counter+=1;
			}
		} else if(i>0, s[i] != 32 && s[i-1] == 32) {
			start = i;
		}
	}
	struct tuple ret = {matret, counter};
	return ret;
}

void c5_3(){
	printf("\n--- C5_3 ------\n");

	char * s1 = "ciao a tutti";
	char * s2 = "ciao   ciao";
	char * s3 = " ";
	char * s4 = "Prova";
	int n1, n2, n3, n4;
	n1 = strlen(s1);
	n2 = strlen(s2);
	n3 = strlen(s3);
	n4 = strlen(s4);

	struct tuple res1;
	struct tuple res2;
	struct tuple res3;
	struct tuple res4;
	
	res1 = c5_3_split(s1);
	res2 = c5_3_split(s2);
	res3 = c5_3_split(s3);
	res4 = c5_3_split(s4);

	for(int i=0; i<res1.number_of_strings; i++){
		printf("<%s> ", res1.string_mat[i]);
	}

	printf("\n");
	for(int i=0; i<res2.number_of_strings; i++){
		printf("<%s> ", res2.string_mat[i]);
	}

	printf("\n");
	for(int i=0; i<res3.number_of_strings; i++){
		printf("<%s> ", res3.string_mat[i]);
	}

	printf("\n");
	for(int i=0; i<res4.number_of_strings; i++){
		printf("<%s> ", res4.string_mat[i]);
	}
	printf("\n");
}






