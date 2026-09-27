#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ponteiro = malloc(sizeof *ponteiro);
    if (ponteiro == NULL) {
        fputs("Falha ao alocar memoria.\n", stderr);
        return 1;
    }

    *ponteiro = 11;
    printf("O conteudo apontado e %d\n", *ponteiro);
    free(ponteiro);
    return 0;
}
