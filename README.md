# Cadastro_alunos_linguagemC
💻 Mini Sistema: Cadastro de Alunos (com menu)

💻 Mini Sistema: Cadastro de Alunos (com menu)

🔹 Funcionalidades:

Cadastrar alunos

Listar alunos

Buscar aluno pelo nome

Sair


🧠 Conceitos usados:
struct

typedef

Vetor de structs

Funções

strcmp (comparação de strings)

Menu interativo



✅ Código completo (pronto pra rodar)
#include <stdio.h>
#include <string.h>

#define MAX 100

// Definição da struct
typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

// Vetor global
Aluno alunos[MAX];
int total = 0;

// Função para cadastrar aluno
void cadastrar() {
    if (total >= MAX) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    printf("\n--- Cadastro de Aluno ---\n");

    printf("Nome: ");
    scanf(" %[^\n]", alunos[total].nome);

    printf("Idade: ");
    scanf("%d", &alunos[total].idade);

    printf("Nota: ");
    scanf("%f", &alunos[total].nota);

    total++;

    printf("Aluno cadastrado com sucesso!\n");
}

// Função para listar alunos
void listar() {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Alunos ---\n");

    for (int i = 0; i < total; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
}

// Função para buscar aluno
void buscar() {
    char nomeBusca[50];
    int encontrado = 0;

    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(alunos[i].nome, nomeBusca) == 0) {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Nota: %.2f\n", alunos[i].nota);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Aluno nao encontrado.\n");
    }
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
                buscar();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
________________________________________
▶️ Como rodar no VS Code
1.	Crie um arquivo: sistema.c 
2.	Cole o código 
3.	Compile: 
gcc sistema.c -o sistema
4.	Execute:
	./sistema
(ou sistema.exe no Windows)







