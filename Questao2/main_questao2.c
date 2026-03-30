#include "questao2.h"
#include "../Questao1/questao1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#define NUMERO_BUSCAS     30
#define NUMERO_GARANTIDAS 15

int main() {
    srand((unsigned)time(NULL));

    // preenchendo o vetor com a quantidade máxima de elementos
    preencherVetor(TAM);

    //criando a lista encadeada e copiando os valores do vetor para a lista (mt fofo parecem um casalzinho)
    Lista *lista = criarLista();
    copiarValoresDoVetorParaLista(lista, vet, TAM);

    // Gerar as chaves da busca
    int chaves[NUMERO_BUSCAS];

    for (int i = 0; i < NUMERO_GARANTIDAS; i++) {
        int pos = rand() % TAM;
        chaves[i] = vet[pos];
    }
    for (int i = NUMERO_GARANTIDAS; i < NUMERO_BUSCAS; i++) {
        chaves[i] = (rand() % TAM) + 1;
    }

    // criando vetores para armazenanr os tempos e resultados das buscas 
    double tempos_vetor[NUMERO_BUSCAS];
    double tempos_lista[NUMERO_BUSCAS];
    int    res_vetor[NUMERO_BUSCAS];
    int    res_lista[NUMERO_BUSCAS];

    // busca sequencial marota no vetor
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        clock_t t0 = timer_start();
        res_vetor[i] = buscaSequencial(chaves[i], TAM);
        tempos_vetor[i] = timer_stop(t0);
    }

    // busca sequencial fofa na lista 
for (int i = 0; i < NUMERO_BUSCAS; i++) {
        clock_t t0 = timer_start();
        res_lista[i] = buscaSequencialLista(lista, chaves[i]);
        tempos_lista[i] = timer_stop(t0);
    }

    // mostrando a tabela dos resultados
    printf("\nID | Chave | Vetor(ms) | Lista(ms) | Status\n");
    for (int i = 0; i < NUMERO_BUSCAS; i++) {
        printf("%d | %d| %.4f | %.4f | %s\n", 
               i + 1, chaves[i], tempos_vetor[i]*1000, tempos_lista[i]*1000, 
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
    printf("===================================================\n");

    return 0;
}