#include <iostream>

using namespace std;

int main()
{

    int x;
    float y,z;

    cout << "Ingrese un numero:";
    cin >> x;
    cout <<endl<< "La quinta parte de su numero: " <<endl<< x/5 <<endl;
    y=x/5;
    cout <<endl<< "Resto: " <<endl<< x-y*5 <<endl;
    z=y/7;
    cout<<endl<< "La septima parte del cociente entre su numero y cinco: " <<endl<<z<<endl;

    return 0;
}
