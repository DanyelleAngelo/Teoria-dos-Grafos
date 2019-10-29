/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#include <stdio.h>
#include <stdlib.h>
#include "findTree.h"
#include "graph.h"
#include "list.h"
#include "listAdj.h"
void findSearch(grafo **g,int v_inicial, int opcao,int resp){
  v_inicial = v_inicial;
  if(v_inicial<0 || v_inicial>((*g)->n_v)){
    printf("Este vértice não existe\n" );
  }else{
    if(resp==2){/*A estrutura é lista de adjascência*/
      FILE *arq = fopen("busca_listAdj.txt","w");
      if(arq==NULL){
        printf("Ocorreu um erro ao abrir o arquivo!");
      }else{
        if(opcao==1)bfsListAdj(*g,v_inicial,arq);
      }
    }else {/*A estrutura é matriz de adjascência*/
      FILE *arq = fopen("busca_MatAdj.txt","w");
      if(arq==NULL){
        printf("Ocorreu um erro ao abrir o arquivo!");
      }else{
        if(opcao==1)bfsMatAdj(*g,v_inicial,arq);
        if(opcao==2)dfsMatAdj(*g,v_inicial,arq);
      }
    }
  }
}
void bfsListAdj(grafo *g,int v_inicial,FILE *arq){
  /*Sempre que formos acessar uma posição do vetor de elementos visitados (visited) decrementaremos o índice em 1,
   isso porque o vetor inicia em 0,e na nossa lista de adjacência não levamos em consideração isso. Como esse vetor
   faz relação com a nossa fila(sempre que marcamos um intem como visitado, adicionamos ele a fila para visitar
  seus filhos mais tarde), os elementos gravados na nossa fila também serão decrementados em 1. Assim sendo,
  na hora de passar essas informações para o arquivo de saída, incrementaremos esses mesmos valores em 1 para que
  o usuário veja a informação da forma como está acostumado*/
  int i,v;
  int *visited = calloc((*g).n_v,sizeof(int));
  int *pai = calloc((*g).n_v,sizeof(int));
  int *nivel = calloc((*g).n_v,sizeof(int));
  list_t *q;
  visited[v_inicial-1]=1;
  nodeIterator aux;
  list_initialize(&q);
  queue_push(q,v_inicial-1);
  fprintf(arq, "\t\tBusca em largura com lista de adjascência\n\n");
  while((q->size)>0){
    v = list_front(q);
    fprintf(arq, "---------- Vértice: %d, ",v+1);
    if(pai[v]==0)fprintf(arq, " nível: %d -> raíz da árvore\n",nivel[v]);
    else{
      fprintf(arq, "nível: %d -> vértice pai: %d\n",nivel[v],pai[v]);
    }
    list_pop(q);
    aux = (*g).listAdj[v].head;//usado para pecorrer os filhos de cada vértice pai
    for(i=0;i<(*g).degree_v[v];i++){
      /*Para cada elemento pai encontrado no vetor, buscarei por seus filhos, marcamos os mesmos como visitados,
      adicionamos os mesmos a fila, definimos seu pai, e seu nível*/
      if(visited[(aux->vertex)-1]!=1){
        visited[(aux->vertex)-1]=1;
        pai[(aux->vertex)-1]=v+1;
        nivel[(aux->vertex)-1] = nivel[v]+1;
        queue_push(q,(aux->vertex)-1);
      }
      aux=aux->next;//avança para o próximo filho do vértice
    }
  }
  free(q);
  q=NULL;
}
void bfsMatAdj(grafo *g,int v_inicial,FILE *arq){
  int i,v;
  int *pai = calloc((*g).n_v,sizeof(int));//vetor que armazenará os pais dos vértices
  int *nivel = calloc((*g).n_v,sizeof(int));//vetor que armazenará a ordem em que os vértices são visitado
  list_t *q;
  list_initialize(&q);
  queue_push(q,v_inicial-1);
  is_visitedMat((*g).matAdj,(*g).n_v,v_inicial);
  fprintf(arq, "\t\tBusca em largura com matriz de adjascência\n\n");
  while((q->size)>0){
    v = list_front(q);
    fprintf(arq, "---------- Vértice: %d, ",v+1);
    if(pai[v]==0)fprintf(arq, " nível: %d -> raíz da árvore\n",nivel[v]);
    else{
      fprintf(arq, "nível: %d -> vértice pai: %d\n",nivel[v],pai[v]+1);
    }
    list_pop(q);
  for(i=0;i<(*g).n_v;i++){
      if((*g).matAdj[v][i]==1){
        /*Existe correspondência entre o vértice analisado e o vértice i, iremos adiciona ele a fila,marcar ele como
        lido, salvar seu pai e seu nível*/
        queue_push(q,i);
        is_visitedMat((*g).matAdj,(*g).n_v,i);
        pai[i]=v;
        nivel[i]=nivel[pai[i]]+1;
      }
    }
  }
  free(q);
  q=NULL;
}
void dfsMatAdj(grafo *g,int v_inicial,FILE *arq){
  int i,v;
  int *visitados = calloc((*g).n_v,sizeof(int));//marca os vértices visitados
  int *pai= calloc((*g).n_v,sizeof(int));//marca os vértices visitados
  int *nivel= calloc((*g).n_v,sizeof(int));//marca os vértices visitados
  list_t *s;
  list_initialize(&s);
  stack_push(s,v_inicial-1);
  fprintf(arq, "\t\tBusca em profundidade com matriz de adjascência\n\n");
  while((s->size)>0){
    v = list_front(s);
    list_pop(s);
    if(visitados[v]==1)continue;
    visitados[v]=1;
    fprintf(arq, "---------- Vértice: %d, ",v+1);
    if(pai[v]==0){
      fprintf(arq, " nível: %d -> raíz da árvore\n",nivel[v]);
    }
    else fprintf(arq, "nível: %d -> vértice pai: %d\n",nivel[v],pai[v]+1);
    for(i=0;i<(*g).n_v;i++){
      if(visitados[i]==0 && (*g).matAdj[v][i]==1){
        if(pai[i]==0){
          pai[i]=v;
          nivel[i] = nivel[v]+1;
        }
        stack_push(s,i);
      }
    }
  }
  free(s);
  s=NULL;
}
void is_visitedMat(int **mat,int n, int vertice){
  int i;
  for(i=0;i<n;i++)mat[i][vertice]=0;
}
