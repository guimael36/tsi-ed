#include <stdio.h>

void classificaCrescente(int a, int b, int *menor, int *maior) {
    if (a < b) {
        *menor = a;
        *maior = b;
    } else {
        *menor = b;
        *maior = a;
    }
}

int main() {
    int num1, num2;
    int menor, maior;

    while (1) {
        scanf("%d %d", &num1, &num2);

        if (num1 == num2) {
            break;
        }

        classificaCrescente(num1, num2, &menor, &maior);

        printf("%d %d\n", menor, maior);
    }

    return 0;
}

