#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "questao3.h"

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

void PreencherVetor(Vetor *v) {
    for (int i = 0; i < v->tamanho; i++) {
        v->conteudo[i] = rand() % v->tamanho;
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


void BubbleSort(Vetor *v) {
    int aux;
    for (int i = 0; i < v->tamanho - 1; i++) {
        for (int j = 0; j < v->tamanho - i - 1; j++) {
            if (v->conteudo[j + 1] < v->conteudo[j]) {
                aux = v->conteudo[j + 1];
                v->conteudo[j + 1] = v->conteudo[j];
                v->conteudo[j] = aux;
            }
        }
    }
}

void InsertionSort(Vetor *v) {
    int pivot, j;
    for (int i = 1; i < v->tamanho; i++) {
        pivot = v->conteudo[i];
        j = i - 1;
        while (j >= 0 && v->conteudo[j] > pivot) {
            v->conteudo[j + 1] = v->conteudo[j];
            j--;
        }
        v->conteudo[j + 1] = pivot;
    }
}

void SelectionSort(Vetor *v) {
    int posMenor, aux;
    for (int i = 0; i < v->tamanho - 1; i++) {
        posMenor = i;
        for (int j = i + 1; j < v->tamanho; j++) {
            if (v->conteudo[posMenor] > v->conteudo[j])
                posMenor = j;
        }
        aux = v->conteudo[i];
        v->conteudo[i] = v->conteudo[posMenor];
        v->conteudo[posMenor] = aux;
    }
}

static void Intercala(Vetor *v, int inicio, int meio, int fim, int aux[]) {
    int i = inicio, j = meio + 1, k = inicio;

    while (i <= meio && j <= fim) {
        if (v->conteudo[i] <= v->conteudo[j])
            aux[k++] = v->conteudo[i++];
        else
            aux[k++] = v->conteudo[j++];
    }
    while (i <= meio) aux[k++] = v->conteudo[i++];
    while (j <= fim)  aux[k++] = v->conteudo[j++];

    for (i = inicio; i <= fim; i++)
        v->conteudo[i] = aux[i];
}

static void MergeSortR(Vetor *v, int *vaux, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        MergeSortR(v, vaux, inicio, meio);
        MergeSortR(v, vaux, meio + 1, fim);
        Intercala(v, inicio, meio, fim, vaux);
    }
}

void MergeSort(Vetor *v) {
    int *vaux = (int *)malloc(v->tamanho * sizeof(int));
    if (vaux == NULL) return;
    MergeSortR(v, vaux, 0, v->tamanho - 1);
    free(vaux);
}

static void QuickSortR(Vetor *v, int inicio, int fim) {
    if (inicio >= fim) return;

    int i = inicio, j = fim;
    int pivot = v->conteudo[(inicio + fim) / 2];
    int temp;

    while (i <= j) {
        while (v->conteudo[i] < pivot) i++;
        while (v->conteudo[j] > pivot) j--;
        if (i <= j) {
            temp = v->conteudo[i];
            v->conteudo[i] = v->conteudo[j];
            v->conteudo[j] = temp;
            i++;
            j--;
        }
    }
    QuickSortR(v, inicio, j);
    QuickSortR(v, i, fim);
}

void QuickSort(Vetor *v) {
    if (v->tamanho <= 1) return;
    QuickSortR(v, 0, v->tamanho - 1);
}
