//Bruno Severo Camilo TIA: 41781619
//Luiz Tagliaferro    TIA: 31861806

#include "arvorehuff.h"
#include "listahuff.h"
#include <stdio.h>
#define ASCII 97
#define TAM 1000

int quantidadedeletras(char *letras) {
  int cont = 0;
  for(int i = 0; i < 26; i++) {
    if(letras[i] > 0)
      cont++;
  }
  return cont;
}

void codificandotexto(char *cod, char *texto, Lista *lista) {
  for(int i = 0; texto[i] != 0; i++) {
    if(texto[i] != ' ')
      imprimeCodigo(lista->cabeca, texto[i], false);
    else
      printf(" ");
  }
}

int main() {
  char letras[26] = {0};
  char texto[TAM];
  char alpha[26] = {0};
  char text[TAM];
  char t = 'A';

  printf("\nEscreva o texto para ser codificado aqui :");
  fgets(texto, TAM, stdin);
  printf("\nTexto digitado: %s", texto);
  printf("\nA seguir as letras presentes e a quantidade de cada uma!");
  printf("\n");

  for(int i = 0; texto[i] != 0; i++) {
    if(texto[i] != ' ')
      letras[texto[i] - 97]++;
  }

  int quant = quantidadedeletras(letras);

  for(int i = 0; text[i] != 0; i++) {
    if(text[i] != ' ')
      letras[text[i] - 97]++;
  }

  for(int i =0; i <26 ; i++) {
    alpha[i] = t+i;
    if (letras[i] != 0)
      printf("%c ", t+i );
  }

  printf("\n");
  for(int j = 0; j < 26; j++) {
    if (letras[j] != 0)
      printf("%d ", letras[j]);
  }


  Lista *lista = criaLista();

  printf("\n");

  for(int j = 0; j < 26; j++) {
    if(letras[j] > 0) {
      int f = letras[j];
      char l = 97 + j;
      No *novo = criaNo(f, l);
      insereNo(lista, novo);
    }
  }

  Arvore *arv = criaArvore();
  huffman(arv, lista);

  int tam = arv->raiz->letra-66;
  char codigo[tam];
  removeInicio(lista);

  printf("\nAgora o código para cada letra gerado!");


  criaCodigos(arv->raiz, 0, arv->raiz, codigo, true, lista, quant*2);  
  char codificado[TAM];
  printf("\n");
  printf("\nAbaixo o texto codificado : ");
  printf("\n");
  codificandotexto(codificado, texto, lista);
  return 0;
}