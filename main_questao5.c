#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Questao1/questao1.h"
#include "Questao2/questao2.h"
#include "Questao3/questao3.h"

int main () {
    srand(time(NULL));

    double temposSeq[20], temposBin[20], temposVet[20], temposLista[20];
    int i = 0, j = 0, w = 0;

    // Questão 1: Busca Binária e Sequencial no Vetor
    // Questão 2: Busca Sequencial no Vetor e na Lista
    for(int tam = 100000; tam <= 1000000; tam += 100000) {
        printf("---------------BUSCA SEQUENCIAL E BINÁRIA EM VETOR COM %d ELEMENTOS------------------\n\n", tam);

        // Preenchendo o vetor desordenado
        printf("Preenchendo vetor desordenadamente...\n\n");
        int *array = (int *)malloc(tam * sizeof(int));
        PreencherVetor(array, tam);

        // Fazendo busca sequencial procurando valor existente no vetor
        int pos = rand() % tam;
        clock_t inicio = timer_start();
        buscaSequencial(array[pos], tam);
        temposSeq[i] = timer_stop(inicio);
        printf("Busca sequencial no vetor (existe):    %.9f s\n", temposSeq[i]);
        i++;

        // Fazendo busca sequencial procurando valor aleatório
        int valor = (int)(rand() % ((long)tam * 100));
        inicio = timer_start();
        buscaSequencial(valor, tam);
        temposSeq[i] = timer_stop(inicio);
        printf("Busca sequencial no vetor (aleatorio): %.9f s\n", temposSeq[i]);
        i++;

        // Preeenchendo o vetor ordenado
        printf("Preenchendo vetor ordenadamente...\n\n");
        preencherVetor(tam);

        // Fazendo a busca binária procurando valor existente no vetor
        pos = rand() % tam;
        inicio = timer_start();
        buscaBinaria(vet[pos], tam);
        temposBin[j] = timer_stop(inicio);
        printf("Busca binaria no vetor (existe):    %.9f s\n", temposBin[j]);
        j++;

        // Fazendo a busca binária procurando valor aleatório
        valor = (int)(rand() % ((long)tam * 100));
        inicio = timer_start();
        buscaBinaria(valor, tam);
        temposBin[i] = timer_stop(inicio);
        printf("Busca binaria no vetor (aleatorio): %.9f s\n", temposBin[j]);
        j++;
        

        printf("---------------BUSCA SEQUENCIAL EM VETOR E EM LISTA COM %d ELEMENTOS------------------\n\n", tam);

        // Copiando valores do vetor desordenado
        printf("Copiando vetor desordenado...\n\n");
        Lista *lista = criarLista();
        copiarValoresDoVetorParaLista(lista, array, tam);

        // Definindo valores a serem buscados
        pos = rand() % tam;
        valor = (int)(rand() % ((long)tam * 100));

        // Fazendo busca sequencial no vetor procurando valor existente
        inicio = timer_start();
        buscaSequencial(array[pos], tam);
        temposVet[w] = timer_stop(inicio);
        printf("Busca sequencial no vetor (existe): %.9f s\n", temposVet[w]);

        // Fazendo busca sequencial na lista procurando valor existente
        inicio = timer_start();
        buscaSequencialLista(lista, array[pos]);
        temposLista[w] = timer_stop(inicio);
        printf("Busca sequencial na lista (existe): %.9f s\n", temposLista[w]);
        w++;

        // Fazendo busca sequencial no vetor procurando valor alaeatório
        inicio = timer_start();
        buscaSequencial(valor, tam);
        temposVet[w] = timer_stop(inicio);
        printf("Busca sequencial no vetor (aleatório): %.9f s\n", temposVet[w]);

        // Fazendo busca sequencial na lista procurando valor aleatório
        inicio = timer_start();
        buscaSequencialLista(lista, valor);
        temposLista[w] = timer_stop(inicio);
        printf("Busca sequencial na lista (aleatório): %.9f s\n", temposLista[w]);
        w++;

        free(array);
    }

    double temposBubble[10], temposInsertion[10], temposSelection[10], temposMerge[10], temposQuick[10];
    i = 0;
    // Questão 3: Ordenação
    for(int tam = 10000; tam <= 100000; tam += 10000) {
        printf("---------------ORDENAÇÃO DE VETOR COM %d ELEMENTOS------------------\n\n", tam);
        // Criando os vetores
        int *array = (int *)malloc(tam * sizeof(int));
        int *bubble = (int *)malloc(tam * sizeof(int));
        int *insertion = (int *)malloc(tam * sizeof(int));
        int *selection = (int *)malloc(tam * sizeof(int));
        int *merge = (int *)malloc(tam * sizeof(int));
        int *quick = (int *)malloc(tam * sizeof(int));

        // Preenchendo os vetores desordenadamente
        printf("Preenchendo vetor desordenadamente...\n\n");
        PreencherVetor(array, tam);
        CopiarVetor(array, bubble, tam);
        CopiarVetor(array, insertion, tam);
        CopiarVetor(array, selection, tam);
        CopiarVetor(array, merge, tam);
        CopiarVetor(array, quick, tam);

        // Ordenando com Bubble Sort
        clock_t inicio = timer_start();
        BubbleSort(bubble, tam);
        temposBubble[i] = timer_stop(inicio);
        printf("Ordenação com Bubble Sort: %.9f s\n", temposBubble[i]);

        // Ordenando com o Insertion Sort
        inicio = timer_start();
        InsertionSort(insertion, tam);
        temposInsertion[i] = timer_stop(inicio);
        printf("Ordenação com Insertion Sort: %.9f s\n", temposInsertion[i]);

        // Ordenando com o Selection Sort
        inicio = timer_start();
        SelectionSort(selection, tam);
        temposSelection[i] = timer_stop(inicio);
        printf("Ordenação com Selection Sort: %.9f s\n", temposSelection[i]);

        // Ordenando com o Merge Sort
        inicio = timer_start();
        MergeSort(merge, tam);
        temposMerge[i] = timer_stop(inicio);
        printf("Ordenação com Merge Sort: %.9f s\n", temposMerge[i]);

        // Ordenando com o QuickSort
        inicio = timer_start();
        QuickSort(quick, tam);
        temposQuick[i] = timer_stop(inicio);
        printf("Ordenação com QuickSort: %.9f s\n", temposQuick[i]);

        i++;

        free(array);
        free(bubble);
        free(selection);
        free(insertion);
        free(merge);
        free(quick);
    }
}   