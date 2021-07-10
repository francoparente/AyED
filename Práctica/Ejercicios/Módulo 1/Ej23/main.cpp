#include <iostream>

using namespace std;

int main()
{
    float k,maxneg=0,minpos=0,minrango=0,sum=0,prom=0;

    cout << "Ingrese un valor, o 0 para finalizar:"<<endl;
    cin >> k;

    while(k!=0)
    {
        if((k<0 && k>maxneg)||(k<0 && maxneg==0))
            maxneg=k;
        if((k>0 && k<minpos)||(k>0 && minpos==0))
            minpos=k;
        if((k>(-17.3) && k<26.9 && k<minrango)||(k>(-17.3) && k<26.9 && minrango==0))
            minrango=k;
        sum=sum+k;
        prom++;
        cout << "Ingrese un valor, o 0 para finalizar:"<<endl;
        cin >> k;
    }

    cout << "Valor máximo negativo: " << maxneg << endl;
    cout << "Valor mínimo positivo: " << minpos << endl;
    cout << "Valor mínimo entre -17.3 y 26.9: " << minrango << endl;
    cout << "Promedio de todos los valores: ";
    if(prom!=0) cout << sum/prom << endl;
    else cout <<"0"<<endl;

    return 0;
}
