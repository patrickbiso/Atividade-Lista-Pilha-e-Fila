#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.c" 

int main() {
    FILA fila;
    REGISTRO reg;
    TIPOCHAVE ch;

    
    inicializarFila(&fila);
    printf("Fila inicializada.\n");
    exibirFila(&fila);

    
    printf("\nInserindo elementos na fila...\n");
    for (int i = 1; i <= 5; i++) {
        reg.chave = i;
        if (inserirNaFila(&fila, reg)) {
            printf("Inserido: %d\n", i);
        } else {
            printf("Falha ao inserir: %d\n", i);
        }
    }
    exibirFila(&fila);

    
    printf("\nExcluindo elementos da fila...\n");
    while (excluirDaFila(&fila, &reg)) {
        printf("Excluído: %d\n", reg.chave);
        exibirFila(&fila);
    }

    
    printf("\nTentando excluir da fila vazia...\n");
    if (!excluirDaFila(&fila, &reg)) {
        printf("Fila está vazia, exclusão não realizada.\n");
    }

    
    printf("\nReinserindo elementos na fila...\n");
    for (int i = 6; i <= 10; i++) {
        reg.chave = i;
        if (inserirNaFila(&fila, reg)) {
            printf("Inserido: %d\n", i);
        } else {
            printf("Falha ao inserir: %d\n", i);
        }
    }
    exibirFila(&fila);

    
    printf("\nBuscando elemento com chave 8 na fila...\n");
    PONT resultado = buscaSeq(&fila, 8);
    if (resultado) {
        printf("Elemento encontrado: %d\n", resultado->reg.chave);
    } else {
        printf("Elemento não encontrado.\n");
    }

    
    printf("\nDestruindo a fila...\n");
    destruirFila(&fila);
    exibirFila(&fila);

    return 0;
}
