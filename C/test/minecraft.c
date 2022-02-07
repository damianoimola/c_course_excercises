#include <stdio.h>


struct node{
	int val;
	int row;
	int col;
	node_t *next;
}

typedef struct node node_t;


void main(void){
	// initialize
	int n=5, m=5;
	int M[5][5] = {
		{1,1,1,0,1},
		{2,2,2,-1,1},
		{0,-1,0,-2,1},
		{0,0,-1,-2,1},
		{2,2,-1,0,0}
	};

	int res = get_most_average_height(n, m, M);
	printf("%d\n", res);
}




int get_most_average_height(int n, int m, int M[n][m]){
	int average = 0;
	node_t *head = malloc(sizeof(*head));
	if(head == NULL){
		fprintf(stdout, "Oops, something went wrong with dynamic memory allocation.\n");
		exit(1);
	}


	
	node_t *current = malloc(sizeof(*current));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j] <= 0) continue;
			head->row = i;
			head->col = j;
			head->val = M[i][j];
			head->next = NULL;
			while(current != NULL){
				enqueue_neighbors(&head, m, n, i, j, M);
				node_t *removed = dequeue(head);
				i=removed->row+1;
				j=removed->col+1;
			}
		}
	}
}


void enqueue_neigbors(node_t **head, int row, int col, int rowind, int colind, int M[][]){
}


void enqueue(node_t **head, int row, int col, int val){
	node_t *new = malloc(sizeof(*new));
	new->row = i;
	new->col = j;
	new->val = val;
	new->next = NULL;

	if((*head) == NULL){		
		(*head)=new;
		return;
	}
	
	new->next = (*head)->next;
	(*head)->next = new;
}


