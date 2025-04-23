#ifndef PILHACF_H
#define PILHACF_H

#define SUCESSO 0 
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define DADO_INEXISTENTE 3
#define MAX_NODOS 5

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    Dado v[MAX_NODOS];
    int frente;
    int re;
    int qtde;
} FilaCF;

void criaFila(FilaCF *f);
int insere(FilaCF *f, Dado d);
int retira(FilaCF *f, Dado *d);
int estaVazia(FilaCF *f);
int consulta(FilaCF *f, Dado *d);
void exibe(FilaCF *f);
int pesquisa(FilaCF *f, int codigo, Dado *d);
int quantidade(FilaCF *f);
int filaCheia(FilaCF *f);

#endif

