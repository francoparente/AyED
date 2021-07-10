#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Ingrese su edad:" << endl;
    cin >> x;

    if(x<=12)
        cout << "Menor" << endl;
    else
        if(x<=18&&x>=13)
            cout << "Cadete" << endl;
        else
            if(x>18&&x<26)
                cout << "Juvenil" << endl;
            else
                cout << "Mayor" << endl;
    return 0;
}
