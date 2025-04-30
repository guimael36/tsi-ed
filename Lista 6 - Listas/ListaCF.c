#include <stdio.h>
#include "ListaCF.h"

void criaLista(ListaCF *l) {
    l->n = 0;
}

void exibe(ListaCF l) {
	int i;
    if (l.n == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (i = 0; i < l.n; i++) {
        printf("Posição %d: Código = %d, Peso = %.2f\n", i, l.v[i].cod, l.v[i].peso);
    }
}

int estaCheia(ListaCF l) {
    return l.n == MAX_NODOS;
}

int estaVazia(ListaCF l) {
    return l.n == 0;
}

int incluiNoFim(ListaCF *l, Dado d) {
    if (estaCheia(*l))
        return LISTA_CHEIA;
    l->v[l->n++] = d;
    return SUCESSO;
}

int excluiDoFim(ListaCF *l, Dado *d) {
    if (estaVazia(*l))
        return LISTA_VAZIA;
    *d = l->v[--l->n];
    return SUCESSO;
}

int incluiNoInicio(ListaCF *l, Dado d) {
	int i;
    if (estaCheia(*l))
        return LISTA_CHEIA;
    for (i = l->n; i > 0; i--) {
        l->v[i] = l->v[i - 1];
    }
    l->v[0] = d;
    l->n++;
    return SUCESSO;
}

int excluiDoInicio(ListaCF *l, Dado *d) {
	int i;
	
    if (estaVazia(*l))
        return LISTA_VAZIA;
    *d = l->v[0];
    for (i = 0; i < l->n - 1; i++) {
        l->v[i] = l->v[i + 1];
    }
    l->n--;
    return SUCESSO;
}

int consultaPorCodigo(ListaCF l, int cod, Dado *d) {
	int i;
	
    for (i = 0; i < l.n; i++) {
        if (l.v[i].cod == cod) {
            *d = l.v[i];
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int incluiAntes(ListaCF *l, int cod, Dado d) {
    if (estaCheia(*l))
        return LISTA_CHEIA;
    int i, j;
    for (i = 0; i < l->n; i++) {
        if (l->v[i].cod == cod)
            break;
    }
    if (i == l->n)
        return CODIGO_INEXISTENTE;
    for (j = l->n; j > i; j--) {
        l->v[j] = l->v[j - 1];
    }
    l->v[i] = d;
    l->n++;
    return SUCESSO;
}

int excluiNodo(ListaCF *l, int cod, Dado *d) {
    int i, j;
    for (i = 0; i < l->n; i++) {
        if (l->v[i].cod == cod)
            break;
    }
    if (i == l->n)
        return CODIGO_INEXISTENTE;
    *d = l->v[i];
    for (j = i; j < l->n - 1; j++) {
        l->v[j] = l->v[j + 1];
    }
    l->n--;
    return SUCESSO;
}

int quantidadeDeNodos(ListaCF l) {
    return l.n;
}
