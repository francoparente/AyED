#include <iostream>

using namespace std;

/*
7. Confeccionar un subprograma que, dados dos vectores de números
enteros liste el contenido de ambos pero en forma ordenada.
Utilice el algoritmo de apareo.
*/

int cantelementos(int v[], int tamfisico)
{
    int i=0;
    while(i<tamfisico && v[i]!=0)
        i++;
    return i;
}

void apareo(int v1[],int tam1, int v2[], int tam2, int v3[])
{
    int i=0, j=0, k=0;
    while(i<tam1 && j<tam2)
    {
        if(v1[i] < v2[j])
        {
            v3[k]=v1[i];
            i++;
        }
        else
        {
            v3[k]=v2[j];
            j++;
        }
        k++;
    }
    for(int cont=i; cont<tam1; cont++)
    {
        v3[k]=v1[cont];
        k++;
    }
    for(int cont=j; cont<tam2; cont++)
    {
        v3[k]=v2[cont];
        k++;
    }
    return;
}

int main()
{
    int v1[10]={2,9,8,4,10};
    int v2[10]={1,13,5,6,7,11,3,15};
    int v3[30]={0};
    apareo(v1,cantelementos(v1,10),v2,cantelementos(v2,10),v3);

    for(int x=0; x<cantelementos(v3,30); x++)
            cout <<"v3["<< x <<"]: "<< v3[x]<<endl;

    return 0;
}

//Esto lo había hecho antes de ver el video del profesor:
/*
int main()
{
    int n,m;
    cout<<"Ingrese tamaño de vector 1: ";
    cin>>n;
    cout<<"Ingrese tamaño de vector 2: ";
    cin>>m;
    int l= n+m;

    int v1[n], v2[m], v3[l];
    int i=0,j=0,k=0,t=0;

    cout<<"------------------------"<<endl;

    for(int q=0; q<n; q++)
    {
        cout<< "Ingrese valor de v1[" << q << "]: ";
        cin >> v1[q];
    }

    cout<<"------------------------"<<endl;

    for(int r=0; r<m; r++)
    {
        cout<< "Ingrese valor de v2[" << r << "]: ";
        cin >> v2[r];
    }
    cout<<"------------------------"<<endl;
    if(i<n && j<m)
    {
        if(v1[i]<v2[m])
        {
            v3[k]=v1[i];
            i++;
        }
        else
        {
            v3[k]=v2[j];
            j++;
        }
        k++;
    }

    if(i<n)
    {
        for(int s=i; s<n; s++)
        {
            v3[k]=v1[s];
            k++;
        }
    }
    else
    {
        for(int f=j; f<m; f++)
        {
            v3[k]=v1[f];
            k++;
        }
    }
    cout<< "Vector apareado y ordenado:"<<endl;
    for(int h=0; h<l; h++)
        cout<<"v3["<<h<<"]= "<<v3[h]<<endl;

    return 0;
}
*/
