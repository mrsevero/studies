#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int busca(char palavra[], char letra) {
    int n = 0;
    if (palavra[n] == letra)
        return n;
    return 1 + busca(&palavra[n+1],letra);
}

int main() {
    char palavra[MAX];
    char letra;

    scanf("%s %c", palavra, &letra);

    int busc = busca(palavra, letra);
    printf("%d", busc);

    return 0;
}