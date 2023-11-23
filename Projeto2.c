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

int particao(struct item *v,int li,int ls,int pivot)
{
    int pivo,e = li,d = ls,m = ls/2;
    struct item aux;

    if(pivot == 0)
    {
       pivo = v[d].chave;
    }
    if(pivot == 1)
    {
        pivo = v[e].chave;
    }
    if(pivot == 2)
    {
        pivo = v[m].chave;
    }
    while(e < d)
    {
        while((v[e].chave>=pivo)&&(e<ls))
        {
            e++;
        }
        while((v[d].chave<pivo)&&(d>li))
        {
            d--;
        }
        if(e<d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    aux = v[li];
    v[li] = v[d];
    v[d] = aux;

    return d;
}

void QuickSort(struct item *v,int li,int ls,int tipo)
{
    if(li < ls)
    {
        if(tipo == 1)
        {
            int p;
            p = particao(v,li,ls,1);
            QuickSort(v,li,p - 1,1);
            QuickSort(v,p+1,ls,1);
        }

        if(tipo == 0)
        {
            int p;
            p = particao(v,li,ls,0);
            QuickSort(v,li,p - 1,0);
            QuickSort(v,p+1,ls,0);
        }

        if(tipo == 2)
        {
            int p;
            p = particao(v,li,ls,2);
            QuickSort(v,li,p - 1,2);
            QuickSort(v,p+1,ls,2);
        }
    }
}

double calcula_tempo(struct item vetor[], int tam,int escolha)
{
    clock_t t;
    struct item vetor_copia[tam];
    memcpy(vetor_copia, vetor, tam * sizeof(struct item));

    switch (escolha)
    {
    case 1:
        t = clock();
        shellSort(vetor_copia,tam);
        t = clock() - t;
        break;

    case 2:
        t = clock();
        mergesort(vetor_copia, tam);
        t = clock() - t;
        break;

    case 3:
        t = clock();
        OddEven(vetor_copia,tam);
        t = clock() - t;
        break;

    case 4:
        t = clock();
        Bubble(vetor_copia,tam);
        t = clock() - t;
        break;

    case 5:
        t = clock();
        insertion(vetor_copia, tam);
        t = clock() - t;
        break;

    case 6:
        t = clock();
        QuickSort(vetor_copia,0,tam-1,0);
        t = clock() - t;
        break;

    case 7:
        t = clock();
        QuickSort(vetor_copia,0,tam-1,1);
        t = clock() - t;
        break;

    case 8:
        t = clock();
        QuickSort(vetor_copia,0,tam-1,2);
        t = clock() - t;
        break;

    default:
        printf("Numero invalido !!!");
        return 0;
    }

    double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempoDeExecucao);

    return tempoDeExecucao;
}

int main(){

int escolha,tam;
double tempo_insertion = 0, media_insertion = 0,tempoPiorCasoInsertion = 0,mediaPiorCasoInsertion = 0;
double tempoBubble = 0,mediaBubble = 0,tempoPiorCasoBubble = 0,mediaPiorCasoBubble = 0;
double tempoMerge = 0,mediaMerge = 0,tempoPiorCasoMerge = 0,mediaPiorCasoMerge = 0;
double tempoOD = 0,mediaOD = 0,tempoPiorCasoOD = 0,mediaPiorCasoOD = 0;
double tempoShell = 0,mediaShell = 0,tempoPiorCasoShell = 0,mediaPiorCasoShell = 0;
double tempoQuickE = 0,mediaQuickE = 0,tempoPiorCasoQuickE = 0,mediaPiorCasoQuickE = 0;
double tempoQuickD = 0,mediaQuickD = 0,tempoPiorCasoQuickD = 0,mediaPiorCasoQuickD = 0;
double tempoQuickM = 0,mediaQuickM = 0,tempoPiorCasoQuickM = 0,mediaPiorCasoQuickM = 0;

while (1)
{

        system("cls");
        printf("Escolha o tamanho do vetor:\n\n");
        printf("(1)\t10 MIL \n(2)\t50 MIL \n(3)\t100 MIL \n(4)\t500 MIL \n(5)\t1 MILHAO\n(6)\tSair do programa\n\n");
        printf("O que deseja fazer: ");
        scanf("%d", &escolha);
        system("cls");

        switch (escolha)
    {
    case 1:
        tam = 10000;
        printf("Vetores de 10 mil posicoes com chaves aleatorias: \n\n");
        break;

    case 2:
        tam = 50000;
            printf("Vetores de 50 mil posicoes com chaves aleatorias: \n\n");
        break;

    case 3:
        tam = 100000;
            printf("Vetores de 100 mil posicoes com chaves aleatorias: \n\n");
        break;

    case 4:
        tam = 500000;
            printf("Vetores de 500 mil posicoes com chaves aleatorias: \n\n");
        break;

    case 5:
        tam = 1000000;
        printf("Vetores de 1 milhao posicoes com chaves aleatorias: \n\n");
        break;

    case 6:
        return 0;
        break;

    default:
        printf("Numero invalido !!!");
        return 0;
    }

    for(int i=0; i < 10; i++)
    {

        struct item* vetor = (struct item*)malloc(tam * sizeof(struct item));

        preencher_aleatorio(vetor,tam);

        printf("InsertionSort: ");
        tempo_insertion += calcula_tempo(vetor,tam,5);

        printf("BubbleSort: ");
        tempoBubble += calcula_tempo(vetor,tam,4);

        printf("ShellSort: ");
        tempoShell += calcula_tempo(vetor,tam,1);

        printf("MergeSort: ");
        tempoMerge += calcula_tempo(vetor,tam,2);

        printf("QuickSort (Pivo na esquerda): ");
        tempoQuickE += calcula_tempo(vetor,tam,7);

        printf("QuickSort (Pivo na direita): ");
        tempoQuickD += calcula_tempo(vetor,tam,6);


        printf("QuickSort (Pivo na meio): ");
        tempoQuickM += calcula_tempo(vetor,tam,8);

        printf("Odd-Even: ");
        tempoOD += calcula_tempo(vetor,tam,3);

        free(vetor);
        printf("\n");

    }

    printf("_________________________________________________________\n");
    printf("\nVetores no pior caso: \n\n");

    for(int i = 0; i < 10; i++)
    {
        struct item* vetor = (struct item*)malloc(tam * sizeof(struct item));

        ordem_insertion_chave(vetor,tam);

        printf("InsertionSort: ");
        tempoPiorCasoInsertion += calcula_tempo(vetor,tam,5);

        printf("BubbleSort: ");
        tempoPiorCasoBubble += calcula_tempo(vetor,tam,4);

        printf("ShellSort: ");
        tempoPiorCasoShell += calcula_tempo(vetor,tam,1);

        printf("MergeSort: ");
        tempoPiorCasoMerge += calcula_tempo(vetor,tam,2);

        printf("QuickSort (Pivo na esquerda): ");
        tempoPiorCasoQuickE += calcula_tempo(vetor,tam,7);

        printf("QuickSort (Pivo na direita): ");
        tempoPiorCasoQuickD += calcula_tempo(vetor,tam,6);


        printf("QuickSort (Pivo na meio): ");
        tempoPiorCasoQuickM += calcula_tempo(vetor,tam,8);

        printf("Odd-Even: ");
        tempoPiorCasoOD += calcula_tempo(vetor,tam,3);

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
    mediaQuickD = tempoQuickD/10;
    mediaPiorCasoQuickD = tempoPiorCasoQuickD/10;
    mediaQuickE = tempoQuickE/10;
    mediaPiorCasoQuickE = tempoPiorCasoQuickE/10;
    mediaQuickM = tempoQuickM/10;
    mediaPiorCasoQuickM = tempoPiorCasoQuickM/10;

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
    printf("\nQuickSort (pivo na direita): ");
    printf("\nTempo medio: %f segundos\n", mediaQuickD);
    printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoQuickD);
    printf("_________________________________________________________\n");
    printf("\nQuickSort (pivo na esquerda): ");
    printf("\nTempo medio: %f segundos\n", mediaQuickE);
    printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoQuickE);
    printf("_________________________________________________________\n");
    printf("\nQuickSort (pivo na meio): ");
    printf("\nTempo medio: %f segundos\n", mediaQuickM);
    printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoQuickM);
    printf("_________________________________________________________\n");
    system("pause");
    }
}
