#ifndef LIST_H
#define LIST_H

typedef struct node Node;
struct node {
	void *item;
	Node *next;
	Node *prev;
};

Node *newNode(void *item);
void Node_remove(Node *n);

/* Lista duplamente ligada circular com cabeça pra facilitar a vida */
typedef struct {
	Node *head;
	/* Alguma outra coisa util */
} List;

List* newList();
void List_pushBack(List* this, void *item);
void List_pushFront(List *this, void *item);

#endif