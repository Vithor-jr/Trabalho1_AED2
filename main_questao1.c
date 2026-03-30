#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "questao1.h"

int main() {
    srand(time(NULL));

    printf("Preenchendo vetor com %d elementos...\n\n", TAM);
    preencherVetor(TAM);

    double temposSeq[30], temposBin[30];

    // ── BUSCA SEQUENCIAL ──────────────────────────────────────────────────────

    for (int i = 0; i < 15; i++) {
        int pos = rand() % TAM;
        clock_t inicio = timer_start();
        buscaSequencial(vet[pos], TAM);
        temposSeq[i] = timer_stop(inicio);
        printf("Busca sequencial %02d (existe):    %.9f s\n", i + 1, temposSeq[i]);
    }

    for (int i = 15; i < 30; i++) {
        int valor = (int)(rand() % ((long)TAM * 100));
        clock_t inicio = timer_start();
        buscaSequencial(valor, TAM);
        temposSeq[i] = timer_stop(inicio);
        printf("Busca sequencial %02d (aleatorio): %.9f s\n", i + 1, temposSeq[i]);
    }

    double mediaSeq  = calcularMedia(temposSeq, 30);
    double desvioSeq = calcularDesvioPadrao(temposSeq, 30, mediaSeq);
    printf("\nMEDIA BUSCA SEQUENCIAL:         %.9f s\n", mediaSeq);
    printf("DESVIO PADRAO BUSCA SEQUENCIAL: %.9f s\n\n", desvioSeq);

    // ── BUSCA BINÁRIA ─────────────────────────────────────────────────────────

    for (int i = 0; i < 15; i++) {
        int pos = rand() % TAM;
        clock_t inicio = timer_start();
        buscaBinaria(vet[pos], TAM);
        temposBin[i] = timer_stop(inicio);
        printf("Busca binaria  %02d (existe):    %.9f s\n", i + 1, temposBin[i]);
    }

    for (int i = 15; i < 30; i++) {
        int valor = (int)(rand() % ((long)TAM * 100));
        clock_t inicio = timer_start();
        buscaBinaria(valor, TAM);
        temposBin[i] = timer_stop(inicio);
        printf("Busca binaria  %02d (aleatorio): %.9f s\n", i + 1, temposBin[i]);
    }

    double mediaBin  = calcularMedia(temposBin, 30);
    double desvioBin = calcularDesvioPadrao(temposBin, 30, mediaBin);
    printf("\nMEDIA BUSCA BINARIA:         %.9f s\n", mediaBin);
    printf("DESVIO PADRAO BUSCA BINARIA: %.9f s\n\n", desvioBin);

    return 0;
}