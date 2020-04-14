/* 

Nome: Bruno Severo Camilo         TIA: 41781619

Exercício discutido via chamada online com: Matheus Soares Santos e  João Pedro Colafati Pedroso

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define TAM 10
#define MAX 100
int matriz[TAM][TAM];

void populaMatriz() {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      matriz[i][j] = rand() % MAX;
    }
  }
}
void imprimirmatriz(){
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  populaMatriz();
  
  imprimirmatriz();
  clock_t start1, end1;
  clock_t start2, end2;
  clock_t start3, end3;
  clock_t start4, end4;
  int cont1 = 0;
  int cont2 = 0;
  int cont3 = 0;
  int cont4 = 0;

  #pragma omp parallel sections
  {
    #pragma omp section
    {
      start1 = clock();
      for(int i = 0; i < TAM/2; i++) {
        for(int j = 0; j < TAM/2; j++) {
          if(matriz[i][j] > MAX/2)
            cont1++;
        }
      }
      end1 = clock();
    }
        #pragma omp section
    {
      start2 = clock();
      for(int i = TAM/2; i < TAM; i++) {
        for(int j = 0; j < TAM/2; j++) {
          if(matriz[i][j] > MAX/2)
            cont2++;
        }
      }
      end2 = clock();
    }
        #pragma omp section
    {
      start3 = clock();
      for(int i = 0; i < TAM/2; i++) {
        for(int j = TAM/2; j < TAM; j++) {
          if(matriz[i][j] > MAX/2)
            cont3++;
        }
      }
      end3 = clock();
    }
        #pragma omp section
    {
      start4 = clock();
      for(int i = TAM/2; i < TAM; i++) {
        for(int j = TAM/2; j < TAM; j++) {
          if(matriz[i][j] > MAX/2)
            cont4++;
        }
      }
      end4 = clock();
    }
  } 

  double dif1 = end1 - start1;
  double dif2 = end2 - start2;
  double dif3 = end3 - start3;
  double dif4 = end4 - start4;
  printf("Tempo Pragma: %.8f\n", (dif1+dif2+dif3+dif4)/CLOCKS_PER_SEC);
  printf("Contador Pragma: %d\n", cont1+cont2+cont3+cont4);
  return 0;
}