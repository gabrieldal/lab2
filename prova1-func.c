

ListaGen* lgen_insere (ListaGen* l, void* p) {
ListaGen* n = (ListaGen*) malloc(sizeof(ListaGen));
n->info = p;
n->prox = l;
return n; }



