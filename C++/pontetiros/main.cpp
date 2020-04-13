#include <iostream>

/*
Ponteiros C++

Para  acessar uma variavel em outro escopo, que nao o que foi criado, é necessário um ponteiro.

Dentro do espaço de memoria do processo a limites p/  alocação dinamica. se ouver necessidade de mais memoria é preciso utilizar a instrução malloc.

int *v = (int *)malloc(tam*sizeof(int));
v[i] ou *(v+i)

Criar matriz dinamicamente 

int **matriz(int linhas, int colunas){
  int **m = (int **)malloc(linhas*sizeof(int*));
  for (int  i =0;i< linhas; i++){
    m[i] = (int*)malloc(colunas*sizeof(int));
  }
}

*/

void metodo2(int *z){
  *z = *z + 1;
  
}

void metodo1(){
  int x = 10;
  std::cout << x << std::endl;
  int *px;
  px = &x;
  metodo2(pxç);
  std::cout << x;
}


int main() {
  metodo1();
}