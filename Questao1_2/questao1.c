#include "questao1.h"

#include <math.h>
#include <stdlib.h>

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int BuscaSequencial(Vetor *v, int chave) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->conteudo[i] == chave) return 1;
    }
    return 0;
}

int BuscaBinaria(Vetor *v, int chave) {
    int i = 0, j = v->tamanho - 1, meio;
    while (i <= j) {
        meio = (i + j) / 2;
        if (v->conteudo[meio] == chave)
            return 1;
        else if (chave > v->conteudo[meio])
            i = meio + 1;
        else
            j = meio - 1;
    }
    return 0;
}