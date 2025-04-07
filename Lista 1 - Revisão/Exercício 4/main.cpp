#include <stdio.h>

void maiorNumero(int num1, int num2){
    if (num1 > num2){
        printf("%d", num1);
    } else if (num2 > num1){
        printf("%d", num2);
    } else {
        printf("Eles sao iguais");
    }
}

int main(){
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int num1, num2;

        printf("N1: ");
        scanf("%d", &num1);

        printf("N2: ");
        scanf("%d", &num2);

        maiorNumero(num1, num2);
        printf("\n");
    }
}