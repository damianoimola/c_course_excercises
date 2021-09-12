#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <assert.h>


void c7_1();
void c7_2();
void c7_3();
void c7_4();

int main(int argn, char ** argv){
	//c7_1();
	//c7_2();
	//c7_3();
	//c7_4();
}


struct crivello{
	int * primes;
	int counter;
};

struct crivello c7_1_crivello_erastotene(int n){
	int * retarr = (int*) malloc(n*sizeof(int));
	int index = 0;
	for(int i=0; i<n; i++){
		int prime = 1;
		for(int j=0; j<i; j++){
			if(j%i == 0){
				prime = 0;
			}
		}

		if(prime){
			retarr[index] = i;
			index += 1;
		}
	}
	struct crivello c = {retarr, index+1};
	return c;
}


void c7_1(){
	printf("--- C7_1 ------\n");

	int n = 120;
	int * primes = (int*) malloc(n*sizeof(int));
	struct crivello c = c7_1_crivello_erastotene(n);
	primes = c.primes;

	for(int i=0; i<c.counter; i++){
		printf("%d ", primes[i]);
	}
}










int c7_2_search_horizontally(int m, int n, char ** C, char * s, int row, int col){
	int len = strlen(s);
	assert(len>0);

	int rtl = 1;
	int ltr = 1;

	// we could also do that we store the both sides
	// vertical strings in two variablea and
	// compare them with 's' using strcmp()
	for(int i=0; i<len; i++){
		// RtL
		if(col+i <= n){
			if(C[row][col+i] != s[i]){
				rtl = 0;
			}
		} else {
			rtl = 0;
		}

		// LtR
		if(col-i >= 0){
			if(C[row][col-i] != s[i]){
				ltr = 0;
			}
		} else {
			ltr = 0;
		}
	}

	return rtl || ltr;
}


int c7_2_search_vertically(int m, int n, char ** c, char * s, int row, int col){
	int len = strlen(s);
	assert(len>0);

	int ttb = 1;
	int btt = 1;

	// we could also do that we store the both sides
	// vertical strings in two variablea and
	// compare them with 's' using strcmp()
	for(int i=0; i<len; i++){
		// TtB
		if(row+i <= n){
			if(C[row+i][col] != s[i]){
				ttb = 0;
			}
		} else {
			ttb = 0;
		}

		// BtT
		if(row-i >= 0){
			if(C[row-i][col] != s[i]){
				btt = 0;
			}
		} else {
			btt = 0;
		}
	}
	return ttb || btt;
}



int c7_2_search_diagonally(int m, int n, char ** C, char * s, int row, int col){
	int len = strlen(s);
	assert(len>0);

	int ttb = 1;
	int btt = 1;

	// we could also do that we store the both sides
	// vertical strings in two variablea and
	// compare them with 's' using strcmp()
	for(int i=0; i<len; i++){
		// TtB
		if(row+i <= n && col+i <= n){
			if(C[row+i][col+i] != s[i]){
				ttb = 0;
			}
		} else {
			ttb = 0;
		}

		// BtT
		if(row-i >= 0 && col-i >= 0){
			if(C[row-i][col-i] != s[i]){
				btt = 0;
			}
		} else {
			btt = 0;
		}
	}
	return ttb || btt;

}



int c7_2_search(int m, int n, char ** C, char * s){
	// righe
	for(int i=0; i<m; i++){
		// colonne
		for(int j=0; j<n; j++){
			if(C[i][j] == s[0]){
				int res1 = c7_2_search_vertically(m, n, C, s, i, j);
				int res2 = c7_2_search_horizontally(m, n, C, s, i, j);
				int res3 = c7_2_search_diagonally(m, n, C, s, i, j);

				if(res1 == 1 || res2 == 1 || res3 == 1){
					return 1;
				}
			}
		}
	}
	return 0;
}



void c7_2(){
}




struct node {
	int val;
	struct node * next;
};


struct node * c7_3_create_linked_list(int n, int arr[n], struct node * head){
	struct node * current = head;

	for(int i=0; i<n; i++){
		struct node * following = (struct node *) malloc(sizeof(struct node));
		current -> val = arr[i];
		current -> next = following;

		current = current -> next;
	}

	return list;
}

// maybe we can make some optimizations
void c7_3_sort(struct node * head){
	struct node * current = head;
	// number of elements
	int counter = 0;
	while(current -> next != NULL){
		counter += 1;
		current = current -> next;
	}
	// reset
	current = head;
	// populate array
	int arr[counter], index = 0;
	while(current -> next != NULL){
		arr[index] = current -> val;
		index += 1;
		current = current -> next;
	}
	// sorting array
	for(int i=0; i<counter; i++){
		for(int j=i; j<n; j++){
			if(arr[i] < arr[j]){
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	c7_3_create_linked_list(counter, arr, head);
}

struct node * c7_3_top(struct node * head, int top){
	struct node * current = head;
	struct node * new = (struct node *) malloc(sizeof(struct node));
	while((current -> next != NULL) || (current -> next -> val < top)){
		new -> val = current -> val;
		new -> next = current -> next
		current = current -> next;
		new = new -> next;
	}
	new -> next = NULL;

	return new;
}


void c7_3(){

}









// a node of a linked list with
// string as a value
struct word{
	char * val;
	struct word * next;
}

struct charinfo{
	int val;
	int counter;
}


void c7_4_create_linked_list(int n, char ** argv, struct word * head){
	struct word * current = head;

	for(int i=0; i<n; i++){
		struct word * string = (struct word *) malloc(sizeof(word));
		current->val = head[i];
		current->next = word;
		current = current-> next;
	}
}


/*
 * arr[
 * 	["aaa", "aaab" "aca"],
 * 	["eef", "eel"],
 * 	...
 * ]
 *	tri-dimensional array
 *
 *	--- NOT TESTED ---
 */
char *** c7_4_group(struct word * head){
	// initializing char list
	struct charinfo * charlist = (struct charinfo *) malloc((size+1) * sizeof(struct charinfo));
	for(int i=0; i<=size; i++){
		charlist[i - minsize].val = minsize + i;
		charlist[i - minsize].counter = 0;
	}

	// info about deep of lists
	struct word * current = head;
	int totsize = 0;
	while(current->next != NULL){
		totsize += strlen(current->val);
		current = current->next;
	}

	// usefull const and varribles
	const int minsize = 97; // 'a'
	const int maxsize = 122; // 'z'
	int size = max-size - minsize;
	char ** groups[size+1] = (char **) malloc(totsize * sizeof(char));


	// valorizing charlist counters and 3-dim matrix
	current = head;
	while(current->next != NULL){
		char * s = current->val;
		int index = s[0] - minsize;
		charlist[index].counter += 1;

		struct charinfo info =  charlist[s[0] - minsize];
		current = current -> next;

		// creo una lista della lunghezza del nuovo numero di stringhe
		char ** string_list = (char **) malloc(info.counter * sizeof(char));
		char ** previous_list = groups[index];

		for(int i=0; i<charlist[index].counter-1; i++){
			string_list[i] = previous_list[i];
		}

		string_list[info.counter - 1] = current->val;
		groups[index] = string_list;
	}

}










