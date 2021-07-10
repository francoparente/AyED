#include <iostream>
#include <cstring>
#include <conio.h> //getch
#include <stdio.h> //fflush
#include <stdlib.h> //atoi

using namespace std;

//10. Dada una matriz de MxN con datos de clientes (apellido y nombre, dirección, edad y saldos)
//se pide ordenarla por saldos. Considere que cada dato es una columna de la tabla y cada cliente es una fila.

void inicializar(char matriz[][4][50])
{
    for (int i=0;i< 100; i++)
    {
        for (int j=0; j< 4; j++)
            strcpy(matriz[i][j],"");
    }
    return;
}

void leerdatos(char matriz[][4][50] , int filas )
{
    for (int i = 0 ; i < filas ; i++)
    {
        cout << "Apellido y nombre " << endl;
        fflush(stdin);
        gets(matriz[i][0]);
        cout << "Ingrese direccion " << endl;
        fflush(stdin);
        gets(matriz[i][1]);
        cout << "Edad" << endl;
        cin >> matriz[i][2];
        cout << "Ingrese saldo " << endl;
        cin >> matriz[i][3];
    }
    return;
}

void ordenar(char matriz[][4][50] , int filas)
{
    int i , j , c ;
    char aux [100];
    for (i=0 ; i < filas ; i++)
    {
        for(j = i+1 ; j < filas ; j++)
        {
            if ( atoi ( matriz[i][3]) < atoi (matriz [j][3]))
            {
                for ( c = 0 ; c < 4 ; c++)
                {
                    strcpy(aux , matriz[i][c]);
                    strcpy(matriz[i][c] , matriz[j][c]);
                    strcpy(matriz[j][c] , aux);
                }
            }
        }
    }
    return;
}

void mostrardatos (char matriz[][4][50] , int filas  )
{
    int i , j ;
    cout << "|   Apellido y nombre    |    Direccion    |    Edad    |    Saldo    | " << endl;
    for (i = 0 ; i < filas ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
            cout << matriz[i][j] << " | " ;
        cout << endl;
    }
    return;
}

int main()
{
  int f ;
  char m[50][4][50] ;
  cout << "Ingrese cantidad de personas a registrar:" << endl;
  cin >> f ;
  inicializar(m);
  leerdatos(m , f );
  ordenar(m , f);
  mostrardatos(m , f );
    return 0;
}
