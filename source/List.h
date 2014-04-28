#ifndef LIST_H
#define LIST_H

typedef struct node Node;
struct node {
	void *item;
	Node *next;
	Node *prev;
};

/* next e prev começam com NULL */
Node *Node_new(void *item);

/* Remove o no da lista e limpa a memoria */
void Node_remove(Node *n);

/* Lista duplamente ligada circular com cabeça pra facilitar a vida */
typedef struct {
	Node *head;
	/* Alguma outra coisa util */
} List;

List *List_new();

/* Adiciona no comeco da lista */
void List_pushBack(List *this, void *item);

/* Adiciona no final da lista */
void List_pushFront(List *this, void *item);

/* Destroi a lista e limpa a memoria */
void List_delete(List *this);

#endif