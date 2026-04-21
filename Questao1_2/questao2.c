#include <stdio.h>
#include <stdlib.h>
#include "questao2.h"

typedef struct tipoNo {
    int valor;
    struct tipoNo *prox;
} No;

typedef struct tipoLista {
    No *prim;
} Lista;

// criando as listas
Lista* CriarLista() {
  Lista *lista = (Lista *) malloc(sizeof(Lista));
  if (!lista) {
     printf("Erro ao alocar memória para Listaa  \n");
     exit(1);
  }
  lista->prim = NULL;
  return lista;
}

void InserirNaLista(Lista * lista, int numero){
  No* novo = (No*) malloc(sizeof(No));

  if (!novo) {
      printf("Erro ao alocar memória para Nozinho \n");
      exit(1);
  }

  novo->valor = numero;
  novo->prox = lista->prim;
  lista->prim = novo;
}

void CopiarValoresDoVetorParaLista(Lista *lista, Vetor *vetor){
  for(int i = vetor->tamanho-1; i >= 0; i--){
    InserirNaLista(lista, vetor->conteudo[i]);
  }
}

// funcao para a busca sequencial na lista
int BuscaSequencialLista(Lista * lista, int valor_procurado){
  if(lista->prim == NULL){
    return -1;
  }

  int cont = 0;
  
  for(No* atual = lista->prim; atual != NULL; atual = atual->prox){
    if(atual->valor == valor_procurado){
      return cont;
    } 
    cont++;
  }
  return -1;
}