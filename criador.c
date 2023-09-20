#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc == 0) {
        printf("Numero invalido...");
        return 0;
    }

    int num;
    sscanf (argv[1],"%d",&num);

    char string[64] = "tests/";

    strcat(string, argv[1]);
    strcat(string, "x");
    strcat(string, argv[1]);
    strcat(string, ".txt");

    FILE *file = fopen(string, "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo %s...\n", string);
        return 0;
    }

    int vetor[num];

    for (int i = 0; i < num; i++) {
        vetor[i] = rand() % num;
        fprintf(file,"%d ",vetor[i]);
    }

    return 0;
}
