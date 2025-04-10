#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

int comparaHorario(Horario h1, Horario h2) {
    if (h1.hora != h2.hora)
        return h1.hora - h2.hora;
    if (h1.minuto != h2.minuto)
        return h1.minuto - h2.minuto;
    return h1.segundo - h2.segundo;
}

void imprimeHorario(Horario h) {
    printf("%02d:%02d:%02d\n", h.hora, h.minuto, h.segundo);
}

int main() {
    Horario h1, h2;
    printf("Digite o primeiro horario: ");
    scanf("%d %d %d", &h1.hora, &h1.minuto, &h1.segundo);
    printf("Digite o segundo horario: ");
    scanf("%d %d %d", &h2.hora, &h2.minuto, &h2.segundo);

    int comp = comparaHorario(h1, h2);
    if (comp < 0)
        imprimeHorario(h1);
    else if (comp > 0)
        imprimeHorario(h2);
    else
        printf("Horarios iguais\n");

    return 0;
}
