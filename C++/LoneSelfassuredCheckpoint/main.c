#include <stdio.h>

int BuscaBinaria3(int x, int n, int v[]){
    return BuscaBinR(x, 0, n, x);
}

int BuscaBinR(int x, int e, int d, int v[]){
    if (e>d){
      return -1;
    }
    if(v[e]==x){
      return e;
    }
    else{
        int m = (e+d)/2;
        if(v[m]<x)
            return BuscaBinR(x, m+1, d, v);
        else
            return BuscaBinR(x, e, m-1, v);
    }
}


int main(void) {
  int x = 9;
  int d = 7;
  int count = 0;
  int e = 0;
  int v[] = {7,8,9,10,11,12,13,14};
  int c = BuscaBinR(x,e,d,v);
  printf("%d", c);
  return 0;
}