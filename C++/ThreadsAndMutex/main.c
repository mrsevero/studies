#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define TAM 5
#define NUM_THREADS 4

typedef struct param {
  int contador;
  int totalizador;
  int gerador;
} Param;

int** matriz;
int farol;
Param p;

pthread_mutex_t bloqueioValores;
pthread_mutex_t bloqueioFarol;

/*
Preenche matriz em dez posições aleatorias (linha e coluna)
Com um numero aleatorio(de 0 a 10)
*/
void imprimir(int** matrix){
  for (int i =0; i<TAM;i++){
    for (int j =0; j<TAM;j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void preparacao() {
  /* Inicializa matriz com 0 */
  matriz = (int **) calloc (TAM, sizeof(int *));
  int i;
  for(i = 0; i < TAM; i++){
    matriz[i] = (int*) calloc(TAM, sizeof(int));
  }

  /* Imprime matriz inicializada */
  imprimir(matriz);
  
  for(int i = 0; i < 10; i++){
    int c = rand() % TAM;
    int l = rand() % TAM;
    if (matriz[l][c] == 0){
      matriz[l][c] = rand() % 11; 
    }
    else {
      i--;
    }
  }

  /* Imprime matriz com números aleatórios */
  printf("\n");
  imprimir(matriz);

  /* Inicializa farol com 10 */
  farol = 10;
}

void * funcao(void *args){
  while(farol != 0) {
    int l = rand()%TAM;  
    int c = rand()%TAM;   
    if (matriz[l][c] != 0){
      pthread_mutex_lock(&bloqueioValores);
      if (matriz[l][c] != 0){
        (p.contador)++;
        p.totalizador += matriz[l][c];
        matriz[l][c] = 0;
        pthread_mutex_unlock(&bloqueioValores);

        /* Decrementa o farol */ 
        pthread_mutex_lock(&bloqueioFarol);
        farol--;
        pthread_mutex_unlock(&bloqueioFarol);

      } else {
        pthread_mutex_unlock(&bloqueioValores);
      }
    } 
  }

  pthread_exit(args);
}

int main() {
  preparacao();

  p.contador = 0;
  p.totalizador = 0;
  p.gerador = rand() % 30;

  /* Cria e dispara as 4 threads */
  pthread_t thread[NUM_THREADS];
  pthread_mutex_init(&bloqueioValores, NULL);
  pthread_mutex_init(&bloqueioFarol, NULL);
  
  int i;
  for(i = 0; i < NUM_THREADS; i++) {
    int rstatus = pthread_create(&thread[i], NULL, funcao, NULL);

    if(rstatus != 0) {
      printf ("Erro ao criar o thread.\n");
      exit(EXIT_FAILURE);
    }
  }
  
  printf ("\nThreads criadas.\n\n");

  for(i = 0; i < NUM_THREADS; i++) {
    pthread_join(thread[i], NULL);
  }

  imprimir(matriz);

  printf("\nTotalizador: %d", p.totalizador);
  printf("\nGerador: %d", p.gerador);
  printf("\nContador: %d", p.contador);
  printf("\nMédia: %.2f\n", (double)(p.totalizador)/(p.contador));
  return 0;   
}