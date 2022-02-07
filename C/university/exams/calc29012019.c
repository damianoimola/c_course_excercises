#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
	int numero;
	int occorrenze;
	struct node *next;
};

struct node *numeri_occorrenze(int A[], int n);
void update_list(struct node **head, int val);
void print_list(struct node *head);

int main(int argc, char **argv){
	int A[7]={-2,1,2,0,1,1,2};
	struct node *list_head;

	list_head = numeri_occorrenze(A, 7);
	print_list(list_head);

	return 0;
}




struct node *numeri_occorrenze(int A[], int n){
	struct node *head = malloc(sizeof(*head));
	if(!head){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation");
		exit(1);
	}
	for(int i=0; i<n; i++){
		update_list(&head, A[i]);
	}
	return head;
}


void update_list(struct node **head, int val){
	struct node *current = malloc(sizeof(*current));
	if(!current){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation");
		exit(1);
	}
	current = *head;

	struct node *new = malloc(sizeof(*new));
	if(!new){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation");
		exit(1);
	}
	new->numero = val;
	new->occorrenze=1;
	new->next = NULL;

	if(current == NULL){
//		current->numero = val;
//		current->occorrenze = 1;
//		current->next = NULL;
		current = new;
		return;
	}

	while(current->next != NULL){
		if(current->numero == val){
			current->occorrenze+=1;
			return;
		}
		current = current->next;
	}
	if(current->numero == val){
		current->occorrenze+=1;
		return;
	}
	current->next = new;
	return;
}


void print_list(struct node *list){
	if(list == NULL) return;

	struct node *current = malloc(sizeof(*current));
	if(!current){
		fprintf(stderr, "Oops, somethign went wrong with dynamic allocation");
		exit(1);
	}
	current = list;

	puts("La sequenza è:");
	while(current != NULL){
		printf("{%d,%d}->", current->numero, current->occorrenze);
		current = current->next;
	}
	fprintf(stdout, "\n");
}
