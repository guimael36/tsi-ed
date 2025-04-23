#include <stdio.h>
#include "fila.h"

void criaFila(FilaCF *f) {
    f->frente = 0;
    f->re = 0;
    f->qtde = 0;
}

int insere(FilaCF *f, Dado d) {
    if (f->qtde == MAX_NODOS) return FILA_CHEIA;
    f->v[f->re] = d;
    f->re = (f->re + 1) % MAX_NODOS;
    f->qtde++;
    return SUCESSO;
}

int retira(FilaCF *f, Dado *d) {
    if (f->qtde == 0) return FILA_VAZIA;
    *d = f->v[f->frente];
    f->frente = (f->frente + 1) % MAX_NODOS;
    f->qtde--;
    return SUCESSO;
}

int estaVazia(FilaCF *f) {
    return f->qtde == 0;
}

int consulta(FilaCF *f, Dado *d) {
    if (f->qtde == 0) return FILA_VAZIA;
    *d = f->v[f->frente];
    return SUCESSO;
}

void exibe(FilaCF *f) {
    if (f->qtde == 0) {
        printf("Fila vazia.\n");
        return;
    }
    int i, pos = f->frente;
    for (i = 0; i < f->qtde; i++) {
        printf("Codigo: %d | Peso: %.2f\n", f->v[pos].cod, f->v[pos].peso);
        pos = (pos + 1) % MAX_NODOS;
    }
}

int pesquisa(FilaCF *f, int codigo, Dado *d) {
    if (f->qtde == 0) return FILA_VAZIA;
    int i, pos = f->frente;
    for (i = 0; i < f->qtde; i++) {
        if (f->v[pos].cod == codigo) {
            *d = f->v[pos];
            return SUCESSO;
        }
        pos = (pos + 1) % MAX_NODOS;
    }
    return DADO_INEXISTENTE;
}

int quantidade(FilaCF *f) {
    return f->qtde;
}

int filaCheia(FilaCF *f) {
    return f->qtde == MAX_NODOS;
}

