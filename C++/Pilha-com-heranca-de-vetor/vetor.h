#ifndef VETOR_H
#define VETOR_H

template<class T>
class Vetor {
private:
    int tamanho;
    T *vetor;

public:
    Vetor(int tamanho);

    ~Vetor();

    bool inserir(T numero, int indice);

    T remover(int indice);

    T ler(int indice);
};

#endif