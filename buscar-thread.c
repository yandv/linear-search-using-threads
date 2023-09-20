#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

/*
*
*/

static int QNT_THREADS = 4;

int RESPONSE = 0;

typedef struct ArgumentsStruct {
    int *nums;
    int p; 
    int r; 
    int x;
} ArgumentsStruct;

int containsElementThread(int *vetor, int nums, int x);

void* containsElement(void *args);

int main(int argc, char const *argv[])
{
        if (argc == 0) {
        printf("Numero invalido...");
        return 0;
    }

    int num;
    sscanf(argv[1],"%d",&num);

    int x;
    sscanf(argv[2],"%d",&x);

    char string[64] = "tests/";

    strcat(string, argv[1]);
    strcat(string, "x");
    strcat(string, argv[1]);
    strcat(string, ".txt");

    FILE *file = fopen(string, "r");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo %s...\n", string);
        return 0;
    }

    int vetor[num];

    for (int i = 0; i < num; i++) {
        fscanf(file, "%i ", &vetor[i]);
    }

    printf("Testando em %i elementos e procurando %d...\n", num, x);
    printf("Resposta: %s\n", containsElementThread(vetor, num, x) == 0 ? "Nao esta no vetor" : "Esta no vetor");
    return 0;
}

int containsElementThread(int *vetor, int nums, int x) {
    pthread_t threadIds[QNT_THREADS];

    int numsPerThread = nums / QNT_THREADS;

    int *ptr;
    int response = 0;

    for (int i = 0; i < QNT_THREADS; i++) {
        ArgumentsStruct args = { vetor, numsPerThread * i, numsPerThread * (i + 1), x };
        pthread_create(&threadIds[i], NULL, &containsElement, &args);
    }

    for (int i = 0; i < QNT_THREADS; i++) {
        pthread_join(threadIds[i], (void**) &ptr);
        response |= *ptr;
    }

    return response;
}

void* containsElement(void *args) {
    ArgumentsStruct *arguments = (struct ArgumentsStruct *) args; 

    RESPONSE = 0;

    for (int i = arguments->p; i < arguments->r; i++) {
        if (arguments->nums[i] == arguments->x) {
            RESPONSE = 1;
            pthread_exit(&RESPONSE);
        }
    }

    pthread_exit(&RESPONSE);
}