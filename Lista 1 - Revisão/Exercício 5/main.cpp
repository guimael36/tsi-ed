#include <stdio.h>

int main(){
    int q, z[10], y, w[10];

    printf("Quantos elementos tem o array? ");
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        printf("Digite o %d elemento do array: ", i+1);
        scanf("%d", &z[i]);
    }  

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    for(int i = 0; i < q; i++){
        if(z[i] > y){
            w[i] = z[i];
            printf("%d\n", w[i]);
        }
    }

    return 0;
}

