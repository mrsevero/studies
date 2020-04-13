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
int trocar_2_elementos(int indice1, int indice2);
int localiza_maior_menor();
int ordena_crescente();
int ordena_decrescente();
int ordena_vetor2();
};
#endif
