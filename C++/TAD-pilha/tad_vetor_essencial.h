//==============================================================================
//= by prof. Marcio Feitosa (12/03/2019)
//= marcio.feitosa@mackenzie.br
//==============================================================================
#ifndef TAD_VETOR_ESSENCIAL_H
#define TAD_VETOR_ESSENCIAL_H

/*
Esta classe Vetor Essencial especifica um veror de N posicoes com funcionalidades
basicas que podem ser estendidas por classes herdeiras.
O vetor so' aceita tipos numericos (int, long, float e double) maiores que zero.
Uma posicao com valor zero significa que esta' vaga.
*/

template<class T> class TadVetorEssencial {

		protected:
		int tamanho;
		T * vetor; //= deve ser protected para poder ser manipulado pelas herdeiras.

		public:
		TadVetorEssencial();
		TadVetorEssencial(int TAMANHO);
		~TadVetorEssencial();
		bool inserir(int indice, const T num);
		void imprimir();
	};

#endif

