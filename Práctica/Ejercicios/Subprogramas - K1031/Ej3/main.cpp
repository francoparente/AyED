#include <iostream>

using namespace std;

long factorial(short n)
{
    long result=1;
    int i;
    if (n>0)
    {
        for(i=1;i<=n;i++)
            result=result*i;
    }
    return result;
}

int main()
{
    int x;
    cout << "Ingrese un numero: " << endl;
    cin >> x;
    cout << x<<"! = "<< factorial(x);
    return 0;
}
