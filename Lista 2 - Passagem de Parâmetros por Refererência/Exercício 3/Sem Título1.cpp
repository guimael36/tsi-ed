#include <stdio.h>

void duplaClassificada(int codigo, int a, int b){
	if (codigo == 0){
		if (a > b){
			printf("%d %d\n", b, a);
		} else {
			printf("%d %d\n", a, b);
		}
	} else if (codigo == 1){
		if (a > b){
			printf("%d %d\n", a, b);
		} else {
			printf("%d %d\n", b, a);
		}
	}
}

int main(){
	int num1, num2, soma;
	
	while(1){
		scanf("%d %d", &num1, &num2);
		
		if (num1 == num2){
			break;
		}
		
		soma = num1 + num2;
		
		if (soma % 2 == 0){
			duplaClassificada(0, num1, num2);
		} else {
			duplaClassificada(1, num1, num2);
		}
	}
	
	return 0;
}
