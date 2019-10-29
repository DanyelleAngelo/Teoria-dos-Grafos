/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#include <stdio.h>
#include <stdlib.h>
#include "listAdj.h"
listVertex *fillList(int n_v,int *n_e,int *degree_v, FILE *arq){
  int v1,v2;
  listVertex *vetor=createVectorList(n_v);
  while(1){
    if(fscanf(arq,"%d %d",&v1,&v2)!=EOF){
      (*n_e)++;//número de arestas
      if((v1<=n_v && v2<=n_v) && (v1>0 && v2>0)){/*Os rótulos dos vértices não podem ser maior que o número de vértices,nem negativos*/
        newNode(vetor,v1,v2);
        degree_v[v1-1]+=1;//incrementa o grau do vértice v1
        degree_v[v2-1]+=1;//incrementa o grau do vértice v2
      }
      else{
        printf("Os vertices informados no arquivo nao existem!\n");
      }
    }
    else{
      break;
    }
  }
  return vetor;
}
listVertex *createVectorList(int n_v){
  listVertex *vetor=calloc(n_v,sizeof(listVertex));
  int i;
  for(i=0;i<n_v;i++){
    /*Para cada posição do nosso vetor de listas:a cabeça e a cauda tem valor NULL*/
    vetor[i].head=NULL;
    vetor[i].tail=NULL;
  }
  return vetor;
}
void newNode(listVertex *vetor,int v1,int v2){
  listNode *nodeV2= malloc(sizeof(listNode));/*aloca espaço na memŕoia para o vértice v2*/
  listNode *nodeV1= malloc(sizeof(listNode));/*aloca espaço na memória para o vértice v1*/
  nodeIterator aux;
  int i;
  nodeV2->vertex = v2;
  nodeV1->vertex = v1;

  //vértice 1 se liga ao 2
  if(vetor[v1-1].head==NULL){/*O vértice v1 até o momento não tinha nenhum vértice incidente sobre ele*/
    vetor[v1-1].head=nodeV2;
    nodeV1->next=NULL;
    nodeV1->prev=NULL;
  }else{/*o vértice v1 já possui outros vértices ligados a ele*/
    aux=vetor[v1-1].tail;/*sempre adicionaremos novos vértices a cauda, por isso fazer uma cópia*/
    aux->next = nodeV2;//atualiza ponteiros
    nodeV2->prev = aux;
    nodeV2->next=NULL;
  }
  vetor[v1-1].tail=nodeV2;//a nova cauda é o último elemento


  //vértice 2 se liga ao 1
  if(vetor[v2-1].head==NULL){/*O vértice v2 até o momento não tinha nenhum vértice incidente sobre ele*/
    vetor[v2-1].head=nodeV1;
    nodeV1->next=NULL;
    nodeV1->prev=NULL;
  }else{/*o vértice v2 já possui outros vértices ligados a ele*/
    aux=vetor[v2-1].tail;/*sempre adicionaremos novos vértices a cauda, por isso fazer uma cópia*/
    aux->next = nodeV1;//atualiza ponteiros
    nodeV1->prev = aux;
    nodeV1->next=NULL;
  }
  vetor[v2-1].tail=nodeV1;//a nova cauda é o último elemento
}

void printListAdj(listVertex *vetor,int *grau,int n){
  int i,j;
  for(i=0;i<n;i++){
    printf("Vertex: %d\n",i+1);
    printf("Vertex incidentes: ");
    nodeIterator aux = vetor[i].head;
    for(j=0;j<grau[i];j++){
      printf("%d ",aux->vertex);
      aux=aux->next;
    }
    printf("\n---------\n");
  }
}
void listDelete(listVertex *vetor, int n){
  int i;
  for(i=0;i<n;i++){
    while(vetor[i].head!=NULL){
      removeHead(&vetor[i]);
    }
  }
}
void removeHead(listVertex *lista){
	nodeIterator node = lista->head;
	lista->head=node->next;
	if(lista->head==NULL){
		lista->tail=NULL;
	}
	free(node);
}
