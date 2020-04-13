#include <stdio.h>

int resto(int x,int y){
  if(y==x){
    return 0;
  }
  if(x<y){
    return x;
  }
  else{
  return 0+resto(x-y,y);
  }
}
int main(void) {


  printf("resultado=%d\n", resto(11,5));


  return 0;
}