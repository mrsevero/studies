# define TAMANHO 5
#include <iostream>
#include <stdlib.h>
using namespace std;
int numeros[TAMANHO];
//==============================================================================
// Metodo para imprimir o vetor.
void imprimir() {
    cout << "\n[ ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << numeros[i] << " ";
    }
    cout << "]";
}
//------------------------------------------------------------------------------
/**
* Metodo para incluir um elemento no vetor. A posicao tem que estar vaga
* (valor do elemento igual a zero). O novo elemento tem que ser maior que
* zero.
*
* @param indice - indice do elemento que sera incluido.
* @param valor - valor do elemento a ser incluido.
* @return
*/
string incluir(int indice, int valor) {
    // verifica se o valor e maior que zero
    if (valor < 0) {
        return "ERRO: o valor tem que ser maior que zero.";
    }
    // verifica se o indice e valido
    if (indice < 0 || indice > TAMANHO - 1) {
        return "ERRO: o indice esta fora dos limites do vetor.";
    }
    // verifica se a posicao ja esta ocupada.
    if (numeros[indice] > 0) {
        return "ERRO: posicao ocupada.";
    }
    // passou por todas as verificacoes: inserir
    numeros[indice] = valor;
    return "Inclusao bem sucedida.";
}
/**
* Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
* elemento (valor).
*
* @param indice - indice do elemento que sera excluido.
* @return - valor do elemento excluido. Se retornar zero e porque a
* posicao estava vazia; se retornar -1 e? porque o indice e invalido.
*/
int excluir(int indice) {
    // verifica se o indice valido
    if (indice < 0 || indice > TAMANHO - 1) {
        return -1;
    }
    int numero = numeros[indice];
    numeros[indice] = 0;
    return numero;
}

int trocar_2_elementos(int indice1, int indice2) {
    int aux = numeros[indice2];
    numeros[indice2] = numeros[indice1];
    numeros[indice1] = aux;
}

int localiza_maior_menor(){
    int aux[TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        aux[i] = numeros[i];
    }
    bool swapped;
    for (int j = 0; j < TAMANHO; j++){
        swapped = false;
        for (int k = 0; k < TAMANHO; k++) {
            if (aux[k] > aux[k+1]){
                int temp = aux[k];
                aux[k] = aux[k+1];
                aux[k + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "O menor numero: " << aux[0] << "\nO maior numero: " << aux[TAMANHO];
}

int ordena_crescente(){
    bool swapped;
    for (int i = 0; i < TAMANHO; i++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (numeros[j] > numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Vetor ordenado em ordem crescente\n";
}

int ordena_decrescente(){
    bool swapped;
    for (int i = 0; i < TAMANHO; i++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (numeros[j] < numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Vetor ordenado em ordem decrescente\n";
}

int ordena_vetor2(){
    int vetor2[TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        vetor2[i] = numeros[i];
    }
    bool swapped;
    for (int k = 0; k < TAMANHO; k++){
        swapped = false;
        for (int j = 0; j < TAMANHO; j++) {
            if (vetor2[j] > vetor2[j+1]){
                int temp = vetor2[j];
                vetor2[j] = vetor2[j+1];
                vetor2[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout << "Novo vetor copiado e ordenado\n";

    cout << "\n[ ";
    for (int l = 0; l < TAMANHO; l++) {
        cout << vetor2[l] << " ";
    }
    cout << "]";
}
//==============================================================================
// MAIN
//==============================================================================
int main() {
    //numeros = new int[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        numeros[i] = 0;
    }
    while(true) {
        system("CLS");
        cout << "\n----------------------------------------------";
        cout << "\n RELEMBRANDO VETORES";
        cout << "\n----------------------------------------------";
        cout << "\n0 - sair.";
        cout << "\n1 - imprimir o vetor.";
        cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0)";
        cout << "\n3 - excluir um elemento.";
        cout << "\n4 - trocar dois elementos de lugar entre si.";
        cout << "\n5 - localizar o maior e o menor elementos do vetor";
        cout << "\n6 - ordenar os elementos do vetor em ordem crescente";
        cout << "\n7 - ordenar os elementos do vetor em ordem decrescente";
        cout << "\n8 - ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retorna o vetor ordenado";
        cout << "\n---------------------";
        cout << "\nQual a sua opcao -> ";

        int opc;
        cin >> opc;
        if (opc == 0) {
            break;
        } else if (opc == 1) {
            imprimir();
            cout << "\n\n";
            system("PAUSE");
        } else if (opc == 2) {
            //= precisa pedir os dados: posicao no vetor (indice) e valor do elemento.
            cout << "Indice do novo elemento: ";
            int idx;
            cin >> idx;
            cout << "Valor do novo elemento: ";
            int val;
            cin >> val;
            cout << incluir(idx, val) << endl;
            system("PAUSE");
        } else if (opc == 3) {
            cout << "Indice do elemento a ser removido: ";
            int idx;
            cin >> idx;
            int val = excluir(idx);
            if (val == 0) {
                cout << "Nao ha elemento na posicao " << idx;
            } else if (val == -1) {
                cout << "ERRO: o indice esta' fora dos limites do vetor.";
            } else {
                cout << "Valor excluido da posicao " << idx << ": " << val;
            }
            cout << "\n\n";
            system("PAUSE");
        } else if (opc == 4) {
            cout << "Indice do primeiro elemento: ";
            int idx;
            cin >> idx;
            cout << "Indice do segundo elemento: ";
            int idy;
            cin >> idy;
            int val = trocar_2_elementos(idx, idy);
            system("PAUSE");
        } else if (opc == 5) {
            int val = localiza_maior_menor();
            system("PAUSE");
        } else if (opc == 6) {
            int val = ordena_crescente();
            system("PAUSE");
        } else if (opc == 7) {
            int val = ordena_decrescente();
            system("PAUSE");
        } else if (opc == 8) {
            int val = ordena_vetor2();
            system("PAUSE");
        }
    }
    //system("PAUSE");
    cout << "\n-------------------------------------------------";
    cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
    return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

