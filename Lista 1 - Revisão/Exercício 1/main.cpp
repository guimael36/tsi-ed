#include <stdio.h>
int main(){
    int q, sexo, fem = 0;
    float altura, contadorAltura = 0, totalAlunas = 0;

    printf("Quantidade de alunos: ");
    scanf("%d", &q);

    for(int i = 1; i <= q; i++){
        printf("Altura do aluno %d: ", i);
        scanf("%f", &altura);
        printf("Sexo do aluno (1 - Masculino, 2 - Feminino): ");
        scanf("%d", &sexo);

        if (sexo == 1){
            if (altura > contadorAltura){
                contadorAltura = altura;
            }
        } else if (sexo == 2){
            fem++;
            totalAlunas += altura;
        }
    }

    printf("Altura do aluno mais alto: %.2f\n", contadorAltura);
    printf("Media de altura das alunas: %.2f\n", totalAlunas/fem);
    return 0;
}