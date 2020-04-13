#include <stdio.h>

/* 

Algoritmos Gulosos 

- Resolve problemas de otimizacao (minimizacao,max)
- Sempre escolhe uma alternativa que parece mais proxima daquele instante, ou seja, NUNCA reconsidera essa decisao
- Nao ha backtracking
- A escolha é feita de acordo com um critério guloso - decisao localmente otimizacao
- Nem sempre dao solucoes otimas
- Algoritmos simples e rapidos
- Para construir a solucao otima existe um conjunto ou lista de candidatos

A ideia basica da estratégia gulosa é construir por etapas uma solucao otima

- em cada passo, apos selecionar um elemento da entrada ( o melhor), decide-se se ele é viavel (caso em que vira a fazer parte da decisao) ou nao .
- apos uma sequencia de decisoes uma solucao para o problema é alcancada.
- nessa sequencia de decisoes, nenhum elemtno e examinado mais de uma vez ou ele fara parte da solucao , ou sera descartado

1> exemplo : problema do troco minimimo
  Imagine que temos moedas de 1,5,10,25,50,100(1 real), como devolver o minimo de moedas para o cliente ?

  EX1: dar troco de 75



  EX2: dar troco de 123



Exercicio: Pense em um algoritmo para resolver o problema do troco.

**** versao professora

int main (){
  int moedas[6] = {100,50,25,10,5,1};
  int troco;
  int numeromoedas,total = 0;
  printf("digite o troco");
  Scanf("%d"troco);
  while(troco>0){
    numeromoedas = troco/moedas[i];
    total += numeromoedas;
    troco-= moedas[i] *numeromoedas;
    i++
  }
  printf("foram necessarias %d moedas, total);
}
 */

int troco(int n){
int troco = 0;
int posicao = 0;
int centavos [6] = {100,50,25,10,5,1};
while(posicao < 6){
  while(n >= centavos[posicao]){
      n = n - centavos[posicao];
      troco++;
  }
  posicao++;
}
  return troco;
}





int main(void) {
  printf("sera preciso %d moedas", troco(100));

  return 0;
}