#include <iostream>

using namespace std;

int main()
{
    int aaaammdd,a,m,d;
    cout << "Ingrese FECHA" << endl;
    cin >> aaaammdd;
    a=aaaammdd/10000;
    m=(aaaammdd-a*10000)/100;
    d=(aaaammdd-a*10000-m*100);
    cout << a << endl;
    cout << m << endl;
    cout << d << endl;

    return 0;
}
