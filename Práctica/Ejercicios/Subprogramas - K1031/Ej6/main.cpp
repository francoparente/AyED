#include <iostream>
#include <conio.h>

using namespace std;

int menu()
{
    char opcion;

    cout << "Elija una opcion:";
    cout << "Presione 'a' si desea sumar los numeros.";
    cout << "Presione 'b' si desea restar los numeros.";
    cout << "Presione 'c' si desea multiplicar los numeros.";
    cout << "Presione 'd' si desea dividir n1 por n2.";

}

float suma(float n1, float n2)
{
    return n1+n2;
}

float producto(float n1,float n2)
{
    return n1*n2;
}

float resta(float n1,float n2)
{
    return n1-n2;
}

float division(float n1,float n2,float div)
{
    if (n2!=0)
        div=n1/n2;
    else
        cout<<"Error: División por cero."<<endl;
    return div;
}

int main()
{
    float x,y,z;
    char k;

    cout<<"Ingrese dos numeros:"<<endl;
    cin>>x>>y;

    cout<<endl<<"Elija una opcion"<<endl;
    cout << "Presione 'a' si desea sumar los numeros."<<endl;
    cout << "Presione 'b' si desea restar los numeros."<<endl;
    cout << "Presione 'c' si desea multiplicar los numeros."<<endl;
    cout << "Presione 'd' si desea dividir "<<x<<" por "<<y<<"."<<endl;
    cout << "Presione 'Esc' si desea finalizar."<<endl<<endl;

    do
    {
        k=getch();
        switch(k)
        {
            case 'a': case 'A':
                cout<<"Suma: "<<suma(x,y)<<endl;
                break;
            case 'b': case 'B':
                cout<<"Resta: "<<resta(x,y)<<endl;
                break;
            case 'c': case 'C':
                cout<<"Producto: "<<producto(x,y)<<endl;
                break;
            case 'd': case 'D':
                cout<<"Cociente: "<<division(x,y,z)<<endl;
                break;
            case 27:
                cout<<"Programa finalizado."<<endl;
                break;
            default:
                cout<<"Ingrese una opcion valida."<<endl;
        }
    }
    while (k!=27);

    return 0;
}
