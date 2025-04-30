#ifndef ListaCF_H
#define ListaCF_H

#define MAX_NODOS 5

#define SUCESSO            0
#define LISTA_VAZIA        1
#define LISTA_CHEIA        2
#define POSICAO_INVALIDA   3
#define CODIGO_INEXISTENTE 4

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    int n;
    Dado v[MAX_NODOS];
} ListaCF;

void criaLista(ListaCF *l);
void exibe(ListaCF l);
int estaCheia(ListaCF l);
int estaVazia(ListaCF l);
int incluiNoFim(ListaCF *l, Dado d);
int excluiDoFim(ListaCF *l, Dado *d);
int incluiNoInicio(ListaCF *l, Dado d);
int excluiDoInicio(ListaCF *l, Dado *d);
int consultaPorCodigo(ListaCF l, int cod, Dado *d);
int incluiAntes(ListaCF *l, int cod, Dado d);
int excluiNodo(ListaCF *l, int cod, Dado *d);
int quantidadeDeNodos(ListaCF l);

#endif
