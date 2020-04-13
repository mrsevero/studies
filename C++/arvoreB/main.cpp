/*==============================================================================
================================================================================
O c�digo abaixo foi extraido de "https://www.vivaolinux.com.br/script/Arvore-B/"
(foram feitos alguns ajustes identificados por "//= PROF. MARCIO")

                            prof. Marcio Feitosa
================================================================================
==============================================================================*/


/*
## Universidade Federal da Bahia
## Docente: Danilo Azevedo
## Bacharelado em Ciencia da Computacao - Estrutura de Dados II

chaves testadas: 20,40,10,30,15,35,7,26,18,22,
5,42,13,46,27,8,32,38,24,45,25

 */

#include "arvoreB.h"
using namespace std; //= PROF. MARCIO

int main() {
	Apontador * arv;
	Registro reg;
	char tecla;
	int chave, i, num = 0;
	arv = (Apontador * ) malloc(sizeof(Apontador));
	node * LISTA = (node * ) malloc(sizeof(node));
	Inicializa(arv);
	inicia(LISTA);
	if (file_exists(namefile)) {
		recuperarReg(arv, LISTA);
	}

	while(1) {

		//===============================================
		// PROF. MARCIO
		//===============================================
		cout << "\ne - encerra";
		cout << "\ni - insere";
		cout << "\nr - remove";
		cout << "\no - imprime 1";
		cout << "\np - imprime 2";
		cout << "\nc - localiza chave";

		cout << "\nOpcao + ENTER: ";
		//------------------------------------------------
		//------------------------------------------------
		//------------------------------------------------


		scanf("%c", & tecla);
		if (tecla == 'e')
			break;
		switch(tecla) {
		case 'i':
			cout << "\nNumero chave: "; //= PROF. MARCIO
			scanf("%d", & chave);
			reg.chave = chave;
			count++;
			reg.rank = count;
			fflush(stdin);
			cout << "\nNome: "; //= PROF. MARCIO
			getchar();
			fgets(reg.nome, sizeof(reg.nome), stdin);
			cout << "\nidade: "; //= PROF. MARCIO
			scanf("%d", &reg.idade);
			if (reg.chave <= 0) {
				count--;
				break;
			}
			Insere(reg, arv);
			break;
		case 'r':
			scanf("%d", & chave);
			reg.chave = chave;
			Retira(reg.chave, arv);
			remove(namefile);
			saveAux( * arv, 2 * ORDEM);
			break;
		case 'o':
			em_ordem( * arv);
			break;
		case 'p':
			for(i = 0; i < 2 * ORDEM; i++) {
				num = Imprime2( * arv, i, 0, num);
			}
			break;
		case 'c':
			getchar();
			scanf("%d", & chave);
			reg.chave = chave;
			Busca(reg, * arv);
			break;
		}
	}
	return 0;
}

//##############################################