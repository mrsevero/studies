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
fracao multf(fracao um, fracao dois) {
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

fracao divf(fracao um, fracao dois) {
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

bool igualf(fracao um, fracao dois) {
	if (um.a * dois.b == um.b * dois.a) {
		return true;
	} else
		return false;
}

int main() {
	fracao teste;
	teste.a = 0;
	teste.b = 3;

	fracao teste2;
	teste2.a = 2;
	teste2.b = 3;

	fracao soma = somaf(teste, teste2);
	fracao mult = multf(teste, teste2);
	fracao div = divf(teste, teste2);
	bool igual = igualf(teste, teste2);

	printf("%d/", soma.a);
	printf("%d \n", soma.b);

	printf("%d/", mult.a);
	printf("%d \n", mult.b);

	printf("%d/", div.a);
	printf("%d \n", div.b);

	printf("%d \n", igual);
}