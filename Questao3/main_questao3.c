#include <stdio.h>
#include "questao3.h"
#include <stdlib.h>
#include <time.h>

#define TAM 100000

int main(){
    int rodadas = 10;

    srand(time(NULL));

    //vetor array, bubble, insertion, selection, merge, quick;
    int *array = (int *)malloc(TAM * sizeof(int));
    int *bubble = (int *)malloc(TAM * sizeof(int));
    int *insertion = (int *)malloc(TAM * sizeof(int));
    int *selection = (int *)malloc(TAM * sizeof(int));
    int *merge = (int *)malloc(TAM * sizeof(int));
    int *quick = (int *)malloc(TAM * sizeof(int));

    for (int i=1; i<=rodadas; i++){
        PreencherVetor(array, TAM);

        // Clonando o vetor
        CopiarVetor(array, bubble, TAM);
        CopiarVetor(array, insertion, TAM);
        CopiarVetor(array, selection, TAM);
        CopiarVetor(array, merge, TAM);
        CopiarVetor(array, quick, TAM);

        printf("\n===== RODADA %d =====\n", i);

        //printf("VETOR ORIGINAL: ");    
        //MostrarVetor(array, TAM);

        clock_t ini, fim;
        double tempo;

		//++++++++++ BUBBLE SORT ++++++++++
        ini = clock();
        BubbleSort(bubble, TAM);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

        printf("BUBBLESORT: ");
        //MostrarVetor(bubble, TAM);
        printf("Tempo: %f s\n", tempo);

        //++++++++++ INSERTION SORT ++++++++++
        ini = clock();
        InsertionSort(insertion, TAM);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

        printf("INSERTIONSORT: ");
        //MostrarVetor(insertion, TAM);
        printf("Tempo: %f s\n", tempo);

        //++++++++++ SELECTION SORT ++++++++++
        ini = clock();
        SelectionSort(selection, TAM);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

        printf("SELECTIONSORT: ");
        //MostrarVetor(selection, TAM);
        printf("Tempo: %f s\n", tempo);

        //++++++++++ MERGE SORT ++++++++++
        ini = clock();
        MergeSort(merge, TAM);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

        printf("MERGESORT: ");
        //MostrarVetor(merge, TAM);
        printf("Tempo: %f s\n", tempo);

        //++++++++++ QUICK SORT ++++++++++
        ini = clock();
        QuickSort(quick, TAM);
        fim = clock();
        tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

        printf("QUICKSORT: ");
        //MostrarVetor(quick, TAM);
        printf("Tempo: %f s\n", tempo);
    }

    free(array);
    free(bubble);
    free(insertion);
    free(selection);
    free(merge);
    free(quick);
    
    return 0;
}