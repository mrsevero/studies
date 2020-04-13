#include <stdio.h>
/*
Problema da mochila 

- Situacao em que e necessario preencher uma mochila com obejtos de diferentes pesos
- A mochila tem um limite de pesos

exemplo
  mochila = 15kg
  6 objetos   *1 peso 4
              *2 peso 5 
              *3 peso 8
              *4 peso 7
              *5 peso 1
              *6 peso 2

  ex 2 
      valor      peso      valor/peso
  a   60          10          6
  b   100         20          5 
  c   120         30          4

1 passo ordenar pela relacao valor/peso decrescente

inserir o que couber na mochila e incrementar a variavel do valor que voce tem

a 7 17   2,43
b 5 13   2,60
c 6 10   1,67
d 4 8    2
e 10 20  2


*/
int mochila = 17;
int objetos[5] = {5,7,4,10,6};
int valores[5] = {13,17,8,20,10};
int total = 0;
int i = 0;
int qdade = 0;
int valor = 0;


int main(void) {
  while (i < sizeof(objetos)/sizeof(int)){
    if (total < mochila){
        if (total + objetos[i] <= mochila){
          total += objetos[i];
          qdade ++;
          valor += valores[i];
          

        }
  }
  i++;
  }
  printf("O total de objetos levados %d e o peso é %d, valor dos objetos %d",qdade ,total, valor);
}