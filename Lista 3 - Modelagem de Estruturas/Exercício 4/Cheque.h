#ifndef CHEQUE_H
#define CHEQUE_H

typedef struct {
    int numero;
    float valor;
    int situacao; // 0 - Em branco, 1 - Emitido, 2 - Compensado
} Cheque;

Cheque criaCheque(int numero);
void exibeCheque(Cheque c);
int obtemSituacao(Cheque c);
float obtemValor(Cheque c);
int obtemNumero(Cheque c);
int compensaCheque(Cheque* c);
int emiteCheque(Cheque* c, float valor);

#endif

