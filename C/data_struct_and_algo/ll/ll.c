#include <stdlib.h>
#include <stdio.h>




struct node *insert_at(struct node **head, int pos, int key){
	struct node *new = malloc(sizeof(*new));
	new->val = key;

	if(*head == NULL){
		new->next = NULL;
		*head = new;
	}

	struct node *curr = *head;
	int counter = 0;
	while(curr->next != NULL && current != pos){
		counter++;
		curr = curr->next;
	}

	if(curr){
		new->next = curr->next;
		curr->next = new;
	} else {
		new->next = NULL;
		curr->next = new;
	}
	return new;
}




struct node *insert_front(struct node **head, int key){
	struct node *new = malloc(sizeof(*new));
	new->key = key;
	new->next = *head;
	*head = new;
	return new;
}





struct node *insert_back(struct node **head, int key){
	struct node *new = malloc(sizeof(*new));
	new->key = key;
	new->next = NULL;

	if(*head == NULL){
		*head = new;
		return new;
	}
	
	struct node *current = *head;
	while(current->next){
		current = current->next;
	}

	current->next = new;
	return new;
}

bool is_empty(struct node *head){
	if(head == NULL) return true;
	return false;
}


struct node *delete_at(struct node **head, int pos){
	if(*head == NULL){
		return NULL;
	}

	int counter = 0;
	while(*head && counter != pos){
		tmp = head;
		head = &(*head)->next;
		counter++;
	}

	struct node **tmp;
	if(*head){
		struct node ptr = *head;
		*tmp->next = *head->next;
		free(ptr);
		return *head;
	}

	return NULL;
}

struct node *delete_key(struct node **head, int key){
	if(*head == NULL){
		return NULL;
	}

	struct node **tmp;
	while(*head && *head->key != key){
		tmp = head;
		head = &(*head)->next;
	}

	if(*head){
		struct node ptr = *head;
		*tmp->next = *head->next;
		free(ptr);
		return head;
	}
	return NULL;
}
