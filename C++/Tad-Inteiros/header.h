#ifndef header
#define header
#include <stdlib.h>
using namespace std;
  class Inteiros{
    private:
    //int * numeros;
    int Num1,Num2;
    public:
    void sair();
    int soma(int Num1, int Num2);
    int sub(int Num1, int Num2);
    int mult(int Num1, int Num2);
    int divi(int Num1, int Num2);
    int sucessor(int Num1);
    int antecessor(int Num1);
};
#endif