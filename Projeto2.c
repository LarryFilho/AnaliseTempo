#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        for (j = i; j > 0 && vetor[j - 1].valor > vetor[j].valor; j--)
        {
            aux = vetor[j - 1];
            vetor[j - 1] = vetor[j];
            vetor[j] = aux;
        }
    }
}


void ordem_insertion_chave(struct item vetor[], int tamanho)
{
    int i, j;
    struct item aux;
    for (i = 1; i < tamanho; i++)
    {
        for (j = i; j > 0 && vetor[j - 1].chave < vetor[j].chave; j--)
        {
            aux = vetor[j - 1];
            vetor[j - 1] = vetor[j];
            vetor[j] = aux;
        }
    }
}

void preencher_aleatorio(struct item vetor[], int tam)
{
    srand(time(NULL));

    for (int i = 0; i < tam; i++) {
        vetor[i].chave = rand();
        vetor[i].valor = ((float)rand() / RAND_MAX) * 900 + 100;
    }
}

void calcula_tempo(struct item vetor[], int tam)
{
    clock_t t;
    struct item vetor_copia[tam];

    for (int i = 0; i < 3; i++)
    {
        printf("CASO: %d \n", i + 1);

        memcpy(vetor_copia, vetor, tam * sizeof(struct item));

        t = clock();
        insertion(vetor_copia, tam);
        t = clock() - t;
        double tempoDeExecucao = ((double)t)/CLOCKS_PER_SEC;

        printf("-----------------------------------------------------------------------------------------------\n");
        printf("Tempo de execucao da funcao insertion: %f segundos\n", tempoDeExecucao);
        printf("-----------------------------------------------------------------------------------------------\n");
    }
}

int main(){

int escolha;
printf("ESCOLHA O METODO DE ORDENACAO:\n");

while (1) {
        printf("===========================================================\n\t1-Insertion Sort: \n\t2-Merge Sort: \n\t3-Bubble Sort: \n\t4-Quick Sort: \n\t5-Shell Sort: \n\t6-Outro: \n7-Sair do programa:\n===========================================================\n");
        printf("O que deseja fazer: ");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha)
        {
            case 1:
                    srand(time(NULL));

                    struct item* vetor1 = (struct item*)malloc(10000 * sizeof(struct item));

                    preencher_aleatorio(vetor1, 10000);

                    printf("VETOR DE 10 MIL POSICOES DO TIPO 1 (TANTO CHAVE QUANTO NUMERO ALEATORIO)\n");

                    calcula_tempo(vetor1,10000);

                    ordem_insertion_chave(vetor1,10000);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    printf("VETOR DE 10 MIL POSICOES DO CASO 2 (CHAVE ORDENADA): \n");

                    calcula_tempo(vetor1,10000);

                    free(vetor1);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    struct item* vetor2 = (struct item*)malloc(50000 * sizeof(struct item));

                    preencher_aleatorio(vetor2, 50000);

                    printf("VETOR DE 50 MIL POSICES DO TIPO 1 (TANTO CHAVE QUANTO NUMERO ALEATORIO)\n");

                    calcula_tempo(vetor2,50000);

                    ordem_insertion_chave(vetor2,50000);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    printf("VETOR DE 50 MIL POSICOES DO CASO 2 (CHAVE ORDENADA): \n");

                    calcula_tempo(vetor2,50000);

                    free(vetor2);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    struct item* vetor3 = (struct item*)malloc(100000 * sizeof(struct item));

                    preencher_aleatorio(vetor3, 100000);

                    printf("VETOR DE 100 MIL POSICOES DO TIPO 1 (TANTO CHAVE QUANTO NUMERO ALEATORIO)\n");

                    calcula_tempo(vetor3,100000);

                    ordem_insertion_chave(vetor3,100000);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    printf("VETOR DE 100 MIL POSICOES DO CASO 2 (CHAVE ORDENADA): \n");

                    calcula_tempo(vetor3,100000);

                    free(vetor3);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    struct item* vetor4 = (struct item*)malloc(500000 * sizeof(struct item));

                    preencher_aleatorio(vetor4, 500000);

                    printf("VETOR DE 500 MIL POSICOES DO TIPO 1 (TANTO CHAVE QUANTO NUMERO ALEATORIO)\n");

                    calcula_tempo(vetor4,500000);

                    ordem_insertion_chave(vetor4,500000);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    printf("VETOR DE 500 MIL POSICOES DO CASO 2 (CHAVE ORDENADA): \n");

                    calcula_tempo(vetor4,500000);

                    free(vetor4);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    struct item* vetor5 = (struct item*)malloc(1000000 * sizeof(struct item));

                    preencher_aleatorio(vetor5, 1000000);

                    printf("VETOR DE 1 MILHAO POSICOES DO TIPO 1 (TANTO CHAVE QUANTO NUMERO ALEATORIO)\n");

                    calcula_tempo(vetor5,1000000);

                    ordem_insertion_chave(vetor5,1000000);

                    printf("-----------------------------------------------------------------------------------------------\n");

                    printf("VETOR DE 1 MILHAO POSICOES DO CASO 2 (CHAVE ORDENADA): \n");

                    calcula_tempo(vetor5,1000000);

                    free(vetor5);

                    printf("-----------------------------------------------------------------------------------------------\n");

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
