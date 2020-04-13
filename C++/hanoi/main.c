#include <stdio.h>
#include <string.h>
int cont;
int movetorre (int N,char orig, char dest, char aux){

     if(N==1)
             cont=cont+1;
     else{
           movetorre(N-1,orig,aux,dest);
           printf ("%c \n", orig);
           printf ("%c \n", dest);
           printf ("%c \n", aux);
           cont=cont+1;
           movetorre(N-1,orig,aux,dest);
         }  
  return 0;       
}

int main(void) {
  char orig;
  char dest;
  char aux;
  movetorre (2, orig, dest, aux);

}