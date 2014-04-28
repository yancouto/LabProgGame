#include "List.h"
#include <stdlib.h>

Node *Node_new(void *item) {
	Node *n = (Node*) malloc(sizeof(Node));
	n->item = item;
	n->next = n->prev = NULL;
	return n;
}

void Node_remove(Node *n) {
	n->next->prev = n->prev;
	n->prev->next = n->next;
	free(n);
}

List *List_new() {
	List *l = (List*) malloc(sizeof(List));
	l->head = Node_new(NULL);
	l->head->next = l->head->prev = l->head;
	return l;
}

static void addAfter(Node *n, void *item) {
	Node *n2 = Node_new(item);
	n2->next = n->next;
	n2->prev = n;
	n->next = n2;
	n2->next->prev = n2;
}

void List_pushFront(List *this, void *item) {
	addAfter(this->head, item);
}

void List_pushBack(List *this, void *item) {
	addAfter(this->head->prev, item);
}

void Lista_delete(List *this) {
	while(this->head->next != this->head)
		Node_remove(this->head->next);
	free(this->head);
	free(this);
}