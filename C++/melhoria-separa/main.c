#include <stdio.h>

int separa(int v[],int p,int r){
  int c = v[(r-p)/2];
  int t,j = p;
  for(int k=p;k<r;k++){
    if(v[k]<=c){
      t=v[j],v[j] = v[k],v[k] = t;
      j++;
    };
  };
    t=v[j],v[j]=v[r],v[r]=t;
    return j;
};


void quickSort(int v[],int p,int r){
  if (p<r){
    int j = separa(v,p,r);
    quickSort(v,p,j-1);
    quickSort(v,j+1,r);
  }
}
int main() {
	int v[8] = {11,22,44,55,66,77,88,99};
  printf("%d\n:", separa(v,0,7) );
  printf("%d", v[0]);
  printf("%d", v[1]);
  printf("%d", v[2]);
  printf("%d", v[3]);
  printf("%d", v[4]);
  printf("%d", v[5]);
  printf("%d", v[6]);
  printf("%d", v[7]);  
		return 0;
};