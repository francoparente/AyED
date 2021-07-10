#include <iostream>

using namespace std;

int main()
{
    int a,b,c,r;
    cout << "Ingrese A y B" << endl;
    cin >> a >> b;
    c=a/b;
    cout << endl << "Cociente: " << c << endl;
    r=a%b;
    cout << "Resto: " << r << endl;
    return 0;
}
