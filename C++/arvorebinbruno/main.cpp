#include <iostream>
using namespace std;

class No
{
	private:
		No *esq, *dir;
		int chave;
	public:
		No(int chave)
		{
			this->chave = chave;
			esq = NULL;
			dir = NULL;
		}
		int getChave()
		{
			return chave;
		}

		No* getEsq()
		{
			return esq;
		}
		No* getDir()
		{
			return dir;
		}
		void setEsq(No* no)
		{
			esq = no;
		}
		void setDir(No* no)
		{
			dir = no;
		}		
};

class Arvore
{
	private:
		No* raiz;

	public:
		Arvore()
		{
			raiz = NULL;
		}

		void inserir(int chave)
		{
			if(raiz == NULL)
			{
				raiz = new No(chave);
			}
			else
			{
				inserirAux(raiz,chave);
			}
		}
		void inserirAux(No* no, int chave)
		{
			if(chave < no->getChave())
			{
				if(no->getEsq() == NULL)
				{
					No *novo_no = new No(chave);
					no->setEsq(novo_no);
				}
				else
				{
					inserirAux(no->getEsq(), chave);
				}
			}
			else if(chave > no->getChave())
			{
				if(no->getDir() == NULL)
				{
					No* novo_no = new No(chave);
					no->setDir(novo_no);
				}
				else
				{
					inserirAux(no->getDir(),chave);
				}
			}
		}	
		No* getRaiz()
		{
			return raiz;
		}

		void emOrdem(No* no)
		{
			if(no != NULL)
			{
				emOrdem(no->getEsq());
				cout << no->getChave() <<" ";
				emOrdem(no->getDir());			
			}
		}
		void preOrdem(No* no)
		{
			if(no != NULL)
			{
				cout << no->getChave() <<" ";
				emOrdem(no->getEsq());
				emOrdem(no->getDir());	
			}
		}
		void posOrdem(No* no)
		{
			if(no != NULL)
			{
				emOrdem(no->getEsq());
				emOrdem(no->getDir());
				cout << no->getChave() <<" ";
			}

		}
    int media(No* no){
      int ocorrencia;
      int atual = 0;
      if(no == NULL){
        return 0;
      }
      else
        ocorrencia = (ocorrencia + no->getChave()+media(no->getDir()+(media(no->getEsq()))))/2;
      return ocorrencia;
    }
    
};
int main(){

	Arvore arv;

  arv.inserir(10);
  arv.inserir(20);

  cout << arv.media(arv.getRaiz());
};

