#include <stdio.h>
#include <stdlib.h>


int maiorElemento (int a, int b[]) { 
		if (a == 1){
	      return b[0];
	   } 
	   else {
	      int x = maiorElemento (a-1, b);
	      if (x > b[a-1]){
	         return x;
	      }else{
	         return b[a-1]; 
	      }
	      }
	}

int main(){
    int valores[] = {7, 6, 21, 15, 8, -7, 1};
    int max = 6;

    printf( "O maior numero do vetor é: %i\n\n", maiorElemento(max,valores));
    
    
    return 0;
    
}