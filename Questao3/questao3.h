typedef struct {
    int *conteudo;
    int tamanho;
} Vetor;

Vetor CriarVetor(int tamanho);
void LiberarVetor(Vetor *v);
void PreencherVetor(Vetor *v);
void CopiarVetor(Vetor *origem, Vetor *destino);
void MostrarVetor(Vetor *v);

void BubbleSort(Vetor *v);
void InsertionSort(Vetor *v);
void SelectionSort(Vetor *v);
void MergeSort(Vetor *v);
void QuickSort(Vetor *v);

double calcularMedia(double *tempos, int tam);
double calcularDesvioPadrao(double *tempos, int tam, double media);
