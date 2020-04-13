#define TAMANHO 5
#ifndef TADVETOR_CAB_H
#define TADVETOR_CAB_H
#include <stdlib.h>
using namespace std;
class TadVetor {
private:
//int * numeros;
int numeros[TAMANHO];
public:
TadVetor();
void imprimir();
string incluir(int indice, int valor);
int excluir(int indice);
void trocar_2_elementos(int indice1, int indice2);
void localiza_maior_menor();
void ordena_crescente();
void ordena_decrescente();
void ordena_vetor2();
};
#endif
