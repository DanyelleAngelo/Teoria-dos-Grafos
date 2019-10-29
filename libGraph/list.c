#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_initialize(list_t **q){
	(*q) = malloc(sizeof(list_t));
	(*q)->head=NULL;
	(*q)->tail=NULL;
	(*q)->size = 0;
}
list_node * new_list_node(int value){
	list_node * new_node = malloc(sizeof(list_node));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}
void list_delete_node(list_node *node){
	free(node);
}
int list_front(list_t *q){
	return q->head->data;
}
void queue_push(list_t *q,int value){
	list_node * new_node = new_list_node(value);
	if(list_empty(q)==0){
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
void list_pop(list_t *q){
	list_iterator aux=q->head;
	if(q->size==1){
		q->head=NULL;
		q->tail=NULL;
	}
	else{
		q->head=aux->next;
	}
	list_delete_node(aux);
	q->size--;
}
void stack_push(list_t *s,int value){
	list_node *new_node=new_list_node(value);
	new_node->next=s->head;
	s->head=new_node;
	if(list_empty(s)==0){
		s->tail=new_node;
	}
	s->size++;
}
int list_empty(list_t *q){
	if(q->size==0)return 0;
	else return 1;
}
