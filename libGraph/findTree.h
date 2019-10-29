/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#ifndef FINDTREE
#define FINDTREE
#include "graph.h"
void findSearch(grafo **g,int v_inicial,int opcao,int resp);
void bfsListAdj(grafo *g,int v_inicial,FILE *arq);
void bfsMatAdj(grafo *g,int v_inicial,FILE *arq);
void is_visitedMat(int **mat,int n, int vertice);
#endif
