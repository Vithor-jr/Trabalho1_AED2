#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao3.h"

#define TAM 10

int vet[TAM];

void PreencherVetor(int v[], unsigned tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % tam;
    }
}

void MostrarVetor(int v[], unsigned tam){
	printf("[");
	for (int i = 0; i<tam; i++){
		if(i!=TAM-1){
			printf("%d ", v[i]);
		} else {
			printf("%d]\n", v[i]);			
		}
	}
}

void CopiarVetor(int v1[], int v2[], unsigned tam){
	for (int i=0; i<tam; i++){
		v2[i] = v1[i];
	}
}

void BubbleSort(int v[], unsigned tam){
    int aux;

    for(int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if(v[j+1] < v[j]) {
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void InsertionSort(int v[], unsigned tam){
	int pivot, j;

	for (int i=1; i<tam; i++){
		pivot = v[i];
		j = i - 1;

		while (v[j]>pivot && j>=0){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = pivot;
	}
}

void SelectionSort(int v[], unsigned tam){
	int posMenor, aux;
	
	for(int i = 0; i<tam-1; i++){
		posMenor = i;
		for (int j = i+1; j<tam; j++){
			if(v[posMenor] > v[j]){
				posMenor = j;
			}
		}
		aux = v[i];
		v[i] = v[posMenor];
		v[posMenor] = aux;
	}
}

void Intercala(int v[], unsigned inicio, unsigned meio, unsigned fim, int aux[]) {
    unsigned i = inicio;
    unsigned j = meio + 1;
    unsigned k = inicio;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
						i++;
						k++;
        } else {
            aux[k] = v[j];
						j++;
						k++;
        }
    }
    while (i <= meio) {
        aux[k] = v[i];
				i++;
				k++;
    }

    while (j <= fim) {
        aux[k] = v[j];
				j++;
				k++;
    }

    for (i = inicio; i <= fim; i++) {
        v[i] = aux[i];
    }
}

void MergeSortR(int v[], int vaux[], unsigned inicio, unsigned fim) {
    if (inicio < fim) {
        unsigned meio = (inicio + fim) / 2;
        MergeSortR(v, vaux, inicio, meio);
        MergeSortR(v, vaux, meio + 1, fim);
        Intercala(v, inicio, meio, fim, vaux);
    }
}

void MergeSort(int v[], unsigned tam) {
    int vaux[TAM];
    MergeSortR(v, vaux, 0, tam - 1);
}

void QuickSortR(int v[], unsigned inicio, unsigned fim) {
    int i = inicio, j = fim;
    int pivot = v[(inicio + fim) / 2];
    int temp;

    while (i <= j) {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;

        if (i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (inicio < j)
        QuickSortR(v, inicio, j);

    if (i < fim)
        QuickSortR(v, i, fim);
}

void QuickSort(int v[], unsigned tam) {
    if (tam <= 1) return;
    QuickSortR(v, 0, tam - 1);
}