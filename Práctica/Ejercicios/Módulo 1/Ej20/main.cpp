#include <iostream>

using namespace std;

int main()
{
    int i,n,m;
    cout << "Ingrese 10 valores:"<<endl;
    for(i=0;i<10;i++)
    {
        cin >> n;
        if(n>m || i==0)
            m=n;
    }
    cout << "El mayor numero ingresado es: " << m;

    return 0;
}
