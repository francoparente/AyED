#include <iostream>

using namespace std;

int main()
{
    /* Dado un valor M determinar y emitir un listado
    con los M primeros múltiplos de 3 que no lo sean
    de 5, dentro del conjunto de los números naturales. */

    int m,n=0,t=1;

    cout << "Ingrese un valor:" << endl;
    cin >> m;
    cout <<endl;

    while (n<m)
    {
        if(t%3==0 && t%5!=0)
        {
            cout << t << endl;
            n++;
        }
        t++;
    }

    return 0;
}
