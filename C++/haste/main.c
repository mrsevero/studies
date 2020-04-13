#include <stdio.h>
#include <stdlib.h>

//Contador das funções
int cont = 0;

//Preenche o vetor de -1
void preencheVetor(float *v, int tam){
  for(int i = 1; i <= tam; i++){
    v[i] = -1;
  }
}

//Preenche os preços com números aleatórios
void preenchePrecos(float *t, int tam){
  for(int i = 1; i <= tam; i++){
    t[i] = rand() % 10000;
  }
}

//Haste Naive
int haste(int n, float *t){
  cont++;
  if(n == 0)
    return 0;
  int i, max = -1;
  for(i = 1; i <= n; i++){
    int temp = t[i] + haste(n-i, t);
    if(temp > max)
      max = temp;
  }
  return max;
}

//Haste Dinâmico
int hasteDinamico(int n, float *tabela, float *vetor){
  int i, max = -1;
  if(n == 0)
    return 0;
  if(vetor[n] != -1){
    return vetor[n];
  }
  else{
    cont++;
    for(i = 1; i <= n; i++){
      vetor[n-i] = hasteDinamico(n-i, tabela, vetor);
      int temp = tabela[i] + vetor[n-i];
      if(temp > max)
        max = temp;
    }
  }
  return max;
}

int main() {
  int tam = 25;
  float precos[tam+1], vetor[tam+1];
  precos[0] = 0;
  vetor[0] = 0;
  preenchePrecos(precos, tam);
  preencheVetor(vetor, tam);
  
  printf("Preço máximo com haste de tamanho %d: ", tam);
  printf("%d", hasteDinamico(tam, precos, vetor));
  printf("\nContador haste dinâmico: %d", cont);

  cont = 0;

  printf("\n\nPreço máximo com haste de tamanho %d: ", tam);
  printf("%d", haste(tam, precos));
  printf("\nContador haste naive: %d", cont);
}