#include <stdio.h>

int main () {

    //Exemplo de ponteiro simples;

    int *ponteiro = (int*) malloc(sizeof(int));
    *ponteiro = 11;

    printf ("O conteudo do ponteiro tem o numero %d\n", *ponteiro);

    free(ponteiro);

    return 0;
}