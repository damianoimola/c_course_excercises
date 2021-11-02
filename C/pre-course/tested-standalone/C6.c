#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void c6_1(int n, char ** argv);
void c6_2();


int main(int argn, char ** argv){
	c6_1(argn-1, argv);
	c6_2();
}




struct dict{
	char letter;
	int count;
};

// note: 'a' = 97, 'z' = 122
struct dict * c6_1_occurrences(int n, char ** strings){
	const int minascii = 97;
	const int maxascii = 122;
	const int dictsize = maxascii - minascii + 1;
	struct dict * occurrences = (struct dict *) malloc(dictsize * sizeof(struct dict));
	// generate empty dict
	for(int i=0; i<dictsize; i++){
		occurrences[i].letter = i + minascii;
		occurrences[i].count = 0;
	}
	// populate dict
	for(int i=0; i<n; i++){
		char * s = strings[i];
		int len = strlen(s);

		for(int j=0; j<len; j++){
			char c = tolower(s[j]);
			int index = (int) c - minascii;
			occurrences[index].count += 1;
		}
	}
	return occurrences;
}

void c6_1(int n, char ** argv){
	// argv[0] contains the name of the file
	// so 'n' has +1 of value
	printf("--- C6_1 ------\n");
	char ** strings = (char **) malloc(sizeof(argv));
	for(int i=0; i<n; i++){
		strings[i] = argv[i+1];
	}

	struct dict * occurrences;
	occurrences = c6_1_occurrences(n, strings);
	const int size = 26; // alphabet length

	for(int i=0; i<size; i++){
		printf("%c: %d\n", occurrences[i].letter, occurrences[i].count);
	}

}




struct node {
	int val;
	struct node * next;
};

struct node * c6_2_build_linked_list(int n, int arr[n]){
	struct node * head = (struct node *) malloc(sizeof(struct node));

	if(n>0){
		head -> val = arr[0]; // initialize
		
		struct node * current = (struct node *) malloc(sizeof(struct node));
		current = head;

		// creates linked list
		for(int i=1; i<n; i++){
			struct node * new = (struct node *) malloc(sizeof(struct node));
			new -> val = arr[i];
			new -> next = NULL;
			current -> next = new;
			current = new;
		}

	}
	
	return head;
}

int * c6_2_order_and_distinct(int n, int * arr){
	int * retarr = (int*) malloc(n*sizeof(int));
	// sorting
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(arr[i]<arr[j]){
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	// skip duplicates
	int index = 0;
	for(int i=0; i<n; i++){
		if(i>0 && arr[i] == retarr[index]){
			continue;
		}
		retarr[index] = arr[i];
		index += 1;
	}

	return retarr;
}

void c6_2_remove_less_than(struct node * head, int x){
	struct node * current = head;
	while((current -> next != NULL) && (current -> next -> val >= x)){
		current = current -> next;
	}
	// remove nodes less than 'x' or override NULL value
	current -> next = NULL;
}

void c6_2_print_list(struct node * head){
	struct node * current = head;

	while(current -> next != NULL){
		printf("(%d) --- ", current -> val);
		current = current -> next;
	}

	printf("(%d)\n", current -> val);
}

void c6_2(){
	printf("--- C6_2 ------\n");
	int n = 6;
	int arr[] = {1, 2, 7, 3, 10, 0};

	int * res = (int*) malloc(n*sizeof(int));
	res = c6_2_order_and_distinct(n, arr);

	struct node * list = (struct node *) malloc(sizeof(struct node));
	list = c6_2_build_linked_list(n, res);
	c6_2_print_list(list);
	c6_2_remove_less_than(list, 7);
	c6_2_print_list(list);
}
















