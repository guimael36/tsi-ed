#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define PILHA_CHEIA 2
#define DADO_INEXISTENTE 3
#define MAX_NODOS 5

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    Dado v[MAX_NODOS];
    int topo;
} PilhaCF;

void criaPilha(PilhaCF *p);
int empilha(PilhaCF *p, Dado d);
int desempilha(PilhaCF *p, Dado *d);
int estaVazia(PilhaCF *p);
int consultaTopo(PilhaCF *p, Dado *d);
void exibe(PilhaCF *p);
int pesquisa(PilhaCF *p, int codigo, Dado *resultado);

#endif
