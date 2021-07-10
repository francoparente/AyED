#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int k,i,sg2=0;
    char g;
    char m[400];
    float v,sl=0,sm=0,sg=0;

    for(k=1;k<=20;k++)
    {
        cout << "**** INFRACCIÓN NÚMERO " << k << " ****" << endl;

        cout << "Ingrese tipo de infracción:" << endl;
        cin >> i;

        while (i!=1 && i!=2 && i!=3 && i!=4)
        {
            cout << "Valor no permitido, ingrese nuevamente un valor entre 1 y 4:" << endl;
            cin >> i;
        }

        cout << "Ingrese motivo de infracción:" << endl;
        fflush(stdin);
        gets(m);

        cout << "Ingrese valor de la multa:" << endl;
        cin >> v;

        cout << "Ingrese gravedad de la infracción:" << endl;
        cin >> g;

        while (g!='L' && g!='M' && g!='G')
        {
            cout << "Valor no permitido, ingrese nuevamente L, M o G:" << endl;
            cin >> i;
        }

        switch(g)
        {
            case 'L':
                sl=sl+v;
                break;
            case 'M':
                sm=sm+v;
                break;
            case 'G':
                sg=sg+v;
                break;
        }

        if ((i==3||i==4)&& g=='G')
            sg2=sg2+1;

        cout << endl << endl;
    }

    cout << "Valor a pagar por infracciones leves: " << sl;
    cout << "Valor a pagar por infracciones medias: " << sl;
    cout << "Valor a pagar por infracciones graves: " << sl;

    if(sg2>3)
        cout << "Clausurar Fábrica.";

    return 0;
}
