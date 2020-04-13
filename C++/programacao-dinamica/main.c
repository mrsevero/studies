#include <stdio.h>
/*

Programação dinamica 

* Na divisão e conquista: O problema é partido em sub problemas que se resolvem separadamente; solucao obtida por combinações de soluções

* Na Programação dinamica: Resolvem-se os problemas de pequena dimensão e guardam-se as soluções de um problema combinando as de menor dimensão

- divisão e conquista é top-down
- programação dinamica é bottom-up

programação dinamica é usual em pesquisa operacional  - "programacao" é aqui usada com o sentido de formular restrições ao problema que tornam um metodo aplicavel 

- Varios algoritmos eficientes utilizam esse paradigma 
- estrututra recursiva
- normalmente um algoritmo recursivo é ineficiente.
- necessario então memorizar os resultados de substancias para evitar recalculo
- reutilizacao das solicoes(eficiencia): podemos sair de um problema exponencial p/ polinomial

Primeiro exemplo: Fibonacii


                    f7
                   /  \
                f6      f5
              /  \      /  \ 
            f5   f4    f4   f3
           /  \      /  \  /  \
         f4  f3     f3  f2 f2  f1
       /  \  / \    / \
      f3  f2 f2 f1 f2 f1
     /  \
   f2    f1

int fibo1(int n){
  if (n<=2){
    return 1;
  }
  else {
    return fibo1(n-1)+ fibo2(n-2);
  }
}


versao iterativa

int fibo2(int n){
  int last=1,nexttolast=1,answer=1;

  if (n<=2)
    return 1;
  for (int =3;i<=n;i++)
{
  answer = last+nexttolast;
  nexttolast = last;
  last = answer;
}
  return answer;
}

Versao iterativa com memorização

usa um vetor para guardar a serie 

  int fibo3(int n){

    int a[100];

    int i;
    a[0] = 1;
    a[1] = 1;
    for (i=2;i<n;i++){
        a[i]= a[i-1]+a[i+2]

    }
    return a[i-1];
  }




Como usar memorização com recursao ?


int fibo4(int n, int memo[]){
  int f;
  if(n<=2){
    memo[n-1]=1;
    return 1;
  }
  else if(memo[n-1]>0)
    return memo[n-1];
  else {
    f=fibo4(n-1,memo)+fibo4(n-2,memo);
    memo[n-1]=f;
    return f;
      }
}

exemplo 2 mochila

Objetivo: maximizar o valor de forma que nao ultrapsse a capacidade da mochila
f(i,p):  valor otimoconsiderando os i primeiros itens e uma mochila com capacidade de P;


  Se Xi esta na solução otima:
        (i-1) considera agora somente os i-1 primeiros itens

        (p-pi) desconta o peso (pi) do obejto i; p é a cap da mochila.

        Se o objetov i esta na solução otima ele leva o valor dele, por isso o "+V"

  Se Xi não esta na solucao otima.
      F(i-1,p)

      (i-1) considera agora somente os i-1 primeiros itens

      Pi nao desconta o peso dele, pois nao esta na solução ótima.
    resolva fazendo o maximo destes 2 casos


Recorrência:

    

exemplo

p= 7 x1  x2  x3  x4
Vi   10  7   25  24
pi   2   1   6   57

xi\P   0  1  2  3  4  5  6  7
0      0  0  0  0  0  0  0  0          
1      0  0  10 10 10 10 10 10 
2      0  7  10 17 17 17 17 17 
3      0  7  10 17 17 17 25 32
4      0  7  10 17 17 24 31 


f(0,p)=f(i,0) = 0

f(1,1) 1 item e peso mochila 1
      p1>p ? 2>1 sim -> n cabe  f(1,1) = f(0,1) = 0

f(1,2)
      p1>p ? 2>2 nao
      = max {f(0,0)+10, f(0,2)} = 10
f(1,3)
      mesma coisa = 10

f(2,1) = max {f(1,0) + 7, f(1,2)} = 7

f(2,2) = max {f(1,1) + 7 }, f(1,2) = 10 = 10

f(2,3) = max {f(1,2)+ 7}, f(1,3) = 17
                10 + 7

.
.
.

f(4,7) = max {(f3,2) + 24, f(3,7)} = 34





*/

int main(void) {
  printf("Hello World\n");
  return 0;
}