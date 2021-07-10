#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// 8. Convertir una tabla de 6 x 5 en un vector ordenado de mayor a menor.

void bubble(int v[],int tam)
{
    int aux;
    for (int i=0; i<tam-1; i++)
    {
       for (int j=0; j<tam-1-i; j++)
       {
           if (v[j+1] < v[j])
           {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
           }
       }
    }
    return;
}

int main()
{
    int t[6][5];
    int v[30]={0};
    //----cargo la tabla----
    srand(time(0));
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<5; j++)
        {
            t[i][j]= rand()%100;
        }
    }
    //----muestro la tabla----
    for (int i2=0; i2<6; i2++)
    {
        for (int j2=0; j2<5; j2++)
        {
            cout << t[i2][j2] << "\t\t";
        }
        cout << endl << endl;
    }
    //----cargo y muestro el vector----
    int k=0;
    cout<<"--------------------------"<<endl;
    for (int i3=0; i3<6; i3++)
    {
        for (int j3=0; j3<5; j3++)
        {
            v[k]=t[i3][j3];
            cout<<"v["<<k<<"]= "<<v[k]<<endl;
            k++;
        }
    }
    cout<<"--------------------------"<<endl;
    bubble(v,30);
    for (int k1=0; k1<30; k1++)
        cout<<"v["<<k1<<"]= "<<v[k1]<<endl;

    return 0;
}
