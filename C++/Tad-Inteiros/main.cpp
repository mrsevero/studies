#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;
int main() {
	
Inteiros start;

while(true) {

int Num1;
int Num2;
cout << "\n0 - sair.";
cout << "\n1 - somar";
cout << "\n2 - subtrair";
cout << "\n3 - multiplicar";
cout << "\n4 - dividir";
cout << "\n5 - sucessor";
cout << "\n6 - antecessor";
cout << "\n Escolha uma opção: ";
cout << "\n";
int opc;
cin >> opc;
if (opc == 0) {
  cout << "Até a próxima!!!! ";
break;
} 
  else if (opc == 1) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << "Segundo numero: ";
    cin >> Num2;
    cout << start.soma(Num1,Num2);
    cout << "\n Resultado!";
    cout << "\n\n";
}
  else if (opc == 2) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << "Segundo numero: ";
    cin >> Num2;
    cout << start.sub(Num1,Num2);
    cout << "\n Resultado!";
    cout << "\n\n";
} 
  else if (opc == 3) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << "Segundo numero: ";
    cin >> Num2;
    cout << start.mult(Num1,Num2);
    cout << "\n Resultado!";
    cout << "\n\n";
}
  else if (opc == 4) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << "Segundo numero: ";
    cin >> Num2;
    cout << start.divi(Num1,Num2);
    cout << "\n Resultado!";
    cout << "\n\n";
} 
  else if (opc == 5) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << start.sucessor(Num1);
    cout << "\n Resultado!";
    cout << "\n\n";
} 
  else if (opc == 6) {
    cout << "Primeiro numero: ";
    cin >> Num1;
    cout << start.antecessor(Num1);
    cout << "\n Resultado!";
    cout << "\n\n";
} 
}
return 0;
}