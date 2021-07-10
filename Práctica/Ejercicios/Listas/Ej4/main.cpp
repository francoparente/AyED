#include <iostream>

using namespace std;

/*
4. Realice una función para ordenar una lista por método de burbuja aplicando el mismo
concepto visto para arrays.
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
    return;
}

int cantElementos(nodo *lista)
{
    int q=0;

    while(lista)
    {
        q++;
        lista = lista->sig;
    }
    return q;
}

nodo *nodoAnterior(nodo* lista, nodo* anteriorA)
{
    if(lista != anteriorA)
    {
        while (lista->sig != anteriorA)
        {
            lista = lista->sig;
        }
        return lista;
    }
    else
    {
        return NULL;
    }
}

void bubbleSort(nodo *&lista)
{
    nodo *aux;
    nodo *ant;
    nodo *prox;
    int q;
    q = cantElementos(lista);

    for(int i=0; i<q; i++)
    {
        aux = lista;
        for(int j=0; j<q-i-1; j++)
        {
            if(aux->info > aux->sig->info)
            {
                if(aux != lista)
                {
                    ant = nodoAnterior(lista, aux);
                    prox = aux->sig;
                    ant->sig = prox;
                    aux->sig = prox->sig;
                    prox->sig = aux;
                }
                else
                {
                    prox = aux->sig;
                    aux->sig = prox->sig;
                    prox->sig = aux;
                    lista = prox;
                }
            }
            else
            {
                aux = aux->sig;
            }
        }
    }
    return;
}

int main()
{
    nodo *lista = NULL;
    nodo *listaOrdenada = NULL;
    insertarAlFinal (lista, 7);
    insertarAlFinal (lista, 9);
    insertarAlFinal (lista, 5);
    insertarAlFinal (lista, 1);
    insertarAlFinal (lista, 2);
    insertarAlFinal (lista, 4);
    insertarAlFinal (lista, 10);
    insertarAlFinal (lista, 8);
    insertarAlFinal (lista, 3);
    insertarAlFinal (lista, 6);

    cout << "Lista:" <<endl;
    mostrarLista (lista);
    cout << endl<<endl;

    cout << "Lista ordenada:" <<endl;
    bubbleSort (lista);
    mostrarLista (lista);
    cout << endl<<endl;

    return 0;
}
