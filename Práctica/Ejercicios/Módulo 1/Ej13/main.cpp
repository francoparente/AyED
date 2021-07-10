#include <iostream>

using namespace std;

int main()
{
    int n,m,producto=0,i;

    cout << "Ingrese dos enteros a multiplicar:" << endl;
    cin >>n>>m;

    for (i=1;i<=m;i++)
    {
        producto=producto+n;
    }
        cout <<n<<" * "<<m<<" = "<<producto<< endl;

    return 0;
}
