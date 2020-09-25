#include <printf.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int a;
	int b;

} fracao;

fracao somaf(fracao um, fracao dois) {
	fracao soma;
	soma.a = (um.a * dois.b + dois.a * um.b);
	soma.b = (um.b * dois.b);
	if (soma.a == 0 || soma.b == 0) {
		soma.a = 0;
		soma.b = 0;
		return soma;
	} else
		return soma;
}
fracao multiplicacao(fracao um, fracao dois) {
	fracao mult;
	mult.a = um.a * dois.a;
	mult.b = um.b * dois.b;
	if (mult.a == 0 || mult.b == 0) {
		mult.a = 0;
		mult.b = 0;
		return mult;
	} else
		return mult;
}

fracao divisao(fracao um, fracao dois) {
	fracao div;
	div.a = um.a * dois.b;
	div.b = um.b * dois.a;
	if (div.a == 0 || div.b == 0) {
		div.a = 0;
		div.b = 0;
		return div;
	} else
		return div;
}

bool igualdade(fracao um, fracao dois) {
	if (um.a * dois.b == um.b * dois.a) {
		return true;
	} else
		return false;
}

int main() {
	fracao fracaocliente;
	fracaocliente.a = 0;
	fracaocliente.b = 3;

	fracao fracaocliente2;
	fracaocliente2.a = 2;
	fracaocliente2.b = 3;

	fracao soma = somaf(fracaocliente, fracaocliente2);
	printf("%d/", soma.a);
	printf("%d \n", soma.b);
	
	fracao mult = multiplicacao(fracaocliente, fracaocliente2);
	
	printf("%d/", mult.a);
	printf("%d \n", mult.b);
	
	fracao div = divisao(fracaocliente, fracaocliente2);
	
	printf("%d/", div.a);
	printf("%d \n", div.b);
	
	bool igual = igualdade(fracaocliente, fracaocliente2);

	printf("%d \n", igual);
}