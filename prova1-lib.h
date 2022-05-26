typedef struct listaGen ListaGen;
ListaGen *lgen_insere(ListaGen *head, void *data);
void lgen_percorre(ListaGen *head, void (*cb)(void *));
void lgen_busca(ListaGen * head, void (*cb)(void *, void*), void *dado);
void lgen_vazia(ListaGen *head, void (*cb)(void *));