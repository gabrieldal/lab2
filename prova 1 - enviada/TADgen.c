/* Lab. Prog II 2022/1 - Prova 1 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaGen
{
    void* info;
    struct listaGen* prox;
}ListaGen;

ListaGen* lgen_insere (ListaGen* head, void* data)//recebe 2 ponteiros, recebe o P da main com a data
{
    ListaGen* n = (ListaGen*) malloc(sizeof(ListaGen));//cria o N e aloca a memória
    n->info = data;//retorna o endereço n para o info na main
    n->prox = head;//retorna o endereço n para o Head na main
    return n;
}

void lgen_percorre(ListaGen *head, void (*cb)(void*)) // recebe uma função como parametro
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)// percorre até chegar a nulo
    {
        cb(p->info);//passa o ponteiro da informção para a função chamada
    }
}

void lgen_busca(ListaGen *head, void (*cb)(void*, void*), void *dado)//mesma função, porém tem um novo ponteiro dado
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)
    {
        cb(p->info, dado);// passa o que está em dado para a função callback
    }
}

ListaGen* lgen_free(ListaGen *head)// percorre a lista liberando a memória, começando pelo head
{
    ListaGen *aux;
    while (head != NULL)
    {
        aux = head;
        head = head->prox;
        free(aux->info);
        free(aux);
    }
    return head;
}

void lgen_vazia(ListaGen *head, void (*cb)(void*))
{
    cb(head);
}

void lgen_remove(ListaGen *head, int (*cb)(void*, void*, void*), void *dado)//parametros errados talvez
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)//percorre até achar
    {
        int z = cb(p, p->info, dado);
        if (z != 0)
        {
            ListaGen* q = head;// tentativa de manter a lista correta depois de deletar o nodo
            while (q->prox != p)
            {
                q=q->prox;
            }
            q->prox = p->prox;
            free(p->info);
            free(p);
            p=NULL;
        }
    }
}