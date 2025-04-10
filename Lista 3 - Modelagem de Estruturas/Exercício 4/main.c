#include <stdio.h>
#include "Cheque.h"

int main() {
    int num1, num2;
    float val1, val2;

    printf("Digite o numero do primeiro cheque: ");
    scanf("%d", &num1);
    printf("Digite o numero do segundo cheque: ");
    scanf("%d", &num2);

    Cheque c1 = criaCheque(num1);
    Cheque c2 = criaCheque(num2);

    printf("Digite o valor do primeiro cheque: ");
    scanf("%f", &val1);
    printf("Digite o valor do segundo cheque: ");
    scanf("%f", &val2);

    emiteCheque(&c1, val1);
    emiteCheque(&c2, val2);

    printf("\nCheques emitidos:\n");
    exibeCheque(c1);
    exibeCheque(c2);

    if (obtemValor(c1) > obtemValor(c2)) {
        compensaCheque(&c1);
    } else {
        compensaCheque(&c2);
    }

    printf("\nSituacoes dos cheques:\n");
    printf("Cheque 1: %d\n", obtemSituacao(c1));
    printf("Cheque 2: %d\n", obtemSituacao(c2));

    printf("\nNumeros dos cheques:\n");
    printf("Cheque 1: %d\n", obtemNumero(c1));
    printf("Cheque 2: %d\n", obtemNumero(c2));

    return 0;
}

