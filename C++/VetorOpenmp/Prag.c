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
  
  printf("Vetor Normal 1: ");
  imprimeVetor(vetor1);
  printf("Vetor Normal 2: ");
  imprimeVetor(vetor2);
  printf("Vetor Normal 3: ");
  imprimeVetor(vetor3);
  printf("Vetor Normal 4: ");
  imprimeVetor(vetor4);

  double dif1, dif2, dif3, dif4;
  clock_t start1, end1;
  clock_t start2, end2;
  clock_t start3, end3;
  clock_t start4, end4;

  #pragma omp parallel num_threads(4)
  {
    #pragma omp critical
    {  
      start1 = clock();
      bubbleSort(vetor1);
      end1 = clock();
    }
    #pragma omp critical 
    {
      start2 = clock();
      bubbleSort(vetor2);
      end2 = clock();
    }
    #pragma omp critical 
    {
      start3 = clock();
      bubbleSort(vetor3);
      end3 = clock();
    }
    #pragma omp critical
    {
      start4 = clock();
      bubbleSort(vetor4);
      end4 = clock();
    }
  } 

  printf("\nVetor Ordernado: 1: ");
  imprimeVetor(vetor1);
  printf("Vetor Ordernado 2: ");
  imprimeVetor(vetor2);
  printf("Vetor Ordernado 3: ");
  imprimeVetor(vetor3);
  printf("Vetor Ordernado 4: ");
  imprimeVetor(vetor4);

  dif1 = end1 - start1;
  dif2 = end2 - start2;
  dif3 = end3 - start3;
  dif4 = end4 - start4;

  printf("Tempo Pragma Total: %.8f segundos\n", (dif1 + dif2 + dif3 + dif4)/CLOCKS_PER_SEC);
  return 0;
}