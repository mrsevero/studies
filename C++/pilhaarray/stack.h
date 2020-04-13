#ifndef STACK_H
#define STACK_H

//tamanho fixo
#define size 10

class Stack{

     private:

        //variavel que gerencia os indices
        int cont;

        int array_stack[size];

     public:

        Stack();
        ~Stack();
        bool isEmpty();
        bool full();
        bool pop();
        bool top(itn value);
        bool push(int value);
        bool equal(Stack &S);
        void reverse();
        void inverte_outra_pilha(Stack &S);
        void copia(Stack &);
        void imprime();
};

#endif
