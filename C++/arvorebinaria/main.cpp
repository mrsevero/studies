#include <iostream>
#include "arvore.h"

int main(){
  Arvore arv;

	std::cout << "\n-------------------------------------------------------------";
	std::cout << "\n                ARVORE BINARIA DE BUSCA";
	std::cout << "\n-------------------------------------------------------------";
	int opc, valor;
	No *loc;

  while (true) {
    std::cout << "\n0 - sair";
	  std::cout << "\n1 - incluir um nó";
	  std::cout << "\n2 - localizar um nó'";
	  std::cout << "\n3 - excluir um nó";
	  std::cout << "\n4 - imprimir a Árvore em Pré Ordem";
	  std::cout << "\n5 - imprimir a Árvore Em Ordem";
	  std::cout << "\n6 - imprimir a Árvore em Pós Ordem";
    std::cout << "\n7 - imprimir a altura da Árvore";
    std::cout << "\n8 - imprimir o menor elemento da Árvore";
	  std::cout << "\n\nSua opcao -> ";
	  std::cin >> opc;
	    
	  if (opc == 0) {
	    break;
	        
	  } else if (opc == 1) {
      std::cout << "Informe o valor do nó a ser incluido: ";
      std::cin >> valor;
      arv.inserir(valor);
      std::cout << "Elemento inserido com sucesso" << std::endl;
            
    } else if (opc == 2) {
      std::cout << "Informe o valor do nó a ser localizado: ";
      std::cin >> valor;
      loc = arv.localiza(valor, arv.getRaiz());
      if (loc == NULL)
        std::cout << "Este nó não existe na árvore" << std::endl;
      else
        std::cout << "Nó encontrado: " << loc->getChave() << std::endl;
                
    } else if (opc == 3) {
      std::cout << "Informe o valor do nó a ser removido: ";
      std::cin >> valor;
      arv.remove(valor);    

    } else if (opc == 4) {
      std::cout << "Pré-Ordem: ";
      arv.preOrdem(arv.getRaiz());
      std::cout << std::endl;

    } else if (opc == 5) {
      std::cout << "Em-Ordem: ";
      arv.emOrdem(arv.getRaiz());
      std::cout << std::endl;

    } else if (opc == 6) {
      std::cout << "Pós-Ordem: ";
      arv.posOrdem(arv.getRaiz());
      std::cout << std::endl;
    
    } else if (opc == 7) {
      std::cout << "Altura da Árvore: " << arv.calculaAltura(arv.getRaiz()) << std::endl;
    
    } else if (opc == 8){
      std::cout << "Menor elemento da Árvore: " << arv.encontraMenor(arv.getRaiz())->getChave() << std::endl;
    }
  } 
  return 0;
}