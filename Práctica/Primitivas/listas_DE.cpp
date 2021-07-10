/** LISTAS DE **/
#include <iostream>
#include <conio.h>
using namespace std;

typedef int tipoinfo;

struct NodoListaDE{
    int info;
    NodoListaDE *sgte = NULL;
    NodoListaDE *ant = NULL;
};

void ListaDEInsertarSiguiente(NodoListaDE  *&n, tipoinfo x){
    NodoListaDE *nuevo = new NodoListaDE();
    nuevo->info = x;

    if(n != NULL){ //Ya hay nodos existentes en la lista
        nuevo->sgte = n->sgte;
        n->sgte = nuevo;
        nuevo->ant = n;

        if(nuevo->sgte){
            nuevo->sgte->ant = nuevo;
        }
    } else{ //Es el primer nodo
        nuevo->sgte = n;
        n = nuevo;
        nuevo->ant = NULL;
    }

    return;
}

void ListaDEBorrarSiguiente(NodoListaDE *n){
    NodoListaDE *aborrar = n->sgte;
    NodoListaDE *sgteaborrar;

    if(aborrar){
        sgteaborrar= aborrar->sgte;
    } else{
        sgteaborrar = NULL;
    }

    n->sgte = sgteaborrar;
    sgteaborrar->ant = n;
    delete aborrar;
    return;
}

NodoListaDE *ListaDEObtenerSiguiente(NodoListaDE *n){
    if(n)
        return n->sgte;
    else
        return NULL;
}

NodoListaDE *ListaDEObtenerUltimo(NodoListaDE *p){
    if(p){
        while(p->sgte){
            p = p->sgte;
        }
    }
    return p;
}

NodoListaDE* ListaDEBuscarNodo(NodoListaDE *raiz, tipoinfo infobuscada){
    NodoListaDE *p = raiz;
    while(p && (p->info != infobuscada)){
        p = p->sgte;
    }
    return p;
}

NodoListaDE* ListaDEBuscarNodoAnterior(NodoListaDE *nodo){
    if(nodo && nodo->ant){
        return nodo->ant;
    }
    else
        return NULL;
}

/*BorrarNodo: recibe el puntero del nodo a borrar*/
void ListaDEborrarNodo(NodoListaDE *&raiz, NodoListaDE *aborrar){
    NodoListaDE *auxsgte;
    NodoListaDE *auxant;

    if(aborrar && aborrar->ant){
        auxant = aborrar->ant;
        ListaDEBorrarSiguiente(auxant);
    } else if(aborrar){
        auxsgte = aborrar->sgte;
        delete aborrar;
        auxsgte->ant = NULL;
        raiz = auxsgte;
    }
    return;
}

void ListaDEInsertarAlFinal(NodoListaDE *&lista, tipoinfo x){
    NodoListaDE *aux;

    if(lista){
        aux = ListaDEObtenerUltimo(lista);
        ListaDEInsertarSiguiente(aux,x);
    } else{
        ListaDEInsertarSiguiente(lista,x);
    }
    return;
}

void ListaDEborrarLista(NodoListaDE *&lista){
    NodoListaDE *anterior;
    NodoListaDE *paux;

    while (lista != NULL){
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
    return;
}

int main(){
    NodoListaDE *milistaDE = NULL;
    NodoListaDE *auxlista = NULL;

    cout << "Agregamos tres numeros, 100, 200 y 300: " << endl;
    ListaDEInsertarAlFinal(milistaDE,100);
    ListaDEInsertarAlFinal(milistaDE,200);
    ListaDEInsertarAlFinal(milistaDE,300);

    cout << "Los mostramos al reves para probar los punteros al anterior: " << endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    cout << auxlista->info << "<==>" << auxlista->ant->info << "<==>" << auxlista->ant->ant->info << endl;

    cout << endl << "Ahora borramos el nodo del medio (el de 200):" <<endl;
    auxlista = ListaDEBuscarNodo(milistaDE,200);
    if(auxlista != NULL){
        ListaDEborrarNodo(milistaDE, auxlista);
        cout << "Nodo borrado exitosamente" << endl;
    } else{
        cout << "No se encontro el nodo a borrar." << endl;
    }

    cout << endl << "Recorremos al derecho y al revés para verificar que los punteros quedaron ok:" << endl;
    cout << "Al derecho:" << endl;
    cout << milistaDE->info << " <==> " << milistaDE->sgte->info << endl;
    cout << "Al reves:" << endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    cout << auxlista->info << " <==> " << auxlista->ant->info << endl;

    cout << endl << "Agregamos un elemento entre el 100 y el 300:" << endl;
    auxlista = ListaDEBuscarNodo(milistaDE,100);
    if(auxlista!= NULL){
        ListaDEInsertarSiguiente(auxlista,467);
        cout << "Nodo agregado exitosamente" << endl;
    }

    cout << "Recorremos al derecho:" << endl;
    auxlista = milistaDE;
    while(auxlista){
        cout << auxlista->info << endl;
        auxlista = auxlista->sgte;
    }

    cout << endl << "Recorremos al reves:" << endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    while(auxlista){
        cout << auxlista->info << endl;
        auxlista = auxlista->ant;
    }

    cout << endl << "Finalmente borramos la lista." << endl;
    ListaDEborrarLista(milistaDE);
    getch();
    return 0;
}
