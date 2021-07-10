#include <iostream>
#include <conio.h>

using namespace std;

/*
4. Diseñar un algoritmo recursivo, que permita invertir el contenido de un vector. Como indica el ejemplo:
Vector original: 28 35 12 43 56 77
Vector invertido: 77 56 43 12 35 28
El algoritmo no podrá usar un vector auxiliar.
*/


void invert(int v[],int tam)
{
    if(tam==0)
        return;
    cout<<"Invertido: " << v[tam-1] <<endl;
    return invert(v, tam-1);
}

int main()
{
    int v[]= {1,2,3,4,5,6,7,8,9,10,11};

    for (int i =0; i < 11; i++)
            cout << "v[" << i << "]= " << v[i] << endl;
    cout << "-------------------------"<<endl;
    invert(v,11);

    getch();
    return 0;
}
