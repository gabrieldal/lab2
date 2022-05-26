#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova1-lib.h"

typedef struct aluno
{
    int matricula;
    char nome[50];
} Aluno;

Aluno *phead = NULL;

ListaGen *insere_aluno(ListaGen *head, int x, char y[50])
{
    Aluno *p = (Aluno *)malloc(sizeof(Aluno));
    p->matricula = x;
    strcpy(p->nome, y);
    return lgen_insere(head, p);
}

void imprime(void *info)
{
    Aluno *p = (Aluno *)info;
    printf("%i\n", p->matricula);
    puts(p->nome);
}

void busca(void *dado, void *dado2)
{
    Aluno *p = (Aluno *)dado;
    Aluno *p2 = (Aluno *)dado2;
    if (p->matricula == p2->matricula)
    {
        printf("%i\n", p->matricula);
        puts(p->nome);
    }
}
void vazia(void *info)
{
    if (info == NULL)
    {
        printf("A lista esta vazia\n");
    }
    if (info != NULL)
    {
        printf("A lista nao esta vazia\n");
    }
}

int main()
{
    int opt = 0, d = 0;
    char d2[50];
    while (opt < 6)
    {

        printf("1. Inserir Aluno\n");
        printf("2. Buscar aluno por matricula\n");
        printf("3. Imprimir Alunos\n");
        printf("4. Retirar aluno por matricula\n");
        printf("5. Verificar lista\n");
        printf("6. Sair\n");
        printf("Opcao:\n");
        fflush(stdin);
        scanf("%i", &opt);

        switch (opt)
        {
        case 1:

            printf("Digite a matricula: ");
            scanf("%i", &d);
            fflush(stdin);
            printf("Digite o nome do aluno: ");
            scanf("%s", &d2);
            fflush(stdin);
            phead = insere_aluno(phead, d, d2);
            break;

        case 2:
            printf("Digite o numero da matricula: \n");
            scanf("%i", &d);
            lgen_busca(phead, busca, &d);
            fflush(stdin);
            break;

        case 3:
            lgen_percorre(phead, imprime);
            fflush(stdin);
            break;

        case 4:
            break;

        case 5:
            lgen_vazia(phead, vazia);
            break;

        case 6:
            break;

        default:
            printf("opcao invalida\n");
            break;
        }
    }
    return 0;
}
