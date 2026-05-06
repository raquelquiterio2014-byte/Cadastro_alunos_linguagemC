#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Lib-para-cadastro/lib_de_apoio.h"

//Testando uma nova versao de cadastramento de alunos;

int main () {

    int opcao = -1;
    int cont = 0;
    int codigo = -1;
    int c;

    srand(time(NULL));

    Alunos *alunos_escolares = (Alunos*) malloc(100 * sizeof(Alunos));

    for (int a = 0; a < 100; a++) {
        alunos_escolares[a].nome = NULL;
    }

    do {

        printf("Bom dia! Selecione as opcoes abaixo pra continuar...\n");
        
        printf("Opcao 1 -- Cadastrar aluno\n");
        printf("Opcao 2 -- Ver os dados do aluno\n");
        printf("Opcao 3 -- sair\n");

        scanf("%d", &opcao);

        while ((c = getchar()) != '\n' && c != EOF);            //Limpando o buffer;

        switch (opcao) {

            case 1:
                cadastro(&alunos_escolares[cont]);
                cont++;
                break;

            case 2:
                printf("Digite o codigo do aluno (0-99):\n");
                scanf("%d", &codigo);
                while ((c = getchar()) != '\n' && c != EOF);

                ver_dados(alunos_escolares, codigo);
                break;
        
            default:
                break;
        }

    } while (cont < 100 && opcao != 3);

    //Liberando a memoria na heap para nao ter vazamento;

    for(int a = 0; a < cont; a++) {
        free(alunos_escolares[a].nome);
    }

    free(alunos_escolares);
    
    return 0;
}