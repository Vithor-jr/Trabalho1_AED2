#ifndef QUESTAO1_H
#define QUESTAO1_H

#include <time.h>
#include "../models/Vetor/Vetor.h"

#define TAM 10000000

clock_t Timer_start();
double Timer_stop(clock_t start);

int BuscaSequencial(Vetor *v, int chave);
int BuscaBinaria(Vetor *v, int chave);

#endif