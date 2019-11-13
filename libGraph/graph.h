/*
*Instituto Federal de Educação, Ciência e Tecnologia de Brasília.
*Autoras: Carlos Eduardo Pereira Santana; Danyelle da Silva Oliveira Angelo e Raquel Pinheiro Costa
*
*Trabalho desenvolvido como requisito de avaliação parcial da disciplina de Teoria dos Grafos, ministrada
*pelo professor Raimundo Cláudios Vasconcelos no segundo semestre de 2019.
*/
#ifndef GRAPH
#define GRAPH
#include "listAdj.h"
typedef struct grafo{
  int n_v;/*Número de vértices do nosso grafo, primeira linha do arquivo a ser lido*/
  int n_e;/*Número de arestas do nosso grafo, número de linhas lido aṕos a primeira linha (cada par de vértices é uma aresta)*/
  int *degree_v;/*Vetor onde o valor armazenado em cada posição indica o grau de cada vértice, cada vértice aqui é encarado como o índice do vetor, por exemplo o vértice 9 de um grafo é o índice 8 do nosso vetor (o vetor começa em zero).*/
  int **matAdj;/*Matriz de adjascência nxn (n=número de vértices). Sempre que o vértice 'a' tiver incidência sobre o vértice 'b', a posição a,b e b,a será setada como 1*/
  listVertex *listAdj;/*Vetor de listas, onde para cada posição do vetor existe uma lista com os vértices incidentes sobre aquela posição*/
}grafo;
/*
@brief: Abre o aqruivo a ser lido, aloca na memória um espaço para a estrutura grafo, ler e armazena o número de vértices do nosso grafo,
chama as funções que cria  lista de adjascência ou matriz de adjascência (de acordo com a opção escolhida pelo usuário).
@param g: ponteiro para o grafo alocado na memória
@param resp: armazena a opção escolhida pelo usuário, 1=gerar matriz de adjascência, 2=gerar lista de adjascência
*/
void initializeGraph(grafo **g,int resp);
/*
@brief: cria/abre o arquivo de saída, grava as informações do grafo (número de vértices, arestas e grau de cada vértice) no arquivo aberto.
@param: g ponteiro para o grafo analisado
*/
void infoGraph(grafo **g);
/**/
void isConnected(grafo **g);

/*
@brief: Verifica o tipo de busca a ser usado e em qual representação deve ser feito a busca, em seguida reencaminha
o programação para busca na representação escolhida.
@param g: grafo sobre o qual se dará a operação
@param v_inicial: elemento raíz da árvore a ser gerada
@param t_busca: tipo e busca a ser feito (profundidade/largura)
@param representacao: tipo de representaçaõ do grafo (matriz de adjacência/lista de adjascência)
*/
void findSearch(grafo **g,int v_inicial,int t_busca,int representacao);
/*
@brief: realiza a busca em largura usando Lista de adjacência
@param g: grafo sobre qual estamos realizando a operação
@param v_inicial: raíz da árvore
@param arq: arquivo no qual farei a gravação das informações da árvore (busca_listAdj.txt)
*/
void bfsListAdj(grafo *g,int v_inicial,FILE *arq);
/*
@brief: realiza a busca em largura usando Matriz de adjacência
@param g: grafo sobre qual estamos realizando a operação
@param v_inicial: raíz da árvore
@param arq: arquivo no qual farei a gravação das informações da árvore (busca_MatAdj.txt)
*/
void bfsMatAdj(grafo *g,int v_inicial,FILE *arq);
/*
@brief: realiza a busca em profundidade usando Matriz de adjacência
@param g: grafo sobre qual estamos realizando a operação
@param v_inicial: raíz da árvore
@param arq: arquivo no qual farei a gravação das informações da árvore (busca_MatAdj.txt)
*/
void dfsMatAdj(grafo *g,int v_inicial,FILE *arq);
/*
@brief: realiza a busca em profundida usando Lista de adjacência
@param g: grafo sobre qual estamos realizando a operação
@param v_inicial: raíz da árvore
@param arq: arquivo no qual farei a gravação das informações da árvore (busca_ListAdj.txt)
*/
void dfsListAdj(grafo *g,int v_inicial,FILE *arq);
/*
@brief: usado para marcar os vértices visitados nas buscas em matriz de adjascência. Antes os vértices que não tinham sido
visitados, mas que existiam no grafo estavam marcados com 1 (havia correspondência entre linha e coluna da matriz (v1 e v2)).
@param n: quantidade de vértices
@param vertice: vértice visitado
@param mat: matriz analisada
*/
void is_visitedMat(int **mat,int n, int vertice);
#endif
