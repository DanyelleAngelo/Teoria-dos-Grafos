/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#include <stdio.h>
#include <stdlib.h>
#include "matAdj.h"
int **allocateMatrix(int n){
  int **matriz,i;
  matriz = calloc(n,sizeof(int*));
  if(matriz[0]=NULL){
    printf("Ocorreu um erro ao tentar alocar a matriz!");
  }
  else{
    for(i=0;i<n;i++){
      matriz[i]=calloc(n,sizeof(int));
    }
  }
  return matriz;
}
int **fillMatrix(int n_v,int *n_e,int *degree_v, FILE *arq){
  int i,**matriz = allocateMatrix(n_v), v1,v2;
  while(1){
    if(fscanf(arq,"%d %d",&v1,&v2)!=EOF){
      (*n_e)++;
      if((v1<=n_v && v2<=n_v) && (v1>0 && v2>0)){
        v1 = v1-1;//nossos vértices começam em 0 e não em 1, por isso diminuir esses valores aqui
        v2= v2-1;
        matriz[v1][v2]=1;//indica ligação entre o vértice v1 e o v2
        matriz[v2][v1]=1;
        degree_v[v1]+=1;
        degree_v[v2]+=1;
      }
      else{
        printf("Os vertices informados no arquivo nao existem!\n");
      }
    }
    else{
      break;
    }
  }
  return matriz;
}
void printMatAdj(int **matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
}
