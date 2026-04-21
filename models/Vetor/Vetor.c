#include "Vetor.h"
#include <stdio.h>
#include <stdlib.h>

Vetor CriarVetor(int tamanho) {
    Vetor v;
    v.tamanho = tamanho;
    v.conteudo = (int *)malloc(tamanho * sizeof(int));
    return v;
}

void LiberarVetor(Vetor *v) {
    free(v->conteudo);
    v->conteudo = NULL;
    v->tamanho = 0;
}

void PreencherVetorDesordenado(Vetor *v) {
    for (int i = 0; i < v->tamanho; i++) {
        v->conteudo[i] = rand() % v->tamanho;
    }
}

void PreencherVetorOrdenado(Vetor *v) {
    for (int i = 0; i < v->tamanho; i++) {
        int min = i * 100 + (i > 0 ? 1 : 0);
        int max = (i + 1) * 100;
        v->conteudo[i] = rand() % (max - min + 1) + min;
    }
}

int GetValue (Vetor *v, int index){
	if (index < v->tamanho && index > 0){
		return v->conteudo[index];
	} else {
		return -1;
	}
}

void SetValue (Vetor *v, int index, int value){
	if (index < v->tamanho && index > 0){
		v->conteudo[index] = value;
	}
}

void MostrarVetor(Vetor *v) {
    printf("[");
    for (int i = 0; i < v->tamanho; i++) {
        if (i != v->tamanho - 1)
            printf("%d ", v->conteudo[i]);
        else
            printf("%d]\n", v->conteudo[i]);
    }
}

void CopiarVetor(Vetor *origem, Vetor *destino) {
    for (int i = 0; i < origem->tamanho; i++) {
        destino->conteudo[i] = origem->conteudo[i];
    }
}

