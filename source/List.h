#ifndef LIST_H
#define LIST_H

/******************** Node stuff **********************/

typedef struct _struct_node Node;
struct _struct_node {
	void *item;
	Node *next;
	Node *prev;
};

/* Pseudo-iterador. Para facilitar a vida mas mesmo assim deixar 
 * conciso, Node tambem e' um "iterador". 
 */
typedef Node Iterator;

/* next e prev começam com NULL */
Node *Node_new(void *item);

/* Remove o no da lista e limpa a memoria. Retorna o proximo no. */
Node* Node_remove(Node *n);

/* "Cria" um novo iterador. */
#define Iterator_new(list) (list)->head->next;

/******************** List stuff **********************/

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
void List_delete(List*);

/* Limpa a lista, tornando-a vazia. */
void List_clear(List*);

#endif