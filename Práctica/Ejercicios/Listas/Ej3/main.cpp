#include <iostream>

using namespace std;

/*
3. Haga un procedimiento que reciba los mismos parámetros del punto 1 pero devuelva
una tercer lista con el contenido de ambas intercalado (es decir un nodo de la lista 1
seguido por un nodo de la lista 2, si una lista se finaliza primero quedan todos los
demás nodos de la otra lista consecutivos).
*/

struct nodo
{
    int info;
    nodo *sig;
};

void insertarAlFinal (nodo *&lista, int n)
{
    nodo *nuevo = new nodo();
    nodo *ultimo = lista;
    nuevo -> info = n;
    nuevo -> sig = NULL;

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        while(ultimo->sig != NULL)
        {
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
    }
    return;
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

void intercalarListas(nodo *lista1, nodo *lista2, nodo *&lista3)
{
    while (lista1)
    {
        insertarAlFinal(lista3, lista1->info);
        lista1 = lista1->sig;
        if(lista2)
        {
            insertarAlFinal(lista3, lista2->info);
            lista2 = lista2->sig;
        }
    }
    while(lista2)
    {
        insertarAlFinal(lista3, lista2->info);
        lista2 = lista2->sig;
    }
    return;
}

int main()
{
    nodo *lista1 = NULL;
    nodo *lista2 = NULL;
    nodo *lista3 = NULL;
    insertarAlFinal (lista1, 1);
    insertarAlFinal (lista1, 3);
    insertarAlFinal (lista1, 5);
    insertarAlFinal (lista1, 7);
    insertarAlFinal (lista2, 2);
    insertarAlFinal (lista2, 4);
    insertarAlFinal (lista2, 6);
    insertarAlFinal (lista2, 8);
    insertarAlFinal (lista2, 9);
    insertarAlFinal (lista2, 10);
    cout << "Lista 1:" <<endl;
    mostrarLista (lista1);
    cout << endl<<endl;
    cout << "Lista 2:" <<endl;
    mostrarLista (lista2);
    cout << endl<<endl;
    cout << "Lista intercalada: "<<endl;
    intercalarListas(lista1, lista2, lista3);
    mostrarLista(lista3);
    cout <<endl<<endl;

    return 0;
}
