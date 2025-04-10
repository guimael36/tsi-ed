#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    Data nascimento;
} Aluno;

int calculaIdade(Data nasc, Data hoje) {
    int idade = hoje.ano - nasc.ano;
    if (hoje.mes < nasc.mes || (hoje.mes == nasc.mes && hoje.dia < nasc.dia))
        idade--;
    return idade;
}

int main() {
    Data hoje;
    printf("Data de hoje: ");
    scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);

    Aluno a;
    while (1) {
        printf("Matricula do aluno (negativa para sair): ");
        scanf("%d", &a.matricula);
        if (a.matricula < 0) break;

        printf("Data de nascimento: ");
        scanf("%d %d %d", &a.nascimento.dia, &a.nascimento.mes, &a.nascimento.ano);

        int idade = calculaIdade(a.nascimento, hoje);
        if (idade >= 18)
            printf("Aluno ja completou 18 anos.\n");
        else
            printf("Aluno ainda nao completou 18 anos.\n");
    }

    return 0;
}

