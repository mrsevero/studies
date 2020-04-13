#include "vetor.h"

template<class T>
Vetor<T>::Vetor(int tamanho) {
    this->tamanho = tamanho;
    this->vetor = new T[tamanho];
    for (int i = 0; i < tamanho; i++) {
        this->vetor[i] = 0;
    }
}

template<class T>
Vetor<T>::~Vetor() {}

template<class T>
bool Vetor<T>::inserir(T numero, int indice) {
    if (this->vetor[indice] == 0) {
        this->vetor[indice] = numero;
        return true;
    }
    return false;
}

template<class T>
T Vetor<T>::remover(int indice) {
    T numeroASerRemovido = this->vetor[indice];
    this->vetor[indice] = 0;
    return numeroASerRemovido;
}

template<class T>
T Vetor<T>::ler(int indice) {
    T numeroASerLido = this->vetor[indice];
    return numeroASerLido;
}