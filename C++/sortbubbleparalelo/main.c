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

void populaVetor(int *v, int *w) {
  for(int i = 0; i < TAM; i++) {
    v[i] = rand() % TAM;
    w[i] = v[i];
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
  
  int vetorNormal1[TAM];
  int vetorNormal2[TAM];
  int vetorNormal3[TAM];
  int vetorNormal4[TAM];

  int vetorPragma1[TAM];
  int vetorPragma2[TAM];
  int vetorPragma3[TAM];
  int vetorPragma4[TAM];

  clock_t start, end;
  double dif;

  populaVetor(vetorNormal1, vetorPragma1);
  populaVetor(vetorNormal2, vetorPragma2);
  populaVetor(vetorNormal3, vetorPragma3);
  populaVetor(vetorNormal4, vetorPragma4);
  
  printf("Vetor Normal 1: ");
  imprimeVetor(vetorNormal1);
  printf("Vetor Normal 2: ");
  imprimeVetor(vetorNormal2);
  printf("Vetor Normal 3: ");
  imprimeVetor(vetorNormal3);
  printf("Vetor Normal 4: ");
  imprimeVetor(vetorNormal4);

  start = clock();

  bubbleSort(vetorNormal1);
  bubbleSort(vetorNormal2);
  bubbleSort(vetorNormal3);
  bubbleSort(vetorNormal4);

  end = clock();
  
  printf("\nVetor Normal 1: ");
  imprimeVetor(vetorNormal1);
  printf("Vetor Normal 2: ");
  imprimeVetor(vetorNormal2);
  printf("Vetor Normal 3: ");
  imprimeVetor(vetorNormal3);
  printf("Vetor Normal 4: ");
  imprimeVetor(vetorNormal4);

  dif = end - start;
  printf ("Tempo Normal: %.8lf segundos.\n", dif/CLOCKS_PER_SEC);

  double dif1, dif2, dif3, dif4;
  clock_t start1, end1;
  clock_t start2, end2;
  clock_t start3, end3;
  clock_t start4, end4;

  printf("\nVetor Pragma 1: ");
  imprimeVetor(vetorPragma1);
  printf("Vetor Pragma 2: ");
  imprimeVetor(vetorPragma2);
  printf("Vetor Pragma 3: ");
  imprimeVetor(vetorPragma3);
  printf("Vetor Pragma 4: ");
  imprimeVetor(vetorPragma4);

  #pragma omp parallel num_threads(4)
  {
    #pragma omp critical
    {  
      start1 = clock();
      bubbleSort(vetorPragma1);
      end1 = clock();
    }
    #pragma omp critical 
    {
      start2 = clock();
      bubbleSort(vetorPragma2);
      end2 = clock();
    }
    #pragma omp critical 
    {
      start3 = clock();
      bubbleSort(vetorPragma3);
      end3 = clock();
    }
    #pragma omp critical
    {
      start4 = clock();
      bubbleSort(vetorPragma4);
      end4 = clock();
    }
  } 

  printf("\nVetor Pragma 1: ");
  imprimeVetor(vetorPragma1);
  printf("Vetor Pragma 2: ");
  imprimeVetor(vetorPragma2);
  printf("Vetor Pragma 3: ");
  imprimeVetor(vetorPragma3);
  printf("Vetor Pragma 4: ");
  imprimeVetor(vetorPragma4);

  dif1 = end1 - start1;
  dif2 = end2 - start2;
  dif3 = end3 - start3;
  dif4 = end4 - start4;

  printf("Tempo Pragma Total: %.8f segundos\n", (dif1 + dif2 + dif3 + dif4)/CLOCKS_PER_SEC);
  return 0;
}