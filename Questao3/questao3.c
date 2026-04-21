#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao3.h"

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