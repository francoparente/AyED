#include <iostream>

using namespace std;

int main()
{
    int a,m,d,aaaammdd;
    cout<<"Ingrese A�o"<<endl;
    cin>>a;
    cout<<"Ingrese Mes"<<endl;
    cin>>m;
    cout<<"Ingrese D�a"<<endl;
    cin>>d;
    aaaammdd=d+m*100+a*10000;
    cout<<aaaammdd;
    return 0;
}
