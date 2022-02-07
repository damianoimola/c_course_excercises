#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct node {
	struct node *next;
	int key;
	int counter;
};

union flt{
	struct ieee754{
		uint32_t mantissa: 23;
		uint32_t exponent: 8;
		uint32_t sign: 1;
	} raw;
	float f;
}

// signatures
void insert_node(struct list **head, float value);
void remove_node(struct list **head, float value);



// MAIN
int main(int argc, char * argv[]){
	
}

void insert_node(struct list **head, float value){
	int val = mantissa(value);

	struct node *new = malloc(sizeof(*new));
	if(!new){
		fprintf(stderr, "Oops, dynamic allocation went wrong\n");
		exit(1);
	}
	new->key = val;
	new->counter = 1;
	new->next = NULL;

	if(*head == NULL){
		*head = new;
		return;
	}

	// find node
	struct node *current = *head;
	while(current != NULL){
		if(current->key == val){
			current->counter += 1;
			return;
		}
		current = current->next;
	}

	// if not found
	new->next = *head->next;
	*head->next = new;
	return;
}


void remove_node(struct list **head, float value){
	int val = mantissa(value);
	
	struct node *current = *head;
	while(current != NULL){
		if(current->next != NULL && current->next->val == key){
			struct node *next = current->next->next;
			current->next = next;
			return;
		}
		current->current->next;
	}
	return;
}


int mantissa(float value){
	union flt f;
	f.float = value;
	return f.raw.mantissa;
}
