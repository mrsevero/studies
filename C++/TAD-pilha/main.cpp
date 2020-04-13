#include <iostream>
#include <stdlib.h>
//#include "tad_vetor_essencial.h"
#include "tad_vetor_essencial.cpp"

using namespace std;

int main()
{
	
	typedef unsigned int ui;
	
	system("cls");
	cout << "Informe o tamanho do vetor: ";
	int tam;
	cin >> tam;
    
    TadVetorEssencial<ui> tv(tam);
    
    while (true){
    	system("cls");
    	cout << "\n0 - sair";
    	cout << "\n1 - incluir um elemento";
    	cout << "\n2 - excluir um elemento";
    	cout << "\n9 - imprimir vetor";
    	cout << "\n\nOpcao -> ";
    	int opc;
    	cin >> opc;
    	
    	if (opc==0){
			break;
		}
		else if (opc==1){
			int idx;
			cout << "informe a posicao que o numero sera' inserido: ";
			cin >> idx;
			ui num;
			cout << "informe o numero: ";
			cin >> num;
			bool ok = tv.inserir(idx,num);
			if (ok){
				cout << "Incluido com sucesso";
			}
			else {
				cout << "Falha na inclusao. Verifique se a posicao nao esta' ocupada.";
			}
		}
		else if (opc==9){
			tv.imprimir();
		}
		cout << "\n\n";
		system("pause");
    	
		
		
	}
	
	cout << "\n\n--- Obrigado e ate' a proxima ---\n\n\n";
    
    
    return 0;       
}