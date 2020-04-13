#include <iostream>
#include <string.h>
#include "Celula.h"

using namespace std;

class ListaLigada {
	
	//= privado
	private:
	Celula * prim;
	int qtdCelulas;
	
	//= publico
	public:
	ListaLigada();
	bool vazia();
	int tamanho();
	void insereInicio(int i);
	string insereEmN(Celula * c, int pos);
	void imprime();
  void remover(int pos);
  
	int localiza(int valor);
	Celula * getPrim();
	
};
