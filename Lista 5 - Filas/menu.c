#include <stdio.h>
#include "fila.h"

int main() {
    FilaCF fila;
    Dado d;
    int opcao, codBusca;

    criaFila(&fila);

    do {
        printf("\n--- MENU ---\n");
        printf("0. Fim\n");
        printf("1. Insere\n");
        printf("2. Retira\n");
        printf("3. Quantidade de nodos\n");
        printf("4. Exibe situacao da fila\n");
        printf("5. Consulta frente\n");
        printf("6. Pesquisa dado\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Encerrando programa...\n");
                break;

            case 1: // Insere
                if (!filaCheia(&fila)) {
                    printf("Digite o codigo e o peso: ");
                    scanf("%d %f", &d.cod, &d.peso);
                    if (insere(&fila, d) == SUCESSO)
                        printf("Insercao realizada com SUCESSO.\n");
                } else {
                    printf("Erro: a fila esta cheia.\n");
                }
                exibe(&fila);
                break;

            case 2: // Retira
                if (retira(&fila, &d) == SUCESSO) {
                    printf("Removido com SUCESSO: Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                } else {
                    printf("Erro: Fila esta vazia.\n");
                }
                exibe(&fila);
                break;

            case 3: // Quantidade
                printf("Quantidade de nodos na fila: %d\n", quantidade(&fila));
                exibe(&fila);
                break;

            case 4: // Situação da fila
                if (estaVazia(&fila)) {
                    printf("A fila esta vazia.\n");
                } else if (filaCheia(&fila)) {
                    printf("A fila esta cheia.\n");
                } else {
                    printf("A fila possui 1 ou mais nodos.\n");
                }
                exibe(&fila);
                break;

            case 5: // Consulta frente
                if (consulta(&fila, &d) == SUCESSO) {
                    printf("Frente da fila: Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                } else {
                    printf("Erro: Fila esta vazia.\n");
                }
                exibe(&fila);
                break;

            case 6: // Pesquisa dado
                printf("Digite o codigo a ser pesquisado: ");
                scanf("%d", &codBusca);
                if (pesquisa(&fila, codBusca, &d) == SUCESSO) {
                    printf("Dado encontrado: Codigo: %d | Peso: %.2f\n", d.cod, d.peso);
                } else {
                    printf("Dado nao encontrado ou fila vazia.\n");
                }
                exibe(&fila);
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

