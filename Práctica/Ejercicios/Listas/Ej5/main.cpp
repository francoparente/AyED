#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>

using namespace std;

/*
5. Realice un programa que lea de un archivo datos de alumnos de un curso. A medida
que el archivo se va leyendo va insertando los registros en una lista. Liste finalmente
todos los nodos para verificar que la operación fue exitosa.
*/

struct alumno
{
    char nombre[50];
    char apellido[50];
    char dni[11];
    int legajo;
    int codcarrera;
};

struct nodo
{
    alumno info;
    nodo *sig;
};

void insertarAlFinal (nodo *&lista, alumno n)
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

void cargarDatos()
{
    FILE *f;
    alumno a;
    f=fopen("archivoAlumnos", "wb");

    strcpy(a.apellido, "Parente");
    strcpy(a.nombre, "Franco");
    strcpy(a.dni, "38940568");
    a.codcarrera = 1548;
    a.legajo = 1579071;
    fwrite (&a, sizeof(alumno), 1, f);

    strcpy(a.apellido, "Alessi");
    strcpy(a.nombre, "Candelaria");
    strcpy(a.dni, "42154354");
    a.codcarrera = 2675;
    a.legajo = 17945865;
    fwrite (&a, sizeof(alumno), 1, f);

    strcpy(a.apellido, "Baggins");
    strcpy(a.nombre, "Frodo");
    strcpy(a.dni, "12654897");
    a.codcarrera = 3452;
    a.legajo = 1164853;
    fwrite (&a, sizeof(alumno), 1, f);

    strcpy(a.apellido, "Gamyi");
    strcpy(a.nombre, "Samwise");
    strcpy(a.dni, "10346579");
    a.codcarrera = 4615;
    a.legajo = 13456784;
    fwrite (&a, sizeof(alumno), 1, f);

    fclose(f);

    return;
}

void mostrarLista(nodo *lista)
{
    int i=1;
    while(lista->sig)
    {
        cout << "=========" << "DATOS DEL ALUMNO " << i << "=========" << endl;
        cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "Legajo: " << lista->info.legajo << endl;
        cout << "Carrera: " << lista->info.codcarrera<< endl << endl;
        lista = lista->sig;
        i++;
    }
    return;
}

void borrarLista(nodo *&lista)
{
    nodo *aux;
    while (lista)
    {
        aux = lista;
        if (aux->sig != NULL)
        {
            lista = lista->sig;
            delete aux;
        }
        else
        {
            delete lista;
            lista = NULL;
        }
    }
}

int main()
{
    FILE *f;
    nodo *lista = NULL;
    alumno a;

    cargarDatos();

    if(f=fopen("archivoAlumnos", "rb"))
    {
        while(!feof(f))
        {
            fread(&a,sizeof(alumno),1,f);
            insertarAlFinal(lista,a);
        }
        fclose(f);
    }
    mostrarLista(lista);
    borrarLista(lista);

    return 0;
}
