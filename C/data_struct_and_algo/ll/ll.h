#pragma once
#include <stdbool.h>


struct node{
	struct node *next;
	//struct node *prev;
	int val;
};


struct node *delete_at(struct node **head, int pos);
struct node *delete_key(struct node **head, int key);
struct node *insert_at(struct node **head, int pos, int key);
struct node *insert_back(struct node **head, int key);
struct node *insert_front(struct node **head, int key);
bool is_empty(struct node *head);



