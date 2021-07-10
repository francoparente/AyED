#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "Ingrese numero de mes: ";
    cin >> x;
    cout << "Ingrese año: ";
    cin >> y;

    switch (x)
{
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            cout<<31;
            break;
        case 2:
            if ((y%4==0 && y%100!=0 || y%400==0))
                cout<<29;
            else
                cout<<28;
                break;
        case 4: case 6:
        case 9: case 11:
            cout<<30;
            break;
}

    return 0;
}
