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



void ordem_insertion_chave(struct item vetor[], int tamanho)
{
    srand(time(NULL));
    int i, j=0;
    struct item aux;
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

int main(){

int escolha;
double tempo_insertion = 0, media_insertion = 0,tempoPiorCasoInsertion = 0,mediaPiorCasoInsertion = 0;
double tempoBubble = 0,mediaBubble = 0,tempoPiorCasoBubble = 0,mediaPiorCasoBubble = 0;

while (1) {

        system("cls");
        printf("Escolha o tamanho do vetor:\n\n");
        printf("(1)\t10 MIL \n(2)\t50 MIL \n(3)\t100 MIL \n(4)\t500 MIL \n(5)\t1 MILHAO\n\n");
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

                    printf("Insertion: ");
                    tempo_insertion += calcula_tempo_insertion(vetor,10000);

                    printf("Bubble: ");
                    tempoBubble += calcula_tempo_bubble(vetor,10000);

                    //calcula_tempo_shell(vetor,10000);

                    //calcula_tempo_merge(vetor,10000);

                    //calcula_tempo_quick(vetor,10000);

                    //calcula_tempo_oddeven(vetor,10000);

                    free(vetor);
                    printf("\n");

                }

                printf("_________________________________________________________\n");
                printf("\nVetores de 10 mil posicoes no pior caso: \n\n");

                for(int i = 0; i < 10; i++)
                {
                    struct item* vetor = (struct item*)malloc(10000 * sizeof(struct item));

                    ordem_insertion_chave(vetor,10000);

                    printf("Insertion: ");
                    tempoPiorCasoInsertion += calcula_tempo_insertion(vetor,10000);

                    printf("Bubble: ");
                    tempoPiorCasoBubble += calcula_tempo_bubble(vetor,10000);

                    /*calcula_tempo_bubble(vetor,10000);

                    calcula_tempo_shell(vetor,10000);

                    calcula_tempo_merge(vetor,10000);

                    calcula_tempo_quick(vetor,10000);

                    calcula_tempo_oddeven(vetor,10000);*/

                    free(vetor);
                    printf("\n");

                }

                media_insertion = tempo_insertion/10;
                mediaPiorCasoInsertion = tempoPiorCasoInsertion/10;
                mediaBubble = tempoBubble/10;
                mediaPiorCasoBubble = tempoPiorCasoBubble/10;
                printf("_________________________________________________________\n");
                printf("\nInsertion: ");
                printf("\nTempo medio: %f segundos\n", media_insertion);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoInsertion);
                printf("_________________________________________________________\n");
                printf("\nBubble: ");
                printf("\nTempo medio: %f segundos\n", mediaBubble);
                printf("Tempo medio no pior caso: %f segundos\n", mediaPiorCasoBubble);
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

                break;
            case 7:
                printf("Saindo do programa. Ate logo!\n");
                return 0;
            default:
                printf("Numero invalido! Digite outro numero: ");
                }
            }
return 0;
}
