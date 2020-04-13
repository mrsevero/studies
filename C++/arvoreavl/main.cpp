#include <iostream>
#include "AVLTree.h"

int main() {
  AVLTree arv;

  arv.inserir(40);
  arv.inserir(30);
  arv.inserir(20);
  arv.inserir(10);
  arv.inserir(1);
  arv.inserir(5);
  arv.inserir(15);
  std::cout << "Arvore em ordem: " << std::endl;
  arv.inOrder();
  std::cout << "Arvore pre ordem: " << std::endl;
  arv.preOrder();
  std::cout << "Arvore pos ordem: " << std::endl;
  arv.posOrder();
  std::cout << "Raiz: " << arv.getRoot()->getData() << std::endl;
  arv.remover(30);
  std::cout << "Arvore em ordem: " << std::endl;
  arv.inOrder();
  std::cout << "Arvore pre ordem: " << std::endl;
  arv.preOrder();
  std::cout << "Arvore pos ordem: " << std::endl;
  arv.posOrder();
  std::cout << "Raiz: " << arv.getRoot()->getData() << std::endl;
}