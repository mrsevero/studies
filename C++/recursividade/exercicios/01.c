#include <stdio.h>

int expoente(int n,int y){
  if(y==1){
    return n;
  }
  else{
  return n*expoente(n,y-1);
  }
}
int main(void) {
  printf("resultado=%d\n", expoente(2,3));
  return 0;
}