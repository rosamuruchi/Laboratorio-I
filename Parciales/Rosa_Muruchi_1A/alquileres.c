#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "alquileres.h"
#include "juegos.h"
#include "utn.h"
#include "clientes.h"


#define LIBRE 0
#define OCUPADO 1

void inicializarAlquiler( eAlquileres x[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = LIBRE;
        x[i].idAlquiler=0;
        x[i].idCliente=0;
        x[i].idJuego=0;
    }
}
int buscarLibreAlquiler( eAlquileres x[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i< tam; i++)
    {
        if( x[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarIdAlquiler(eAlquileres x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( x[i].idAlquiler == id && x[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarFechaAlquiler(eAlquileres x[], int tam, int dia, int mes, int anio)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(x[i].isEmpty == OCUPADO)
        {
            if( x[i].fecha.dia == dia && x[i].fecha.mes==mes && x[i].fecha.anio==anio)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int nextIdAlquiler (eAlquileres lista[], int len)
{
    int retorno = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(lista[i].idAlquiler>retorno)
            {
                retorno=lista[i].idAlquiler;
            }
        }
    }
    return retorno+1;
}
int addAlquiler(eAlquileres lista[], int len, int idAlquiler,int idJuego,int idCliente, int dia, int mes, int anio)
{
    int returnAux= -1;
    int libre;
    int siguienteId;
    libre=buscarLibreAlquiler(lista,len);
    siguienteId=nextIdAlquiler(lista,idAlquiler);

    lista[libre].idAlquiler = siguienteId;
    lista[libre].idCliente= idCliente;
    lista[libre].idJuego= idJuego;
    lista[libre].fecha.dia=dia;
    lista[libre].fecha.mes=mes;
    lista[libre].fecha.anio=anio;
    lista[libre].isEmpty = OCUPADO;
    returnAux = 0;

    return returnAux;
}


void harcodearAlquileres(eAlquileres x[])
{
    int i;
    int idAlquileres[6]= {1,2,3,4,5,6};
    int idJuegos[6]= {2,4,2,4,3,2};
    int idcliente[6] = {100,101,103,100,102,104};
    int dia[6]= {1,1,3,4,5,7};
    int mes[6]= {10,10,4,7,8,6};
    int year[6]= {1980,1980,1999,2000,2010,2018};

    for(i=0; i<6; i++)
    {
        x[i].idAlquiler=idAlquileres[i];
        x[i].idJuego=idJuegos[i];
        x[i].idCliente=idcliente[i];
        x[i].fecha.dia=dia[i];
        x[i].fecha.mes=mes[i];
        x[i].fecha.anio=year[i];
        x[i].isEmpty=OCUPADO;
    }
}

void mostrarListaAlquileresxClientes(eAlquileres listaAlquiler[],int tamAlquiler,eClientes listaClientes[],int tamClientes)
{
    int i,j;
    int auxIdCliente;
    int auxId;
    int estaLibre;

    listadoDeClientes(listaClientes,tamClientes);
    printf("\nIngrese el Id del Cliente: ");
    fflush(stdin);
    scanf("%d",&auxId);

    auxIdCliente=buscarIdClientes(listaClientes,tamClientes,auxId);
    estaLibre=listaClientes[auxIdCliente].isEmpty;

    if(estaLibre!=OCUPADO)
    {
        printf("Id No se encuentra en la Lista\n");
    }
    else
    {
        printf("\nID_ALQUILER\tFECHA\tID_CLIENTE\tAPELLIDO\tNOMBRE\n\n");
        for(i=0; i<tamClientes; i++ )
        {
            if(listaClientes[i].id==auxId)
            {
                for(j=0; j<tamClientes; j++)
                {
                    if(listaClientes[auxIdCliente].id==listaAlquiler[j].idCliente)
                    {
                        if(listaAlquiler[j].isEmpty==OCUPADO)
                        {
                            printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%s\n",listaAlquiler[j].idAlquiler,listaAlquiler[j].fecha.dia,listaAlquiler[j].fecha.mes,listaAlquiler[j].fecha.anio,listaClientes[auxIdCliente].id,listaClientes[auxIdCliente].apellido,listaClientes[auxIdCliente].nombre);
                            // printf("%d\v%02d/%02d/%4d\v%d\v%s\v%s\n",listaAlquiler[j].idAlquiler,listaAlquiler[j].fecha.dia,listaAlquiler[j].fecha.mes,listaAlquiler[j].fecha.anio,listaClientes[auxIdCliente].id,listaClientes[auxIdCliente].apellido,listaClientes[auxIdCliente].nombre);
                        }
                    }
                }
            }
        }
    }

}

void mostrarListaAlquileresxJuegos(eAlquileres listaAlquiler[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos)
{
    int i,j;
    int auxIdJuego;
    int auxId;
    int estaLibre;

    listadoDeJuegos(listaJuegos,tamJuegos);
    printf("\nIngrese el Id del Juego: ");
    fflush(stdin);
    scanf("%d",&auxId);

    auxIdJuego=buscarIdJuegos(listaJuegos,tamJuegos,auxId);
    estaLibre=listaJuegos[auxIdJuego].isEmpty;

    if(estaLibre!=OCUPADO)
    {
        printf("Id No se encuentra en la Lista\n");
    }
    else
    {
        printf("\nID_ALQUILER\tFECHA\t   ID_JUEGO\tNOMBRE\t   PRECIO\n\n");
        for(i=0; i<tamJuegos; i++ )
        {
            if(listaJuegos[i].id==auxId)
            {
                for(j=0; j<tamJuegos; j++)
                {
                    if(listaJuegos[auxIdJuego].id==listaJuegos[j].id)
                    {
                        if(listaAlquiler[j].isEmpty==OCUPADO)
                        {
                            printf("%d\t\t%02d/%02d/%4d\t%d\t%s\t%.2f\n",listaAlquiler[j].idAlquiler,listaAlquiler[j].fecha.dia,listaAlquiler[j].fecha.mes,listaAlquiler[j].fecha.anio,listaJuegos[auxIdJuego].id,listaJuegos[auxIdJuego].descripcion,listaJuegos[auxIdJuego].importe);
                        }
                    }
                }
            }
        }
    }
}

void listadoDeAlquileres(eAlquileres listaAlquileres[], int tamAlquiler)
{
    int i;
    printf("\n------------------------------------------------\n");
    printf("\n\t LISTADO DE ALQUILERES \n");
    printf("\n------------------------------------------------\n");
    printf("ID_ALQUILER\tFECHA\tID_CLIENTE\tID_JUEGO\n");
    printf("------------------------------------------------\n");
    for(i=0; i<tamAlquiler; i++)
    {
        if(listaAlquileres[i].isEmpty==OCUPADO)
        {
            printf("%d\t\t%02d/%02d/%4d\t%d\t%d\n\n",listaAlquileres[i].idAlquiler,listaAlquileres[i].fecha.dia,listaAlquileres[i].fecha.mes,listaAlquileres[i].fecha.anio,listaAlquileres[i].idCliente,listaAlquileres[i].idJuego);

        }
    }
}

void altaAlquileres (eAlquileres listaAlquileres[], int tamAlquiler, eJuegos listaJuegos[],int tamJuegos, eClientes listaClientes[],int tamClientes)
{
    int indexLibre;
    int idAlquiler;
    int idJuego;
    int idCliente;

    char respuesta;
    int idBuscado;
    int idClienteBuscado;
    int validarId;
    int validarJuego;
    int validarCliente;
    int agregarAlquiler;

    int auxDay;
    int auxMounth;
    int auxYear;
    int validarDay;
    int validarMounth;
    int validarYear;

    indexLibre=buscarLibreAlquiler(listaAlquileres,tamAlquiler);

    if(indexLibre== -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        listadoDeAlquileres(listaAlquileres,tamAlquiler);
        validarId=getEntero(&idAlquiler,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
        if(validarId!=0)
        {
            printf("ID Alquiler : %d\n\n",idAlquiler);

        }
        listadoDeJuegos(listaJuegos,tamJuegos);
        validarJuego=getEntero(&idJuego,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
        if(validarJuego!=0)
        {
            printf("ID Juego: %d\n",idJuego);
        }
        idBuscado=buscarIdJuegos(listaJuegos,tamJuegos,idJuego);
        if(idBuscado != -1)
        {
            printf("Nombre del Juego: %s\nSeguir? s/n: ",listaJuegos[idBuscado].descripcion);
            respuesta= tolower(getche());
            printf("\n\n");
            if(respuesta=='s')
            {
                listadoDeClientes(listaClientes,tamClientes);
                validarCliente=getEntero(&idCliente,"Ingrese Id del Cliente:","ERROR! Reingrese Id:",0,9999);
                if(validarCliente!=0)
                {
                    printf("ID Cliente: %d\n",idCliente);
                }
                idClienteBuscado=buscarIdClientes(listaClientes,tamClientes,idCliente);
                if(idClienteBuscado != -1)
                {
                    printf("Apellido y Nombre del Cliente: %s   %s\n\nSeguir? s/n:",listaClientes[idClienteBuscado].apellido,listaClientes[idClienteBuscado].nombre);
                    respuesta= tolower(getche());
                    printf("\n\n");
                    if(respuesta=='s')
                    {
                        printf("Ingrese Fecha:\n");
                        validarDay=getEntero(&auxDay,"Dia: ","Error! ReIngrese Dia[1-31]: ",1,31);
                        validarMounth=getEntero(&auxMounth,"Mes: ","Error! ReIngrese Mes [1-12]: ",1,12);
                        validarYear=getEntero(&auxYear,"Anio: ","Error! ReIngrese Anio[1970-2018]: ",1970,2018);
                        if(validarDay!=0 && validarMounth!=0 && validarYear!=0)
                        {
                            printf("Fecha: %02d/%02d/%4d\n",auxDay,auxMounth,auxYear);
                        }
                        agregarAlquiler=addAlquiler(listaAlquileres,tamAlquiler,indexLibre,idJuego,idCliente,auxDay,auxMounth,auxYear);
                        if(agregarAlquiler== -1)
                        {
                            printf("No se pudo Cargar el Alquiler!\n");
                        }
                        else
                        {
                            printf("Alquiler Cargado!\n");
                        }
                    }
                    else
                    {
                        printf("Alquiler Cancelado!\n\n");
                    }
                }
                else
                {
                    printf("No se encontro ningun Id!\n\n");
                }
            }
            else
            {
                printf("Alquiler Cancelado!\n\n");
            }
        }
        else
        {
            printf("No se encontro Codigo del Juego!\n\n");
        }
    }
}

void modificarAlquileres(eAlquileres listaAlquileres [], int tam)
{
    int opcion;
    int idBuscado;
    int idAlquiler;
    int idJuego;
    int idCliente;

    char respuesta;
    int validarId;
    int validarJuego;
    int validarCliente;

    int auxDay;
    int auxMounth;
    int auxYear;
    int validarDay;
    int validarMounth;
    int validarYear;

    listadoDeAlquileres(listaAlquileres,tam);
    printf("Ingrese Id: ");
    fflush(stdin);
    scanf("%d", &idAlquiler);

    idBuscado=buscarIdAlquiler(listaAlquileres,tam,idAlquiler);
    if( idBuscado == -1)
    {
        printf("No hay ningun Alquiler con el ID: %d\n", idAlquiler);
    }
    else
    {
        printf("El Id corresponde al Cliente con Id : %d", listaAlquileres[idBuscado].idCliente);
        printf("\nModificar?s/n: ");
        respuesta=tolower(getche());
        if(respuesta== 's')
        {
            printf("\nIngrese que desea modificar:\n1.ID Alquiler\n2.ID cliente\n3.ID juego\n4.Fecha\n5.Cancelar\nOpcion:");
            fflush(stdin);
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                validarId=getEntero(&idAlquiler,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
                if(validarId!=0)
                {
                    listaAlquileres[idBuscado].idAlquiler=idAlquiler;
                    printf("ID Alquiler : %d\n\n",idAlquiler);
                }
                break;
            case 2:
                validarJuego=getEntero(&idJuego,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
                if(validarJuego!=0)
                {
                    listaAlquileres[idBuscado].idJuego=idJuego;
                    printf("ID Juego: %d\n",idJuego);
                }
                break;
            case 3:
                validarCliente=getEntero(&idCliente,"Ingrese Id del Cliente:","ERROR! Reingrese Id:",0,9999);
                if(validarCliente!=0)
                {
                    listaAlquileres[idBuscado].idCliente=idCliente;
                    printf("ID Cliente: %d\n",idCliente);
                }
                break;
            case 4:
                printf("Ingrese Fecha:\n");
                validarDay=getEntero(&auxDay,"Dia: ","Error! ReIngrese Dia[1-31]: ",1,31);
                validarMounth=getEntero(&auxMounth,"Mes: ","Error! ReIngrese Mes [1-12]: ",1,12);
                validarYear=getEntero(&auxYear,"Anio: ","Error! ReIngrese Anio[1970-2018]: ",1970,2018);
                if(validarDay!=0 && validarMounth!=0 && validarYear!=0)
                {
                    listaAlquileres[idBuscado].fecha.dia=auxDay;
                    listaAlquileres[idBuscado].fecha.mes=auxMounth;
                    listaAlquileres[idBuscado].fecha.anio=auxYear;
                    printf("Fecha: %02d/%02d/%4d\n",auxDay,auxMounth,auxYear);
                }
                break;
            case 5:
                break;
            }
        }
        else if(respuesta == 'n')
        {
            printf("\nJuego Cancelado\n");
        }
        else
        {
            printf("\nPor favor Ingresar s/n!\n");
        }
    }
}

int removeAlquiler(eAlquileres lista[], int len, int id)
{
    int retorno= -1;
    int indice;

    indice = buscarIdAlquiler(lista,len,id);
    if( indice == -1)
    {
        printf("No hay ningun Alquiler con el Id: %d\n", id);
    }
    else
    {
        lista[indice].isEmpty = LIBRE;
        retorno=0;
    }
    return retorno;
}

void BajaAlquiler(eAlquileres lista[], int len)
{
    char borrar;
    int indice;
    int auxiliarId;
    int alquilerBorrado;

    listadoDeAlquileres(lista,len);

    printf("Ingrese Id Del Alquiler: ");
    fflush(stdin);
    scanf("%d", &auxiliarId);

    indice = buscarIdAlquiler(lista,len,auxiliarId);

    if( indice == -1)
    {
        printf("No hay ningun Alquiler con el Id: %d\n", auxiliarId);
    }
    else
    {
        printf("El Alquiler corresponde al Cliente: %d\n",lista[indice].idCliente);

        printf("\nConfirma borrado?[s/n]: ");
        fflush(stdin);
        borrar=tolower(getche());
        if(borrar == 'n')
        {
            printf("\nBorrado cancelado\n\n");
        }
        else if(borrar == 's')
        {
            alquilerBorrado=removeAlquiler(lista,len,auxiliarId);
            if(alquilerBorrado==0)
            {
                printf("\nSe ha eliminado el Alquiler\n\n");
            }
            else
            {
                printf("\nNo se ha podido borrar el Alquiler\n\n");
            }
        }
    }
}
