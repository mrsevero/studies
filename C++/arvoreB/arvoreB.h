#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#define ORDEM 2
#define namefile "_arquivo.dat"

extern int cont, count;

typedef struct {
	int chave;
	char nome[20];
	int idade;
	int ApPage[2];
	int rank;
} Registro;

typedef struct Pagina_str * Apontador;
typedef struct Pagina_str {
	int n;
	int pageNum;
	int num;
	Registro r[2 * ORDEM];
	Apontador p[2 * ORDEM + 1];
} Pagina;

struct Node {
	Registro info;
	struct Node * prox;
};
typedef struct Node node;

//####################################################

typedef Apontador TipoDicionario;

//############################### Estrutura 1 Btree

//############################# //Estrutura 2 lista encadeada

void Inicializa(TipoDicionario * Dicionario);
void inicia(node * LISTA);
void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int * Diminuiu);
void Busca(Registro Reg, Apontador Ap);
void em_ordem(Apontador raiz);
void buscainFile(Registro Reg, Apontador pagina);
int isleaf(Apontador a);
int file_exists(const char * filename);
void Insere(Registro Reg, Apontador * Ap);
void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir);
void Ins(Registro Reg, Apontador Ap, int * Cresceu, Registro * RegRetorno, Apontador * ApRetorno);
int Imprime2(Apontador p, int Nivel, int aux, int n);
int Imprime(Apontador p, int N, int aux, int n);
void InsertPosFile(Registro Reg, Apontador * Ap);
node * busca(Registro info, node * LISTA);
void InsPosFile(Registro Reg, Apontador Ap, int * Cresceu, Registro * RegRetorno, Apontador * ApRetorno);
void pos_ordem(Apontador raiz);
void Retira(int Ch, Apontador * Ap);
void Ret(int Ch, Apontador * Ap, int * Diminuiu);
void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int * Diminuiu);
void saveAux(Apontador p, int Nivel);
void salvar(Apontador pagina, Registro Reg[]);
void recuperarReg(Apontador * arv, node * LISTA);
void insereInicio(Registro info, node * LISTA);
void execut(Registro info, node * LISTA);
void exibe(node * LISTA);

#endif