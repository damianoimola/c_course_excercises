
/*
 *		PYTHON LIST BUILDER
 *
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "config.h"


// pre-defined funcs
void push(node ** head, ctype val, type_t type);
void printll(node ** head);
void printval(ctype val, type_t type);
void compute_data(node ** head, int n, char * argv[]);



int main(int argc, char * argv[]){
	if(argc == 1){
		return 0;
	}

	node * head = (node*) malloc(sizeof(node));

	if(head == NULL){
		printf("memory allocation failed");
		return 0;
	}

	/*int arr1[3] = {1, 2, 3};
	int arr2[3] = {1.5, 2.5, 3.5};
	char str[8] = "Push me\0";
	char ch = 'D';

	ctype arr1[3] = { {.i=3}, {.f=4.1}, {.c='a'} };
	ctype arr2[3] = { {.f=1.5}, {.f=2.5}, {.f=3.5}};
	printf("%d, %f, %c\n", arr1[0].i, arr1[1].f, arr1[2].c);*/
	
	
	//ctype flt = { .f=4.1 };
	//ctype ll = { .ll=12345678};
	//ctype ch = { .c='D' };

	
	compute_data(&head, argc, argv);

	//push(&head, flt, FLOAT);
	//push(&head, ll, LONGLONG);
	//push(&head, ch, CHAR);

	printll(&head);

	free(head);
	return 0;
}


// IMPORTANT: LIFO method
// TODO: try with free(), without using memcpy
void push(node ** head, ctype val, type_t type){
	node * new = (node*) malloc(sizeof(node));

	new->datatype = type;
	new->val = val;
	new->next =(*head);

	(*head) = new;
	//memcpy((*head), new, sizeof(node)); // head = new
	//free(new);
	//new = NULL;
}


// THE PROBLEM IS HERE, FIX IT
void printll(node ** head){
	node * current = (node*) malloc(sizeof(node));
	current = (*head);
	while(current->next != NULL){
		printval(current->val, current->datatype);
		current = current->next;
	}
	free(current);
	current = NULL;
}


void printval(ctype val, type_t type){
	switch(type){
		case CHAR:
			printf("%c is a CHAR", val.c);
			break;

		case SHORT:
			printf("%hd is a SHORT", val.sh);
			break;

		case INT:
			printf("%d is a INT", val.i);
			break;

		case FLOAT:
			printf("%f is a FLOAT", val.f);
			break;

		case DOUBLE:
			printf("%lf is a DOUBLE", val.d);
			break;

		case LONG:
			printf("%ld is a LONG INT", val.l);
			break;

		case LONGLONG:
			printf("%lld is a LONG LONG INT", val.ll);
			break;

		//case STRING:printf("%s", val.s);

		default:
			printf("Tipo di dato non presente");
	}
	puts("");
}




void compute_data(node ** head, int n, char * argv[]){
	// wasting some mem here
	desc * descs = (desc*) malloc(n*sizeof(desc));
	//parseargs(&descs, n, argv);
	parseargs(&descs, n, argv);


	for(int i=0; i<n-1; i++){
		printf("DESCRIPTION #%d val:%d\n", i, descs[i]);
	}
	// n-1 because we remove first argv
	// so we populate n-1 items inside
	// linked list
	for(int i=0; i<n-1; i++){
		push(head, descs[i].val, descs[i].type);
	}
	free(descs);
}
