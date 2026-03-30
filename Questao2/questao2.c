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

Lista * criarLista() {
  Lista *lista = (Lista *) malloc(sizeof(Lista));
  if (!lista) {
  printf("Erro ao alocar memória para Listaa  \n");
  exit(1);
  }
  lista->prim = NULL;
  return lista;
}

void inserirNaLista(Lista * lista, int numero){
  No* novo = (No*) malloc(sizeof(No));
  if (!novo) {
  printf("Erro ao alocar memória para Nozinho \n");
  exit(1);
  }

  novo->valor = numero;
  novo->prox = lista->prim;
  lista->prim = novo;
}

void copiarValoresDoVetorParaLista(Lista * lista, int * vetor, int tamanho){
  for(int i = tamanho-1; i >= 0; i--){
    inserirNaLista(lista, vetor[i]);
  }
}

// funcao para a busca sequencial na lista

int buscaSequencialLista(Lista * lista, int valor_procurado){

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