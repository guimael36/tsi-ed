#include <stdio.h>
#include "pilha.h"

int main() {
    PilhaCF pilha;
    Dado d;
    int opcao, cod, status;

    criaPilha(&pilha);

    do {
        printf("\n==== MENU ====\n");
        printf("1. Empilha\n");
        printf("2. Desempilha\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da pilha\n");
        printf("5. Consulta topo\n");
        printf("6. Pesquisa codigo\n");
        printf("0. Fim\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o codigo e peso: ");
                scanf("%d %f", &d.cod, &d.peso);
                status = empilha(&pilha, d);
                if (status == SUCESSO)
                    printf("Empilhado com sucesso.\n");
                else
                    printf("Erro: Pilha cheia.\n");
                break;

            case 2:
                status = desempilha(&pilha, &d);
                if (status == SUCESSO)
                    printf("Desempilhado: Codigo: %d, Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Erro: Pilha vazia.\n");
                break;

            case 3:
                printf("Quantidade de nodos: %d\n", pilha.topo + 1);
                break;

            case 4:
                if (estaVazia(&pilha))
                    printf("A pilha esta vazia.\n");
                else if (pilha.topo == MAX_NODOS - 1)
                    printf("A pilha esta cheia.\n");
                else
                    printf("A pilha possui 1 ou mais nodos.\n");
                break;

            case 5:
                status = consultaTopo(&pilha, &d);
                if (status == SUCESSO)
                    printf("Topo: Codigo: %d, Peso: %.2f\n", d.cod, d.peso);
                else
                    printf("Erro: Pilha vazia.\n");
                break;

            case 6:
                printf("Digite o codigo para pesquisa: ");
                scanf("%d", &cod);
                status = pesquisa(&pilha, cod, &d);
                if (status == SUCESSO)
                    printf("Encontrado: Codigo: %d, Peso: %.2f\n", d.cod, d.peso);
                else if (status == DADO_INEXISTENTE)
                    printf("Codigo nao encontrado na pilha.\n");
                else
                    printf("Erro: Pilha vazia.\n");
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

        if (opcao != 0) {
            printf("\nEstado atual da pilha:\n");
            exibe(&pilha);
        }

    } while(opcao != 0);

    return 0;
}

