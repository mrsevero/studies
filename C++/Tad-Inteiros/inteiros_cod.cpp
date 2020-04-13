#include <iostream>
#include "header.h"

int Inteiros::soma(int Num1,int Num2) {
  return Num1 + Num2;
}

int Inteiros::sub(int Num1,int Num2){
  return Num1 - Num2;
}

int Inteiros::mult(int Num1,int Num2) {
  return Num1 * Num2;
}

int Inteiros::divi(int Num1,int Num2) {
  return Num1 / Num2;
}

int Inteiros::sucessor(int Num1) {
  return ++Num1;
}

int Inteiros::antecessor(int Num1) {
  return --Num1;
}

