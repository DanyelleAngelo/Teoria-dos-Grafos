/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libGraph/graph.h"
#include "libGraph/listAdj.h"
#include "libGraph/matAdj.h"
int main(void){
  grafo *g;
  int opcao,t_busca,v_inicial;
  setlocale(LC_ALL, "Portuguese");
  while(1){
    printf("\t------- Escolha uma opção -------\n\n");
    printf("0 - Encerrar programa\n1 - Busca em matriz de adjacência\n2 - Busca em lista de adjacência\n3 - Verificar componentes conexos\n4 - Distância entre vértices\n");
    printf("---------- Opção:");
    scanf("%d",&opcao);
    if(opcao==0){
      printf("\n\n\t---------- Sessão encerrada! ----------\n");
      break;
    }else if(opcao==1 || opcao==2 || opcao==3 || opcao==4){
      initializeGraph(&g,opcao);
      infoGraph(&g);
      if(opcao==1 || opcao==2){
          printf("\n\n\t------- Operações disponíveis -------\n");
          printf("0 - Encerrar programa\n1 - Busca em largura\n2 - Busca em Profundidade\n");
          printf("---------- Opção:");
          scanf("%d",&t_busca);
          if(t_busca==1 || t_busca ==2){
            printf("Digite o vértice inicial do grafo:\n");
            scanf("%d",&v_inicial);
            findSearch(&g,v_inicial,t_busca,opcao);

          }else if(t_busca==0){
              printf("\n\n\t---------- Sessão encerrada! ----------\n");
              break;
          }
        //  if(opcao==2)listDelete((*g).listAdj,(*g).n_v);//deleta lista da memória
      }else if(opcao==4){
        int v_inicial,v_final;
        printf("Digite o vértice inicial da busca:");
        scanf("%d",&v_inicial);
        printf("Digite o vértice final da busca:");
        scanf("%d",&v_final);
        dijkstra((*g).matAdj,(*g).n_v,v_inicial,v_final);
      }
    }else{
      printf("Opção inválida!\n");
    }
    printf("\n\n\n");
  }
  free(g);
  g=NULL;
}
