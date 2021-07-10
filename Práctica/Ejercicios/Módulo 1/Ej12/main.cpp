#include <iostream>

using namespace std;

int main()
{
    int i,suma;
    suma=0;
    for(i=1;i<=100;i++)
        cout << i << endl;

    for(i=1;i<=100;i++)
        cout << (suma=suma+i) << endl;

    return 0;
}
