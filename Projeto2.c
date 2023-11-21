#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct item
{
    int chave;
    float valor;

}item;

void insertion(struct item vetor[], int tamanho)
{
    int i, j;
    struct item aux;

    for (i = 1; i < tamanho; i++)
    {
        for (j = i; j > 0; j--)
        {
            if(vetor[j].chave > vetor[j - 1].chave)
            {
                aux = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void Bubble(struct item vetor[], int tam)
{
    struct item aux;
    for(int i = 0; i < tam-1;i++)
    {
        for(int j=1;j<tam-1;j++)
        {
            if(vetor[j - 1].chave < vetor[j].chave)
            {
                aux = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void OddEven(struct item vetor[], int tam) {
    struct item aux;

    int troca = 1;

    while (troca) {
        troca = 0;


        for (int i = 1; i < tam - 1; i += 2) {
            if (vetor[i].chave < vetor[i + 1].chave) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1;
            }
        }


        for (int i = 0; i < tam - 1; i += 2) {
            if (vetor[i].chave < vetor[i + 1].chave) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1;
            }
        }
    }
}

void ordem_insertion_chave(struct item vetor[], int tamanho)
{
    srand(time(NULL));
    int i, j=0;
    for (i = 0; i < tamanho; i++)
    {
        vetor[i].chave = rand()%10+j;

        j=j+10;
    }

}

void preencher_aleatorio(struct item vetor[], int tam)
{
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
    {
        vetor[i].chave = rand();
        vetor[i].valor = ((float)rand() / RAND_MAX) * 900 + 100;
    }
}

void merge (struct item *v,struct item *c,int i,int m,int f)
{
    int z,iv = i,ic = m + 1;
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
    while(iv <= m && ic <= f)
    {
        if(c[iv].chave >= c[ic].chave)
        {
            v[z++] = c[iv++];
        }
        else
        {
            v[z++] = c[ic++];
        }
    }
    while (iv <= m)
    {
        v[z++] = c[iv++];
    }
    while (ic <= f)
    {
        v[z++] = c[ic++];
    }
}

void sort(struct item *v,struct item *c,int i,int f)
{
    if(i < f)
    {
        int m = (i + f) / 2;
        sort(v,c,i,m);
        sort(v,c,m + 1,f);
        if(v[m].chave > v[m+1].chave)
        {
            merge(v,c,i,m,f);
        }
    }
}

void mergesort (struct item *v, int n)
{
    struct item *c = malloc(sizeof(struct item) * n);
    sort(v, c, 0, n - 1);
    free(c);
}

void shellSort(struct item *v, int n) {

    int i, j;
    item value;

    int h = 1;
    while(h < n) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < n; i++) {
            value = v[i];
            j = i;
            while (j > h-1 && value.chave >= v[j - h].chave) {
                v[j] = v[j - h];
                j -=h;
            }
            v[j] = value;
        }
        h = h/3;
    }
}

double calcula_tempo_insertion(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    t = clock();
    insertion(vetor_copia, tam);
    t = clock() - t;

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

double calcula_tempo_bubble(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    t = clock();
    Bubble(vetor_copia,tam);
    t = clock() - t;

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

double calcula_tempo_oddeven(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    t = clock();
    OddEven(vetor_copia,tam);
    t = clock() - t;

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

double calcula_tempo_merge(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    t = clock();
    mergesort(vetor_copia, tam);
    t = clock() - t;

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

double calcula_tempo_shell(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    t = clock();
    shellSort(vetor_copia,tam);
    t = clock() - t;

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

int main(){

int escolha;
double tempo_insertion = 0, media_insertion = 0,tempoPiorCasoInsertion = 0,mediaPiorCasoInsertion = 0;
double tempoBubble = 0,mediaBubble = 0,tempoPiorCasoBubble = 0,mediaPiorCasoBubble = 0;
double tempoMerge = 0,mediaMerge = 0,tempoPiorCasoMerge = 0,mediaPiorCasoMerge = 0;
double tempoOD = 0,mediaOD = 0,tempoPiorCasoOD = 0,mediaPiorCasoOD = 0;
double tempoShell = 0,mediaShell = 0,tempoPiorCasoShell = 0,mediaPiorCasoShell = 0;

while (1) {

        system("cls");
        printf("Escolha o tamanho do vetor:\n\n");
        printf("(1)\t10 MIL \n(2)\t50 MIL \n(3)\t100 MIL \n(4)\t500 MIL \n(5)\t1 MILHAO\n(6)\tSair do programa\n\n");
        printf("O que deseja fazer: ");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha)
        {
            case 1:
                printf("Vetores de 10 mil posicoes com chaves aleatorias: \n\n");

                for(int i=0; i < 10; i++)
                {

                    struct item* vetor = (struct item*)malloc(10000 * sizeof(struct item));

                    preencher_aleatorio(vetor,10000);

                    printf("InsertionSort: ");
                    tempo_insertion += calcula_tempo_insertion(vetor,10000);

                    printf("BubbleSort: ");
                    tempoBubble += calcula_tempo_bubble(vetor,10000);

                    printf("ShellSort: ");
                    tempoShell += calcula_tempo_shell(vetor,10000);

                    printf("MergeSort: ");
                    tempoMerge += calcula_tempo_merge(vetor,10000);

                    //calcula_tempo_quick(vetor,10000);

                    printf("Odd-Even: ");
                    tempoOD += calcula_tempo_oddeven(vetor,10000);

                    free(vetor);
                    printf("\n");

                }

                printf("_________________________________________________________\n");
                printf("\nVetores de 10 mil posicoes no pior caso: \n\n");

                for(int i = 0; i < 10; i++)
                {
                    struct item* vetor = (struct item*)malloc(10000 * sizeof(struct item));

                    ordem_insertion_chave(vetor,10000);

                    printf("InsertionSort: ");
                    tempoPiorCasoInsertion += calcula_tempo_insertion(vetor,10000);

                    printf("BubbleSort: ");
                    tempoPiorCasoBubble += calcula_tempo_bubble(vetor,10000);

                    printf("ShellSort: ");
                    tempoPiorCasoShell += calcula_tempo_shell(vetor,10000);

                    printf("MergeSort: ");
                    tempoPiorCasoMerge += calcula_tempo_merge(vetor,10000);

                    //calcula_tempo_quick(vetor,10000);

                    printf("Odd-Even: ");
                    tempoPiorCasoOD += calcula_tempo_oddeven(vetor,10000);

                    free(vetor);
                    printf("\n");

                }

                media_insertion = tempo_insertion/10;
                mediaPiorCasoInsertion = tempoPiorCasoInsertion/10;
                mediaBubble = tempoBubble/10;
                mediaPiorCasoBubble = tempoPiorCasoBubble/10;
                mediaOD = tempoOD/10;
                mediaPiorCasoOD = tempoPiorCasoOD/10;
                mediaMerge = tempoMerge/10;
                mediaPiorCasoMerge = tempoPiorCasoMerge/10;
                mediaShell = tempoShell/10;
                mediaPiorCasoShell = tempoPiorCasoShell/10;

                printf("_________________________________________________________\n");
                printf("\nInsertion: ");
                printf("\nTempo medio: %f segundos\n", media_insertion);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoInsertion);
                printf("_________________________________________________________\n");
                printf("\nBubble: ");
                printf("\nTempo medio: %f segundos\n", mediaBubble);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoBubble);
                printf("_________________________________________________________\n");
                printf("\nOdd-Even: ");
                printf("\nTempo medio: %f segundos\n", mediaOD);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoOD);
                printf("_________________________________________________________\n");
                printf("\nMergeSort: ");
                printf("\nTempo medio: %f segundos\n", mediaMerge);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoMerge);
                printf("_________________________________________________________\n");
                printf("\nShellSort: ");
                printf("\nTempo medio: %f segundos\n", mediaShell);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoShell);
                printf("_________________________________________________________\n");
                system("pause");

                break;
            case 2:

                break;
            case 3:

                break;
           case 4:

                break;
           case 5:

                break;
            case 6:
                printf("Saindo do programa. Ate logo!\n");
                return 0;
                break;
            default:
                printf("Numero invalido! Digite outro numero: ");
                }
            }
}
