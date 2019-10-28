#ifndef LISTADJ
#define LISTADJ
typedef struct listNode{/*Vértice (nó) incidente sobre o vértice 'a'*/
  int vertex;/*Número/Rótulo do vértice incidente*/
  struct listNode *next;/*a ordem dos vértices armazenados na estrutura não indica ligação entre os mesmos (ou seja, não necessariamente
  o next/prev de um vértice é incidente sobre ele),estes ponteiros existem apenas para facilitar a iteração sobre a lista*/
  struct listNode *prev;/*Vértice conectado a um vértice 'a', analogo ao ponteiro acima*/
}listNode;
typedef listNode * nodeIterator;/*Ponteiro para iterar sobre a lista*/
typedef struct listVertex{/*Lista que armazena os vértices(listNode) incidentes sobre um vértice 'a'*/
  int degree;/*Grau da lista (do vértice a) - quantidade de elementos na lista*/
  listNode *head;/*Cabeça da lista, usada para facilitar a iteração sobre a mesma*/
  listNode *tail;/*Cauda da lista*/
}listVertex;
/*
@brief: chama a função que cria um vetor de listas que será armazenado na estrutura grafo(ver:graph.h), lê o arquivo fornecido
como parâmetro a função e para cada linha lida, verifica se os vértices podem existir, se sim, cria um novo nó(ver função
newNode), este nó nada mais é que um ponteiro para um vértice que incide sobre outro.
@param n_v: número de vértices do nosso grafo
@param n_e: número de arestas do grafo
@param arq: ponteiro para o arquivo que contém as informações iniciais do grafo
@return: vetor do tipo listVertex (cada posição do vetor tem uma lista de vértices incidentes)
*/
listVertex *fillList(int n_v,int *n_e, FILE *arq);
/*
@brief: cria um vetor de listas, inializando o grau, a cabeça e cauda de todas as listas presentes no vetor.
@param n_v: número de vértices do grafo.
@return: vetor do tipo listVertex (cada posição do vetor tem uma lista de vértices incidentes) para a função que a chamou
*/
listVertex *createVectorList(int n_v);
/*
@brief: cria um nó na lista do vértice v1 e v2 (adiciona v1 como incidente na lista do vértice v2 e vice versa). Aqui já atualizamos
o grau, a cabeça e a cauda da lista do vértice analisado.
@param vetor: vetor de listas, onde cada índice do vetor indica um vértice
@param v1: vértice incidente sobre v2
@param v2: vértice incidente sobre v1
*/
void newNode(listVertex *vetor,int v1,int v2);
/*
@brief: pecorre a o vetor de listas, copiando o grau de cada vértice para um vetor que será retornado pela função.
@param vetor: vetor de listas que armazena os vértices incidentes sobre outro.
@param n: número de vértices do grafo
@return: vetor que conté o grau de cada vértice
*/
int *countsDegreesList(listVertex *vetor,int n);
/*
@brief: imprime os vértices incidentes sobre cada vértice
@param vetor: vetor de listas que armazena os vértices incidentes sobre outro.
@param n: ordem da matriz
*/
void printListAdj(listVertex *vetor,int n);
#endif
