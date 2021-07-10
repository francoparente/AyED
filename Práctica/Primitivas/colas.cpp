/** COLAS **/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int info; //Puede ser cualquier cosa
    Nodo *sgte;
};

//Queue
void queue(Nodo *&inicio, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->info = n;
    nuevo_nodo->sgte = NULL;

    if((inicio == NULL)){
        inicio = nuevo_nodo;
    } else{
        fin->sgte = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout << "Elemento " << n << " agregado exitosamente." << endl;
}

//Unqueue
void unqueue(Nodo *&inicio, Nodo *&fin){
    int n;

    if(inicio){
        n = inicio->info;
        Nodo *aux = inicio;

        if(inicio == fin){
            inicio = NULL;
            fin = NULL;
        } else{
            inicio = inicio->sgte;
        }
        cout << "Elemento " << n << " sacado exitosamente." << endl;
        delete aux;
    } else{
        cout << "Error: Cola vacia." << endl;
    }
}

int main(){
    Nodo *inicio = NULL;
    Nodo *fin = NULL;

    cout << "Agregando valores a la cola: " << endl;
    queue(inicio, fin, 4);
    queue(inicio, fin, 3);
    queue(inicio, fin, 9);
    queue(inicio, fin, 2);

    cout << endl << "Sacando valores de la cola: " << endl;
    unqueue(inicio, fin);
    unqueue(inicio, fin);
    unqueue(inicio, fin);
    unqueue(inicio, fin);

    cout << endl << "Intentando quitar algo cuando ya no existe nada: " << endl;
    unqueue(inicio, fin);

    return 0;
}
