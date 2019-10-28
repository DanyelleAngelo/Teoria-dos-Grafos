#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "matAdj.h"
#include "listAdj.h"
void initializeGraph(grafo **g, int resp){
  FILE *arq =fopen("grafo.txt","r");
  if(arq==NULL){
    printf("Ocorreu um erro ao abrir o arquivo!\n");
  }
  (*g) = malloc(sizeof(grafo));
  fscanf(arq,"%d",&((*g)->n_v));

  if(resp==1){
    (*g)->matAdj =fillMatrix((*g)->n_v,&((*g)->n_e),arq);
    (*g)->degree_v = countsDegreesMatrix((*g)->matAdj,(*g)->n_v);
  }else if(resp==2){
    (*g)->listAdj =fillList((*g)->n_v,&((*g)->n_e),arq);
    (*g)->degree_v = countsDegreesList((*g)->listAdj,(*g)->n_v);
  }
  fclose(arq);
}
void infoGraph(grafo **g){
  FILE *arq =fopen("saida.txt","w");
  int i;
  if(arq==NULL){
    printf("Ocorreu um erro ao criar o arquivo de saida!\n");
  }
  fprintf(arq,"# n = %d\n",(*g)->n_v);
  fprintf(arq,"# m = %d\n",(*g)->n_e);
  for(i=0;i<(*g)->n_v;i++){
    fprintf(arq,"%d %d\n",(i+1),(*g)->degree_v[i]);
  }
  fclose(arq);
}

void isConnected(grafo **g){

}
