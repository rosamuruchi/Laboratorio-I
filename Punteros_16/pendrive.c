#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pendrive.h"
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarLista(ePendrive *pen,int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        (pen+i)->estado=LIBRE;
        (pen+i)->codigo= 0;
    }
}

int menu()
{
    int opcion;
    printf("1.Cargar Pendrive\n");
    printf("2.Mostrar Pendrive\n");
    printf("3.Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int buscarLibre(ePendrive *pen,int cantidad)
{
    int index = -1;
    int i;
    if(cantidad > 0 && pen != NULL)
    {
        index = -2;
        for(i=0 ; i<cantidad ; i++)
        {
            if((pen+i)->estado == LIBRE)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int siguienteId(ePendrive *pen,int limite)
{
   /* int retorno = 0;
    int i;
    if(limite > 0 && pen != NULL)
    {
        for(i=0; i<limite; i++)
        {        printf("No se pudo abrir fichero!\n");

            if((pen+i)->estado == OCUPADO)
            {
                if((pen+i)->codigo>retorno)
                {
                    retorno=(pen+i)->id;
                }

            }
        }
    }

    return retorno+1;*/
}


int cargarPendriveParam(ePendrive* pen, int codigo, char marca[], int capacidad, float precio)
{
    int returnAux=-1;
    if(pen!=NULL)
    {
        pen->codigo=codigo;
        strcpy(pen->marca,marca);
        pen->capacidad= capacidad;
        pen->precio =precio;
        returnAux = 0;
    }
    else
    {
        printf("Error!!\n");
    }
    return returnAux;
}

int cargarPendrive (ePendrive* pen)
{
    int index;
    int auxCodigo;
    char auxMarca[50];
    float auxPrecio;
    int auxCapacidad;

    int validacionCodigo;
    int validacionPrecio;
    int validacionMarca;
    int validacionCapacidad;
    int agregarPendrive;

    if(pen==NULL)
    {
        printf("No se pudo abrir fichero!\n");

    }
    else
    {
        validacionCodigo= getEntero(&auxCodigo,"Ingrese Codigo: ","ERROR! Reingrese Codigo: ",1,1000);
        validacionMarca= getString(auxMarca,"Ingrese Marca: ","ERROR! Reingrese Marca: ");
        validacionCapacidad= getEntero(&auxCapacidad,"Ingrese Capacidad: ","ERROR! Reingrese Capacidad: ",1,1000);
        validacionPrecio= getFlotante(&auxPrecio,"Ingrese Precio: ","ERROR! Reingrese Precio: ");
        /*printf("\n\nIngrese Codigo:");
        scanf("%d", &pen->codigo);

        printf("Ingrese Marca de Pendrive:");
        fflush(stdin);
        gets(pen->marca);

        printf("Ingrese Capacidad:");
        scanf("%d", &pen->capacidad);

        printf("Ingrese Precio:");
        scanf("%f", &pen->precio);*/

        if(validacionCodigo!=0 && validacionMarca!=0 && validacionCapacidad!=0 && validacionPrecio!=0)
        {
            printf("Ingreso Correcto!\n");
        }

        agregarPendrive=cargarPendriveParam(pen,auxCodigo,auxMarca,auxCapacidad,auxPrecio);
        if(agregarPendrive== -1)
        {
            printf("No se pudo Cargar el Empleado!\n");
        }
        else
        {
            index=1;
            printf("Empleado Cargado!\n");
        }
    }
    return index;
}

void mostrarPendrive(ePendrive* pen)
{
    if(pen==NULL)
    {
        printf("No se pudo abrir fichero!\n");

    }
    else
    {
        printf("CODIGO  MARCA  CAPACIDAD PRECIO\n\n");
        printf("%d\t%s\t%dGB\t%.2f\n",pen->codigo,pen->marca,pen->capacidad,pen->precio);

    }
}

 /*ePendrive* new_Pendrive()
 {

     ePendrive* nuevoPendrive;

     nuevoPendrive = (ePendrive*) malloc(sizeof(ePendrive));

     if(nuevoPendrive != NULL){
        nuevoPendrive->codigo = 0;
        strcpy(nuevoPendrive->marca, "");
       nuevoPendrive->capacidad = 0;
       nuevoPendrive->precio = 0;
     }

 return nuevoPendrive;

 }*/

