#include <iostream>
#include "pilha.h"
#include "vetor.cpp"

using namespace std;

Pilha::Pilha(int tamanhoDoVetor) : Vetor<int>(tamanhoDoVetor) {
    this->topo = -1;
    this->tamanhoDoVetor = tamanhoDoVetor;
}

Pilha::~Pilha() {}

bool Pilha::isEmpty() {
    if (this->topo < 0) {
        return true;
    }

    return false;
}

bool Pilha::isFull() {
    if (this->topo < tamanhoDoVetor - 1) {
        return false;
    }

    return true;
}

void Pilha::push(int x) {
    if (!Pilha::isFull()) {
        topo++;
        Pilha::inserir(x, topo);
        cout << "Número " << x << " adicionado com sucesso!" << endl;
        return;
    }

    cout << "Falha ao adicionar o número " << x << " pois a pilha está cheia!" << endl;
}

int Pilha::pop() {
    if (this->topo < 0) {
        cout << "Falha ao obter número pois o array está vazio." << endl;
    }

    int currentNumber = Pilha::remover(this->topo);
    topo--;
    return currentNumber;
}

void Pilha::imprimir() {
    cout << "[ ";

    for (int i = 0; i < tamanhoDoVetor; i++) {
        cout << Pilha::ler(i) << " ";
    }

    cout << "]" << endl;

}

int Pilha::procurar(int numeroProcurado) {
    for (int i = 0; i < tamanhoDoVetor; i++) {
        if (Pilha::ler(i) == numeroProcurado) {
            return i;
        }
    }
    return -1;
}