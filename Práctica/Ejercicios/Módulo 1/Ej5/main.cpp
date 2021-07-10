#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "Ingrese dos numeros:" << endl;
    cin >> x;
    cin >> y;
    if (x>y)
    {
        cout << "El numero mayor es: " << x;
    }
    else
    {
        cout << "El numero mayor es: " << y;
    }

    return 0;
}
