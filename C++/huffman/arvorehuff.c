#include "arvorehuff.h"
#include "nohuff.h"
#include "listahuff.h"
#include <stdbool.h>

Arvore* criaArvore() {
  Arvore *nova = malloc(sizeof(Arvore));
  return nova;
}

bool vazia(Arvore *arv) {
  return arv->raiz == NULL;
}

void imprimeArvore(No* no) {
  if(no != NULL) {
    imprimeNo(no);
    imprimeArvore(no->left);
    imprimeArvore(no->right);
  }
}

void huffman(Arvore *arv, Lista *lista) {
  char letra = 'A';

  while(lista->cabeca->prox != NULL) {
    No* esq = removeInicio(lista);
    No* dir = removeInicio(lista);
    int f = getFrequencia(esq) + getFrequencia(dir);
    char l = letra;
    letra++;
    arv->raiz = criaNo(f, l);
    setLeft(arv->raiz, esq);
    setRight(arv->raiz, dir);
    insereNo(lista, arv->raiz);
  }
}

bool folha(No *no) {
  return (no->left == NULL && no->right == NULL);
}

void criaCodigos(No *no, int i, No* raiz, char *codigo, bool esq, Lista *lista, int tam) {
  if(no != NULL) {
    if(esq && getFrequencia(no) != getFrequencia(raiz)) {
      codigo[i] = '0';
      i++;
    } else if(!esq && getFrequencia(no) != getFrequencia(raiz)){
      codigo[i] = '1';
      i++;
    }
    if(folha(no)) {
      imprimeNo(no);
      printf(" Código: ");
      char *cod = malloc(tam*sizeof(char));
      for(int k = 0; k < i; k++) {
        cod[k] = codigo[k];
      }
      No *novo = criaNo(getFrequencia(no), getLetra(no));
      novo->codigo = cod;
      insereNo(lista, novo);
      printf("%s", novo->codigo);
    }
    
    criaCodigos(no->left, i, raiz, codigo, true, lista, tam);
    criaCodigos(no->right, i, raiz, codigo, false, lista, tam);
  }
}