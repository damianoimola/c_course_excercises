#pragma once


/*
 * 	ADJACENCY LIST IMPLEMENTATION
 * 	with the "abstract data type"
 * 	paradigm. Here is the doc:
 *
 * 	https://en.wikipedia.org/wiki/Graph_(abstract_data_type)
 */


struct node;
struct adjlist;
struct graph;

// V is the nodes set cardinality
// a.k.a. how many nodes are inside
// the graph
struct graph *creategraph(unsigned int V);

// add a vertex to graph
void addvertex(graph **g, unsigned int val);

// add an edge to graph
void addedge(struct graph **g, unsigned int src, unsigned int dest);

// checks if nodes are adjacents
int areadjacent(graph *g, unsigned int node1, unsigned int node2);

// remove a graph edge
void rmvedge(graph **g, unsigned int src, unsigned int dest);

// remove a graph vertex
void rmvvertex(graph **g, unsigned int val){

// prints the graph to stdin file
void printgraph(graph *g);

// checks if the undirected graph passed
// as argument have the requirements
// to be connected
int canBeConnect(undirected *graph);

// checks if the undirected graph passed
// as argument have the requirements
// to be aciclyc
int canBeAciclyc(undirected *graph);


