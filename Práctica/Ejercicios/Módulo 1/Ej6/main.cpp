#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a,b,c,f,F;
    cout << "Ingrese primer fecha:" << endl;
    cout << "Ano: ";
    cin >> x;
    cout << "Mes: ";
    cin >> y;
    cout << "Dia: ";
    cin >> z;

    cout << "Ingrese segunda fecha:" << endl;
    cout << "Ano: ";
    cin >> a;
    cout << "Mes: ";
    cin >> b;
    cout << "Dia: ";
    cin >> c;

    f=x*10000+y*100+z;
    F=a*10000+b*100+c;

    if (f>F)
    {
        cout << "La fecha mas reciente es: " << z << "/" << y << "/" << x;
    }
    else
    {
        cout << "La fecha mas reciente es: " << c << "/" << b << "/" << a;
    }

    return 0;
}
