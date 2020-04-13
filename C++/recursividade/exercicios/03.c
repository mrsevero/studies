#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int ocorrencias(char palavra[], char letra) {
    if (palavra[0] == NULL) return 0;
    return (letra == palavra[0]) + ocorrencias(&palavra[1], letra);
}

int main() {
    char palavra[MAX];
    char letra;

    scanf("%s %c", palavra, &letra);

    int ocorre = ocorrencias(palavra, letra);
    printf("%d", ocorre);

    return 0;
}