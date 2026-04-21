#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *conteudo;
    int tamanho;
} Vetor;

Vetor CriarVetor(int tamanho);

int GetValue (Vetor *v, int index);
void SetValue (Vetor *v, int index, int value);

void LiberarVetor(Vetor *v);
void PreencherVetorDesordenado(Vetor *v);
void PreencherVetorOrdenado(Vetor *v);
void CopiarVetor(Vetor *origem, Vetor *destino);
void MostrarVetor(Vetor *v);

#endif