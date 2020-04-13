#ifndef INTEIRO_H
#define INTEIRO_H

class Inteiro
{	
	private:
		int value;

	public:
		Inteiro(int v);
    ~Inteiro();
		Inteiro suc();
    Inteiro ante();
		Inteiro operator+(Inteiro n);
		Inteiro operator*(Inteiro n);
    Inteiro operator/(Inteiro n);
    Inteiro operator-(Inteiro n);
		int getValue();
};

#endif
