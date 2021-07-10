/** PILAS **/
#include <iostream>
using namespace std;


struct Nodo{
    int info; //Puede ser cualquier cosa
    Nodo *sgte;
};

//Push
void push(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->info = n;
    nuevo_nodo->sgte = pila;
    pila = nuevo_nodo;

    cout << "Elemento " << n << " agregado exitosamente." << endl;
}

//Pop
void pop(Nodo *&pila){
    if(pila){
        Nodo *aux = pila;
        int n;
        n = aux->info;
        pila = aux->sgte;
        cout << "Elemento " << n << " sacado exitosamente." << endl;
        delete aux;
    } else{
        cout << "Error: Pila vacia." << endl;
    }
}

int main(){
    Nodo *pila = NULL;
    cout << "Ingresando valores a la pila: " << endl;
    push(pila, 1);
    push(pila, 5);
    push(pila, 3);

    cout << endl << "Sacando valores de la pila: " << endl;
    pop(pila);
    pop(pila);
    pop(pila);

    cout << endl << "Intentando eliminar algo cuando ya no existe nada: " << endl;
    pop(pila);

    return 0;
}
