#include "natural.h"
#include <iostream>

int main(){

  Natural a(7);
  int b;

  b = a.suc().getValue(); 

  std::cout << b;

  return 0;
}