#include <iostream>
#include <stdlib.h>
#include "arvore.h"

Arvore::Arvore(){
  raiz = NULL;
}

void Arvore::inserir(int chave){
  if(raiz == NULL){
    raiz = new No(chave);
    altura++;
  }
  else
    inserirAux(raiz, chave, 1);
}

void Arvore::inserirAux(No *no, int chave, int cont){
  cont++;
  if(chave < no->getChave()){
    if(no->getEsq() == NULL){
      No *novo_no = new No(chave);
      novo_no->setPai(no);
      no->setEsq(novo_no);
    }
    else
      inserirAux(no->getEsq(), chave, cont);
  }
  else if(chave > no->getChave()){
    if(no->getDir() == NULL){
      No *novo_no = new No(chave);
      novo_no->setPai(no);
      no->setDir(novo_no);
    }
    else
      inserirAux(no->getDir(), chave, cont);
  }
  if(cont > altura)
    altura = cont;
  //Não podem existir 2 chaves iguais
}

No* Arvore::getRaiz(){
  return raiz;
}

void Arvore::imprimeRaiz(){
  std::cout << "\n raiz = " << raiz->getChave() << std::endl;
}

void Arvore::setRaiz(No *no){
  raiz = no;
}

void Arvore::preOrdem(No* no){
  if(no != NULL){
    std::cout << no->getChave() << " ";
    preOrdem(no->getEsq());
    preOrdem(no->getDir());
  }
}

void Arvore::emOrdem(No* no){
  if(no != NULL){
    emOrdem(no->getEsq());
    std::cout << no->getChave() << " ";
    emOrdem(no->getDir());
  }
}

void Arvore::posOrdem(No* no){
  if(no != NULL){
    posOrdem(no->getEsq());
    posOrdem(no->getDir());
    std::cout << no->getChave() << " ";
  }
}

No* Arvore::localiza(int chave, No* no){
  if(no == NULL) 
    return NULL;
  if(chave == no->getChave())
    return no;
  if(chave < no->getChave())
    return localiza(chave, no->getEsq());
  else
    return localiza(chave, no->getDir());
}

void Arvore::remove(int chave){
   removeRaiz(localiza(chave, raiz));
}

//Maior entre os menores
void Arvore::removeRaiz(No *no){
  //1º caso: Nó não existe
  if(no == NULL){
    std::cout << "Este nó não existe na árvore" << std::endl;
  }
  //2º caso: Nó é folha
  else if(no->getDir() == NULL && no->getEsq() == NULL){
    std::cout << "Nó removido com sucesso 1" << std::endl;
    if(no == raiz)
      raiz = NULL;
    else{
      if(no->getPai()->getEsq() == no)
        no->getPai()->setEsq(NULL);
      else
        no->getPai()->setDir(NULL);
    }
    free(no);
  }
  //3º caso: Nó não possui filho da esquerda
  else if(no->getEsq() == NULL){
    std::cout << "Nó removido com sucesso 2" << std::endl;
    if(no == raiz)
      raiz = no->getDir();
    else{
      no->getPai()->setDir(no->getDir());

      if(no->getPai()->getEsq() == no)
        no->getPai()->setEsq(NULL);
      else
        no->getPai()->setDir(NULL);
    }
    free(no);
  }
  //4º caso: Nó possui dois filhos 
  else{
    std::cout << "Nó removido com sucesso 3" << std::endl;
    No *i = no->getEsq();
    while(i->getDir() != NULL)
      i = i->getDir();

    no->getPai()->setEsq(i);
    i->setEsq(no->getEsq());
    if(no->getPai()->getEsq() == no)
      no->getPai()->setEsq(NULL);
    else
      no->getPai()->setDir(NULL);
    free(no);
  }
}

No* Arvore::encontraMenor(No *no){
  if(no->getEsq() == NULL)
    return no;
  else if (no == NULL)
    return NULL;
  else
    return encontraMenor(no->getEsq());
}

int Arvore::getAltura(){
  return altura;
}

int Arvore::calculaAltura(No *no){
  if(no == NULL)
    return 0;
  int cont1 = calculaAltura(no->getEsq());
  int cont2 = calculaAltura(no->getDir());
  if (cont1 >= cont2)
    return cont1 + 1;
  else
    return cont2 + 1;
}