#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50
#define hash(key) ((key) % SIZE)

struct node_t{
	int key;
	struct node_t *next;
	void *element;
};

struct hashtable{
	struct node_t table[SIZE];
}
typedef struct hashtable hashtable;




bool insert(hashtable *ht, int key, void *element){
	if(element == NULL){
		errno = ;//some error number
		fpritnf(stderr, "Element can't be NULL\n");
		exit(1);
	}
	
	int index = hash(key);
	// recupero la lista di trabocco associata
	struct node_t *head = ht->table[index].next, 
		      *current = head,
		      *new = malloc(sizeof(*new) + sizeof(element));
	while(current->next != NULL){
		if(current->key == key){
			fprintf(stderr, "Key already inside the list\n");
			exit(1);
		}
		current = current->next;
	}

	if(current->key == key){
		fprintf(stderr, "Key already inside the list\n");
		exit(1);
	}else{
		new->key = key;
		new->element = element;
		new->next = NULL;
		current->next = new;
	}
}


void *find(hashtable *ht, int key){	
	int index = hash(key);
	struct node_t **head = ht->table[index].next;
	while((*head) && (*head)->key != key){
		head = &(*head)->next;
	}

	if(!(*head))
		return NULL
	return (*head)->element;
}




bool insert(hashtable *ht, int key, void *element){
	if(element == NULL){
		errno = ;//some error number
		fpritnf(stderr, "Element can't be NULL\n");
		exit(1);
	}
	
	if(find(ht, key) != false){
		return false;
	}

	int index = hash(key);
	// recupero la lista di trabocco associata
	struct node_t **head = &ht->table[index].next, 
		      *new = malloc(sizeof(*new));
	if(!(new)){
		// failed malloc
	}

	new->key = key;
	new->element = element;
	new->next = *head; // lo aggiungo in testa
	*head = new;

	return true;
}



bool delete(hashtable *ht, int key){
	int index = hash(key);
	struct node_t **head = &ht->table[index].next;
	while((*head) && (*head)->key != key){
		head = &(*head)->next;
	}

	if(!(*head))
		return false;

	del = *head;
	*head = (*head)->next; // imposto quello che devo eliminare come il suo successivo
	free(del);

	return true;
}
