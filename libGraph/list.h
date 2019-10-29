#ifndef LIST_H
#define LIST_H
/*Neste programa podemo optar por usar uma fila e uma pilha(podemos "simular" a pilha através de um algoritmo recursivo), portanto implementaremos uma fila e usaremos as funções
de listas e pilhas (que são filas) para remover e adicionar elementos. Observação: a diferença real da pilha e
da fila é once insiro o elemento. Na fila insiro um elemento sempre na cauda (assim removo sempre o elemento mais antigo),
na pilha adiciono o elemento sempre na cabeça, assim removo sempre o elemento mais novo*/
typedef struct list_node{
	int data;
	struct list_node *next;
}list_node;
typedef list_node * list_iterator;
typedef struct list_t{
	list_node *head;
	list_node *tail;
	int size;
}list_t;
void list_initialize(list_t **q);
list_node * new_list_node(int data);
void list_delete_node(list_node *node);
int list_front(list_t *q);
void list_pop(list_t *q);
void queue_push(list_t *q,int data);
void stack_push(list_t *s,int value);
int list_empty(list_t *q);

#endif
