#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define ARCHIVOASEGURADOS "Asegurados.Bak"
#define ARCHIVOPROCESADOS "Procesados.Bak"
#define ARCHIVOACTIVOS "archivo_desactivadas"

using namespace std;

//Trabajo Práctico - Algoritmos y Estructura de datos - K1031

struct polizaAsegurado
{
    int numeroDePoliza;
    char numeroDni[11];
    char nombre[20];
    char apellido[20];
    bool cuotaAlDia;
    char patenteDelAuto[10];
    bool polizaActiva;
    int cantidadDeIncidentes;
};

struct incidenteACargar
{
    int codigoIncidente;
    char fechaHora[20];
    char dniDelAsegurado[11];
    char dniOtroConductor[11];
    char calle[50];
    int alturaDeCalle;
};

void cargarPoliza()
{
    FILE *f;
    polizaAsegurado p;
    if(f=fopen(ARCHIVOASEGURADOS, "ab"))
    {
        cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.numeroDePoliza;
        cout << "Ingrese el numero de DNI: " << endl;
        cin >> p.numeroDni;
        cout << "Ingrese nombre del asegurado: " << endl;
        cin >> p.nombre;
        cout << "Ingrese apellido del asegurado: " << endl;
        cin >> p.apellido;
        cin.ignore();
        cout << "Ingrese patente del auto: " << endl << endl;
        cin.getline(p.patenteDelAuto,10,'\n');

        p.cantidadDeIncidentes = 0;
        p.cuotaAlDia = true;
        p.polizaActiva = true;
        fwrite(&p, sizeof(polizaAsegurado), 1, f);
        fclose(f);
        cout << "------------------------------" << endl;
        cout << "|La poliza se cargo con exito|" << endl;
        cout << "------------------------------" << endl;
        return;
     }
     else
        cout <<"-----------------------------" << endl;
        cout <<"|No se pudo cargar la poliza|" << endl;
        cout <<"-----------------------------" << endl;
}

void mostrarPolizas(char nombreArchivo[])
{
    FILE *archivo;
    polizaAsegurado p;
    archivo= fopen(nombreArchivo, "rb");

    while (fread(&p, sizeof(polizaAsegurado), 1, archivo))
    {
        cout << "\tDatos del asegurado" <<endl<< "\t-------------------" << endl;
        cout << "\t\t Numero de poliza: " << p.numeroDePoliza << endl;
        cout << "\t\t DNI: " << p.numeroDni << endl;
        cout << "\t\t Nombre: " << p.nombre << endl;
        cout << "\t\t Apellido: " << p.apellido << endl;
        if(p.cuotaAlDia)
            cout << "\t\t Cuota al dia: Si" <<endl;
        else
            cout << "\t\t Cuota al dia: No" <<endl;
        cout << "\t\t Patente: " << p.patenteDelAuto<< endl;
        if(p.polizaActiva)
            cout << "\t\t Poliza activa: Si" <<endl;
        else
            cout << "\t\t Poliza activa: No" <<endl;
        cout << "\t\t Cantidad de incidentes: " << p.cantidadDeIncidentes << endl<<endl;
    }
    return;
}

void mostrarArchivoIncidentes()
{
    FILE *archivoIncidentes;
    incidenteACargar p;
    archivoIncidentes = fopen(ARCHIVOPROCESADOS, "rb");

    while(fread(&p, sizeof(incidenteACargar), 1, archivoIncidentes))
    {
        cout << "\t Datos del incidente" <<endl<< "\t -------------------" << endl;
        cout << "\t\t Codigo de incidente: " << p.codigoIncidente << endl;
        cout << "\t\t Fecha y hora: " << p.fechaHora << endl;
        cout << "\t\t Dni del asegurado: " << p.dniDelAsegurado << endl;
        cout << "\t\t Dni del otro conductor: " << p.dniOtroConductor << endl;
        cout << "\t\t Calle: " << p.calle << endl;
        cout << "\t\t Altura: " << p.alturaDeCalle << endl;
        cout << endl << endl;
    }
    fclose(archivoIncidentes);
}

bool desactivarPoliza()
{
    FILE *f;
    polizaAsegurado p;
    int polizaADesactivar, encontrado = 0;
    if (f = fopen(ARCHIVOASEGURADOS, "rb+"))
    {
        cout << "Ingrese el numero de la poliza a desactivar" << endl;
        cin >> polizaADesactivar;
        while(fread(&p, sizeof(struct polizaAsegurado),1,f) && !encontrado)
        {
            if (polizaADesactivar == p.numeroDePoliza)
            {
                encontrado = 1;
                p.polizaActiva = false;
                fseek(f,sizeof(polizaAsegurado)*(-1), SEEK_CUR);
                fwrite(&p,sizeof(polizaAsegurado),1,f);
                fclose(f);
                cout << "----------POLIZA DESACTIVADA CON EXITO----------" << endl;
                return true;
            }
        }
    }
            else
    {
        cout <<endl<< " ---------------------" << endl;
        cout << "|No existe el archivo|" << endl;
        cout << " ---------------------" << endl;
        return false;
    }
    return true;
}

int buscarPorPolizaConParametro(int polizaABuscar)
{
    FILE *f;
    int encontrado = 0;
    struct polizaAsegurado p;
    if (f = fopen(ARCHIVOASEGURADOS,"rb"))
    {
        while(fread(&p,sizeof(struct polizaAsegurado),1,f) && !encontrado)
        {
            if (polizaABuscar == p.numeroDePoliza)
            {
                encontrado = 1;
                if (p.polizaActiva){
                    cout <<endl<< "Datos del asegurado" <<endl<< "-------------------" << endl;
                    cout << "Numero de poliza: " << p.numeroDePoliza << endl;
                    cout << "DNI: " << p.numeroDni << endl;
                    cout << "Nombre: " << p.nombre << endl;
                    cout << "Apellido: " << p.apellido << endl;
                        if(p.cuotaAlDia == true)
                            cout << "Cuota al dia: Si" <<endl;
                        else
                            cout << "Cuota al dia: No" <<endl;
                    cout << "Patente: " << p.patenteDelAuto<< endl;
                        if(p.polizaActiva == true)
                            cout << "Poliza activa: Si" <<endl;
                        else
                            cout << "Poliza activa: No" <<endl;
                    cout << "Cantidad de incidentes: " << p.cantidadDeIncidentes << endl<<endl;
                } else
                {
                    cout<<endl<<" --------------------------------------------"<<endl;
                    cout << "|La poliza buscada existe pero no esta activa|" << endl;
                    cout<<" --------------------------------------------"<<endl;
                    return 2;
                }
            }
        }
        if (!encontrado)
        {
                cout<<endl<<" --------------------------------"<<endl;
                cout<<"|No se encontro la poliza buscada|"<<endl;
                cout<<" --------------------------------"<<endl;
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int buscarPorDNI()
{
    FILE* f;
    int poliza;
    char DNIABuscar[11];
    polizaAsegurado p;
    if (f=fopen(ARCHIVOASEGURADOS,"rb"))
    {
        cout << "Ingrese DNI: " << endl;
        cin >> DNIABuscar;

        while(fread(&p,sizeof(polizaAsegurado),1,f))
        {
            if(strcmp(DNIABuscar, p.numeroDni) == 0)
                cout << "Poliza asociada: " << p.numeroDePoliza << endl;
        }
        cout << "Ingrese la poliza correspondiente " << endl;
        cin >> poliza;
        buscarPorPolizaConParametro(poliza);
        fclose(f);
        return 1;
    }
    return 0;
}

int buscarPorPoliza()
{
    FILE *f;
    int polizaABuscar, encontrado = 0;
    struct polizaAsegurado p;
    if (f = fopen(ARCHIVOASEGURADOS,"rb"))
    {
        cout << "Ingrese un numero de Poliza: " << endl;
        cin >> polizaABuscar;
        while(fread(&p,sizeof(struct polizaAsegurado),1,f) && !encontrado)
        {
            if (polizaABuscar == p.numeroDePoliza)
            {
                encontrado = 1;
                if (p.polizaActiva)
                {
                    cout <<endl<< "Datos del asegurado" <<endl<< "-------------------" << endl;
                    cout << "Numero de poliza: " << p.numeroDePoliza << endl;
                    cout << "DNI: " << p.numeroDni << endl;
                    cout << "Nombre: " << p.nombre << endl;
                    cout << "Apellido: " << p.apellido << endl;
                        if(p.cuotaAlDia == true)
                            cout << "Cuota al dia: Si" <<endl;
                        else
                            cout << "Cuota al dia: No" <<endl;
                    cout << "Patente: " << p.patenteDelAuto<< endl;
                        if(p.polizaActiva == true)
                            cout << "Poliza activa: Si" <<endl;
                        else
                            cout << "Poliza activa: No" <<endl;
                    cout << "Cantidad de incidentes: " << p.cantidadDeIncidentes << endl<<endl;
                }
                else
                {
                    cout<<endl<<" --------------------------------------------"<<endl;
                    cout << "|La poliza buscada existe pero no esta activa|" << endl;
                    cout<<" --------------------------------------------"<<endl;
                    return 2;
                }
            }
        }

        if (!encontrado)
        {
            cout<<endl<<" --------------------------------"<<endl;
            cout<<"|No se encontro la poliza buscada|"<<endl;
            cout<<" --------------------------------"<<endl;
        }
            fclose(f);
            return 1;
    }
    return 0;
}

int cantidadDePolizas()
{
    FILE *asegurados;
    polizaAsegurado p;
    int tamanioEnBytes, cantPolizas;

    asegurados = fopen (ARCHIVOASEGURADOS, "rb");
    fseek(asegurados, sizeof(polizaAsegurado), SEEK_END);
    tamanioEnBytes = ftell(asegurados);
    cantPolizas = tamanioEnBytes/72;

    return cantPolizas;
}

void listarPorIncidentes()
{
    FILE *asegurados;
    polizaAsegurado p;
    int vectorCantIncidentes[cantidadDePolizas()],i = 0, j, k,auxiliar, vectorLength;

    asegurados = fopen(ARCHIVOASEGURADOS, "rb");

    while(fread(&p, sizeof(polizaAsegurado), 1, asegurados))
    {
        vectorCantIncidentes[i] = p.cantidadDeIncidentes;
        i++;
    }
    for (j = 0; j < cantidadDePolizas() ; j++){
        for (k = 0; k < (cantidadDePolizas() -1); k++){
            if(vectorCantIncidentes[k] < vectorCantIncidentes[k+1]){
                auxiliar = vectorCantIncidentes[k];
                vectorCantIncidentes[k] = vectorCantIncidentes[k+1];
                vectorCantIncidentes[k+1] = auxiliar;
            }
        }
    }
    fclose(asegurados);
    for(j = 0; j < cantidadDePolizas(); j++)
    {
        asegurados = fopen(ARCHIVOASEGURADOS, "rb");
        while(fread(&p, sizeof(polizaAsegurado), 1, asegurados))
        {
            if(vectorCantIncidentes[j-1] == vectorCantIncidentes[j])
            {
                break;
            }
            else
            {
               if (vectorCantIncidentes[j] == p.cantidadDeIncidentes && p.polizaActiva)
                {
                    buscarPorPolizaConParametro(p.numeroDePoliza);
                }
            }
        }
        fclose(asegurados);
    }
}

void imprimirNumeroDePolizas(char docAsegurado[])
{
    FILE *asegurados;
    polizaAsegurado p;
    asegurados = fopen(ARCHIVOASEGURADOS, "rb");
    cout << "Polizas asociadas " << endl;

    while(fread(&p, sizeof(polizaAsegurado), 1, asegurados))
    {
        if(strcmp(docAsegurado, p.numeroDni) == 0 && p.polizaActiva)
            cout << p.numeroDePoliza << endl;
    }
    fclose(asegurados);
}

void cargarLoteDeIncidentes ()
{
    FILE *asegurados, *incidentes;
    polizaAsegurado p;
    incidenteACargar q;
    int poliza;
    char opcion;

    do
    {
        incidentes = fopen (ARCHIVOPROCESADOS, "ab");
        cout << "----------INGRESANDO DATOS DE INCIDENTE----------" << endl;
        cout << "Ingrese el codigo de incidente " << endl;
        cin >> q.codigoIncidente;
        cout << "Ingrese la fecha y hora (AAAA/MM/DD/hh:mm)" << endl;
        cin >> q.fechaHora;
        cout << "Ingrese el DNI del asegurado" << endl;
        cin >> q.dniDelAsegurado;
        cout << "Ingrese el DNI del otro conductor" << endl;
        cin >> q.dniOtroConductor;
        cin.ignore();
        cout << "Ingrese la calle " << endl;
        cin.getline(q.calle,50,'\n');
        cout << "Ingrese la altura de la calle" << endl;
        cin >> q.alturaDeCalle;

        fwrite(&q, sizeof(incidenteACargar), 1, incidentes);
        fclose(incidentes);

        imprimirNumeroDePolizas(q.dniDelAsegurado);

        cout << "Ingrese la poliza correspondiente " << endl;
        cin >> poliza;

        asegurados = fopen(ARCHIVOASEGURADOS, "rb+");
        while(fread(&p, sizeof(polizaAsegurado), 1, asegurados))
        {
            if(poliza == p.numeroDePoliza)
            {
                p.cantidadDeIncidentes++;
                fseek(asegurados, sizeof(polizaAsegurado)*-1, SEEK_CUR);
                fwrite(&p, sizeof(polizaAsegurado), 1, asegurados);
                cout << "----------DATOS CARGADOS CORRECTAMENTE----------" << endl;
                break;
            }
        }
        fclose(asegurados);

        cout << "Desea cargar otro incidente? (Y/N)" <<endl;
        cin >> opcion;
    }
    while (opcion == 'Y' || opcion == 'y');
}

void finDeJornada()
{
    FILE *auxiliar, *poliza;
    polizaAsegurado p, q;
    auxiliar = fopen (ARCHIVOACTIVOS, "wb");
    poliza = fopen(ARCHIVOASEGURADOS, "rb+");
    while (fread(&p, sizeof(polizaAsegurado), 1, poliza))
    {
        if(p.polizaActiva)
        {

            fwrite(&p, sizeof(polizaAsegurado), 1, auxiliar);
        }

    }

    fclose(auxiliar);
    fclose(poliza);

    return;
}

void seleccionarArchivo()
{
    char opcion, confirmacion;

    do
    {
    cout << "----------SELECCIONADOR DE ARCHIVOS----------" <<endl;
    cout << "1- Archivo de polizas activas e inactivas" << endl;
    cout << "2- Archivo de polizas activas" << endl;
    cout << "3- Archivo de incidentes procesados" << endl <<endl;

    cout << "Seleccione el archivo a mostrar por pantalla: ";
    cin >> opcion;
    cout << endl;

    switch(opcion)
    {
    case '1':
        cout << "Lista de polizas activas e inactivas" << endl;
        cout << "====================================" << endl << endl;
        mostrarPolizas(ARCHIVOASEGURADOS);
        break;
    case '2':
        cout << "Lista de polizas activas" << endl;
        cout << "========================" << endl << endl;
        mostrarPolizas(ARCHIVOACTIVOS);
        break;
    case '3':
        cout << "Lista de incidentes procesados" << endl;
        cout << "==============================" << endl << endl;
        mostrarArchivoIncidentes();
        break;
    default:
        cout << "-----------------------------------" << endl;
        cout << "|No ha seleccionado ningun archivo|" << endl;
        cout << "-----------------------------------" << endl;
    }
    cout << "Desea mostrar otro archivo por pantalla? (Y/N): ";
    cin >> confirmacion;
    cout << endl;

    } while(confirmacion == 'y' || confirmacion == 'Y');
    return;
}

int main()
{
    char opcion;
    do
    {
        cout<<endl;
        cout << "Elija una opcion" << endl;
        cout << "1- Mostrar polizas" << endl;
        cout << "2- Cargar nueva poliza " << endl;
        cout << "3- Desactivar poliza existente" << endl;
        cout << "4- Buscar poliza por DNI" << endl;
        cout << "5- Buscar poliza por Nro. de poliza" << endl;
        cout << "6- Mostrar polizas por cantidad de incidentes descendente" << endl;
        cout << "7- Procesar lote de incidentes" << endl;
        cout << "8- Finalizar jornada" << endl;
        cout << "Esc - Cerrar programa" << endl<<endl;

        do
        {
            opcion = getch();
        }
        while ((opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6' && opcion!='7' && opcion !='8' && opcion!=27));

        switch (opcion)
        {
            case '1':
                seleccionarArchivo();
                break;
            case '2':
                cargarPoliza();
                break;
            case '3':
                desactivarPoliza();
                break;
            case '4':
                buscarPorDNI();
                break;
            case '5':
                buscarPorPoliza();
                break;
            case '6':
                listarPorIncidentes();
                break;
            case '7':
                cargarLoteDeIncidentes();
                break;
            case '8':
                finDeJornada();
                break;
            case 27:
                return 0;
                break;
        }
    }
    while (opcion!= 27);
    getch();
    return 0;
}
