#include <iostream>
#include <conio.h>

using namespace std;

/*
1. Utilizando las funciones de ListasSE provistas en clase haga un programa que permita
al usuario:
    -Insertar un elemento ordenadamente en la lista
    -Buscar el mayor elemento
    -Calcular el promedio de la lista
*/

struct nodo
{
    int info;
    nodo *sig;
};

void insertarOrdenado (nodo *&lista, int n)
{
    nodo *nuevoNodo = new nodo();
    nuevoNodo -> info = n;
    nodo *aux = lista;
    nodo *aux2;
    while ((aux != NULL) && (aux -> info < n))
    {
        aux2 = aux;
        aux = aux -> sig;
    }
    if (aux != lista)
    {
        aux2 -> sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    nuevoNodo -> sig = aux;
}

void mostrarLista(nodo *lista)
{
    nodo *p = new nodo();
    p = lista;

    while(p != NULL)
    {
        cout << p -> info << " -> ";
        p = p -> sig;
    }
}

void buscarMayor(nodo *lista)
{
    nodo *p = new nodo();
    nodo *p2 = new nodo();
    p = lista;
    p2 = lista -> sig;
    while(p2)
    {
        p = p -> sig;
        p2 = p2 -> sig;
    }
    cout << "El mayor elemento de la lista: " << p -> info << endl;
}

void promedio(nodo *lista)
{
    nodo *p = new nodo();
    p = lista;
    int sum=0, q=0;
    float promedio;

    while(p != NULL)
    {
        sum += p -> info;
        p = p -> sig;
        q++;
    }
    promedio = sum/q;
    cout << "Promedio: " << promedio <<endl;
    return;
}

void menu()
{
    cout << endl << "Ingrese una opcion: " << endl;
    cout << "1 - Ingresar un nuevo elemento" << endl;
    cout << "2 - Mostrar lista" << endl;
    cout << "3 - Buscar mayor" << endl;
    cout << "4 - Calcular promedio" << endl;
    cout << "esc - Salir" << endl <<endl;
    return;
}

int main()
{
    nodo *lista = NULL;
    char opcion;
    int n;
    do
    {
        menu();
        opcion = getch();
        switch(opcion)
        {
            case '1':
                cout << "Ingrese la info: " << endl;
                cin >> n;
                insertarOrdenado(lista,n);
                break;
            case '2':
                mostrarLista(lista);
                cout << endl;
                break;
            case '3':
                buscarMayor(lista);
                break;
            case '4':
                promedio(lista);
                break;
        }
    }
    while(opcion != 27);
    return 0;
}
