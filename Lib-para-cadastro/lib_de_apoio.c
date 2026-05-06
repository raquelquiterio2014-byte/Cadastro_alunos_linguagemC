#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib_de_apoio.h"

void cadastro (Alunos *ingressante) {

    ingressante->nome = malloc(200);            //O nome eh colocado na heap por que ocupa muitos mais bytes que outros;
    int c;

    printf("Digite o nome do aluno: ");
    fgets(ingressante->nome, 200, stdin);

    printf("Digite a idade do aluno: ");
    scanf("%d", &ingressante->idade);

    while ((c = getchar()) != '\n' && c != EOF);

    printf("O registro esta sendo criado....");

    ingressante->registro = 1900 + (rand() % 101);
}

void ver_dados(Alunos *ingressante, int codigo) {

    printf("Nome do aluno: %s\n\n", ingressante[codigo].nome);
    printf("Idade: %d\tRegistro: %d\n", ingressante[codigo].idade, ingressante[codigo].registro);
}