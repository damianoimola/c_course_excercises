#include <stdio.h>
#include <stdlib.h>

# define RED 1
#define BLACK 0

struct tree {
	int key;
	int val;
	int color;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}

typedef struct tree tree_t;



tree_t *function(tree_t *T, int x){
	tree_t *u = lookupNode(T, x);
	if(u!=NULL){
		// means that 'u' are NOT a leaf
		if(u->left != NULL && u->right != NULL){
			tree_t *s = u->right;
			while(s->left != NULL){
				s=s->left;
			}
			u->key = s->key;
			u->value = s->value;
			u=s;
			x=s->key;
		}

		tree_t *t = malloc(sizeof(*t));

		// means that 'u' has only left child
		if(u->left != NULL && u->right == NULL){
			t=u->left;
		} else {
			t=u->right;
		}

		link(u.parent, t, x);
		if(u->color == BLACK){
			balanceDelete(T,t);
		}
		if(u.parent == NULL){
			T=t;
		}
		free(u);
	}
	while(T->parent != NULL){
		T=T->parent;
	}
	return T;
}




void balanceDelete(tree_t *T, tree_t *t){
	while(t != T && t->color == BLACK){
		tree_t *p = t->parent;
		if(t=p->left){
			tree_t *f = p->parent;
			tree_t *ns = f->left;
			tree_t *nd = f->right;
			if(f->color == RED){
				p->color = RED;
				f->color = BLACK;
				rotateLeft(p);
			} else {
				if(ns->color == BLACK && ns->color == BLACK){
					f->color = RED;
					t = p;
				} else if(ns->color == RED && nd->color == BLACK){
					ns->color = BLACK;
					f->color = RED;
					rotateRight(f);
				} else if(nd->color == RED){
					f->color = RED;
					p->color = BLACK;
					nd->color = BLACK;
					rotateLeft(p);
					t=T;
				}
			}
		} else {
			// codice speculare al precedente
		}
	}
	if(t!=NULL){
		t->color = BLACK;
	}
}


