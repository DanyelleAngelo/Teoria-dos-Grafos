#ifndef QUEUE_H
#define QUEUE_H
typedef struct queue_node{
	int data;
	struct queue_node *next;
}queue_node;
typedef queue_node * queue_iterator;
typedef struct queue_t{
	queue_node *head;
	queue_node *tail;
	int size;
}queue_t;
void queue_initialize(queue_t **q);
queue_node * new_queue_node(int data);
void queue_delete_node(queue_node *node);
int queue_front(queue_t *q);
void queue_push(queue_t *q,int data);
void queue_pop(queue_t *q);
int queue_empty(queue_t *q);

#endif
