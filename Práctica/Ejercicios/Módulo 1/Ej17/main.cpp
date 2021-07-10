#include <iostream>

using namespace std;

int main()
{
    int i=1;
    float sueldo,s1=0,s2=0,s3=0,s4=0;

    while(sueldo!=0)
    {
        cout << "Ingrese sueldo de empleado " << i << endl;
        i++;
        cin >> sueldo;
        if(sueldo < 1520 && sueldo!=0)
            s1++;
        if(sueldo >= 1520 && sueldo < 2780)
            s2++;
        if(sueldo >= 2780 && sueldo < 5999)
            s3++;
        if(sueldo >= 5999)
            s4++;
    }

    cout<<"Empleados que ganan menos de $1520: "<<s1<<endl;
    cout<<"Empleados que ganan entre $1520 y $2779: "<<s2<<endl;
    cout<<"Empleados que ganan entre $2780 y $5999: "<<s3<<endl;
    cout<<"Empleados que ganan más de $5999: "<<s4<<endl;

    return 0;
}
