#include <iostream>
#include <conio.h>

using namespace std;

/*
3. Se leen las letras de una palabra carácter a carácter.
El último carácter que ingresa es la barra de dividir(/), que indica que la palabra ha finalizado.
Escribir un programa que imprima la palabra en el orden que se ingresó y en sentido
inverso (por ejemplo: pera arep, la palabra podrá tener hasta 20 caracteres).
*/

int main()
{
    char c;
    char palabra[21];
    int i=0;

    cout<<"Ingrese una palabra de 20 caracteres como maximo, escriba '/' para finalizar la palabra"<<endl;

    while(c!='/')
    {
        palabra[i]=c;
        c=getche();
        i++;
    }

    cout <<endl<<endl<< "Palabra: ";
    for(int k=0; k<i; k++)
        cout << palabra[k];

    cout <<endl<<endl<< "Palabra al reves: ";
    for(int k=i-1; k>=0; k--)
        cout << palabra[k];

    cout<<endl;
    return 0;
}
