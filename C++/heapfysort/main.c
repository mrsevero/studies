#include <stdio.h>

void maxHeapfy(int a[],int i,int n){
    int t;
    int maior = i;
    //filho a esquerda
    int l = 2*i+1;
    //filho a direita
    int r = 2*i+2;
    //comparacao entre pai com filho esquerda
    if (l<n && a[l] > a[i])
      maior = l;
    //comparacao entre pai com filho da direita
    if (r<n && a[r] > a[maior])
      maior = r;
      //troca o pai pelo filho
    if (maior != i) {
      t = a[i];
      a[i] = a[maior];
      a[maior] = t;
      // continua a ordenar o maior como pai se houver filho
      maxHeapfy(a,maior,n);
    }
};

void heapSort(int a[], int n){
  //construir a max heap com base do que foi passado
  //pega o maior indice com filho
  int t;
  for(int k=n/2-1;k>=0; k--){
    maxHeapfy(a,k,n);
  }

// colocar maior elemento da vez na ordem (ultimo lugar)
// repetir ate o final
  for (int j=n-1;j>=1;j--){
    t = a[0];
    a[0] = a[j];
    a[j] = t;
    maxHeapfy(a,0,j);
  }

};

int main(void) {

  int v[] = {1,9,4,5,0,10,7};
  int n = 7;
  heapSort(v,n);

	for (int b=0;b<n ;b++){
  printf("%d\n", v[b]);
  }
  return 0;
}