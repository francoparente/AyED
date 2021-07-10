#include <iostream>

using namespace std;

int main()
{
    int x,y,z;

    cout << "Ingrese la longitud de los lados del triangulo:" << endl;
    cin >> x;
    cin >> y;
    cin >> z;

    if (x==y&&x==z)
    {
        cout << "Equilatero";
    }
    else
    {
        if (x!=y&&y!=z&&x!=z)
        cout << "Escaleno";
        else
        cout << "Isosceles";
    }

    return 0;
}
