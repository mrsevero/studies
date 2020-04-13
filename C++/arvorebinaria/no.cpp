#include <iostream>
#include "no.h"

No::No(int chave){
  this->chave = chave;
  esq = NULL;
  dir = NULL;
  pai = NULL;
}

int No::getChave(){
  return chave;
}

No* No::getEsq(){
  return esq;
}

No* No::getDir(){
  return dir;
}

No* No::getPai(){
  return pai;
}

void No::setEsq(No *no){
  esq = no;
}

void No::setDir(No *no){
  dir = no;
}

void No::setPai(No *no){
  pai = no;
}