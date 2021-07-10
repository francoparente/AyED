#include <iostream>
#include <math.h>

using namespace std;

float raices(float a,float b,float c, float &x1, float &x2)
{
    if((b*b-4*a*c)>0)
    {
        x1=(-b+sqrt(b*b-4*a*c))/2*a;
        x2=(-b-sqrt(b*b-4*a*c))/2*a;
        return true;
    }
    return false;
}
int main()
{
    float x,y,z,r1,r2;

    cout << "Ingrese los coeficientes de su polinomio de grado 2:" << endl;
    cin >> x>>y>>z;
    if(raices(x,y,z,r1,r2))
        cout << "Las raices de su polinomio son: " << endl << "x1 = " << r1 << endl << "x2 = " << r2;
    else
        cout << "Las raices no son reales.";

    return 0;
}
