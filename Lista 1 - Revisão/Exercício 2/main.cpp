#include <stdio.h>

void exibeOnzeTracos(){
    for(int i = 0; i < 11; i++){
        printf("-");
    }
}

void retanguloTracos(){
    for(int i = 0; i < 4; i++){
        exibeOnzeTracos();
        printf("\n");
    }
}

int main(){
    retanguloTracos();
    printf("\n");
    retanguloTracos();
}