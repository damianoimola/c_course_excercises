#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int num;
	int row;
	int col;
	struct node *next;
} node_t;


void print_list(node_t *list){
	node_t * current = list;
	while(current!=NULL){
		printf("(%d,%d,%d) ->", current->num, current->row, current->col);
		current = current->next;
	}
	printf("\b\b\b\n");
}

void push_back(node_t ** list, int num, int row, int col){	
	node_t * new = malloc(sizeof(*new));
	new->num = num;
	new->row = row;
	new->col = col;
	new->next = NULL;

	if(*list == NULL){
		//list = malloc(sizeof(*list));
		//memcpy(*list, new, sizeof(node_t));
		*list = new;
		return;
	}

	node_t * current = *list;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new;
}



node_t * sparseList(size_t n, size_t m, int M[n][m]){
	node_t * L1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(M[j][i]!=0){
				push_back(&L1, M[j][i], j, i);
			}
		}
	}
	return L1;
}




node_t * sparseRow(node_t * L1, int rowIndex){
	node_t *current = L1;
	node_t *L2;// = malloc(sizeof(*L2));
	//if(!L2){printf("Oops, somethign went wrong with dynamic allocation\n");	exit(EXIT_FAILURE);}
	while(current != NULL){
		if(current->row == rowIndex){
			push_back(&L2, current->num, current->row, current->col);
		}
		current = current->next;
	}
	return L2;
}
int main (void){
	char *nome_cognome = "Damiano Imola"; // TODO Inserisci nome e cognome 
	char *matricola = "0291890";   // TODO Inserisci matricola (es. "0123456")
	printf("%s -Matricola: %s\n", nome_cognome, matricola);
	int nr=4, nc=4;
	int M[4][4] = {{0,2,0,0}, {1,0,-3,4}, {5,0,0,3}, {0,0,0,0}};
	struct node *list_head1, *list_head2;
	/* Invocare la funzione "sparseList" con la matrice M come argomento */
	list_head1 = sparseList(nr, nc, M);
	print_list(list_head1);
	/* Invocare la funzione "sparseRow" con la lista creata da sparseList come argomento */
	list_head2 = sparseRow(list_head1, 2);
	print_list(list_head2);
	return 0;
}




























