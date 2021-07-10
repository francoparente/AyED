#include <iostream>

using namespace std;

/*
6.
Realice un subprograma que muestre el contenido de un vector en forma ordenada descendentemente.
El tamaño del array es informado por parámetro.
*/

void ordenar (int v[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << "v["<<i<<"] = "<< v[tam-1-i]<<endl;
    }
    return;
}

int main()
{
    int t;
    cout << "Ingrese tamaño del vector:" << endl;
    cin>>t;
    int v[t];

    for(int i=0; i<t; i++)
    {
        cout<< "Ingrese valor de v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "-----------------" << endl;
    cout << "Vector invertido:" << endl;
    ordenar(v,t);
    return 0;
}
