#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

/*1. Escriba un programa que permita a un usuario ingresar n valores float
y se guarden en un archivo, el número n lo informa al comienzo del programa.
Al finalizar el programa debe listar todos los números guardados en el archivo.*/

int main()
{
    setlocale(LC_ALL, "");
    int n,x;

    cout << "Cuántos valores desea ingresar?" << endl;
    cin >> n;

    FILE*f;
    f=fopen("archivo_ej1","wb");

    for(int i=0; i<n; i++)
    {
        cout << "Ingrese el valor " << i+1 << ": "<<endl;
        cin >> x;
        fwrite (&x, sizeof(int), 1, f);
    }
    fclose(f);

    cout << "---------------------------" << endl;
    cout << "Los valores ingresados son:" << endl;

    f=fopen("archivo_ej1","rb");

    fread (&x, sizeof(int), 1, f);
    for(int j=0; j<n; j++)
    {
        cout << "Valor " << j+1 << ": " << x << endl;
        fread (&x, sizeof(int), 1, f);
    }
    fclose(f);

    return 0;
}
