#include <iostream>

using namespace std;

int factorial(int a)
{
    int f=1;
    if(a>0)
    {
        for(int i=1;i<=a;i++)
            f=f*i;
    }
    return f;
}

int main()
{
    cout << factorial(3) << endl;
    return 0;
}
