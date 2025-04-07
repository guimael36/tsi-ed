#include <stdio.h>
int main() {
    int matriz[10][10], L, C, i, j, valor, encontrado;
    
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &L);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &C);

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser verificado (negativo para terminar):\n");

    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);

        if (valor < 0) {
            break;
        }

        encontrado = 0;
        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                if (matriz[i][j] == valor) {
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado) {
                break;
            }
        }

        if (encontrado) {
            printf("Esta na matriz \n");
        } else {
            printf("Nao esta na matriz \n");
        }
    }
}
