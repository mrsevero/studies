#include <iostream>
#include "pilha.h"

using namespace std;

int main() {
    Pilha minhaPilha(4);  // verficando se a minha esta vazia
    if (minhaPilha.isEmpty()) {
        cout << "A pilha esta  vazia" << endl;
    } else {
        cout << "A pilha nao esta vazia" << endl;
    }

    minhaPilha.push(5);
    minhaPilha.push(10);
    minhaPilha.push(15);
    minhaPilha.push(20);
    minhaPilha.push(25); 

    int estaNaPilha = minhaPilha.procurar(10);

    (estaNaPilha != -1) ? cout << "O numero esta na pilha e esta na posicao " << estaNaPilha << endl : cout
            << "Numero procurado nao esta na pilha" << endl;

    minhaPilha.imprimir();

    if (minhaPilha.isFull()) {
        cout << "A pilha esta cheia" << endl;
    } else {
        cout << "A pilha nao esta cheia" << endl;
    }

    cout << "Numero " << minhaPilha.pop() << " removido da pilha" << endl;

    if (minhaPilha.isFull()) {
        cout << "A pilha esta cheia" << endl;
    } else {
        cout << "A pilha nao esta cheia" << endl;
    }

    minhaPilha.imprimir();
    minhaPilha.pop();
    minhaPilha.pop();
    minhaPilha.pop();
    minhaPilha.imprimir();

    if (minhaPilha.isEmpty()) {
        cout << "A pilha esta  vazia" << endl;
    } else {
        cout << "A pilha nao esta vazia" << endl;
    }
    return 0;
}