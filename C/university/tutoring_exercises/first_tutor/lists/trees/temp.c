




node_rb_t *insertNode(node_rb_t *trav, node_rb_t *temp){
	if(trav == NULL)
		return temp;

	if(temp->data < trav->data){
		trav->leftChild = insertNode(trav->leftChild, temp);
		trav->leftChild->parent = trav;
	}
	else if(temp->data > trav->data){
		trav->rightChild = insertNode(trav->rightChild, temp);
		trav->rihtChild->parent = trav;
	}
	return trav;
}
