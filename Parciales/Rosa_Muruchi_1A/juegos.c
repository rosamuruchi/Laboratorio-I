#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "juegos.h"
#include "utn.h"
#include "clientes.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarJuegos( eJuegos x[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = LIBRE;
        x[i].id=0;
    }
}
int buscarLibreJuegos( eJuegos x[], int tam)
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

int buscarIdJuegos(eJuegos x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( x[i].id == id && x[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int nextIdJuegos (eJuegos lista[], int len)
{
    int retorno = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(lista[i].id>retorno)
            {
                retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}

int addJuegos(eJuegos lista[], int len, int id, char descripcion[],float importe)
{
    int returnAux= -1;
    int libre;
    int siguienteId;
    libre=buscarLibreJuegos(lista,len);
    siguienteId=nextIdJuegos(lista,id);

    lista[libre].id = siguienteId;
    strcpy(lista[libre].descripcion,descripcion);
    lista[libre].importe = importe;
    lista[libre].isEmpty = OCUPADO;
    returnAux = 0;

    return returnAux;
}

void harcodearJuegos(eJuegos x[])
{
    int i;
    eJuegos y[]=
    {
        {1, "Solitario", 1, 15.50},
        {2, "Preguntados", 1, 25.00},
        {3, "Puzzle", 1, 10.99},
        {4, "CandyCrush", 1, 30.25},
        {5, "Sonic", 1, 25},
    };
    for(i=0; i<5; i++)
    {
        x[i] = y[i];
    }
}

void listadoDeJuegos(eJuegos lista[], int length)
{
    int i;
    printf("\n-------------------------------------------\n");
    printf("ID_JUEGO\tDESCRIPCION\tIMPORTE\n");
    printf("\n-------------------------------------------\n");
    for(i=0; i<length; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            printf("%d\t%s\t\t%.2f\n",lista[i].id,lista[i].descripcion,lista[i].importe);
        }
    }
}

int altaJuegos(eJuegos lista[],int tam)
{
    int retorno=-1;
    int indice;
    int agregarjuego;

    int validarDescripcion;
    int validarImporte;
    int validarId;
    char auxiliarNombre[50];
    float auxiliarImporte;
    int auxiliarId;
    int juegoBuscado;

    indice = buscarLibreJuegos(lista, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        listadoDeJuegos(lista,tam);
        validarId=getEntero(&auxiliarId,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
        if(validarId!=0)
        {
            printf("ID: %d\n",auxiliarId);
        }
        juegoBuscado= buscarIdJuegos(lista,tam,auxiliarId);
        if(juegoBuscado != -1)
        {
            printf("Existe un Juego con el ID %d\n", auxiliarId);
        }
        else
        {

            validarDescripcion= getStringAlfaNumerico(auxiliarNombre,"Ingrese Descripcion:","ERROR! Reingrese su Nombre:");
            validarImporte= getFlotante(&auxiliarImporte,"Ingrese Importe: ","ERROR! Reingrese su Importe:");

            if(validarDescripcion == 0)
            {
                printf("NOMBRE: %s\n",auxiliarNombre);
            }
            if(validarImporte != 0)
            {
                printf("IMPORTE: %.2f\n\n",auxiliarImporte);
            }

            agregarjuego=addJuegos(lista,tam,indice,auxiliarNombre,auxiliarImporte);
            if(agregarjuego== -1)
            {
                printf("No se pudo Cargar el juego!\n");
            }
            else
            {
                retorno=0;
                printf("Juego Cargado!\n");
            }
        }
    }
    return retorno;
}

void modificarJuegos(eJuegos lista[], int len)
{

    int auxiliarId;
    int juegoBuscado;
    char respuesta;
    int opcion;

    int validarDescripcion;
    int validarImporte;
    char auxiliarDescripcion[50];
    float auxiliarImporte;


    listadoDeJuegos(lista,len);

    printf("Ingrese Id: ");
    fflush(stdin);
    scanf("%d", &auxiliarId);

    juegoBuscado = buscarIdJuegos(lista,len,auxiliarId);

    if( juegoBuscado == -1)
    {
        printf("No hay ningun Cliente con el ID %d\n", auxiliarId);
    }
    else
    {
        printf("El Id corresponde a : %s", lista[juegoBuscado].descripcion);
        printf("\nModificar?s/n: ");
        respuesta=tolower(getche());
        if(respuesta== 's')
        {
            printf("\nIngrese que desea modificar:\n1.DESCRIPCION\n2.IMPORTE\n3.Cancelar\nOpcion:");
            fflush(stdin);
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                validarDescripcion= getString(auxiliarDescripcion,"Ingrese Name:","ERROR! Reingrese:");
                if(validarDescripcion != 0)
                {
                    strcpy(lista[juegoBuscado].descripcion,auxiliarDescripcion);
                    printf("NAME: %s\n",auxiliarDescripcion);
                }
                break;
            case 2:
                validarImporte= getFlotante(&auxiliarImporte,"Ingrese Importe: ","ERROR! Reingrese su Importe:");
                if(validarImporte != 0)
                {
                    lista[juegoBuscado].importe = auxiliarImporte;
                    printf("Importe: %.2f\n",auxiliarImporte);
                }
                break;
            case 3:
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

int removeJuegos(eJuegos lista[], int len, int id)
{
    int retorno= -1;
    int indice;

    indice = buscarIdJuegos(lista,len,id);
    if( indice == -1)
    {
        printf("No hay ningun JUEGO con el Id: %d\n", id);
    }
    else
    {
        lista[indice].isEmpty = LIBRE;
        retorno=0;
    }
    return retorno;
}

int BajaJuegos(eJuegos lista[], int len)
{
    int retorno=-1;
    char borrar;
    int indice;
    int auxiliarId;
    int juegoBorrado;

    listadoDeJuegos(lista,len);

    printf("Ingrese Id Del JUEGO: ");
    fflush(stdin);
    scanf("%d", &auxiliarId);

    indice = buscarIdJuegos(lista,len,auxiliarId);

    if( indice == -1)
    {
        printf("No hay ningun Juego con el Id: %d\n", auxiliarId);
    }
    else
    {
        printf("El Juego corresponde a: %s\n",lista[indice].descripcion);

        printf("\nConfirma borrado?[s/n]: ");
        fflush(stdin);
        borrar=tolower(getche());
        if(borrar == 'n')
        {
            printf("\nBorrado cancelado\n\n");
        }
        else if(borrar == 's')
        {
            juegoBorrado=removeJuegos(lista,len,auxiliarId);
            if(juegoBorrado==0)
            {
                printf("\nSe ha eliminado el Juego\n\n");
                retorno=0;
            }
            else
            {
                printf("\nNo se ha podido borrar el juego\n\n");
            }
        }
    }
    return retorno;
}

void ordenarJuegos(eJuegos lista[], int len)
{
    eJuegos Auxjuegos;
    int j;
    int flagNoestaOrdenado=1;

    while (flagNoestaOrdenado==1)
    {
        flagNoestaOrdenado=0;
        for (j = 1; j < len; j++)
        {
            if (lista[j].importe < lista[j - 1].importe)
            {
                Auxjuegos = lista[j];
                lista[j] = lista[j - 1];
                lista[j - 1] = Auxjuegos;
                flagNoestaOrdenado = 1;
            }
            else if(strcmp(lista[j].descripcion,lista[j-1].descripcion)>0 && lista[j].importe == lista[j-1].importe)
            {
                Auxjuegos = lista[j];
                lista[j] = lista[j - 1];
                lista[j - 1] = Auxjuegos;
                flagNoestaOrdenado = 1;
            }
        }
    }
    printf("-------------------------------------------------\n");
    printf("\nLISTA ORDENADA POR IMPORTE asc Y DESCRIPCION desc\n");
    listadoDeJuegos(lista,len);
}








