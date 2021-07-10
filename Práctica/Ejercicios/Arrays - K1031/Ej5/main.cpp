#include <iostream>
#include <conio.h>

using namespace std;

/*
5. Hacer un programa que permita realizar la suma y el producto de dos vectores.
El usuario deberá poder elegir el tamaño del vector (entre 2 y 10 valores).
*/

void suma(int v1[],int v2[],int tam)
{
    int sum[tam];
    for(int i=0; i<tam; i++)
    {
        sum[i]=v1[i]+v2[i];
    }
    cout << sum;
    return;
}

void productoescalar(int v1[],int v2[],int tam)
{
    int prod;
    for(int i=0; i<tam; i++)
    {
        prod += v1[i]*v2[i];
    }
    cout << prod;
    return;
}

//Ni las usé las funciones... pero las dejo ahí igual

int main()
{
    int tam;
    cout << "Ingrese tamaño del vector:" << endl;
    cin >> tam;
    int v1[10];
    int v2[10];

    for(int i=0; i<tam; i++)
    {
        cout<< "Ingrese valor de v1[" << i << "]: ";
        cin >> v1[i];
    }
    cout <<"---------------------"<<endl;
    for(int k=0; k<tam; k++)
    {
        cout<< "Ingrese valor de v2[" << k << "]: ";
        cin >> v2[k];
    }

    cout <<"---------------------"<<endl;
    int prod=0;
    for(int j=0; j<tam; j++)
        prod += v1[j]*v2[j];
    cout << "Producto escalar = "<<prod<<endl;

    cout <<"---------------------"<<endl;
    int sum[tam];
    for(int t=0; t<tam; t++)
    {
        sum[t]=v1[t]+v2[t];
        cout<< "suma["<<t<<"] = "<<sum[t]<<endl;
    }
    return 0;
}
