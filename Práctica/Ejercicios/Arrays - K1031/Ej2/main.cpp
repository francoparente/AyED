#include <iostream>
#include <cmath>

using namespace std;

/*
2. Dado un vector 15 valores, hacer un programa que pueda obtener, y sacar por pantalla:
− el mayor de los valores
− el menor de los valores
− el más próximo al promedio
*/

int mayor (int v[])
{
    int mayor= v[0];
    for(int i=1; i<15; i++)
    {
        if(v[i]>mayor)
            mayor=v[i];
    }
    return mayor;
}

int menor (int v[])
{
    int menor=v[0];
    for(int i=1; i<15; i++)
    {
        if(v[i]<menor)
            menor=v[i];
    }
    return menor;
}

float promedio (int v[])
{
    int sum=0;
    for(int i=0; i<15; i++)
        sum+=v[i];
    return sum/15;
}

int mascercano (int v[])
{
    float prom= promedio(v);
    int mc= v[0];
    float dist= abs(v[0]-prom);
    for(int i=0; i<15; i++)
    {
        if(abs(v[i]-prom)<dist)
        {
            dist= abs(v[i]-prom);
            mc= v[i];
        }

    }
    return mc;
}

int main()
{
    int v[15]={4,8,12,16,20,24,28,30,2,6,10,14,18,22,26};


    cout << "El mayor valor es: " << mayor(v) << endl;
    cout << "El menor valor es: " << menor(v) << endl;
    cout << "El promedio es: " << promedio(v) << endl;
    cout << "El valor mas cercano al promedio es: " << mascercano(v) << endl;

    return 0;
}
