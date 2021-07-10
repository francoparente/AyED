#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a;
    cout << "Ingrese tres valores:" << endl;
    cout << "Primer angulo:";
    cin >> x;
    cout << "Segundo angulo:";
    cin >> y;
    cout << "Tercer angulo:";
    cin >> z;

    a=x+y+z;

    if (a==180)
    {
        cout << "Forman un triangulo";
    }
    else
    {
        cout << "No forman triangulo";
    }

    // Ahora lo hago pero ingresando el valor de los lados, no de los ángulos
cout << endl;

    int u,v,w;
    cout << "Ingrese tres valores:" << endl;
    cout << "Primer lado:";
    cin >> u;
    cout << "Segundo lado:";
    cin >> v;
    cout << "Tercer lado:";
    cin >> w;

    if (u+v>w&&u+w>v&&v+w>u)
    {
        cout << "Forman un triangulo";
    }
    else
    {
        cout << "No forman triangulo";
    }


    return 0;
}
