#ifndef LISTA_H
#define LISTA_H
#include "nohuff.h"
#include <stdbool.h>

typedef struct lista {
    No *cabeca;
} Lista;

Lista* criaLista();

bool listaVazia(Lista *lista);

void imprimeLista(Lista *lista);

void imprimeCodigo(No *no, char letra, bool controle);

void insereNo(Lista *lista, No *no);

No* removeInicio(Lista *lista);

#endif