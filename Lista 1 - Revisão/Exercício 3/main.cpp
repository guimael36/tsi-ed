#include <stdio.h>

void exibeDivisores(){
    for(int i = 1; i <= 20; i++){
        printf("Divisores de %d: ", i);
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(){
    exibeDivisores();
}