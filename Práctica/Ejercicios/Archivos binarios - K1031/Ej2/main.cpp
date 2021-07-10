#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
/* 2. Agregue al código anterior la funcionalidad para poder modificar un número,
solicitando al usuario en qué posición está el número que quiere modificar y
cuál es el nuevo valor. Los cambios deben ser guardados en el archivo.*/

int main()
{
    setlocale(LC_ALL, "");
    int n,x;

    cout << "Cuántos valores desea ingresar?" << endl;
    cin >> n;

    FILE*f;
    f=fopen("archivo_ej2","wb");

    for(int i=0; i<n; i++)
    {
        cout << "Ingrese el valor " << i+1 << ": "<<endl;
        cin >> x;
        fwrite (&x, sizeof(int), 1, f);
    }
    fclose(f);
//---------------------------------------------------------------------------
    cout << "---------------------------" << endl;
    cout << "Los valores ingresados son:" << endl;
    f=fopen("archivo_ej2","rb");

    fread (&x, sizeof(int), 1, f);
    for(int j=0; j<n; j++)
    {
        cout << "Valor " << j+1 << ": " << x << endl;
        fread (&x, sizeof(int), 1, f);
    }
    fclose(f);
//---------------------------------------------------------------------------
    int offset;
    cout << "---------------------------" << endl;

    f=fopen("archivo_ej2","rb+");
    cout<<"Qué número de elemento desea modificar?"<<endl;
    cin>>offset;
    cout<<"Ingrese el nuevo valor:"<<endl;
    cin>>x;

    fseek (f, (offset-1)*sizeof(int), SEEK_SET);
    fwrite(&x, sizeof(int), 1, f);
    fclose(f);
//---------------------------------------------------------------------------
    cout << "---------------------------" << endl;
    cout << "Los nuevos valores son:" << endl;
    f=fopen("archivo_ej2","rb");

    fread (&x, sizeof(int), 1, f);
    for(int k=0; k<n; k++)
    {
        cout << "Valor " << k+1 << ": " << x << endl;
        fread (&x, sizeof(int), 1, f);
    }
    fclose(f);

    return 0;
}
