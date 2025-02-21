#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float premios[12];
} Premios;

int main() {
    FILE *arquivo = fopen("PREMIOS.DAT", "rb");
    if (!arquivo) {
        printf("Erro ao abrir PREMIOS.DAT!\n");
        return 1;
    }

    Premios p;
    fread(&p, sizeof(Premios), 1, arquivo);
    fclose(arquivo);

    printf("Valores dos prêmios:\n");
    for (int i = 0; i < 12; i++) {
        printf("Prêmio %d: R$ %.2f\n", i + 1, p.premios[i]);
    }

    return 0;
}
