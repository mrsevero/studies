#include <iostream>
#include <stdlib.h>
#include "tadvetor_cab.h"
using namespace std;
int main() {
TadVetor tv;
while(true) {
system("CLS");
cout << "\n----------------------------------------------";
cout << "\n RELEMBRANDO VETORES";
cout << "\n----------------------------------------------";
cout << "\n0 - sair.";
cout << "\n1 - imprimir o vetor.";
cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0)";
cout << "\n3 - excluir um elemento.";
cout << "\n4 - trocar dois elementos de lugar entre si.";
cout << "\n5 - localizar o maior e o menor elementos do vetor";
cout << "\n6 - ordenar os elementos do vetor em ordem crescente";
cout << "\n7 - ordenar os elementos do vetor em ordem decrescente";
cout << "\n8 - ordenar os elementos do vetor em um segundo vetor o metodo cria o novo vetor,copia os dados e retorna o vetor ordenado";
cout << "\n---------------------";
cout << "\nQual a sua opcao -> ";
int opc;
cin >> opc;
if (opc == 0) {
break;
} else if (opc == 1) {
tv.imprimir();
cout << "\n\n";
system("PAUSE");
} else if (opc == 2) {
//= precisa pedir os dados: posicao no vetor (indice) e valor do elemento.
cout << "Indice do novo elemento: ";
int idx;
cin >> idx;
cout << "Valor do novo elemento: ";
int val;
cin >> val;
cout << tv.incluir(idx, val) << endl;
system("PAUSE");
} else if (opc == 3) {
cout << "Indice do elemento a ser removido: ";
int idx;
cin >> idx;
int val = tv.excluir(idx);
if (val == 0) {
cout << "Nao ha´ elemento na posicao " << idx;
} else if (val == -1) {
cout << "ERRO: o indice esta' fora dos limites do vetor.";
} else {
cout << "Valor excluido da posicao " << idx << ": " << val;
}
cout << "\n\n";
system("PAUSE");
} else if (opc == 4) {
cout << "Indice do primeiro elemento: ";
int idx;
cin >> idx;
cout << "Indice do segundo elemento: ";
int idy;
cin >> idy;
tv.trocar_2_elementos(idx, idy);
system("PAUSE");
}
else if (opc == 5) {
tv.localiza_maior_menor();
system("PAUSE");
} 
else if (opc == 6) {
tv.ordena_crescente();
system("PAUSE");
}
else if (opc == 7) {
tv.ordena_decrescente();
system("PAUSE");
} 
else if (opc == 8) {
tv.ordena_vetor2();
system("PAUSE");
}
}
//system("PAUSE");
cout << "\n-------------------------------------------------";
cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
}