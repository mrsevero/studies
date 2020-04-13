
#include <iostream>

using namespace std;

int simpleArraySum(int v[] , int tam){
    int soma;
    for (int i=0;tam;i++){
        soma += v[i];
    }
    return soma;
};
/*
 * Complete the simpleArraySum function below.
 */

int main()
{
    int vetor [6]= {1,2,3,4,5,6};
    int *ip;
    ip = &vetor[0];  
    int tam = 6;
    cout << *ip << endl;
    ip = &vetor[1];
    cout << *ip << endl;
    *ip = 25;
    cout << vetor[1] << endl;
}
