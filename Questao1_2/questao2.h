#include "../models/Vetor/Vetor.h"

typedef struct tipoLista Lista;

Lista* CriarLista();

void InserirNaLista(Lista * lista, int numero);

void CopiarValoresDoVetorParaLista(Lista *lista, Vetor *vetor);

int BuscaSequencialLista(Lista *lista, int valor_procurado);