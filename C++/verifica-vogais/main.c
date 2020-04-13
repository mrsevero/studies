#include <stdio.h>

int separa(char v[],int p,int r){
  int t,j = p;
  for(int k=p;k<r;k++){
    if(v[k] == 'a' || v[k] ==  'e' || v[k] ==  'i' || v[k] ==  'o' || v[k] ==  'u') {
      t=v[j],v[j] = v[k],v[k] = t;
      j++;
    };
  };
     t=v[j],v[j]=v[r],v[r]=t;
}

int main() {
	char v[7] = {'a','t','e','g','w','i','p'};
  printf("%c", separa(v,0,7) ) ;
  printf("%c", v[0]);
  printf("%c", v[1]);
  printf("%c", v[2]);
  printf("%c", v[3]);
  printf("%c", v[4]);
  printf("%c", v[5]);
  printf("%c", v[6]);
    return 0;
};
