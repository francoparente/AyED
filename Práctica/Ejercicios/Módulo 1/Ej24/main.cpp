#include <iostream>

using namespace std;

int main()
{
    int n,nmax=-1,nmin,pos=0,sum=0,lote=1,maxpos,maxlote;

    do{
        pos=0;
        sum=0;
        cout<<"Ingrese valores para el sublote "<<lote<<endl;
        cout<<"(ingrese 0 para pasar al siguiente sublote o un valor negativo para finalizar)"<<endl;
        cin>>n;
        nmin=n;
        while(n>0)
        {
            pos++;
            sum+=n;
            if(n>nmax){
                nmax=n;
                maxpos=pos;
                maxlote=lote;}
            if(n<nmin)
                nmin=n;
            cin>>n;
        }
        if(pos){
            cout<<"Promedio: "<<sum/pos<<endl;
            cout<<"Minimo: "<<nmin<<endl<<endl;}
        else
            cout<<"Sublote vacio."<<endl<<endl;
        lote++;
    }
    while(n>=0);

    if(nmax!=-1){
        cout<<"Total de sublotes: "<<lote-1<<endl<<endl;
        cout<<"Valor maximo del lote: "<<nmax<<endl<<"Numero de lote: "<<maxlote<<endl<<"Posicion dentro del lote: "<<maxpos<<endl<<endl;}





    return 0;
}
