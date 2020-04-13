#include <stdio.h>

int mult(int x,int y){
  if(y==0){
    return 0;
  }
  else{
  return x+mult(x,y-1);
  }
}
int main(void) {
  printf("resultado=%d\n", mult(10,2));
  return 0;
}