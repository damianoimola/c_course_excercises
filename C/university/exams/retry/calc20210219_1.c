#include <stdio.h>
#include <stdlib.h>


struct node {
	struct node *next;
	int key;
	int counter;
}

union flt{
	struct ieee754{
		uint32_t mantissa:23;
		uint32_t esponente:8;
		uint32_t segno:1;
	};
	float n;
}




void insert_node(struct node **head, float value){
	struct head *curr = *head;
	struct head *new = malloc(sizeof(*new));
	if(!*new){
		fprintf(stderr, "Oops, something went wrong with dynamic allocation\n");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->counter = 1;
	int mantissa = get_mantissa(value);
	new->key = mantissa;

	while(current != NULL){
		if(current->key == mantissa){
			current->counter+=1;
			return;
		}
		current = current->next;
	}

	current = new;
	return;
}


void remove_node(struct node **head, float value){
	int mantissa = get_mantissa(value);

	while(*head && *(head)->key!=mantissa)
		// la cosa buona è che "head" e' una copia
		// del puntatore presente nella funzione
		head = &((*head)->next);

	if(*head){
		// prendo l'elemento con la mantissa
		ptr = *head;
		// lo sostituisco con il successivo
		*head = (*head)->next;
		// libero l'elemento
		free(ptr);
	} 
}



int main(void){

}
