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
  int representacao,t_busca,v_inicial;
  setlocale(LC_ALL, "Portuguese");
  while(1){
    printf("\t------- Escolha uma forma de representação para o grafo -------\n\n");
    printf("0 - Encerrar programa\n1 - Matriz de adjacência\n2 - Lista de adjacência\n");
    printf("---------- Opção:");
    scanf("%d",&representacao);
    if(representacao==0){
      printf("\n\n\t---------- Sessão encerrada! ----------\n");
      break;
    }
    else if(representacao==1 || representacao==2){
        initializeGraph(&g,representacao);
        infoGraph(&g);
        printf("\n\n\t------- Operações disponíveis -------\n");
        printf("0 - Encerrar programa\n1 - Busca em largura\n2 - Busca em Profundidade\n3 - Verificar componentes conexos\n");
        printf("---------- Opção:");
        scanf("%d",&t_busca);
        if(t_busca==1 || t_busca ==2){
          printf("Digite o vértice inicial do grafo:\n");
          scanf("%d",&v_inicial);
          findSearch(&g,v_inicial,t_busca,representacao);

        }else if(t_busca==0){
            printf("\n\n\t---------- Sessão encerrada! ----------\n");
            break;
        }
      //  if(representacao==2)listDelete((*g).listAdj,(*g).n_v);//deleta lista da memória

        break;
    }else{
      printf("Opção inválida!\n");
    }
    printf("\n\n\n");
  }
  free(g);
  g=NULL;
}
