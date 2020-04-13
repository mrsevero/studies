#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"


class AVLTree{
  public:
    AVLTree();
    virtual ~AVLTree();
    AVLNode* getRoot();
    bool isEmpty();
    int height();
    int qtNodes();
    void inserir (int valor);
    void remover(int valor);
    void preOrder();
    void posOrder();
    void inOrder();
    void reverseOrder();
  
  protected:

  private:
    AVLNode *root;
    int height(AVLNode*);
    int qtNodes(AVLNode*);
    AVLNode* inserir(AVLNode*, int);
    AVLNode* localiza(int valor, AVLNode *no);
    bool localizaPai(AVLNode *pai, AVLNode *filho, bool left);
    AVLNode* localizaPai2(AVLNode *pai, AVLNode *filho, bool left);
    bool rotaciona(int valor, AVLNode *no, bool left);
    void removeNo(int valor, AVLNode *no);
    void preOrder(AVLNode *no);
    void posOrder(AVLNode *no);
    void inOrder(AVLNode *no);
    AVLNode* rotateLL(AVLNode*);
    AVLNode* rotateRR(AVLNode*);
    AVLNode* rotateLR(AVLNode*);
    AVLNode* rotateRL(AVLNode*);
    void reverseOrder(AVLNode*);
    int maximo(int, int);
};

#endif // AVLTREE_H