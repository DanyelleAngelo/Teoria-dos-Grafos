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
#include <time.h>
#include "libGraph/graph.h"
#include "libGraph/findTree.h"
#include "libGraph/listAdj.h"
#include "libGraph/matAdj.h"
int main(void){
  grafo *g;
  int resp,opcao,v_inicial;
   clock_t Ticks[2];
   Ticks[0] = clock();
  setlocale(LC_ALL, "Portuguese");
  while(1){
    printf("\t------- Escolha uma forma de representação para o grafo -------\n\n");
    printf("0 - Encerrar programa\n1 - Matriz de adjacência\n2 - Lista de adjacência\n");
    printf("---------- Opção:");
    scanf("%d",&resp);
    if(resp==0){
      printf("\n\n\t---------- Sessão encerrada! ----------\n");
      break;
    }
    else if(resp==1 || resp==2){
        initializeGraph(&g,resp);
        infoGraph(&g);
        printf("\n\n\t------- Operações disponíveis -------\n");
        printf("0 - Encerrar programa\n1 - Busca em largura\n2 - Busca em Profundidade\n3 - Verificar componentes conexos\n");
        printf("---------- Opção:");
        scanf("%d",&opcao);
        if(opcao==1 || opcao ==2){
          printf("Digite o vértice inicial do grafo:\n");
          scanf("%d",&v_inicial);
          findSearch(&g,v_inicial,opcao,resp);

        }else if(opcao==0){
            printf("\n\n\t---------- Sessão encerrada! ----------\n");
            break;
        }
      //  if(resp==2)listDelete((*g).listAdj,(*g).n_v);//deleta lista da memória

        break;
    }else{
      printf("Opção inválida!\n");
    }
    printf("\n\n\n");
  }
  free(g);
  g=NULL;
  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo gasto: %g ms.", Tempo);
}
