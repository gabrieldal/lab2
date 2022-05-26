#include <stdio.h>
#include <stdlib.h>

typedef struct listaGen
{
    void *info;
    struct listaGen *prox;
} ListaGen;

ListaGen *lgen_insere(ListaGen *head, void *data)
{
    ListaGen *n = (ListaGen *)malloc(sizeof(ListaGen));
    n->info = data;
    n->prox = head;
    return n;
}
void lgen_percorre(ListaGen *head, void (*cb)(void *))
{
    ListaGen *p;
    for (p = head; p != NULL; p = p->prox)
    {
        cb(p->info);
    }
}
void lgen_busca(ListaGen *head, void (*cb)(void *, void *), void *dado)
{
    ListaGen *p;
    for (p = head; p != NULL; p = p->prox)
    {
        cb(p->info, dado);
    }
}
void lgen_vazia(ListaGen *head, void (*cb)(void *))
{
    cb(head);
}
