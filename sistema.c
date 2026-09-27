#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ALUNOS 100
#define NOME_TAMANHO 50

typedef struct {
    char nome[NOME_TAMANHO];
    int idade;
    float nota;
} Aluno;

static Aluno alunos[MAX_ALUNOS];
static size_t total = 0;

static int ler_linha(char *destino, size_t tamanho) {
    if (!fgets(destino, (int)tamanho, stdin)) return 0;
    size_t fim = strcspn(destino, "\n");
    if (destino[fim] == '\n') {
        destino[fim] = '\0';
    } else if (!feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return 0; /* reject truncated input */
    }
    return 1;
}

static int ler_inteiro(const char *texto, int *valor) {
    char sobra;
    return sscanf(texto, " %d %c", valor, &sobra) == 1;
}

static int ler_nota(const char *texto, float *valor) {
    char sobra;
    return sscanf(texto, " %f %c", valor, &sobra) == 1 && isfinite(*valor) && *valor >= 0.0f && *valor <= 10.0f;
}

static void cadastrar(void) {
    char entrada[64];
    Aluno novo;
    if (total == MAX_ALUNOS) {
        puts("Limite de alunos atingido.");
        return;
    }
    printf("Nome: ");
    if (!ler_linha(novo.nome, sizeof novo.nome) || novo.nome[0] == '\0') {
        puts("Nome invalido ou muito longo.");
        return;
    }
    printf("Idade: ");
    if (!ler_linha(entrada, sizeof entrada) || !ler_inteiro(entrada, &novo.idade) || novo.idade < 0 || novo.idade > 120) {
        puts("Idade invalida.");
        return;
    }
    printf("Nota (0 a 10, use ponto decimal): ");
    if (!ler_linha(entrada, sizeof entrada) || !ler_nota(entrada, &novo.nota)) {
        puts("Nota invalida.");
        return;
    }
    alunos[total++] = novo;
    puts("Aluno cadastrado com sucesso.");
}

static void mostrar(const Aluno *aluno) {
    printf("Nome: %s | Idade: %d | Nota: %.2f\n", aluno->nome, aluno->idade, aluno->nota);
}

static void listar(void) {
    if (total == 0) puts("Nenhum aluno cadastrado.");
    for (size_t i = 0; i < total; ++i) mostrar(&alunos[i]);
}

static void buscar(void) {
    char nome[NOME_TAMANHO];
    printf("Digite o nome do aluno: ");
    if (!ler_linha(nome, sizeof nome)) {
        puts("Nome invalido ou muito longo.");
        return;
    }
    for (size_t i = 0; i < total; ++i) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            mostrar(&alunos[i]);
            return;
        }
    }
    puts("Aluno nao encontrado.");
}

int main(void) {
    char entrada[32];
    int opcao;
    for (;;) {
        puts("\n1 - Cadastrar | 2 - Listar | 3 - Buscar | 0 - Sair");
        printf("Escolha: ");
        if (!ler_linha(entrada, sizeof entrada)) break;
        if (!ler_inteiro(entrada, &opcao)) {
            puts("Opcao invalida.");
            continue;
        }
        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: buscar(); break;
            case 0: puts("Saindo..."); return 0;
            default: puts("Opcao invalida.");
        }
    }
    return 0;
}
