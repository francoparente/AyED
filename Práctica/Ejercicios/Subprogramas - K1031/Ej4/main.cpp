#include <iostream>

using namespace std;

void proced(float n1,float n2,float &mayor)
{
    if (n1!=n2){
        if(n1>n2)
            mayor=n1;
        else
            mayor=n2;
        }
    return;
}

int main()
{
    float x,y,z;
    cout << "Ingrese dos numeros: " << endl;
    cin >> x >> y;
    proced(x,y,z);
    cout << "El mayor es: "<< z;

    return 0;
}
