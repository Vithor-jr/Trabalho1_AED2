#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "questao2.h"
#include "questao1.h"
#include "../models/Estatisticas/Estatisiticas.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#define NUMERO_BUSCAS     30
#define NUMERO_GARANTIDAS 15

void Questao1 (Vetor arrayOrdenado, Vetor arrayDesordenado){
    printf("Preenchendo vetores com %d elementos...\n\n", TAM);

    PreencherVetorOrdenado(&arrayOrdenado);
    PreencherVetorDesordenado(&arrayDesordenado);

    double temposSeq[30], temposBin[30];

    // ################# BUSCA SEQUENCIAL  #################

    for (int i = 0; i < 15; i++) {
        int pos = rand() % TAM;
        int valor = GetValue(&arrayDesordenado, pos);
        clock_t inicio = Timer_start();
        BuscaSequencial(&arrayDesordenado, valor);
        temposSeq[i] = Timer_stop(inicio);
        printf("Busca sequencial %02d (existe):    %.9f s\n", i + 1, temposSeq[i]);
    }

    for (int i = 15; i < 30; i++) {
        int valor = (int)(rand() % ((long)TAM * 100));
        clock_t inicio = Timer_start();
        BuscaSequencial(&arrayDesordenado, valor);
        temposSeq[i] = Timer_stop(inicio);
        printf("Busca sequencial %02d (aleatorio): %.9f s\n", i + 1, temposSeq[i]);
    }

    double mediaSeq  = CalcularMedia(temposSeq, 30);
    double desvioSeq = CalcularDesvioPadrao(temposSeq, 30, mediaSeq);
    
    printf("\nMEDIA BUSCA SEQUENCIAL:         %.9f s\n", mediaSeq);
    printf("DESVIO PADRAO BUSCA SEQUENCIAL: %.9f s\n\n", desvioSeq);

    // ################# BUSCA BINÁRIA  #################

    for (int i = 0; i < 15; i++) {
        int pos = rand() % TAM;
        int valor = GetValue(&arrayOrdenado, pos);
        clock_t inicio = Timer_start();
        BuscaBinaria(&arrayOrdenado, valor);
        temposBin[i] = Timer_stop(inicio);
        printf("Busca binaria  %02d (existe):    %.9f s\n", i + 1, temposBin[i]);
    }

    for (int i = 15; i < 30; i++) {
        int valor = (int)(rand() % ((long)TAM * 100));
        clock_t inicio = Timer_start();
        BuscaBinaria(&arrayOrdenado, valor);
        temposBin[i] = Timer_stop(inicio);
        printf("Busca binaria  %02d (aleatorio): %.9f s\n", i + 1, temposBin[i]);
    }

    double mediaBin  = CalcularMedia(temposBin, 30);
    double desvioBin = CalcularDesvioPadrao(temposBin, 30, mediaBin);
   
    printf("\nMEDIA BUSCA BINARIA:         %.9f s\n", mediaBin);
    printf("DESVIO PADRAO BUSCA BINARIA: %.9f s\n\n", desvioBin);
}

void Questao2 (Vetor array) {
    //criando a lista encadeada e copiando os valores do vetor para a lista (mt fofo parecem um casalzinho)
    Lista *lista = CriarLista();
    CopiarValoresDoVetorParaLista(lista, &array);

    // Gerar as chaves da busca
    int chaves[NUMERO_BUSCAS];

    for (int i = 0; i < NUMERO_GARANTIDAS; i++) {
        int pos = rand() % TAM;
        chaves[i] = GetValue(&array, pos); // Sempre vai dar OK
    }
    for (int i = NUMERO_GARANTIDAS; i < NUMERO_BUSCAS; i++) {
        chaves[i] = (int)(rand() % ((long)TAM * 100)); // Pode dar N/A
    }

    // criando vetores para armazenanr os tempos e resultados das buscas 
    double tempos_vetor[NUMERO_BUSCAS];
    double tempos_lista[NUMERO_BUSCAS];
    int    res_vetor[NUMERO_BUSCAS];
    int    res_lista[NUMERO_BUSCAS];

    // busca sequencial marota no vetor
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        clock_t t0 = Timer_start();
        res_vetor[i] = BuscaSequencial(&array, chaves[i]);
        tempos_vetor[i] = Timer_stop(t0);
    }

    // busca sequencial fofa na lista
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        clock_t t0 = Timer_start();
        res_lista[i] = BuscaSequencialLista(lista, chaves[i]); 
        tempos_lista[i] = Timer_stop(t0);
    }

    // mostrando a tabela dos resultados
    printf("\nID | Chave | Vetor(s) | Lista(s) | Status\n");
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        printf("%d | %d| %.4f | %.4f | %s\n", 
               i + 1, chaves[i], tempos_vetor[i], tempos_lista[i], 
               (res_vetor[i] == 1) ? "OK" : "N/A");
    }

    // aq é a media
    double soma_vetor = 0, soma_lista = 0;
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        soma_vetor += tempos_vetor[i];
        soma_lista += tempos_lista[i];
    }
    double media_vetor = soma_vetor / NUMERO_BUSCAS;
    double media_lista = soma_lista / NUMERO_BUSCAS;

    // desvio padrao
    double desvio_vetor = 0, desvio_lista = 0;
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        desvio_vetor += (tempos_vetor[i] - media_vetor) * (tempos_vetor[i] - media_vetor);
        desvio_lista += (tempos_lista[i] - media_lista) * (tempos_lista[i] - media_lista);
    }
    desvio_vetor = sqrt(desvio_vetor / NUMERO_BUSCAS);
    desvio_lista = sqrt(desvio_lista / NUMERO_BUSCAS);

    // resumo resultadsos
    printf("\n================ RESULTADOS FINAIS ================\n");
    printf("Vetor -> Media: %.6f ms | Desvio: %.6f ms\n", media_vetor * 1000, desvio_vetor * 1000);
    printf("Lista -> Media: %.6f ms | Desvio: %.6f ms\n", media_lista * 1000, desvio_lista * 1000);
    printf("===g================================================\n");

    free(lista);
}

int main() {
    Vetor arrayOrdenado = CriarVetor(TAM);
    Vetor arrayDesordenado = CriarVetor(TAM);

    Questao1(arrayOrdenado, arrayDesordenado);
    
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    
    Questao2(arrayDesordenado);

    return 0;
}