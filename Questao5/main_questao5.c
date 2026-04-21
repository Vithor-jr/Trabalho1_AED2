#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Questao1_2/questao1.h"
#include "../Questao1_2/questao2.h"
#include "../Questao3/questao3.h"

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
        Vetor array = CriarVetor(tam);
        PreencherVetorDesordenado(&array);

        // Fazendo busca sequencial procurando valor existente no vetor
        int pos = rand() % tam;
        int valor = GetValue(&array, pos); 
        
        clock_t inicio = Timer_start();
        BuscaSequencial(&array, valor);

        temposSeq[i] = Timer_stop(inicio);
        printf("Busca sequencial no vetor (existe):    %.9f s\n", temposSeq[i]);
        i++;

        // Fazendo busca sequencial procurando valor aleatório
        valor = (int)(rand() % ((long)tam * 100));
        inicio = Timer_start();
        BuscaSequencial(&array, valor);
        temposSeq[i] = Timer_stop(inicio);
        printf("Busca sequencial no vetor (aleatorio): %.9f s\n", temposSeq[i]);
        i++;

        // Preeenchendo o vetor ordenado
        printf("Preenchendo vetor ordenadamente...\n\n");
        PreencherVetorOrdenado(&array);

        // Fazendo a busca binária procurando valor existente no vetor
        pos = rand() % tam;
        valor = GetValue(&array, pos); 
        inicio = Timer_start();
        BuscaBinaria(&array, valor);
        temposBin[j] = Timer_stop(inicio);
        printf("Busca binaria no vetor (existe):    %.9f s\n", temposBin[j]);
        j++;

        // Fazendo a busca binária procurando valor aleatório
        valor = (int)(rand() % ((long)tam * 100));
        inicio = Timer_start();
        BuscaBinaria(&array, valor);
        temposBin[i] = Timer_stop(inicio);
        printf("Busca binaria no vetor (aleatorio): %.9f s\n", temposBin[j]);
        j++;
        

        printf("---------------BUSCA SEQUENCIAL EM VETOR E EM LISTA COM %d ELEMENTOS------------------\n\n", tam);

        // Copiando valores do vetor desordenado
        printf("Copiando vetor desordenado...\n\n");
        Lista *lista = CriarLista();
        CopiarValoresDoVetorParaLista(lista, &array);

        // Definindo valores a serem buscados
        pos = rand() % tam;
        
        // Fazendo busca sequencial no vetor procurando valor existente
        valor = GetValue(&array, pos);
        inicio = Timer_start();
        BuscaSequencial(&array, valor);
        temposVet[w] = Timer_stop(inicio);
        printf("Busca sequencial no vetor (existe): %.9f s\n", temposVet[w]);

        // Fazendo busca sequencial na lista procurando valor existente
        inicio = Timer_start();
        valor  = GetValue(&array, pos);
        BuscaSequencialLista(lista, valor);
        temposLista[w] = Timer_stop(inicio);
        printf("Busca sequencial na lista (existe): %.9f s\n", temposLista[w]);
        w++;

        // Fazendo busca sequencial no vetor procurando valor alaeatório
        inicio = Timer_start();
        valor = (int)(rand() % ((long)tam * 100));
        BuscaSequencial(&array, valor);
        temposVet[w] = Timer_stop(inicio);
        printf("Busca sequencial no vetor (aleatorio): %.9f s\n", temposVet[w]);

        // Fazendo busca sequencial na lista procurando valor aleatório
        inicio = Timer_start();
        BuscaSequencialLista(lista, valor);
        temposLista[w] = Timer_stop(inicio);
        printf("Busca sequencial na lista (aleatorio): %.9f s\n\n\n", temposLista[w]);
        w++;
        
        LiberarVetor(&array);
    }

    double temposBubble[10], temposInsertion[10], temposSelection[10], temposMerge[10], temposQuick[10];
    i = 0;
    // Questão 3: Ordenação
    for(int tam = 10000; tam <= 100000; tam += 10000) {
        printf("---------------ORDENAÇÃO DE VETOR COM %d ELEMENTOS------------------\n\n", tam);
        // Criando os vetores
        Vetor array     = CriarVetor(tam);
        Vetor bubble    = CriarVetor(tam);
        Vetor insertion = CriarVetor(tam);
        Vetor selection = CriarVetor(tam);
        Vetor merge     = CriarVetor(tam);
        Vetor quick     = CriarVetor(tam);

        // Preenchendo os vetores desordenadamente
        printf("Preenchendo vetor desordenadamente...\n\n");
        PreencherVetorDesordenado(&array);
        CopiarVetor(&array, &bubble);
        CopiarVetor(&array, &insertion);
        CopiarVetor(&array, &selection);
        CopiarVetor(&array, &merge);
        CopiarVetor(&array, &quick);

        // Ordenando com Bubble Sort
        clock_t inicio = Timer_start();
        BubbleSort(&bubble);
        temposBubble[i] = Timer_stop(inicio);
        printf("Ordenação com Bubble Sort: %.9f s\n", temposBubble[i]);

        // Ordenando com o Insertion Sort
        inicio = Timer_start();
        InsertionSort(&insertion);
        temposInsertion[i] = Timer_stop(inicio);
        printf("Ordenação com Insertion Sort: %.9f s\n", temposInsertion[i]);

        // Ordenando com o Selection Sort
        inicio = Timer_start();
        SelectionSort(&selection);
        temposSelection[i] = Timer_stop(inicio);
        printf("Ordenação com Selection Sort: %.9f s\n", temposSelection[i]);

        // Ordenando com o Merge Sort
        inicio = Timer_start();
        MergeSort(&merge);
        temposMerge[i] = Timer_stop(inicio);
        printf("Ordenação com Merge Sort: %.9f s\n", temposMerge[i]);

        // Ordenando com o QuickSort
        inicio = Timer_start();
        QuickSort(&quick);
        temposQuick[i] = Timer_stop(inicio);
        printf("Ordenação com QuickSort: %.9f s\n", temposQuick[i]);

        i++;

        LiberarVetor(&array);
        LiberarVetor(&bubble);
        LiberarVetor(&insertion);
        LiberarVetor(&selection);
        LiberarVetor(&merge);
        LiberarVetor(&quick);
    }

    FILE *f = fopen("tempos.csv", "w");
    
    // Busca sequencial e binária
    fprintf(f, "algoritmo,tamanho,caso,tempo_s\n");

    i = 0;
    for (int tam = 100000; tam <= 1000000; tam += 100000) {
        fprintf(f, "sequencial,%d,existe,%.9f\n",   tam, temposSeq[i]);   i++;
        fprintf(f, "sequencial,%d,aleatorio,%.9f\n", tam, temposSeq[i]);  i++;
    }
    
    j = 0;
    for (int tam = 100000; tam <= 1000000; tam += 100000) {
        fprintf(f, "binaria,%d,existe,%.9f\n",   tam, temposBin[j]);   j++;
        fprintf(f, "binaria,%d,aleatorio,%.9f\n", tam, temposBin[j]);  j++;
    }
    
    // Busca vetor vs lista
    w = 0;
    for (int tam = 100000; tam <= 1000000; tam += 100000) {
        fprintf(f, "vetor,%d,existe,%.9f\n",    tam, temposVet[w]);
        fprintf(f, "lista,%d,existe,%.9f\n",    tam, temposLista[w]);   w++;
        fprintf(f, "vetor,%d,aleatorio,%.9f\n", tam, temposVet[w]);
        fprintf(f, "lista,%d,aleatorio,%.9f\n", tam, temposLista[w]);   w++;
    }
    
    // Ordenação
    i = 0;
    for (int tam = 10000; tam <= 100000; tam += 10000) {
        fprintf(f, "bubble,%d,unico,%.9f\n",    tam, temposBubble[i]);
        fprintf(f, "insertion,%d,unico,%.9f\n", tam, temposInsertion[i]);
        fprintf(f, "selection,%d,unico,%.9f\n", tam, temposSelection[i]);
        fprintf(f, "merge,%d,unico,%.9f\n",     tam, temposMerge[i]);
        fprintf(f, "quick,%d,unico,%.9f\n",     tam, temposQuick[i]);
        i++;
    }
    fclose(f);
    printf("\nTempos exportados para tempos.csv\n");
}   