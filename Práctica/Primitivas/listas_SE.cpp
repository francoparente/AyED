/** LISTAS SE **/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//Struct de alumno
struct alumno{
    char nombre[20];
    char apellido[20];
    int edad;
};

//Struct para la lista de alumnos
struct NodoListaSEalumnos{
    alumno info;
    NodoListaSEalumnos *sgte;
};

//Struct para la lista de enteros
struct Nodo{
    int info;
    Nodo *sgte;
};

//Obtener el nodo siguiente a la info ingresada
Nodo *ObtenerSiguiente(Nodo *n){
    if(n){
        return n->sgte;
    } else{
        return NULL;
    }
}

//Obtener el ultimo nodo de la lista
Nodo *obtenerUltimo(Nodo *lista){
    while(lista && lista->sgte){
        lista = lista->sgte;
    }
    return lista;
}

//Recibe un puntero de la lista (raiz u otro)
//y la informacion para el nuevo nodo
void AgregarNodoAlFinal(Nodo *&lista, int x){
    Nodo *paux;

    if(lista){
        paux = obtenerUltimo(lista);
        paux->sgte = new Nodo();
        paux = paux->sgte;
        paux->info = x;
        paux->sgte = NULL;
    }
    else{ //Si no existe la lista, crea el primer nodo
        lista= new Nodo();
        lista->info = x;
        lista->sgte = NULL;
    }

    return;
}

//Inserta un nuevo nodo despues del nodo ingresado
void InsertarSiguiente(Nodo *&n, int x){
    Nodo *nuevo = new Nodo();
    nuevo->info = x;

    if(n){
        nuevo->sgte = n->sgte;
        n->sgte = nuevo;
    } else{
        nuevo->sgte = n;
        n = nuevo;
    }

    return;
}

void InsertarAlFinal(Nodo *&lista, int x)
{
    Nodo *aux;
    aux = obtenerUltimo(lista);

    if(aux){
        InsertarSiguiente(aux,x);
    } else{
        InsertarSiguiente(lista,x);
    }
    return;
}

void insertarOrdenado(Nodo *&lista, int ainsertar){
    Nodo *paux = lista;
    Nodo *anterior = NULL;

    while(paux && paux->info < ainsertar){
        anterior = paux;
        paux = paux->sgte;
    }

    if(paux != lista){
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;
    }
    else{
        lista = new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }
    return;
}

void BorrarSiguiente(Nodo  *n){
    Nodo *aborrar = n->sgte;
    Nodo *sgteaborrar;

    if(aborrar){
        sgteaborrar = aborrar->sgte;
    } else{
        sgteaborrar = NULL;
    }

    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

void MostrarLista(Nodo *milista){
    while(milista){
        cout << milista->info << endl;
        milista = ObtenerSiguiente(milista);
    }
}

Nodo *BuscarNodo(Nodo *p, int infobuscada){
    while(p && (p->info != infobuscada)){
        p = p->sgte;
    }

    return p;
}

Nodo *BuscarNodoAnterior(Nodo *raiz, Nodo *anterior_a){
    Nodo *p =NULL;

    if(raiz != anterior_a){
        p = raiz;

        while(p && (p->sgte != anterior_a)){
            p = p->sgte;
        }
        return p;
    } else{
        return NULL;
    }
}

//borrarNodo: recibe por parámetro lista y el puntero a borrar
void borrarNodo(Nodo *&raiz, Nodo *aborrar){
    if(raiz && aborrar){
        if(aborrar == raiz){
            raiz = raiz->sgte;
            delete aborrar;
        } else{
            Nodo *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
    return;
}

void ordenarLista(Nodo *lista){
     Nodo *actual, *siguiente;
     int t;

     actual = lista;

     while(actual->sgte != NULL){
          siguiente = actual->sgte;

        while(siguiente != NULL){

            if(actual->info > siguiente->info){
                t = siguiente->info;
                siguiente->info = actual->info;
                actual->info = t;
            }
            siguiente = siguiente->sgte;
        }

        actual = actual->sgte;
        siguiente = actual->sgte;
     }
}

void borrarLista(Nodo *&lista){ //De adelante hacia atras
    Nodo *anterior;
    Nodo *paux;

    while(lista != NULL){
        anterior = NULL;
        paux = lista;

        while(paux && paux->sgte){
            anterior = paux;
            paux = paux->sgte;
        }

        if(paux){
            delete paux;
            if(anterior != NULL)
                anterior->sgte = NULL;
            else
                lista = NULL;
        }
    }
}

void borrarListaAtras(Nodo *&inicio){ //De atras hacia adelante
    Nodo *anterior;
    Nodo *paux;

    while(inicio != NULL){
        anterior = NULL;
        paux = inicio;

        while(paux && paux->sgte){
			anterior = paux;
			paux = paux ->sgte;
        }

        if (paux){
            delete paux;
            if(anterior != NULL)
                anterior->sgte=NULL;
            else
                inicio = NULL;
        }
    }
}

int main()
{
    Nodo *inicio = NULL; //Inicio de la lista
    Nodo *aux, *x;

    cout << "***** Manejo de lista de enteros *****" << endl;
    cout << "Insertamos el primer nodo: " << endl;
    InsertarSiguiente(inicio, 5);
    MostrarLista(inicio);

    cout << endl << "Insertamos 3 valores mas: " << endl;
    aux = obtenerUltimo(inicio);
    InsertarSiguiente(aux,8);

    aux = obtenerUltimo(inicio);
    InsertarSiguiente(aux,3);

    aux = obtenerUltimo(inicio);
    InsertarSiguiente(aux,12);

    MostrarLista(inicio);

    x = obtenerUltimo(inicio);
    cout << endl << "Obtenemos el ultimo: " << x->info << endl;

    cout << endl << "Buscamos un 3: " << endl;
    x = BuscarNodo(inicio, 3);
    if(x){
        cout << "El dato buscado es: " << x->info << endl;
    } else{
        cout << "El elemento no existe" << endl;
    }

    cout << endl << "Buscamos un elemento que no existe: ";
    x = BuscarNodo(inicio, 15);
    if(x){
        cout << "El dato buscado es: " << x->info << endl;
    } else{
        cout << "El elemento no existe" << endl;
    }

    cout << endl << "Ordenamos la lista: " << endl;
    ordenarLista(inicio);
    MostrarLista(inicio);

    cout << endl << "Insertamos un 9 luego del 8: " << endl;
    x = BuscarNodo(inicio, 8);
    if(x){
        InsertarSiguiente(x, 9);
    }
    MostrarLista(inicio);

    cout << endl << "Insertamos un 6 de forma ordenada: " << endl;
    insertarOrdenado(inicio, 6);
    MostrarLista(inicio);


    cout << endl << "Borramos el elemento 3: " << endl;
    x = BuscarNodo(inicio, 3);
    borrarNodo(inicio, x);
    MostrarLista(inicio);

    cout << endl << "Borramos toda la lista." << endl;
    borrarLista(inicio);
    char c = getch();

    system("cls");
    cout << "***** Manejo de lista de alumnos *****" << endl;

    cout << "Ingresamos alumnos..." << endl;
    int cant_alumnos;
    cout << "Ingrese cantidad de alumnos: ";
    cin >> cant_alumnos;

    alumno *ptr_alumno;
    ptr_alumno = new alumno[cant_alumnos];

    cout << "Ingresamos datos de cada alumno: " << endl;
    for (int i=0; i< cant_alumnos;i++){
        cout << "\nIngrese nombre: ";
        cin >> ptr_alumno[i].nombre ;
        cout << "Ingrese apellido: ";
        cin >> ptr_alumno[i].apellido;
        cout << "Ingrese edad: ";
        cin >> ptr_alumno[i].edad;
    }

    cout << endl << "Listamos alumnos: " << endl;
    for (int i=0; i< cant_alumnos;i++){
        cout << endl << "ALUMNO NRO." << i+1 << endl;
        cout << " - Nombre: " << ptr_alumno[i].nombre << endl;
        cout << " - Apellido: "<< ptr_alumno[i].apellido << endl;
        cout << " - Edad: " << ptr_alumno[i].edad << endl << endl;
    }

    //Libero espacio en memoria del puntero
    delete [] ptr_alumno;

    return 0;
}
