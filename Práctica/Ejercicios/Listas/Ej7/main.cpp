#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>

using namespace std;

/*
5. Realice un programa que lea de un archivo datos de alumnos de un curso. A medida
que el archivo se va leyendo va insertando los registros en una lista. Liste finalmente
todos los nodos para verificar que la operación fue exitosa.

6. Modifique el programa anterior para que cada estructura alumno contenga una lista
de materias aprobadas.
Las materias se leen desde otro archivo y poseen la siguiente forma:

7. Agregar el siguiente comportamiento al programa anterior:
- Cuando el sistema arranca, carga de los archivos las listas del punto anterior.
- Se presenta al usuario un menú que permite:
        o Buscar un alumno y ver sus datos por Legajo.
        o Listar materias aprobadas de un alumno (se ingresa legajo).
        o Listar el promedio de un alumno (se ingresa legajo).
        o Agregar un alumno.
        o Agregar materia aprobada a un alumno.
        o Salir del programa: Debe insertar en los archivos correspondientes los
          registros que se hayan agregado en la ejecución y liberar toda la memoria
          solicitada.
*/

struct alumno
{
    char nombre[50];
    char apellido[50];
    char dni[11];
    int legajo;
    int codcarrera;
};

struct nodoAlumno
{
    alumno info;
    nodoAlumno *sig;
    nodoAlumno *listaMaterias;
};

struct materia
{
    char nombreMateria[50];
    char fechaAprobacion[11];
    int legajo;
    int nota;
    int libro;
    int folio;
};

struct nodoMateria
{
    materia info;
    nodoMateria *sig;
};

void insertarSiguienteAlumnos (nodoAlumno *&n, alumno x)
{
    nodoAlumno *nuevo = new nodoAlumno();
    nuevo->listaMaterias = NULL;
    nuevo->info = x;
    if (n != NULL)
    {
        nuevo->sig = n->sig;
        n->sig = nuevo;
    }
    else
    {
        nuevo->sig = n;
        n = nuevo;
    }
    return;
}

void insertarAlFinalAlumnos (nodoAlumno *&n, alumno x)
{
    nodoAlumno *nuevo = new nodoAlumno();
    nodoAlumno *ultimo = n;
    nuevo -> info = x;
    nuevo -> sig = NULL;

    if(n == NULL)
    {
        n = nuevo;
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

void insertarSiguienteMaterias (nodoMateria *&n, materia x)
{
    nodoMateria *nuevo = new nodoMateria();
    nuevo->info = x;
    if (n != NULL)
    {
        nuevo->sig = n->sig;
        n->sig = nuevo;
    }
    else
    {
        nuevo->sig = n;
        n = nuevo;
    }
    return;
}

void insertarAlFinalMaterias (nodoMateria *&n, materia x)
{
    nodoMateria *nuevo = new nodoMateria();
    nodoMateria *ultimo = n;
    nuevo -> info = x;
    nuevo -> sig = NULL;

    if(n == NULL)
    {
        n = nuevo;
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

void cargarMateriasPrueba()
{
    FILE *f;
    f=fopen("archivoMaterias","wb");
    materia m;
    if (f)
    {

        strcpy(m.nombreMateria,"Algoritmos y Estructura de Datos");
        strcpy(m.fechaAprobacion,"1995-06-28");
        m.libro=10;
        m.folio=114;
        m.nota= 8;
        m.legajo=71432;
        fwrite(&m, sizeof(materia),1,f);

        strcpy(m.nombreMateria,"Algoritmos y Estructura de Datos");
        strcpy(m.fechaAprobacion,"2014-11-28");
        m.libro=41;
        m.folio=19;
        m.nota= 9;
        m.legajo=190263;
        fwrite(&m, sizeof(materia),1,f);

        strcpy(m.nombreMateria,"Fisica I");
        strcpy(m.fechaAprobacion,"1997-03-15");
        m.libro=21;
        m.folio=711;
        m.nota= 7;
        m.legajo=71432;
        fwrite(&m, sizeof(materia),1,f);

        fclose(f);
        cout << "El archivo ha sido cargado con exito" << endl;
    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}

void mostrarLista(nodoAlumno *lista)
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

void borrarListaMaterias(nodoMateria *&lista)
{
    nodoMateria *aux;
    while(lista)
        aux = lista;
        if (aux->sig != NULL)
        {
            lista = lista->sig;
            delete aux;
        }
        else
        {
            lista = NULL;
            delete aux;
        }
    return;
}

void borrarListaAlumno(nodoAlumno *&lista)
{
    nodoAlumno *aux;
    while (lista)
    {
        aux = lista;
        if(aux->sig)
        {
            borrarListaMaterias(aux->listaMaterias);
            lista = lista->sig;
            delete aux;
        }
        else
        {
            borrarListaMaterias(aux->listaMaterias);
            lista = NULL;
            delete aux;
        }
    }
    return;
}

nodo* buscarPorLegajo(nodo *lista, int legajo)
{
    while (lista && lista->info.legajo != legajo)
        lista = lista->sgte;
    return lista;
}

void mostrarAlumno(nodoAlumno *lista, nodoAlumno->info->legajo)
{
    cout << "=========" << "DATOS DEL ALUMNO " << i << "=========" << endl;
    cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
    cout << "DNI: " << lista->info.dni << endl;
    cout << "Legajo: " << lista->info.legajo << endl;
    cout << "Carrera: " << lista->info.codcarrera<< endl << endl;
    return;
}

void mostrarMaterias(nodoMateria *lista)
{
    while (lista)
    {
        cout << "Nombre: " << lista->info.nombreMateria << endl;
        cout << "Fecha: " << lista->info.fechaAprobacion<< endl;
        cout << "Nota: " << lista->info.nota << endl;
        cout << "Libro: " << lista->info.libro << endl;
        cout << "Folio: " << lista->info.folio << endl;
        lista = lista->sgte;
    }
}

void levantarArchivos(nodo *&lista)
{
    FILE *f;
    alumno a;
    materia m;
    f=fopen("archivoAlumnos","rb");
    while (fread(&a,sizeof(alumno),1,f))
        insertarSiguienteAlumnos(lista,a);
    fclose(f);

    f=fopen("archivoMaterias","rb");
    while (fread(&m,sizeof(materia),1,f))
    {
        nodo *aux = buscarPorLegajo(lista, m.legajo);
        if (aux)
            insertarSiguienteMaterias(aux->listaMaterias,m);
    }
    fclose(f);
    return;
}

char mostrarmenu()
{
    char opcion;
    cout << "Ingrese una opcion: " << endl;
    cout << "0 - Levantar archivos de prueba (borra archivos anteriores)" << endl;
    cout << "1 - Buscar alumno por legajo" << endl;
    cout << "2 - Listar materias aprobadas de un alumno" << endl;
    cout << "3 - Listar promedio" << endl;
    cout << "4 - Agregar un alumno" << endl;
    cout << "5 - Agregar una materia" << endl;
    cout << "6 - Listar todos los alumnos" << endl;
    cout << "esc - Salir" << endl;
    do
    {
       opcion=getch();
    } while ((opcion!='0') &&(opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!='6') && (opcion!=27));
    return opcion;
}

void guardarAlumnosDisco(nodoAlumno *lista)
{
    FILE *falumnos;
    FILE *fmaterias;
    nodoAlumno *auxAlumno = NULL;
    nodoMateria *auxMateria = NULL;
    if (falumnos = fopen("archivoAlumnos","wb"))
    {
        if (fmaterias = fopen("archivoMaterias","wb"))
        {
            auxAlumno = lista;
            while (auxAlumno)
            {
                fwrite(&(auxAlumno->info), sizeof(alumno),1,falumnos);
                auxMateria = auxAlumno->listaMaterias;
                while(auxMateria)
                {
                    fwrite(&(auxMateria->info), sizeof(materia),1,fmaterias);
                    auxMateria = auxMateria->sig;
                }
                auxAlumno = auxAlumno->sig;
            }
            fclose(fmaterias);
        }
        else
            cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE MATERIAS" << endl;
        fclose(falumnos);
    }
    else
        cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE ALUMNOS" << endl;
    return;
}

int main()
{
    nodoAlumno *listaAlumnos = NULL;
    nodoAlumno *x = NULL;

    do
    {
        opcion = mostrarmenu()
        switch(opcion)
        {
        case '0':
            borrarListaAlumno(listaAlumnos);
            cargarDatos();
            cargarMateriasPrueba();
            levantarArchivos(listaAlumnos);
            break;

        case '1':
            cout<<"Ingrese legajo: "<<endl;
            cin>>legajo;
            x = buscarPorLegajo(listaAlumnos,legajo);
            if(x)
                mostrarAlumno(x->info);
            else
                cout<<"No se encontro el alumno."<<endl;
            break;

        case '2':
            cout<<"Ingrese legajo: "<<endl;
            cin>>legajo;
            x = buscarPorLegajo(listaAlumnos,legajo);
            if(x)
                mostrarMaterias(x->listaMaterias);
            else
                cout<<"No se encontro el alumno."<<endl;
            break;

        case '3':
            //o Listar el promedio de un alumno (se ingresa legajo).

            break;

        case '4':
            //o Agregar un alumno.

            break;

        case '5':
            //o Agregar materia aprobada a un alumno.

            break;

        case '6':
            //o listar todos los alumnos
            break;
        }
    }
    while(opcion != 27)
    guardarAlumnosDisco(listaAlumnos);
    borrarListaAlumno(listaAlumnos);

    return 0;
}
