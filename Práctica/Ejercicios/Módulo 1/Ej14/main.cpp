#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int i,n,p=0,s=0,d=0;
    srand(time(NULL));

    for(i=1 ; i<=50 ; i++)
    {   n = rand() % 300 -100;
        cout << n << endl;
        if(n>100)
        {
            p=p+n;
            d=d+1;
        }
        if(n<-10)
        {
            s=s+n;
        }
    }
    cout << "Promedio de números mayores a 100: " << p/d << endl;
    cout << "Suma de números menores a -10: " << s;

    return 0;
}
