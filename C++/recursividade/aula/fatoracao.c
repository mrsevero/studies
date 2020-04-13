#include <stdio.h>

int fatoracao(int n){
  if(n==1){
    return 1;
  }
  else{
  return n*fatoracao(n-1);
  }
}
int main(void) {
  printf("resultado=%d\n", fatoracao(3));
  return 0;
}