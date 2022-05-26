#include<stdio.h>
#include<stdlib.h>
#include"prova1-lib.h"

static ListaGen* insere_ponto(ListaGen* l, float x, float y){
Ponto *p = (Ponto*)malloc(sizeof(Ponto));
p->x = x;
p->y = y;
return lgen_insere(l,p);

int main(void)
{
    int opt=0;

    while(opt<6){

        printf("1. Criar Lista\n");
        printf("2. Inserir na Lista\n");
        printf("3. Percorrer a Lista\n");
        printf("4. Verificar se a Lista esta vazia\n");
        printf("5. Liberar a Lista\n");
        printf("6. Sair\n");
        printf("Opcao:\n");
        scanf("%i", &opt);


        switch(opt){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
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
