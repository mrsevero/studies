#ifndef ARVORE_H
#define ARVORE_H
#include "no.h"

class Arvore{
  private:
    No *raiz;
    int altura = 0;
  public:
    Arvore();
    void inserir(int chave);
    void inserirAux(No *no, int chave, int cont);
    No* getRaiz();
    void imprimeRaiz();
    void setRaiz(No *no);
    void preOrdem(No *no);
    void emOrdem(No *no);
    void posOrdem(No *no);
    No* localiza(int chave, No *r);
    void remove(int chave);
    void removeRaiz(No *no);
    No* encontraMenor(No *no);
    int getAltura();
    int calculaAltura(No *no);
};

#endif