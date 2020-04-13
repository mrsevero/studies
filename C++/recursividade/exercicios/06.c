#include <stdio.h>

int div(int x,int y){
  if(x-y==0){
    return 1;
  }
  if(x-y < 0){
      return 0;
  }
  else{
  return 1+div(x-y,y);
  }
}
int main(void) {
  printf("resultado=%d\n", div(7,2));
  return 0;
}