#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao3.h"

void PreencherVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % tam;
    }
}

void MostrarVetor(int v[], int tam){
	printf("[");
	for (int i = 0; i<tam; i++){
		if(i!=tam-1){
			printf("%d ", v[i]);
		} else {
			printf("%d]\n", v[i]);			
		}
	}
}

void CopiarVetor(int v1[], int v2[], int tam){
	for (int i=0; i<tam; i++){
		v2[i] = v1[i];
	}
}

void BubbleSort(int v[], int tam){
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

void InsertionSort(int v[], int tam){
	int pivot, j;

	for (int i=1; i<tam; i++){
		pivot = v[i];
		j = i - 1;

		while (j >= 0 && v[j] > pivot){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = pivot;
	}
}

void SelectionSort(int v[], int tam){
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

void Intercala(int v[], int inicio, int meio, int fim, int aux[]) {
 int i = inicio;
 int j = meio + 1;
 int k = inicio;

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

void MergeSortR(int v[], int vaux[], int inicio, int fim) {
    if (inicio < fim) {
     int meio = (inicio + fim) / 2;
        MergeSortR(v, vaux, inicio, meio);
        MergeSortR(v, vaux, meio + 1, fim);
        Intercala(v, inicio, meio, fim, vaux);
    }
}

void MergeSort(int v[], int tam) {
    int *vaux = (int *)malloc(tam * sizeof(int));
    if (vaux == NULL) return;  
    MergeSortR(v, vaux, 0, tam - 1);
    free(vaux);
}

void QuickSortR(int v[], int inicio, int fim) {
    if (inicio >= fim) return;

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

    QuickSortR(v, inicio, j);
    QuickSortR(v, i, fim);
}

void QuickSort(int v[], int tam) {
    if (tam <= 1) return;
    QuickSortR(v, 0, tam - 1);
}