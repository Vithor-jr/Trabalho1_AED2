#include <math.h>
#include "Estatisiticas.h"

double CalcularMedia(double *tempos, int tam) {
    double soma = 0;
    for (int i = 0; i < tam; i++) soma += tempos[i];
    return soma / tam;
}

double CalcularDesvioPadrao(double *tempos, int tam, double media) {
    double soma = 0;
    for (int i = 0; i < tam; i++) {
        double d = tempos[i] - media;
        soma += d * d;
    }
    return sqrt(soma / (tam - 1));
}
