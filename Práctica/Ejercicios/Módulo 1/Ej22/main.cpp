#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string n,mayor="-",menor="-";
    int i=1,f,fmayor,fmenor;

    cout << "**** Persona numero " << i << " ****" <<endl<<endl;
    cout << "Ingrese un nombre o 'fin' para finalizar:" << endl;
    cin >> n;

    if(n!="fin")
        {mayor=n; menor=n;}

    while(n!="fin")
    {
        cout << "Ingrese fecha de nacimiento en formato AAAAMMDD:" << endl;
        cin >> f;
        cout << endl;

        if(i==1)
            {fmayor=f; fmenor=f;}

        if(f>fmenor)
            {fmenor=f; menor=n;}

        if(f<fmayor)
            {fmayor=f; mayor=n;}

        i++;
        cout << "**** Persona numero " << i << " ****" <<endl<<endl;
        cout << "Ingrese un nombre o 'fin' para finalizar:" << endl;
        cin >> n;
    }

    cout << "La persona de menor edad es: " << menor << endl;
    cout << "La persona de mayor edad es: " << mayor << endl;

    return 0;
}
