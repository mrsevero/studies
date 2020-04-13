#include <iostream>
using namespace std;

#define tam 3
#define max 100

int main()
{
    int a[tam][tam], b[tam][tam], mult[tam][tam], i, j, k;

    for(i = 0; i < tam; ++i)
        for(j = 0; j < tam; ++j)
        {
            a[i][j] = rand()%max;
        }

    for(i = 0; i < tam; ++i)
        for(j = 0; j < tam; ++j)
        {
            b[i][j] = rand()%max;
        }

    for(i = 0; i < tam; ++i)
        for(j = 0; j < tam; ++j)
        {
            mult[i][j]=0;
        }

    for(i = 0; i < tam; ++i)
        for(j = 0; j < tam; ++j)
            for(k = 0; k < tam; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < tam; ++i)
    for(j = 0; j < tam; ++j)
    {
        cout << " " << mult[i][j];
        if(j == tam-1)
            cout << endl;
    }

    return 0;
}

