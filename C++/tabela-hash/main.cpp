#include <iostream>
#include "TabHash.h"

using namespace std;

int main() {
  TabHash th(5);

  while (true) {
		cout << "\n0 - sair";
		cout << "\n1 - inserir um elemento.";
		cout << "\n2 - remover um elemento.";
		cout << "\n3 - verificar se um determinado elemento esta' na tabela e informar sua posicao (indice do vetor + posicao na lista).";
		cout << "\n4 - imprimir a tabela e tambem o total de elementos presentes na tabela.";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1;
			cout << "Valor do elemento: ";
			cin >> opc1;
      th.incluir(opc1);
		} else if (opc == 2) {
      int opc2;
			cout << "Valor do elemento: ";
			cin >> opc2;
      cout << th.remover(opc2);
		} else if(opc == 3) {
			int opc3;
			cout << "Valor do elemento: ";
			cin >> opc3;
      th.encontra(opc3);
		} else if (opc == 4) {
			cout << "\n\nImpressao dos elemento da lista -> ";
			cout << th.imprimir();
		}
	}
	cout << "\n\n\n-----  FIM  -----\n\n\n";
	return 0;
}