#include "questao1.h"
#include <math.h>
#include <stdlib.h>

// Definição do vetor global
Vetor vet;

clock_t timer_start() {
    return clock();
}

double timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

void preencherVetor(int tam) {
    for (int i = 0; i < tam; i++) {
        int min = i * 100 + (i > 0 ? 1 : 0);
        int max = (i + 1) * 100;
        vet[i] = rand() % (max - min + 1) + min;
    }
}

double calcularMedia(double *tempos, int tam) {
    double soma = 0;
    for (int i = 0; i < tam; i++) soma += tempos[i];
    return soma / tam;
}

double calcularDesvioPadrao(double *tempos, int tam, double media) {
    double soma = 0;
    for (int i = 0; i < tam; i++) {
        double d = tempos[i] - media;
        soma += d * d;
    }
    return sqrt(soma / (tam - 1));
}

int buscaSequencial(int chave, int tam) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] == chave) return 1;
    }
    return 0;
}

int buscaBinaria(int chave, int tam) {
    int i = 0, j = tam - 1, meio;
    while (i <= j) {
        meio = (i + j) / 2;
        if (vet[meio] == chave)
            return 1;
        else if (chave > vet[meio])
            i = meio + 1;
        else
            j = meio - 1;
    }
    return 0;
}