#include <stdio.h>
#include "Cheque.h"

Cheque criaCheque(int numero) {
    Cheque c;
    c.numero = numero;
    c.valor = 0.0;
    c.situacao = 0;
    return c;
}

void exibeCheque(Cheque c) {
    printf("Numero: %d | Valor: %.2f | Situacao: %d\n", c.numero, c.valor, c.situacao);
}

int obtemSituacao(Cheque c) {
    return c.situacao;
}

float obtemValor(Cheque c) {
    return c.valor;
}

int obtemNumero(Cheque c) {
    return c.numero;
}

int compensaCheque(Cheque* c) {
    if (c->situacao == 1) {
        c->situacao = 2;
        return 0;
    }
    return 1;
}

int emiteCheque(Cheque* c, float valor) {
    if (c->situacao == 0) {
        c->valor = valor;
        c->situacao = 1;
        return 0;
    }
    return 1;
}

