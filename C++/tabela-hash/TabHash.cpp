#include <stdlib.h>
#include <sstream>
#include "TabHash.h"
#include "Celula.h"

//******************************************************************************
//                             CONSTRUTOR
//******************************************************************************
TabHash::TabHash(int tamanho) {
	this->vetor = new ListaLigada[tamanho];
	this->tamanho = tamanho;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


//******************************************************************************
// CALCULA A POSICAO DA LISTA NO VETOR EM QUE ESTA', OU DEVERA' ESTAR, O ELEMENTO
// CUJO VALOR E' IGUAL AO PARAMETRO "valor"
//******************************************************************************
int TabHash::posicao(int valor) {
	return valor % tamanho;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


//******************************************************************************
//                    VERIFICAR SE UM ELEMENTO ESTA NA TABELA
//******************************************************************************
void TabHash::encontra(int valor) {
	int pos = posicao(valor); //= posicao no vetor que sera' inserido o novo elemento.

	//==========================================================================
	// verificar se o valor ja' se encontra armazenado.
	int aux = vetor[pos].localiza(valor);
	if (aux > 0) {
    cout << "Valor " << valor << " ja consta armazenado na tabela " << pos <<" na posicao " << aux << ".\n";
	}else{
    cout << "\n\nElemento nao esta armazenado na lista\n";
  }
}

//******************************************************************************
//                    INCLUIR UM ELEMENTO NA TABELA
//******************************************************************************
string TabHash::incluir(int valor) {

	stringstream ss;
	int pos = posicao(valor); //= posicao no vetor que sera' inserido o novo elemento.

	//==========================================================================
	// verificar se o valor ja' se encontra armazenado.
	int aux = vetor[pos].localiza(valor);
	if (aux > 0) {
		ss << "Valor " << valor << " ja consta armazenado na tabela na posicao" << pos <<".";
		return ss.str();
	}
	//--------------------------------------------------------------------------

	vetor[pos].insereInicio(valor);
	ss << "Elemento " << valor << " foi incluido na Lista " << pos;

	return ss.str();

}
string TabHash::imprimir() {

	stringstream ss;

  int count = 0;
	for (int i = 0; i < this->tamanho; i++) {

		Celula * cursor = vetor[i].getPrim();
		ss << "\n(" << i << ") [ ";
		while (cursor != NULL) {
			ss << cursor->getInfo() << " ";
      count++;
			cursor = cursor->getProx();
		}
		ss << "]";
	}
  cout << "\nExiste(m) " << count << " elemento(s) na tabela";
	//--------------------------------------------------------------------------
	
	return ss.str();

}


string TabHash::remover(int valor){
  stringstream ss;
	int pos = posicao(valor); 
	int aux = vetor[pos].localiza(valor);

	if (aux > 0) {
    vetor[pos].remover(pos);
		ss << "Elemento removido";
		return ss.str();
	}else{
    ss << "Elemento nao esta armazenado na tabela";
		return ss.str();
  }
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
