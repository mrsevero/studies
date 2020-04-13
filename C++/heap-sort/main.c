// heap sort
// criado por johm willians em 1964.



/*  Tem complexidade de O(NlogN) no pior e medio caso. mesmo tendo a mesma complexidade no no caso medio que o quick sort, o heap sort acaba sendo mais lento que algumas boas implementacoes do quicksort . Porem, alem de ser mais rapido que o quicksort, necessita de menos memoria para executar (nao utiliza um vetor auxiliar).

  Utiliza a abrodagem do selectionSort, ou opoe o maior elemento no do array e o segundo
  maior dele,etc.

  Para ordenar utiliza uma heap(arvore binaria) com as seguintes propriedades:
    - O valor de cada no nao e menor que os valores armazenados em cada folha
    - A arvore e perfeitamente balanceada e as folhas do ultimo nivel estao todas em posicoes mais a esquerda

  Elementos no heap(max heap) nao estao perfeitamente ordenador. APenas sabe-se que o maior elemento esta no nó raiz e que, para cada nó, todos os seus desdendentes nao sao maiores que os elementos da raiz.

  A ideia e utilizar a abordagem de heap representando uma arvore como um array


              |30|5|1|9|40|8|2|17|
                      |30|
                      /  \
                   |5|     |1| 
                   / \     / \
                |9|  |40  |8| |2|
                /
              |17|


  Como voce faria para que a regra A fosse atendida para este caso ?

                |40|30|8|9|17|1|2|5|
                      |40|
                      /  \
                   |30|   |8| 
                   / \     / \
                |9|  |17| |1| |2|
                /
              |5|


  Consegue propor um algoritmo ?

  - transforme o vetor numa maxHeap, V[0] tera o maior elemento do vetor.
  - se V[0] for alterado, o heap pode ser restabelecido muito rapidamente a operacao Reapply nao demora mais de log(n) para este servico.
  DESCOBRIR OS FILHOS = INDICE*2+1 PARA FILHOS DA ESQUERDA 
                        INDICE*2+2 PARA FILHOS DA DIREITA

                        
  Algoritmo___

  - Dado o vetor V de N elementos, transformar em um heap(MAX)
  - pegar o primeiro elemento e trocar como o V[max]
  - repetir o primeiro elemento e trocar com V[max]
  - repetir o processo com o um array formado pelos v[0], v[max-1]



*/
#include <stdio.h>

void maxHeapfy(int a[], int i, int n){
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

  int v[] = {3,1,9,4,10,0,5,8};
  int n = 8;
  heapSort(v,n);

  printf("%d\n", v[0]);
  printf("%d\n", v[1]);
  printf("%d\n", v[2]);
  printf("%d\n", v[3]);
  printf("%d\n", v[4]);
  printf("%d\n", v[5]);
  printf("%d\n", v[6]);
  printf("%d\n", v[7]);
  return 0;
}