#include "natural.h"

Natural::Natural(int v){
  value = v;
}

Natural::~Natural(){}

unsigned int Natural::getValue(){
    return value;
}

Natural Natural::suc(){
  Natural n(value+1); 
  return n;
}

Natural Natural::soma(Natural n){
  Natural n(value+n.getValue());
  return n;
}

Natural Natural::mult(Natural n){
    Natural n(value*n.getValue());
    return n;
}

