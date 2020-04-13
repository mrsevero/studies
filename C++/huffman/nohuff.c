#include "nohuff.h"

No* criaNo(int f, char l) {
  No *nova = malloc(sizeof(No));
  nova->frequencia = f;
  nova->letra = l;
  return nova;
}

void imprimeNo(No *no) {
  printf("\nLetra %c: %d", getLetra(no), getFrequencia(no));
}

int getFrequencia(No *no) {
  return no->frequencia;
}

char getLetra(No *no) {
  return no->letra;
}

char* getCodigo(No *no) {
  return no->codigo;
}

void setLeft(No *raiz, No *no) {
  raiz->left = no;
}

void setRight(No *raiz, No *no) {
  raiz->right = no;
}