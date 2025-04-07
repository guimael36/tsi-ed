#include <stdio.h>
int calcDivisao(int num1, int num2){
	if (num2 == 0){
		printf("Divisao por zero\n");
		return 1;
	} else {
		float resultado = (float) num1 / num2;
		printf("%.2f\n", resultado);
		return 0;
	}
}

int main(){
	int n, num1, num2;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d %d", &num1, &num2);
		
		calcDivisao(num1, num2);
	}
	
	return 0;
}
