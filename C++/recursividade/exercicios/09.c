#include <stdio.h>
#include <stdlib.h>


int somaDigitos(int n){
    if(n==0){
        return 0;
    }
    else{
        return n%10 + somaDigitos(n/10);
    }
}

int main(){
  int n = 321;

  printf("%d", somaDigitos(n));
}