#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"
#include "autos.h"
#include "egresos.h"

#define LIBRE 1
#define OCUPADO 0

void inicializarListaPropietario(EPropietario lista[],int limite)
{

    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            lista[i].estado= LIBRE;
            lista[i].idPropietario= 0;
        }
    }
}



void inicializarPropietariosHardCode(EPropietario lista[], int limite)
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    int i;

    for(i=0; i<4; i++)
    {
        lista[i].idPropietario=id[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].numeroTarjeta,tarjeta[i]);
        strcpy(lista[i].direccion,direccion[i]);
        lista[i].estado = OCUPADO;
    }
}


int buscarLugarLibre(EPropietario lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;


        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteId(EPropietario lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                if(lista[i].idPropietario>retorno)
                {
                    retorno=lista[i].idPropietario;
                }

            }
        }
    }

    return retorno+1;
}

int buscarPorId(EPropietario lista[],int limite, int auxId)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].idPropietario == auxId)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void altaDePropietario (EPropietario lista[], int limite)
{
    int auxId;
    int valor;

    mostrarListaPropietario(lista,limite);

    printf("Ingresar Id del Propietario: ");
    scanf("%d",&valor);

    auxId=buscarLugarLibre(lista,limite);

    if(auxId!=-1)
    {
        printf("\nIngrese un nombre del Propietario: ");
        fflush(stdin);
        gets(lista[auxId].nombre);

        printf("\nIngrese Direccion del Propietario: ");
        fflush(stdin);
        gets(lista[auxId].direccion);

        printf("Ingrese Numero de Tarejeta de Credito: ");
        fflush(stdin);
        gets(lista[auxId].numeroTarjeta);

        lista[auxId].idPropietario=siguienteId(lista,limite);
        lista[auxId].estado=OCUPADO;
    }
    else
    {
        printf("NO HAY ESPACIO!\n\n");
    }
    mostrarListaPropietario(lista,limite);

}
void mostrarListaPropietario(EPropietario lista[],int limite)
{

    int i;
    printf(" ID    NOMBRE     DIRECCION     TARJETA \n");

    for(i=0; i<limite; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            printf("\n %d     %s      %s        %s \n\n",lista[i].idPropietario,lista[i].nombre,lista[i].direccion,lista[i].numeroTarjeta);
        }
    }
}

void modificarDatos(EPropietario lista[], int limite)
{
    int valor;
    int auxId;
    char respuesta='s';

    EPropietario auxtarjeta;

    mostrarListaPropietario(lista,limite);

    printf("Ingrese el Id para modificar: ");
    scanf("%d",&valor);

    auxId= buscarPorId(lista,limite,valor);

    if(auxId == -1)
    {
        printf("Id INCORRECTO\n\n");
    }
    else
    {
        printf("El usuario de la Tarjeta es : %s ", lista[auxId].nombre);
        printf("\nresponder s/n : ");
        respuesta= getche();
        printf("\n");

        if(respuesta=='s')
        {
            printf("\nIngrese el nueva Tarjeta: ");
            fflush(stdin);
            gets(auxtarjeta.numeroTarjeta);

            strcpy(lista[auxId].numeroTarjeta,auxtarjeta.numeroTarjeta);

            system("cls");
            printf("Usuario Cargado con exito!\n");

            mostrarListaPropietario(lista,limite);
            getch();


        }
        else
        {
            printf("Tarjeta Cancelada!\n\n");
        }

    }

}

void bajaPropietario (EPropietario lista[], int limite)
{
    int valor;
    int auxId;
    char respuesta='s';

    mostrarListaPropietario(lista,limite);

    printf("\nIngrese el Id para dar de Baja: ");
    scanf("%d",&valor);

    auxId= buscarPorId(lista,limite,valor);


    if(auxId == -1)
    {
        printf("Id INCORRECTO\n");
    }
    else
    {
        printf("El usuario para dar de baja es : %s ", lista[auxId].nombre);
        printf("\nresponder s/n : ");
        respuesta= getche();
        printf("\n");

        if(respuesta=='s')
        {
            lista[auxId].estado=-1;
            system("cls");
            printf("Usuario Borrado con exito!\n\n");
        }
        else
        {
            printf("baja cancelada!\n");
        }
    }
    mostrarListaPropietario(lista,limite);
}
