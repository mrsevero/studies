#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Carro{
  private:
    string marca;
    int ano;
  public:
    void setMarca(string x){
      marca = x;
    }
    string getMarca(){
      return marca;
    }
    void setAno(int y){
      if (y>1990)
        ano = y;
      else 
        ano = 1990;
    }
    int getAno(){
	    	return ano;
  	}
}


int main(int argc, char *argv) {
  Carro c1;
  c1.setMarca("ferrari");
  c1;setAno(1222);


  cout << c1.getMarca();
  cout << c1.getAno();
}