#ifndef lib_de_apoio_h
#define lib_de_apoio_h

typedef struct {
    char *nome;
    int idade;
    int registro;
} Alunos;

void cadastro(Alunos *ingressante);
void ver_dados(Alunos *ingressante, int posicao);

#endif