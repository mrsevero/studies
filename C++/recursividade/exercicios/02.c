#include <stdio.h>
 
int tamanhostr(char *n) {
  if (NULL != *n)
    return 1 + tamanhostr(n + 1);
  else
    return 0;
}
 
int main() {
  printf("%d\n", tamanhostr("bruno"));
  return 0;
};