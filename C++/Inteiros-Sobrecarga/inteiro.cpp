#include "inteiro.h"

using namespace std;

	Inteiro::Inteiro(int v){
		value = v;
}

  Inteiro::~Inteiro(){}


	int Inteiro::getValue(){
		return value;
}


	Inteiro Inteiro::suc(){
		Inteiro n(value+1);
		return n;
}
  Inteiro Inteiro::ante(){
		Inteiro n(value-1);
		return n;
}

	Inteiro Inteiro::operator+(Inteiro n){
		Inteiro s(value+n.getValue());
		return s;
}
  Inteiro Inteiro::operator-(Inteiro n){
		Inteiro s(value-n.getValue());
		return s;
}
	Inteiro Inteiro::operator*(Inteiro n){
		if (n.getValue() == 0 || value == 0)
		return 0;
		else if (n.getValue() == 1)
		return value;
		else
		return value*n.getValue();
}


  Inteiro Inteiro::operator/(Inteiro n){
    if(n.getValue() == 0 || value == 0)
    return 0;
    else if (n.getValue() == 1)
    return value;
    else
    return value/n.getValue();
  }
