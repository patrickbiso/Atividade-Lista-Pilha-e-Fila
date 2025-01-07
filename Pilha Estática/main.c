#include <stdio.h>
#include "pilhaEstatica.h"

int main() {
    PILHA pilha;
    inicializarPilha(&pilha);
    help();
    char comando = ' ';
    scanf("%c", &comando);
    while (comando != 'q') {
        switch (comando) {
            case 'i':
                inserir(&pilha);
                break;
            case 'e':
                excluir(&pilha);
                break;
            case 'p':
                exibir(&pilha);
                break;
            case 'v':
                exibirPilhaInvertida(&pilha);
                break;
            case 'd':
                destruir(&pilha);
                break;
            case 'l':
                meuLog(&pilha);
                break;
            case 'h':
                help();
                break;
            default:
                while (comando != '\n') scanf("%c", &comando);
        }
        scanf("%c", &comando);
    }

    return 0;
}
