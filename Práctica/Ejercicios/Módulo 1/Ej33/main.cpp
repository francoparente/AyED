#include <iostream>

using namespace std;

/*
Desarrollar una funci�n que calcule el m�ximo com�n divisor de dos n�meros enteros A, B con el siguiente algoritmo:
1) Dividir A por B, y calcular el resto (0 < R < B)
2) Si R = 0, el MCD es B, si no seguir en 3)
3) Reemplazar A por B, B por R, y volver al paso 1)
*/

int mcd(int a,int b)
{
    while (1)
    {
        int r = a%b;
        if(r==0)
            return b;
        a=b;
        b=r;
    }
    return 0;
}

int main()
{
    cout<< mcd(19,5) <<endl;

    return 0;
}
