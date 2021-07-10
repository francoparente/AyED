#include <iostream>

using namespace std;

/*
2. Realice un procedimiento o función que al recibir dos listas como parámetro, devuelva
una tercer lista que concatene las mismas.
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

void concatenarListas (nodo *lista1, nodo *lista2)
{
    nodo *p = new nodo();
    p = lista1;

    while(p->sig != NULL)
    {
        p = p -> sig;
    }
    p->sig = lista2;
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

int main()
{
    nodo *lista1 = NULL;
    nodo *lista2 = NULL;
    insertarOrdenado (lista1, 1);
    insertarOrdenado (lista1, 2);
    insertarOrdenado (lista1, 3);
    insertarOrdenado (lista1, 4);
    insertarOrdenado (lista2, 5);
    insertarOrdenado (lista2, 6);
    insertarOrdenado (lista2, 7);
    cout << "Lista 1:" <<endl;
    mostrarLista (lista1);
    cout << endl<<endl;
    cout << "Lista 2:" <<endl;
    mostrarLista (lista2);
    cout << endl<<endl;
    cout << "Lista concatenada: "<<endl;
    concatenarListas(lista1, lista2);
    mostrarLista(lista1);
    cout << endl<<endl;

    return 0;
}
