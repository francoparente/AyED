#include <iostream>

using namespace std;

float modulo(float x)
{
    if (x<0)
        return x*(-1);
    else
        return x;
}
int main()
{
    float a;
    cout << "Ingrese un numero" << endl;
    cin >> a;
    cout << "El modulo del numero es: "<< modulo(a);
    return 0;
}
