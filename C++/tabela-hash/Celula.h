#ifndef CELULA_H
#define CELULA_H

class Celula {
	private:
	int info;
	Celula * prox;

	public:
	Celula(int);
	int  getInfo();
	void setInfo(int);
	Celula * getProx();
	void setProx(Celula * );
};
#endif

