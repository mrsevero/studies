#include <stdio.h>
int cont = 0;

void preenche_vetor(int n, int *vet){
  for(int i = 0; i < n; i++)
    vet[i] = -1;
}

int fibo_dinamica(int n, int *vet){
  cont++;
  if(n == 0){
    vet[0] = 0;
    return 0;
  }
  if(n == 1 || n == 2){
    vet[n] = 1;
    return 1;
  }
  if(vet[n-1] == -1){
    vet[n-1] = fibo_dinamica(n-1, vet);
    vet[n-2] = fibo_dinamica(n-2, vet);
  }
  return vet[n-1] + vet[n-2];
}

int main(void) {
  int opcao;
  printf("Digite o valor para Fibonacci: ");
  scanf("%d", &opcao);

  int vetor[opcao];
  preenche_vetor(opcao, vetor);

  int resultado = fibo_dinamica(opcao, vetor);

  printf("\nFibonacci Dinâmico: %d", resultado);
  printf("\nQuantidade de Acessos Dinâmico: %d", cont);
  cont = 0;
  return 0;
}