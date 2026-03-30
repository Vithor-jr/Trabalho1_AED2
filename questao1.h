#ifndef QUESTAO1_H
#define QUESTAO1_H

#include <time.h>

#define TAM 100000000

typedef int Vetor[TAM];
extern Vetor vet;

clock_t timer_start();
double timer_stop(clock_t start);

void preencherVetor(int tam);
double calcularMedia(double *tempos, int tam);
double calcularDesvioPadrao(double *tempos, int tam, double media);

int buscaSequencial(int chave, int tam);
int buscaBinaria(int chave, int tam);

#endif