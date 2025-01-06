#include <stdio.h>
#include "ListaLigadaD.h"

void exibirListaInversa(LISTA* l) {
    
    PONT atual = l->inicio;
    while (atual != NULL && atual->prox != NULL) {
        atual = atual->prox;
    }
    
    printf("Lista inversa: ");
    while (atual != NULL) {
        printf("%d ", atual->reg.chave);
        atual = atual->ant;
    }
    printf("\n");
}

int main() {
    LISTA lista;
    REGISTRO reg;

    inicializarLista(&lista);

    
    reg.chave = 10;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 20;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 15;
    inserirElemListaOrd(&lista, reg);

    
    printf("Lista direta: ");
    exibirLista(&lista);

    exibirListaInversa(&lista);

    return 0;
}
