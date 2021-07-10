#include <iostream>

using namespace std;

int main()
{
    int n,i;
    int k,mayor,menor,pmayor,pmenor;

    cout << "Ingrese cantidad de valores:" << endl;
    cin >> n;
    cout << endl;

    for(i=1 ; i<=n ; i++)
    {
        cout << "Ingrese un valor:" << endl;
        cin >> k;
        if(k>mayor || i==1)
        {
            mayor=k;
            pmayor=i;
        }
        if(k<menor || i==1)
        {
            menor=k;
            pmenor=i;
        }
    }

    cout << "El menor valor es " << menor << ", y su posición es la " << pmenor << "." << endl;
    cout << "El mayor valor es " << mayor << ", y su posición es la " << pmayor << "." << endl;


    return 0;
}
