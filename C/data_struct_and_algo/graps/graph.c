#include <stdio.h>


typedef struct node{
	int val;
	gnode_t *next;
} gnode_t;


// adjacency list
typedef struct list{
	int delta;
	gnode_t * head;
} glist_t;


// undirected
typedef struct graph{
	int edges; // V
	int nodes; // E
	glist_t *adjlist;
} graph;





static void valid(graph *g){
	if(g == NULL){
		puts("A non valid Graph has been provided.");
		exis(1);
	}
}


// no side effect
extern graph *creategraph(unsigned int V){
	graph *g = malloc(sizeof(*graph));
	g->edges = 0;
	g->nodes = V;
	g->adjlist = malloc(sizeof(*glist)*V); // One node for each vertex

	for(int i=0; i<v; i++){
		g->adjlist[i]->head = NULL;
	}
	return graph;
}

// side effect
static graph *creategraph(graph **g, unsigned int V){
	valid(*g);

	*g->edges = 0;
	*g->nodes = V;
	*g->adjlist = malloc(sizeof(*glist)*V); // One node for each vertex

	for(int i=0; i<v; i++){
		*g->adjlist[i]->head = NULL;
		*g->adjlist[i]->delta = 0;
	}
	return *g;
}

extern void addvertex(graph **g, unsigned int val){
	valid(*g);

	else if(val <= g->nodes){
		printf("This node is already inside the graph");
	}
	glist_t *new = malloc(sizeof(*new));
	if(!new){
		puts("Somethign went wrong with dynamic allocation");
		exit(1);
	}
	new->head = NULL;
	new->delta = 0;
	// it can be built better double the size of adjlist
	*g->adjlist = realloc(*g->adjlist, *g->nodes+1);
	*g->adjlist[val] = new;
	
}

extern void addedge(graph **g, unsigned int src, unsigned int dest){
	valid(*g);
	if((*g)->adjlist == NULL){
		puts("Before adding an edge, you should initialize the graph.");
		exit(1);
	}
	else if(src>g->nodes || dest>g->nodes){
		puts("A non valid source or destination node has been provided.");
		exit(1);
	}
	
	graph current = *g;
	list *srclist = current->adjlist[src];
	current->adjlist[src].delta+=1;
	gnode_t *srcnode = malloc(sizeof(*srcnode));
	srcnode->val = src;
	srcnode->next = NULL;
	push(srclist, srcnode);

	list *destlist = current->adjlist[dest];
	current->adjlist[dest].delta+=1;
	gnode_t *destnode = malloc(sizeof(*destnode));
	destnode->val = dest;
	destnode->next = NULL;	
	push(destlist, destnode);

	(*g).edges+=1;
}


extern int areadjacent(graph *g, unsigned int node1, unsigned int node2){
	valid(g);
	if(node1 == NULL || node2 == NULL){
		puts("Bad node provided");
		exit(1);
	}

	if(node1 == node2){
		// by definition
		return 0;
	}
	
	int delta1 = g->adjlist[node1].delta;
	int delta2 = g->adjlist[node2].delta;
	// retreive node with minimim connections
	int res = delta1<delta2 ? delta1 : delta2;

	gnode_t *current = g->adjlist[res]->head;;
	while(current != NULL){
		if(current->val == node1 || current->val == node2) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}


extern void printgraph(graph *g){
	valid(g);
	for(int i=0, i<g->nodes; i++){
		gnode_t *current = g->adjlist[i]->head;
		while(current!=NULL){
			printf("%d ->", current->val);
			current = current->next;
		}
		printf("\b\b\b\n");
		free(current);
	}
}

extern void rmvedge(graph **g, unsigned int src, unsigned int dest){
	valid(*g);
	if(src > *g->nodes || dest > *g->nodes){
		puts("Not valid node provided");
		exit(1);
	}
	if(src == dest){
		rmvvertex(g, src);
	}
	// deleting src->dest edge
	gnode_t *current = *g->adjlist[src]->head;
	if(current == NULL){
		printf("The edge that you want to delete, didn't exists");
		return;
	} else if (current == dest){
		*g->adjlist[src]->head = current->next;
	} else {
		while(current->next != NULL && current->next != dest){
			current = current->next;
		}
		current->next = current->next->next;
	}

	// deleting dest->src edge
	current = *g->adjlist[dest]->head;
	if(current == NULL){
		printf("The edge that you want to delete, didn't exists");
		return;
	} else if (current == dest){
		*g->adjlist[dest]->head = current->next;
	} else {
		while(current->next != NULL && current->next != dest){
			current = current->next;
		}
		current->next = current->next->next;
	}

}

extern void rmvvertex(graph **g, unsigned int val){
	valid(*g);
	if(val > *g->nodes){
		puts("Not valid node provided");
		exit(1);
	}

	char *from = (char*) *g->adjlist + val*sizeof(glist_t);
	char *to = from - val*sizeof(glist_t);
	size_t size = *g->nodes-val;
	memmove(from, to, size);
}

extern int canBeConnected(graph *g){
	return g->edges >= g->nodes-1;
}

extern int canBeConnected(graph *g){
	return g->edges <= g->nodes-1;
}
