#include "AVLTree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

AVLTree::AVLTree(){
  //ctor
  root = NULL;
}

AVLTree::~AVLTree(){
  //destrutor
  //TODO - Implementar destrutor
}

bool AVLTree::isEmpty(){
  return root==NULL;
}

int AVLTree::height(){
  //altura da árvore é a altura do seu nó raiz
  return height(root); 
}

int AVLTree::height(AVLNode *no){
  /*Se o nó for NULL retorna 0, senão retorna o que vier do método getHeight()*/
	return no==NULL? 0:no->getHeight();
}

int AVLTree::maximo(int lhs, int rhs){
  return lhs>rhs? lhs: rhs;
}

int AVLTree::qtNodes(){
  return qtNodes(root);
}

int AVLTree::qtNodes(AVLNode* no){
  if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

AVLNode* AVLTree::getRoot(){
  return root;
}

/*Inserir é polimorfico. o Método publico é pra inserir na árvore. Esse método invoca o método privado, que é recursivo*/
void AVLTree::inserir (int valor){
  root = inserir(root,valor);
}

AVLNode* AVLTree::inserir(AVLNode* node, int valor){
  /*Se é uma arvore ou subarvore vazia, cria 1 novo nó e retorna*/
  if (node == NULL)
    return new AVLNode(valor);
  if (valor < node->getData()){
    node->setLeft(inserir(node->getLeft(), valor));
    if(height(node->getRight()) - height(node->getLeft()) == -2){
      if(valor < node->getLeft()->getData())
        node = rotateLL(node);
      else
        node = rotateLR(node);
    }
  }
  else{
    if (valor > node->getData()){
      node->setRight(inserir(node->getRight(), valor));
      if(height(node->getRight()) - height(node->getLeft()) == 2){
        if(valor > node->getRight()->getData())
          node = rotateRR(node);
        else
          node = rotateRL(node);
      }
    }
  }
  node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
  
  return node;
}

AVLNode* AVLTree::rotateLL(AVLNode *node){
  AVLNode *leftSubTree = node->getLeft();
  node->setLeft(leftSubTree->getRight());
  leftSubTree->setRight(node);
  node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
  leftSubTree->setHeight(maximo(height(leftSubTree->getLeft()), height(node) + 1));
  return leftSubTree;
}

AVLNode* AVLTree::rotateRR(AVLNode *node){
  AVLNode *rightSubTree = node->getRight();
  node->setRight(rightSubTree->getLeft());
  rightSubTree->setLeft( node );
  node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
  rightSubTree->setHeight(maximo(height(rightSubTree->getRight()), height(node) + 1));
  return rightSubTree;
}


AVLNode* AVLTree::rotateLR(AVLNode *node){
  node->setLeft(rotateRR(node->getLeft()));
  return rotateLL(node);
}

AVLNode* AVLTree::rotateRL(AVLNode *node){
  node->setRight(rotateLL(node->getRight()));
  return rotateRR(node);
}

AVLNode* AVLTree::localiza(int valor, AVLNode* no){
	if(no == NULL)
		return NULL;
	else if(valor == no->getData())
    return no;
  else if(valor < no->getData())
    return localiza(valor, no->getLeft());
  else
    return localiza(valor, no->getRight());
}

bool AVLTree::localizaPai(AVLNode* pai, AVLNode* filho, bool left){
	if(pai->getLeft() == filho || pai->getRight() == filho)
		return left;    
  else{ 
    if(filho->getData() < pai->getData())
      return localizaPai(pai->getLeft(), filho, true);
    else 
      return localizaPai(pai->getRight(), filho, false);
  }
}

AVLNode* AVLTree::localizaPai2(AVLNode* pai, AVLNode* filho, bool left){
	if(pai->getLeft()->getData() == filho->getData() || pai->getRight()->getData() == filho->getData())
		return pai;    
  else{ 
    if(filho->getData() < pai->getData())
      return localizaPai2(pai->getLeft(), filho, true);
    else 
      return localizaPai2(pai->getRight(), filho, false);
  }
}

bool AVLTree::rotaciona(int valor, AVLNode *no, bool left){
	if(abs(height(no->getRight()) - height(no->getLeft())) == 2){
    return true;
  }
  return false;
}

void AVLTree::remover(int valor){
	removeNo(valor, localiza(valor, root));
}

void AVLTree::removeNo(int valor, AVLNode *no){
	if(no == NULL){
		std::cout << "Este nó não existe na árvore" << std::endl;
	}
	//Nó é folha
	else if(no->getLeft() == NULL && no->getRight() == NULL){
    std::cout << "Entrou 1" << std::endl;
    AVLNode *pai = localizaPai2(root, no, false);
    if(pai->getLeft()->getData() == no->getData())
      pai->setLeft(NULL);
    else
      pai->setRight(NULL);    
    delete no;
    bool left = rotaciona(valor, pai, false);
    std::cout << "Left: " << left << std::endl;
    if(left){
      if(valor < no->getLeft()->getData())
        no = rotateLL(no);
      else if(valor > no->getLeft()->getData())
        no = rotateLR(no);
      else if(valor > no->getRight()->getData())
        no = rotateRR(no);
      else
        no = rotateRL(no);
	  }
  }
	//Nó não tem filho da esquerda
	else if(no->getLeft() == NULL){
    std::cout << "Entrou 2" << std::endl;
		AVLNode *pai = localizaPai2(root, no, false);
    if(pai->getLeft()->getData() == no->getData())
      pai->setLeft(no->getRight());
    else
      pai->setRight(no->getRight());
    delete no;
    bool left = rotaciona(valor, pai, false);
    std::cout << "Left: " << left << std::endl;
    if(left){
      if(valor < no->getLeft()->getData())
        no = rotateLL(no);
      else if(valor > no->getLeft()->getData())
        no = rotateLR(no);
      else if(valor > no->getRight()->getData())
        no = rotateRR(no);
      else
        no = rotateRL(no);
	  }
	}
	//Nó não tem filho da direita
	else if(no->getRight() == NULL){
    std::cout << "Entrou 3" << std::endl;
    AVLNode *pai = localizaPai2(root, no, false);
    if(pai->getLeft()->getData() == no->getData())
      pai->setLeft(no->getLeft());
    else
      pai->setRight(no->getLeft());
    delete no;
    bool left = rotaciona(valor, pai, false);
    std::cout << "Left: " << left << std::endl;
    if(left){
      if(valor < no->getLeft()->getData())
        no = rotateLL(no);
      else if(valor > no->getLeft()->getData())
        no = rotateLR(no);
      else if(valor > no->getRight()->getData())
        no = rotateRR(no);
      else
        no = rotateRL(no);
	  }
	}
	//Nó tem dois filhos
	else{
    std::cout << "Entrou 4" << std::endl;
		AVLNode *i = no->getLeft();
		AVLNode *j = no;
		while(i->getRight() != NULL){
			j = i;
			i = i->getRight();
		}
		j->setRight(i->getLeft());
		i->setLeft(no->getLeft());
		i->setRight(no->getRight());
    AVLNode *pai = localizaPai2(root, no, false);
    std::cout << "Pai: " << pai->getData() << std::endl;
		if(pai->getLeft()->getData() == no->getData())
      pai->setLeft(i);
    else
      pai->setRight(i);
    delete no;
    bool left = rotaciona(valor, pai, false);
    std::cout << "Left: " << left << std::endl;
    if(left){
      if(valor < no->getLeft()->getData())
        no = rotateLL(no);
      else if(valor > no->getLeft()->getData())
        no = rotateLR(no);
      else if(valor > no->getRight()->getData())
        no = rotateRR(no);
      else
        no = rotateRL(no);
	  }
  }
}

void AVLTree::preOrder(){
  preOrder(root);
}

void AVLTree::inOrder(){
  inOrder(root);
}

void AVLTree::posOrder(){
  posOrder(root);
}
void AVLTree::reverseOrder(){
  reverseOrder(root);
}
void AVLTree::preOrder(AVLNode *no){
  if (no!=NULL){
    cout<<no->getData()<<endl;
    preOrder(no->getLeft());
    preOrder(no->getRight());
  }
}

void AVLTree::posOrder(AVLNode *no){
  if (no!=NULL){
    posOrder(no->getLeft());
    posOrder(no->getRight());
    cout<<no->getData()<<endl;
  }
}

void AVLTree::inOrder(AVLNode *no){
  if (no!=NULL){
    inOrder(no->getLeft());
    cout<<no->getData()<<endl;
    inOrder(no->getRight());
  }
}

void AVLTree::reverseOrder(AVLNode *no){
  if (no!=NULL){
  reverseOrder(no->getRight());
  cout<<no->getData()<<endl;
  reverseOrder(no->getLeft());
  }
}