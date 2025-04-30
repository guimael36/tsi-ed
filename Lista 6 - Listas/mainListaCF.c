#include <stdio.h>
#include "ListaCF.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    ListaCF lista;
    Dado dado;
    int cod, codigoRef, resultado;

    criaLista(&lista);

    do {
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situação da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por código\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n\n");	
		printf("Informe a operação: ");
		scanf("%d",&cod);

        switch (cod) {
            case 1:
                printf("Informe o código: ");
                scanf("%d", &dado.cod);
                printf("Informe o peso: ");
                scanf("%f", &dado.peso);
                resultado = incluiNoFim(&lista, dado);
                break;

            case 2:
                exibe(lista);
                continue;

            case 3:
                printf("Quantidade de nodos: %d\n", quantidadeDeNodos(lista));
                break;

            case 4:
                printf("Lista %s\n", estaVazia(lista) ? "vazia" : (estaCheia(lista) ? "cheia" : "com espaço disponível"));
                break;

            case 5:
                resultado = excluiDoFim(&lista, &dado);
                if (resultado == SUCESSO)
                    printf("Excluído: código = %d, peso = %.2f\n", dado.cod, dado.peso);
                break;

            case 6:
                printf("Informe o código: ");
                scanf("%d", &dado.cod);
                printf("Informe o peso: ");
                scanf("%f", &dado.peso);
                resultado = incluiNoInicio(&lista, dado);
                break;

            case 7:
                resultado = excluiDoInicio(&lista, &dado);
                if (resultado == SUCESSO)
                    printf("Excluído: código = %d, peso = %.2f\n", dado.cod, dado.peso);
                break;

            case 8:
                printf("Informe o código a consultar: ");
                scanf("%d", &codigoRef);
                resultado = consultaPorCodigo(lista, codigoRef, &dado);
                if (resultado == SUCESSO)
                    printf("Encontrado: código = %d, peso = %.2f\n", dado.cod, dado.peso);
                break;

            case 9:
                printf("Informe o código de referência: ");
                scanf("%d", &codigoRef);
                printf("Informe o novo código: ");
                scanf("%d", &dado.cod);
                printf("Informe o peso: ");
                scanf("%f", &dado.peso);
                resultado = incluiAntes(&lista, codigoRef, dado);
                break;

            case 10:
                printf("Informe o código a excluir: ");
                scanf("%d", &codigoRef);
                resultado = excluiNodo(&lista, codigoRef, &dado);
                if (resultado == SUCESSO)
                    printf("Excluído: código = %d, peso = %.2f\n", dado.cod, dado.peso);
                break;
        }

        if (cod != 2 && cod != 0) {
            if (resultado == SUCESSO)
                printf("Operação realizada com SUCESSO!\n");
            else if (resultado == LISTA_CHEIA)
                printf("ERRO: Lista cheia!\n");
            else if (resultado == LISTA_VAZIA)
                printf("ERRO: Lista vazia!\n");
            else if (resultado == CODIGO_INEXISTENTE)
                printf("ERRO: Código inexistente!\n");
            exibe(lista);
        }

    } while (cod != 0);

    return 0;
}
