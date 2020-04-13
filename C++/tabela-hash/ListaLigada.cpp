#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Celula.h"
#include "ListaLigada.h"

using namespace std;


ListaLigada::ListaLigada() {
	prim = NULL;
	qtdCelulas = 0;
}

bool ListaLigada::vazia() {
	return prim == NULL;
}

int ListaLigada::tamanho() {
	return this->qtdCelulas;
}

void ListaLigada::insereInicio(int i) {
	Celula * c = new Celula(i);
	c->setProx(prim);
	prim = c;
	qtdCelulas++;
}

string ListaLigada::insereEmN(Celula * c, int pos) {

	stringstream ss;

	while (true) {

		//int x = 2;

		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1) {
			insereInicio(c->getInfo());
			ss << "Inserido no inicio";
			break;
		}

		Celula * cursor = this->prim;
		for (int i = 1; i < pos - 1; i++) {
			cursor = cursor->getProx();
		}

		c->setProx(cursor->getProx());
		cursor->setProx(c);

		qtdCelulas++;

		ss << "Inserido na posicao " << pos;

		break;

	}

	return ss.str();

}

void ListaLigada::remover(int pos){
  if(!vazia()){

    if(prim->getProx() == NULL)
      prim = NULL;
    
    else
    {
      Celula * cursor = prim;
      Celula * cursor2 = prim;


      for (int i = 1; i < pos - 1; i++) {
        cursor = cursor->getProx();
        cursor2 = cursor2->getProx();
      }

      delete cursor->getProx(); 

      for (int i = pos; i < qtdCelulas; i++) {
        cursor2 -> setProx((cursor)->getProx()->getProx());
        cursor2 = cursor->getProx();
      }

      qtdCelulas--; // atualiza a cauda
    }
  }
}


void ListaLigada::imprime() {
	Celula * cursor = prim;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "]\n";
}


int ListaLigada::localiza(int valor) {
	Celula * cursor = prim;
	int pos = 0;
	while(cursor != NULL) {
		pos++;
		if (cursor->getInfo() == valor) {
			return pos;
		}
		cursor = cursor->getProx();
	}
	return 0;
}

Celula * ListaLigada::getPrim() {
	return this->prim;
}
