#ifndef NO_H
#define NO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  struct No* prox;
  struct No* left;
  struct No* right;
  int frequencia;
  char letra;
  char *codigo;
} No;

No* criaNo(int f, char l);

void imprimeNo(No *no);

int getFrequencia(No *no);

char getLetra(No *no);

char* getCodigo(No *no);

void setLeft(No *raiz, No *no);

void setRight(No* raiz, No *no);

#endif