#include <stdio.h>
#include "pilha.h"

void criaPilha(PilhaCF *p) {
    p->topo = -1;
}

int empilha(PilhaCF *p, Dado d) {
    if (p->topo == MAX_NODOS - 1)
        return PILHA_CHEIA;
    p->topo++;
    p->v[p->topo] = d;
    return SUCESSO;
}

int desempilha(PilhaCF *p, Dado *d) {
    if (p->topo == -1)
        return PILHA_VAZIA;
    *d = p->v[p->topo];
    p->topo--;
    return SUCESSO;
}

int estaVazia(PilhaCF *p) {
    return (p->topo == -1);
}

int consultaTopo(PilhaCF *p, Dado *d) {
    if (p->topo == -1)
        return PILHA_VAZIA;
    *d = p->v[p->topo];
    return SUCESSO;
}

void exibe(PilhaCF *p) {
    int i;
    if (p->topo == -1) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos da pilha (do topo para a base):\n");
    for (i = p->topo; i >= 0; i--) {
        printf("Código: %d, Peso: %.2f\n", p->v[i].cod, p->v[i].peso);
    }
}

int pesquisa(PilhaCF *p, int codigo, Dado *resultado) {
    int i;
    if (p->topo == -1)
        return PILHA_VAZIA;

    for (i = p->topo; i >= 0; i--) {
        if (p->v[i].cod == codigo) {
            *resultado = p->v[i];
            return SUCESSO;
        }
    }
    return DADO_INEXISTENTE;
}

