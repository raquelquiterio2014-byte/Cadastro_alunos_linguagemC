# Cadastro de alunos em C

Projeto de estudo de C: cadastro em memória com menu para adicionar, listar e buscar alunos pelo nome. Os dados **não são salvos em disco**; encerrando o programa, a lista é perdida. A busca exige o nome completo com a mesma grafia.

## Compilar e executar

Requer compilador C com suporte a C11 (por exemplo, GCC).

```bash
gcc -std=c11 -Wall -Wextra -pedantic sistema.c -o sistema
./sistema
```

No Windows com GCC, execute `sistema.exe` no lugar de `./sistema`.

O menu aceita `1` para cadastrar, `2` para listar, `3` para buscar e `0` para sair. Exemplo abreviado:

```text
Escolha: 1
Nome: Ana
Idade: 20
Nota (0 a 10, use ponto decimal): 8.5
Aluno cadastrado com sucesso.
Escolha: 3
Digite o nome do aluno: Ana
Nome: Ana | Idade: 20 | Nota: 8.50
```

O programa limita o nome a 49 caracteres, verifica idade entre 0 e 120 e nota entre 0 e 10. Usa `struct`, vetor de registros, funções, `fgets`, `sscanf`, `strcmp` e ponteiros para passar um aluno à função de exibição. A capacidade é de 100 alunos.

## Exercícios separados: ponteiros e memória dinâmica

`Ponteiros-malloc/01-hello-world.c` é um primeiro programa C. `Ponteiros-malloc/02-ponteiro-simples.c` demonstra `malloc`, desreferenciação e `free`, com verificação de falha de alocação:

```bash
gcc -std=c11 -Wall -Wextra -pedantic Ponteiros-malloc/02-ponteiro-simples.c -o ponteiro
./ponteiro
```

O exemplo de `malloc` é independente do cadastro. O arquivo antigo `Cadastro_alunos_linguagem_C.txt` foi substituído por `sistema.c`; sua versão anterior continua no histórico Git.

## Próximas melhorias

Persistência em arquivo, pesquisa sem distinção de maiúsculas, atualização e exclusão de registros, e testes automatizados do menu.
