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
#include "queue.h"
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
  int *visited = calloc((*g).n_v,sizeof(int));
  int *pai = calloc((*g).n_v,sizeof(int));
  int *nivel = calloc((*g).n_v,sizeof(int));
  visited[v_inicial-1]=1;
  queue_t *q;
  int i,v;
  nodeIterator aux;
  queue_initialize(&q);
  queue_push(q,v_inicial-1);
  fprintf(arq, "\t\tBusca em largura com lista de adjascência\n\n");
  while((q->size)>0){
    v = queue_front(q);
    fprintf(arq, "---------- Vértice: %d, ",v+1);
    if(pai[v]==0)fprintf(arq, " nível: %d -> raíz da árvore\n",nivel[v]);
    else{
      fprintf(arq, "nível: %d -> vértice pai: %d\n",nivel[v],pai[v]);
    }
    queue_pop(q);
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
}
void bfsMatAdj(grafo *g,int v_inicial,FILE *arq){
  int *pai = calloc((*g).n_v,sizeof(int));
  int *nivel = calloc((*g).n_v,sizeof(int));
  queue_t *q;
  int i,v;
  queue_initialize(&q);
  queue_push(q,v_inicial-1);
  is_visitedMat((*g).matAdj,(*g).n_v,v_inicial);
  fprintf(arq, "\t\tBusca em largura com matriz de adjascência\n\n");
  while((q->size)>0){
    v = queue_front(q);
    fprintf(arq, "---------- Vértice: %d, ",v+1);
    if(pai[v]==0)fprintf(arq, " nível: %d -> raíz da árvore\n",nivel[v]);
    else{
      fprintf(arq, "nível: %d -> vértice pai: %d\n",nivel[v],pai[v]+1);
    }
    queue_pop(q);
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
}
void is_visitedMat(int **mat,int n, int vertice){
  int i;
  for(i=0;i<n;i++)mat[i][vertice]=0;
}
