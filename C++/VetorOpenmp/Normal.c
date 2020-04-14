/* 

Nome: Bruno Severo Camilo         TIA: 41781619

Exercício discutido via chamada online com: Matheus Soares Santos e  João Pedro Colafati Pedroso

*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define TAM 50

void bubbleSort(int *v) {
  for(int i = 0; i < TAM; i++) {
    for(int j = i; j < TAM; j++) {
      if(v[i] > v[j]) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}

void populaVetor(int *v) {
  for(int i = 0; i < TAM; i++) {
    v[i] = rand() % TAM;
  }
}

void imprimeVetor(int *v){
  printf("[ ");
  for(int i = 0; i < TAM; i++){
    printf("%d ", v[i]);
  } 
  printf("]\n");
}

int main(void) {
  
  int vetor1[TAM];
  int vetor2[TAM];
  int vetor3[TAM];
  int vetor4[TAM];
  
  clock_t start, end;
  double dif;

  populaVetor(vetor1);
  populaVetor(vetor2);
  populaVetor(vetor3);
  populaVetor(vetor4);
  
  printf("Vetor 1: ");
  imprimeVetor(vetor1);
  printf("Vetor 2: ");
  imprimeVetor(vetor2);
  printf("Vetor 3: ");
  imprimeVetor(vetor3);
  printf("Vetor 4: ");
  imprimeVetor(vetor4);

  start = clock();

  bubbleSort(vetor1);
  bubbleSort(vetor2);
  bubbleSort(vetor3);
  bubbleSort(vetor4);

  end = clock();
  
  printf("\nVetor 1 Ordenado: ");
  imprimeVetor(vetor1);
  printf("Vetor 2 Ordenado: ");
  imprimeVetor(vetor2);
  printf("Vetor 3 Ordenado: ");
  imprimeVetor(vetor3);
  printf("Vetor 4 Ordenado: ");
  imprimeVetor(vetor4);

  dif = end - start;
  printf ("Tempo: %.8lf segundos.\n", dif/CLOCKS_PER_SEC); 
  return 0;
}