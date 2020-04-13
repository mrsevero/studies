#include <stdio.h>

// Busca de Padroes

int trivial (char palavra[],int m, char texto[],int n){
  int k,r,ocours = 0;
  for (k=m;k<=n;k++){
    //conta quantos caracteres sao iguais na sequencia
    //se for igual ao int M ele considera que encontrou uma palavra
    r = 0;
    while (r<m && palavra[m-r-1] == texto[k-r-1])
      r+=1;
    if (r >= m)
      ocours +=1;
  }
    return ocours;
}

int trivialesquerda (char palavra[],int m, char texto[],int n){
  int k,r,j,ocours = 0;
  for (k=0;k<=n;k++){
    //conta quantos caracteres sao iguais na sequencia
    //se for igual ao int M ele considera que encontrou uma palavra
    r = 0;
    while (r<m && palavra[k] == texto[j])
      r+=1;
    if (r >= m)
      ocours +=1;
    j+=1;
  }
    return ocours;
}

/*
  
    * funciona  por força bruta
    * consome tempo NxM no pior caso
    * simule para palavra = `teste`
        text = `este e um teste teste.``


    * modifique o codigo para que faça a busca da esquerda para a direita

*/


int main(void) {
  char frase [] = {"te amo meu amor"} ;
  int tam = strlen(frase);
  printf("ocorrencias : %d", trivial ("amo", 3, frase , tam ));
  return 0;
}