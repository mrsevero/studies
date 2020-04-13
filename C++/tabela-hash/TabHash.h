#ifndef TABHASH_H
#define TABHASH_H

#include <iostream>
#include "ListaLigada.h"

using namespace std;

class TabHash {

	private:
	int tamanho;
	ListaLigada * vetor;
	int posicao(int valor);

	public:
	TabHash(int tamanho);
  void encontra(int valor);
	string incluir(int valor);
	string remover(int valor);
	string imprimir();
};

#endif
