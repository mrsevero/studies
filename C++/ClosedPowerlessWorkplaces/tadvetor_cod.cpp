#include <iostream>
#include "tadvetor_cab.h"
TadVetor::TadVetor() {
//numeros = new int[TAMANHO];
for (int i = 0; i < TAMANHO; i++) {
numeros[i] = 0;
}
}
//==============================================================================
// Metodo para imprimir o vetor.
void TadVetor::imprimir() {
cout << "\n[ ";
for (int i = 0; i < TAMANHO; i++) {
cout << numeros[i] << " ";
}
cout << "]";
}
//------------------------------------------------------------------------------
/**
* Metodo para incluir um elemento no vetor. A posicao tem que estar vaga
* (valor do elemento igual a zero). O novo elemento tem que ser maior que
* zero.
*
* @param indice - indice do elemento que sera´ incluido.
* @param valor - valor do elemento a ser incluido.
* @return
*/
string TadVetor::incluir(int indice, int valor) {
// verifica se o valor e´ maior que zero
if (valor < 0) {
return "ERRO: o valor tem que ser maior que zero.";
}
// verifica se o indice e´ valido
if (indice < 0 || indice > TAMANHO - 1) {
return "ERRO: o indice esta´ fora dos limites do vetor.";
}
// verifica se a posicao ja´ esta´ ocupada.
if (numeros[indice] > 0) {
return "ERRO: posicao ocupada.";
}
// passou por todas as verificacoes: inserir
numeros[indice] = valor;
return "Inclusao bem sucedida.";
}
/**
* Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
* elemento (valor).
*
* @param indice - indice do elemento que sera´ excluido.
* @return - valor do elemento excluido. Se retornar zero e´ porque a
* posicao estava vazia; se retornar -1 e´ porque o indice e´ invalido.
*/
int TadVetor::excluir(int indice) {
// verifica se o indice e´ valido
if (indice < 0 || indice > TAMANHO - 1) {
return -1;
}
}

void TadVetor::trocar_2_elementos(int indice1, int indice2) {
  int aux = numeros[indice2];
    numeros[indice2] = numeros[indice1];
    numeros[indice1] = aux;
}

void TadVetor::localiza_maior_menor(){
    int aux[TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        aux[i] = numeros[i];
    }
    bool swapped;
    for (int j = 0; j < TAMANHO; j++){
        swapped = false;
        for (int k = 0; k < TAMANHO; k++) {
            if (aux[k] > aux[k+1]){
                int temp = aux[k];
                aux[k] = aux[k+1];
                aux[k + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "O menor numero: " << aux[0] << "\nO maior numero: " << aux[TAMANHO];
}

void TadVetor::ordena_crescente(){
    bool swapped;
    for (int i = 0; i < TAMANHO; i++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (numeros[j] > numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Vetor ordenado em ordem crescente\n";
}

void TadVetor::ordena_decrescente(){
    bool swapped;
    for (int i = 0; i < TAMANHO; i++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (numeros[j] < numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Vetor ordenado em ordem decrescente\n";
}

void TadVetor::ordena_vetor2(){
    int vetor2[TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        vetor2[i] = numeros[i];
    }
    bool swapped;
    for (int k = 0; k < TAMANHO; k++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (vetor2[j] > vetor2[j+1]){
                int temp = vetor2[j];
                vetor2[j] = vetor2[j+1];
                vetor2[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Novo vetor copiado e ordenado\n";
    cout << "\n[ ";
    for (int l = 0; l < TAMANHO; l++) {
        cout << vetor2[l] << " ";
    }
    cout << "]";
}

