
#ifndef PILHA_H
#define PILHA_H
#define TAMANHO 10

#include "vetor.h"

class Pilha : Vetor<int> {
private:
    int topo;
    int tamanhoDoVetor;

public:
    Pilha(int tamanhoDaPilha);

    ~Pilha();

    bool isEmpty();

    bool isFull();

    void push(int x);

    int pop();

    void imprimir();

    int procurar(int numeroProcurado);

};

#endif