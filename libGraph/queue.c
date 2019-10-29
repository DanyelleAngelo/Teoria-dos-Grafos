#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void queue_initialize(queue_t **q){
	(*q) = malloc(sizeof(queue_t));
	(*q)->head=NULL;
	(*q)->tail=NULL;
	(*q)->size = 0;
}
queue_node * new_queue_node(int value){
	queue_node * new_node = malloc(sizeof(queue_node));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}
void queue_delete_node(queue_node *node){
	free(node);
}
int queue_front(queue_t *q){
	return q->head->data;
}
void queue_push(queue_t *q,int value){
	queue_node * new_node = new_queue_node(value);
	if(queue_empty(q)==0){
		q->head=new_node;
		q->tail=new_node;
		q->head->next=q->tail;
	}
	else{
		q->tail->next=new_node;
		q->tail=new_node;
	}
	q->size++;
}
void queue_pop(queue_t *q){
	queue_iterator aux=q->head;
	if(q->size==1){
		q->head=NULL;
		q->tail=NULL;
	}
	else{
		q->head=aux->next;
	}
	queue_delete_node(aux);
	q->size--;
}
int queue_empty(queue_t *q){
	if(q->size==0)return 0;
	else return 1;
}
