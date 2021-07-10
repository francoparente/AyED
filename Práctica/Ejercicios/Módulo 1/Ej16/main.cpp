#include <iostream>

using namespace std;

int main()
{
    int n,s=0;

    cout << "****Se contarán los valores positivos hasta que ingrese uno negativo.****" << endl << "Ingrese valores:" << endl;
    cin >> n;

    while (n>0)
    {
        s++;
        cin >> n;
    }

    if(s==0)
        cout << "No se ingresaron valores.";
    else
        cout << "Cantidad de valores ingresados: " << s;




    return 0;
}
