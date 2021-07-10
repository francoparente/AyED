#include <iostream>

using namespace std;

void modulo(float &x)
{
    if (x<0)
        x=x*(-1);
    else
        x=x;
    return;
}
int main()
{
    float a;
    cout << "Ingrese un numero" << endl;
    cin >> a;
    modulo (a);
    cout << "El modulo del numero es: "<< a;
    return 0;
}
