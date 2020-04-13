#include <iostream>
#include "tad_vetor_essencial.h"

using namespace std;

template<class T> TadVetorEssencial<T>::TadVetorEssencial() {

}

template<class T> TadVetorEssencial<T>::TadVetorEssencial(int TAMANHO) {
	this->tamanho = TAMANHO;
	this->vetor = new T[TAMANHO];
	for (int i = 0; i < TAMANHO; i++) {
		this->vetor[i] = 0;
	}
}

template<class T> TadVetorEssencial<T>::~TadVetorEssencial(){
	delete(this->vetor);
}

template<class T> bool TadVetorEssencial<T>::inserir(int indice, const T num) {
	if (this->vetor[indice] > 0) {
		return false;
	}
	this->vetor[indice] = num;
	return true;
}


template<class T> void TadVetorEssencial<T>::imprimir() {
	cout << "\n\nTamanho do vetor = " << this->tamanho << endl;
	cout << "[ ";
	for (int i=0; i < this->tamanho; i++) {
		cout << this->vetor[i] << " ";
	}
	cout << "]\n\n";
}





