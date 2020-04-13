#include <stdio.h>

void inverse(char *string){
   if(*string){
	  inverse(string+1);
	  putchar(*string);
   }
}

int main(){
   inverse("Bruno Severo");
   return 0;
}