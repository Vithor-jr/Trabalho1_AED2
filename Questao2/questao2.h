typedef struct tipoLista Lista;
Lista * criarLista();
void inserirNaLista(Lista * lista, int numero);
void copiarValoresDoVetorParaLista(Lista * lista, int * vetor, int tamanho);
int buscaSequencialLista(Lista * lista, int valor_procurado);