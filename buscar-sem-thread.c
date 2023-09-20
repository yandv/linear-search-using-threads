#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

static int QNT_THREADS = 4;

int containsElement(int *vetor, int nums, int x);

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
    printf("Resposta: %s\n", containsElement(vetor, num, x) == 0 ? "Nao esta no vetor" : "Esta no vetor");
    return 0;
}

int containsElement(int *vetor, int nums, int x) {
    for (int i = 0; i < nums; i++) {
        if (vetor[i] == x) {
            return 1;
        }
    }

    return 0;
}