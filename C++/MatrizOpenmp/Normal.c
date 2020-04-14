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

  start1 = clock();

  int cont1 = 0, cont2 = 0;
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      if(matriz[i][j] > MAX/2)
        cont1++;
    }
  }

  end1 = clock();

  double dif1 = end1 - start1;

  printf("Tempo Normal: %.8f\n", dif1/CLOCKS_PER_SEC);
  printf("Contador Normal: %d\n", cont1);
  return 0;
}