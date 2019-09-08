#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "informes.h"
#include "juegos.h"
#include "utn.h"
#include "clientes.h"
#include "alquileres.h"

#define LIBRE 0
#define OCUPADO 1

void menuDeTodo(eClientes listaClientes[], int tamClientes, eJuegos listaJuegos[], int tamJuegos,eAlquileres listaAlquileres[],int tamAlquieleres)
{
    int opcion;
    char seguir = 's';
    char seguirJuego = 's';
    char seguirCliente = 's';
    char seguirAlquiler = 's';
    char seguirInforme = 's';
    int contadorJuegos=0;
    int contadorClientes=0;
    int AuxAltasJuegos;
    int AuxBajaJuegos;
    int auxAltaClientes;
    int auxBajaClientes;
    system("cls");

    do
    {
        printf("***Menu de Menues***\n\n");
        printf("1- JUEGOS\n");
        printf("2- CLIENTES\n");
        printf("3- ALQUILERES\n");
        printf("4- INFORMES\n");
        printf("5- SALIR\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            do
            {
                switch(menuJuegos())
                {
                case 1:

                    AuxAltasJuegos=altaJuegos(listaJuegos,tamJuegos);
                    if(AuxAltasJuegos==0)
                    {
                        contadorJuegos++;
                        printf("Se cargo Exitosamente!\n");
                    }
                    else
                    {
                        printf("No se pudo cargar!!\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(contadorJuegos>0)
                    {
                        modificarJuegos(listaJuegos,tamJuegos);
                    }
                    else
                    {
                        printf("No hay ningun Juego Cargado!\n");
                    }
                    system("pause");
                    break;
                case 3:
                    AuxBajaJuegos=BajaJuegos(listaJuegos,tamJuegos);
                    if(AuxBajaJuegos==0)
                    {
                        contadorJuegos--;
                    }
                    else
                    {
                        printf("No hay ningun Juego Cargado!\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(contadorJuegos>0)
                    {
                        listadoDeJuegos(listaJuegos,tamJuegos);
                    }
                    else
                    {
                        printf("No hay ningun Juego Cargado!\n");
                    }
                    system("pause");
                    break;
                case 5:
                    if(contadorJuegos>0)
                    {
                        ordenarJuegos(listaJuegos,tamJuegos);
                    }
                    else
                    {
                        printf("No hay ningun Juego Cargado!\n");
                    }
                    system("pause");
                    break;
                default:
                    seguirJuego = 'n';
                    break;
                }
            }
            while(seguirJuego == 's');
            system("cls");
            //system("pause");
            break;
        case 2:
            do
            {
                switch(menuClientes())
                {
                case 1:
                    auxAltaClientes= altaClientes(listaClientes,tamClientes);
                    if(auxAltaClientes==0)
                    {
                        contadorClientes++;
                    }
                    else
                    {
                        printf("No hay ningun Cliente cargado!\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(contadorClientes>0)
                    {
                        modificarClientes(listaClientes,tamClientes);
                    }
                    else
                    {
                        printf("No hay ningun Cliente cargado!\n");
                    }
                    system("pause");
                    break;
                case 3:
                    auxBajaClientes=BajaClientes(listaClientes,tamClientes);
                    if(auxBajaClientes==0)
                    {
                        contadorClientes--;
                    }
                    else
                    {
                        printf("No hay ningun Cliente cargado!\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(contadorClientes>0)
                    {
                        listadoDeClientes(listaClientes,tamClientes);
                    }
                    else
                    {
                        printf("No hay ningun Cliente cargado!\n");
                    }
                    system("pause");
                    break;
                case 5:
                    if(contadorClientes>0)
                    {
                        ordenarClientes(listaClientes,tamClientes);
                    }
                    else
                    {
                        printf("No hay ningun Cliente cargado!\n");
                    }
                    system("pause");
                    break;
                default:
                    seguirCliente = 'n';
                    break;
                }

            }
            while(seguirCliente == 's');
            system("cls");
            //system("pause");
            break;
        case 3:
            do
            {
                switch(menuAlquileres())
                {
                case 1:
                    altaAlquileres(listaAlquileres,tamAlquieleres,listaJuegos,tamJuegos,listaClientes,tamClientes);
                    system("pause");
                    break;
                case 2:
                    modificarAlquileres(listaAlquileres,tamAlquieleres);
                    system("pause");
                    break;
                case 3:
                    BajaAlquiler(listaAlquileres,tamAlquieleres);
                    system("pause");
                    break;

                case 4:
                    listadoDeAlquileres(listaAlquileres,tamAlquieleres);
                    system("pause");
                    break;
                default:
                    seguirAlquiler='n';
                    break;
                }

            }
            while(seguirAlquiler == 's');
            system("cls");//system("pause");
            break;

        case 4:
            do
            {
                switch(menuInformes())
                {
                case 1:
                    mostrarListaAlquileresxClientes(listaAlquileres,tamAlquieleres,listaClientes,tamClientes);
                    system("pause");
                    break;
                case 2:
                    mostrarListaAlquileresxJuegos(listaAlquileres,tamAlquieleres,listaJuegos,tamJuegos);
                    system("pause");
                    break;
                case 3:
                    recaudacionTotalDeAlquileres(listaAlquileres,tamAlquieleres,listaJuegos,tamJuegos);
                    system("pause");
                    break;
                case 4:
                    mostrarListaDeJuegosxFechaDeAlquileres(listaAlquileres,tamAlquieleres,listaJuegos,tamJuegos);
                    system("pause");
                    break;
                case 5:
                    mostrarListaDeClientesxFechaDeAlquileres(listaAlquileres,tamAlquieleres,listaClientes,tamClientes);
                    system("pause");
                    break;
                case 6:
                    mostrarListaJuegosMenosAlquilados(listaAlquileres,tamAlquieleres,listaJuegos,tamJuegos);
                    system("pause");
                    break;
                case 7:
                    mostrarListaClientesConMasAlquileres(listaAlquileres,tamAlquieleres,listaClientes,tamClientes);
                    system("pause");
                    break;
                case 8:
                    seguirInforme='n';
                    break;
                }
            }
            while(seguirInforme == 's');
            system("cls");//system("pause");
            break;
            default:
                 seguir='n';
                 break;
        }
    }while(seguir == 's');
    system("pause");
}

int menuJuegos()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- ALTA DE JUEGOS\n");
    printf("2- MODIFICAR JUEGOS\n");
    printf("3- BAJA JUEGOS\n");
    printf("4- LISTADO DE JUEGOS\n");
    printf("5- LISTADO DE JUEGOS ORDENADOS\n");
    printf("6- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuClientes()
{
    int opcion;
    system("cls");

    printf("***Menu de Clientes***\n\n");
    printf("1- ALTA DE CLIENTES\n");
    printf("2- MODIFICAR CLIENTES\n");
    printf("3- BAJA CLIENTES\n");
    printf("4- LISTADO DE CLIENTES\n");
    printf("5- LISTADO DE CLIENTES ORDENADOS\n");
    printf("6- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuAlquileres()
{
    int opcion;
    system("cls");

    printf("***Menu de Alquileres***\n\n");
    printf("1- ALTA DE ALQUILER\n");
    printf("2- MODIFICAR ALQUILER\n");
    printf("3- BAJA ALQUILER\n");
    printf("4- LISTADO DE ALQUILERES\n");
    printf("5- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("***Menu de Informes***\n\n");
    printf("1- LISTADO DE ALQUILER por CLIENTES\n");
    printf("2- LISTADO DE ALQUILER por JUEGOS\n");
    printf("3- RECAUDACION DE ALQUILERES\n");
    printf("4- LISTADO DE JUEGOS por FECHA DE ALQUILER\n");
    printf("5- LISTADO DE CLIENTES por FECHA DE ALQUILER\n");
    printf("6- LISTADO DE JUEGOS MENOS ALQUILADOS\n");
    printf("7- LISTADOS DE CLIENTES CON MAS ALQUILERES\n");
    printf("8- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void recaudacionTotalDeAlquileres(eAlquileres listaAlquiler[], int tamAlquiler,eJuegos listaJuegos[],int tamJuegos)
{
    int i,j;
    float valorTotal=0;
    int contador=0;
    int contadorDeAlquileres=0;
    float promedioDeAlquileres;

    for(i=0; i<tamAlquiler; i++)
    {
        if(listaAlquiler[i].isEmpty==OCUPADO)
        {
            for(j=0; j<tamJuegos; j++)
            {
                if(listaAlquiler[i].idJuego==listaJuegos[j].id)
                {
                    valorTotal+=listaJuegos[j].importe;
                    contador++;
                }
            }
        }
    }
    promedioDeAlquileres=(float)valorTotal/contador;

    for (i=0; i<contador; i++)
    {
        if ((listaAlquiler[i].isEmpty == OCUPADO) && (listaJuegos[i].importe >= promedioDeAlquileres))
        {
            contadorDeAlquileres++;
        }
    }

    printf("-------ALQUILERES-------\n\n");
    printf("La Recaudacion Total de Alquileres es: %.2f\n\n",valorTotal);
    printf("El promedio de los Alquileres es: %.2f\n\n",promedioDeAlquileres);
    printf("Los Juegos que sobrepasan el alquiler promedio son: %d\n\n",contadorDeAlquileres);

}

void mostrarListaDeJuegosxFechaDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos)
{
    int i,j;
    int idBuscado;
    int estaLibre;

    int auxDay;
    int auxMounth;
    int auxYear;

    int validarDay;
    int validarMounth;
    int validarYear;

    listadoDeAlquileres(listaAlquileres,tamAlquiler);

    printf("Ingrese Fecha:\n");
    validarDay=getEntero(&auxDay,"Dia: ","Error! ReIngrese Dia[1-31]: ",1,31);
    validarMounth=getEntero(&auxMounth,"Mes: ","Error! ReIngrese Mes [1-12]: ",1,12);
    validarYear=getEntero(&auxYear,"Anio: ","Error! ReIngrese Anio[1970-2018]: ",1970,2018);
    if(validarDay!=0 && validarMounth!=0 && validarYear!=0)
    {
        printf("Fecha: %02d/%02d/%4d\n",auxDay,auxMounth,auxYear);

    }
    idBuscado=buscarFechaAlquiler(listaAlquileres,tamAlquiler,auxDay,auxMounth,auxYear);
    estaLibre=listaJuegos[idBuscado].isEmpty;

    if(estaLibre!=OCUPADO)
    {
        printf("La Fecha Ingresada No se encuentra en la Lista\n");
    }
    else
    {
        printf("\nID_ALQUILER\tFECHA\t   ID_JUEGO\tNOMBRE\t   PRECIO\n\n");
        for(i=0; i<tamJuegos; i++ )
        {
            if(listaAlquileres[i].fecha.dia == auxDay && listaAlquileres[i].fecha.mes==auxMounth && listaAlquileres[i].fecha.anio==auxYear)//(listaJuegos[i].id==idBuscado)
            {
                for(j=0; j<tamJuegos; j++)
                {
                    if(listaAlquileres[i].idJuego==listaJuegos[j].id)
                    {
                        if(listaAlquileres[j].isEmpty==OCUPADO)
                        {
                            printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%.2f\n",listaAlquileres[i].idAlquiler,listaAlquileres[i].fecha.dia,listaAlquileres[i].fecha.mes,listaAlquileres[i].fecha.anio,listaJuegos[j].id,listaJuegos[i].descripcion,listaJuegos[i].importe);
                        }
                    }
                }
            }
        }
    }

}

void mostrarListaDeClientesxFechaDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes)
{
    int i,j;
    int idBuscado;
    int estaLibre;

    int auxDay;
    int auxMounth;
    int auxYear;

    int validarDay;
    int validarMounth;
    int validarYear;

    listadoDeAlquileres(listaAlquileres,tamAlquiler);

    printf("Ingrese Fecha:\n");
    validarDay=getEntero(&auxDay,"Dia: ","Error! ReIngrese Dia[1-31]: ",1,31);
    validarMounth=getEntero(&auxMounth,"Mes: ","Error! ReIngrese Mes [1-12]: ",1,12);
    validarYear=getEntero(&auxYear,"Anio: ","Error! ReIngrese Anio[1970-2018]: ",1970,2018);
    if(validarDay!=0 && validarMounth!=0 && validarYear!=0)
    {
        printf("Fecha: %02d/%02d/%4d\n",auxDay,auxMounth,auxYear);

    }
    idBuscado=buscarFechaAlquiler(listaAlquileres,tamAlquiler,auxDay,auxMounth,auxYear);
    estaLibre=listaClientes[idBuscado].isEmpty;

    if(estaLibre!=OCUPADO)
    {
        printf("La Fecha Ingresada No se encuentra en la Lista\n");
    }
    else
    {
        printf("\nID_ALQUILER\tFECHA\t   ID_CLIENTE\tNOMBRE\t   APELLIDO\n\n");
        for(i=0; i<tamClientes; i++ )
        {
            if(listaAlquileres[i].fecha.dia == auxDay && listaAlquileres[i].fecha.mes==auxMounth && listaAlquileres[i].fecha.anio==auxYear)//(listaJuegos[i].id==idBuscado)
            {
                for(j=0; j<tamClientes; j++)
                {
                    if(listaAlquileres[i].idCliente==listaClientes[j].id)
                    {
                        if(listaAlquileres[j].isEmpty==OCUPADO)
                        {
                            printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%s\n",listaAlquileres[i].idAlquiler,listaAlquileres[i].fecha.dia,listaAlquileres[i].fecha.mes,listaAlquileres[i].fecha.anio,listaClientes[j].id,listaClientes[i].nombre,listaClientes[i].apellido);
                        }
                    }
                }
            }
        }
    }
}

int cantidadDeAlquileresPorJuego(eAlquileres listaAlquileres[],int tamAlquiler,int idJuego)
{
    int contadorAlquiler=0;
    int i;

    for(i=0; i<tamAlquiler; i++)
    {
        if(listaAlquileres[i].isEmpty==OCUPADO && listaAlquileres[i].idJuego==idJuego)
        {
            contadorAlquiler++;
        }
    }
    return contadorAlquiler;
}

int minimaCantidadDeJuegos (eAlquileres listaAlquileres[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos)
{
    int minimo;
    int i,j;
    int cantidadJuegos;

    for (j=0; j<tamJuegos; j++)
    {
        if(listaJuegos[j].isEmpty==OCUPADO)
        {
            for(i=0; i<tamAlquiler; i++)
            {
                if(listaAlquileres[i].isEmpty==OCUPADO)
                {
                    cantidadJuegos=cantidadDeAlquileresPorJuego(listaAlquileres,tamAlquiler,listaAlquileres[i].idJuego);
                    if(i==0)//el primero el mayor y menor
                    {
                        minimo=cantidadJuegos;
                    }
                    else
                    {
                        if(cantidadJuegos<minimo )
                        {
                            minimo=cantidadJuegos;
                        }
                    }
                }
            }
        }
    }
    return minimo;
}

void mostrarListaJuegosMenosAlquilados(eAlquileres listaAlquiler[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos)
{
    int i,j;
    int cantidadMinimaJuegos;
    int cantidadJuegosDeAlquileres;

    printf("\nID_ALQUILER\tFECHA\t   ID_JUEGO\tNOMBRE\t   PRECIO\n\n");
    for (j=0; j<tamJuegos; j++)
    {
        if(listaJuegos[j].isEmpty==OCUPADO)
        {
            for(i=0; i<tamAlquiler; i++)
            {
                if(listaAlquiler[i].isEmpty==OCUPADO)
                {
                    if(listaAlquiler[i].idJuego==listaJuegos[j].id)
                    {
                        cantidadJuegosDeAlquileres=cantidadDeAlquileresPorJuego(listaAlquiler,tamAlquiler,listaAlquiler[i].idJuego);
                        cantidadMinimaJuegos=minimaCantidadDeJuegos(listaAlquiler,tamAlquiler,listaJuegos,tamJuegos);
                        if(cantidadJuegosDeAlquileres==cantidadMinimaJuegos)
                        {
                            printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%.2f\n",listaAlquiler[i].idAlquiler,listaAlquiler[i].fecha.dia,listaAlquiler[i].fecha.mes,listaAlquiler[i].fecha.anio,listaAlquiler[i].idJuego,listaJuegos[j].descripcion,listaJuegos[j].importe);
                        }
                    }
                }
            }
        }
    }
}

int cantidadDeAlquileresPorClientes(eAlquileres listaAlquileres[],int tamAlquiler,int idCliente)
{
    int contadorAlquiler=0;
    int i;

    for(i=0; i<tamAlquiler; i++)
    {
        if(listaAlquileres[i].isEmpty==OCUPADO && listaAlquileres[i].idCliente==idCliente)
        {
            contadorAlquiler++;
        }
    }
    return contadorAlquiler;
}

int maximaCantidadClientesDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes)
{
    int maximo;
    int i,j;
    int cantidadClientes;

    for (j=0; j<tamClientes; j++)
    {
        if(listaClientes[j].isEmpty==OCUPADO)
        {
            for(i=0; i<tamAlquiler; i++)
            {
                if(listaAlquileres[i].isEmpty==OCUPADO)
                {
                    cantidadClientes=cantidadDeAlquileresPorClientes(listaAlquileres,tamAlquiler,listaAlquileres[i].idCliente);
                    if(i==0)//el primero el mayor y menor
                    {
                        maximo=cantidadClientes;
                    }
                    else
                    {
                        if(cantidadClientes>maximo )
                        {
                            maximo=cantidadClientes;
                        }
                    }
                }
            }
        }
    }
    return maximo;
}

void mostrarListaClientesConMasAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes)
{
    int i,j;
    int cantidadMaximaClientes;
    int cantidadClientesDeAlquileres;

    printf("\nID_ALQUILER\tFECHA\t   ID_CLIENTE\tNOMBRE\t   APELLIDO\n\n");
    for(i=0; i<tamAlquiler; i++ )
    {
        if(listaAlquileres[i].isEmpty==OCUPADO)
        {
            for(j=0; j<tamClientes; j++)
            {
                if(listaAlquileres[j].isEmpty==OCUPADO && listaAlquileres[i].idCliente==listaClientes[j].id)
                {
                    cantidadMaximaClientes=maximaCantidadClientesDeAlquileres(listaAlquileres,tamAlquiler,listaClientes,tamClientes);
                    cantidadClientesDeAlquileres=cantidadDeAlquileresPorClientes(listaAlquileres,tamAlquiler,listaAlquileres[i].idCliente);
                    if(cantidadClientesDeAlquileres==cantidadMaximaClientes)
                    {

                        printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%s\n",listaAlquileres[i].idAlquiler,listaAlquileres[i].fecha.dia,listaAlquileres[i].fecha.mes,listaAlquileres[i].fecha.anio,listaClientes[j].id,listaClientes[j].nombre,listaClientes[j].apellido);
                    }
                }
            }
        }
    }
}
