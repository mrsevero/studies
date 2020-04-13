#include <iostream>
#include "inteiro.h"

using namespace std;


int main() {
      while(true) {
        cout << "\n0 - sair.";
        cout << "\n1 - Sucessor";
        cout << "\n2 - Antecessor ";
        cout << "\n3 - Soma";
        cout << "\n4 - Subtração";
        cout << "\n5 - Multiplicação";
        cout << "\n6 - Divisão";
        cout << "\nQual a sua opcao -> ";
          int opc;
            cin >> opc;
          if (opc == 0) {
            break;
        } else if (opc == 1) {
          int b;
          cout << "Digite um numero: ";
          cin >> b;
          Inteiro sucessor(b);
          cout << sucessor.suc().getValue();
        } else if (opc == 2) {
          cout << "Digite um numero: ";
          int b;
          cout << "Digite um numero: ";
          cin >> b;
          Inteiro antecessor(b);
          cout << antecessor.ante().getValue();
        } else if (opc == 3) {
          int a;
          int b;
          cout << "Digite um numero: ";
          cin >> a;
          cout << "Digite outro numero: ";
          cin >> b;
          Inteiro num1(a);
          Inteiro num2(b);
          Inteiro c = num1 + num2;
          cout << c.getValue();
        } else if (opc == 4) {
          int a;
          int b;
          cout << "Digite um numero: ";
          cin >> a;
          cout << "Digite outro numero: ";
          cin >> b;
          Inteiro num1(a);
          Inteiro num2(b);
          Inteiro c = num1 - num2;
          cout << c.getValue();
        } else if (opc == 5) {
          int a;
          int b;
          cout << "Digite um numero: ";
          cin >> a;
          cout << "Digite outro numero: ";
          cin >> b;
          Inteiro num1(a);
          Inteiro num2(b);
          Inteiro c = num1 * num2;
          cout << c.getValue();
        } else if (opc == 6) {
          int a;
          int b;
          cout << "Digite um numero: ";
          cin >> a;
          cout << "Digite outro numero: ";
          cin >> b;
          Inteiro num1(a);
          Inteiro num2(b);
          Inteiro c = num1 / num2;
          cout << c.getValue();
        }
}
cout << "\n-------------------------------------------------";
cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
return 0;
}
