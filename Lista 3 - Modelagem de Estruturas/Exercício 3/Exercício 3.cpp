#include <stdio.h>

typedef struct {
    int numero;
    float saldo;
} Conta;

Conta criaConta(int numero) {
    Conta c = {numero, 0.0};
    return c;
}

void depositaNaConta(Conta *c, float valor) {
    c->saldo += valor;
}

void retiraDaConta(Conta *c, float valor) {
    c->saldo -= valor;
}

float obtemSaldo(Conta c) {
    return c.saldo;
}

int main() {
    Conta corrente, poupanca;
    int num;
    float saldo;

    printf("Numero e saldo da conta corrente: ");
    scanf("%d %f", &num, &saldo);
    corrente = criaConta(num);
    corrente.saldo = saldo;

    printf("Numero e saldo da conta poupanca: ");
    scanf("%d %f", &num, &saldo);
    poupanca = criaConta(num);
    poupanca.saldo = saldo;

    int op;
    float valor;

    do {
        printf("\nOperacao (1.Dep CC 2.Dep Poup 3.Ret CC 4.Ret Poup 5.Fim): ");
        scanf("%d", &op);

        if (op == 5) break;

        printf("Valor: ");
        scanf("%f", &valor);

        switch (op) {
            case 1:
                depositaNaConta(&corrente, valor);
                break;
            case 2:
                depositaNaConta(&poupanca, valor);
                break;
            case 3:
                if (corrente.saldo >= valor) {
                    retiraDaConta(&corrente, valor);
                } else {
                    float falta = valor - corrente.saldo;
                    if (poupanca.saldo >= falta) {
                        retiraDaConta(&poupanca, falta);
                        corrente.saldo = 0;
                    } else {
                        printf("Saldo insuficiente\n");
                    }
                }
                break;
            case 4:
                if (poupanca.saldo >= valor)
                    retiraDaConta(&poupanca, valor);
                else
                    printf("Saldo insuficiente\n");
                break;
        }

        printf("Saldo Corrente: %.2f\n", corrente.saldo);
        printf("Saldo Poupanca: %.2f\n", poupanca.saldo);

    } while (op != 5);

    return 0;
}

