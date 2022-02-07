#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 128

typedef struct node{
	struct node *next;
	int key;
	void *element;
} node;

typedef struct list{
	struct node *head;
} list;

typedef struct hashtable{
	struct list arr[SIZE];
} hashtable;


bool insert(hashtable *ht, int key, void *element);
void *find(hashtable *ht, int key);
bool delete(hashtable *ht, int key);




bool delete(hashtable *ht, int key){
	// se nel node avevo *prev mi bastava assegnare
	// il find ad un puntatore ed utilizzare quello
	if(!find(ht, key)){
		return false;
	}

	int index = key%SIZE;
	node *current = ht->arr[index]->head;
	node *prev;
	node *ptr;

	while(current && current->key != key){
		prev = current;
		current = current->next;
	}

	if(current){
		ptr = current;
		prev->next = current->next;
		free(ptr);
		return true;
	}
	return false;
}





void *find(hashtable *ht, int key){
	int index = key%SIZE;
	node *current = ht->arr[index]->head;
	while(current->next != NULL){
		if(current->key == key){
			return current->element;
		}
		current = current->next;
	}
	return current->key == key ? current->element : NULL;
}




bool insert(hashtable *ht, int key, void *element){
	if(!element){
		fprintf(stderr, "Please provide a valid element.\n");
		exit(EXIT_FAILURE);
	}
	if(find(ht, key)){
		return false;
	}

	int index = key%SIZE;
	node *current = ht->arr[index]->head;

	while(current->next != NULL){
		current = current->next;
	}

	node *new = malloc(sizeof(*new) + sizeof(element));
	new->key = key;
	new->next = NULL;
	new->element = element;
	current->next = new;

	return true;
}
