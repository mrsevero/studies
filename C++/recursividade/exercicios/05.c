#include<stdio.h>

int inverte(int n){
    if(n==0)
      return n;
     else
    {
     printf("%d", n % 10);
     n=n / 10;
     return inverte(n);
    }
return 0;
 }
int main(){
   int numero;
   int aux;
   printf("Digite um numero:");
   scanf("%d",&numero);
   inverte(numero);
   return 0;
}