#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao3.h"

#include "questao3.h"
#include "../models/Estatisticas/Estatisiticas.h"

#define TAM 100000
#define RODADAS 10

int main() {
    srand(time(NULL));
    double times[5][RODADAS];
    double medias[5], desvios[5];

    Vetor array     = CriarVetor(TAM);
    Vetor bubble    = CriarVetor(TAM);
    Vetor insertion = CriarVetor(TAM);
    Vetor selection = CriarVetor(TAM);
    Vetor merge     = CriarVetor(TAM);
    Vetor quick     = CriarVetor(TAM);

    for (int i = 0; i < RODADAS; i++) {
        PreencherVetorDesordenado(&array);

        CopiarVetor(&array, &bubble);
        CopiarVetor(&array, &insertion);
        CopiarVetor(&array, &selection);
        CopiarVetor(&array, &merge);
        CopiarVetor(&array, &quick);

        printf("\n=+-+-+-+-+-+-+- RODADA %d +-+-+-+-+-+-+-\n", i+1);

        clock_t ini, fim;
        double tempo;

        ini = clock(); 
        BubbleSort(&bubble);       
        fim = clock();
        times[0][i] = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("BUBBLESORT:    %lf s\n", times[0][i]);

        ini = clock(); 
        InsertionSort(&insertion); 
        fim = clock();
        times[1][i] = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("INSERTIONSORT: %lf s\n", times[1][i]);

        ini = clock(); 
        SelectionSort(&selection); 
        fim = clock();
        times[2][i] = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("SELECTIONSORT: %f s\n", times[2][i]);

        ini = clock(); 
        MergeSort(&merge);         
        fim = clock();
        times[3][i] = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("MERGESORT:     %f s\n", times[3][i]);

        ini = clock(); 
        QuickSort(&quick);         
        fim = clock();
        times[4][i] = (double)(fim - ini) / CLOCKS_PER_SEC;
        printf("QUICKSORT:     %f s\n", times[4][i]);
    }

    for (int i = 0; i<5; i++){
        medias[i] = CalcularMedia(times[i], RODADAS);
        desvios[i]  = CalcularDesvioPadrao(times[i], RODADAS, medias[i]);
    }

    printf("\n\n+-+-+-+-+-+-+-+ RESULTADOS +-+-+-+-+-+-+-+\n");
    printf("1 - BUBBLESORT:\n");
    printf("    Media:         %lf\n", medias[0]);
    printf("    Desvio Padrao: %lf\n\n", desvios[0]);

    printf("2 - INSERTIONSORT:\n");
    printf("    Media:         %lf\n", medias[1]);
    printf("    Desvio Padrao: %lf\n\n", desvios[1]);

    printf("3 - SELECTIONSORT:\n");
    printf("    Media:         %lf\n", medias[2]);
    printf("    Desvio Padrao: %lf\n\n", desvios[2]);

    printf("4 - MERGESORT:\n");
    printf("    Media:         %lf\n", medias[3]);
    printf("    Desvio Padrao: %lf\n\n", desvios[3]);

    printf("5 - QUICKSORT:\n");
    printf("    Media:         %lf\n", medias[4]);
    printf("    Desvio Padrao: %lf\n\n", desvios[4]);

    LiberarVetor(&array);
    LiberarVetor(&bubble);
    LiberarVetor(&insertion);
    LiberarVetor(&selection);
    LiberarVetor(&merge);
    LiberarVetor(&quick);

    return 0;
}
