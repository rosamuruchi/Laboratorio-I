#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "autos.h"
#include "funciones.h"

#define LIBRE 1
#define OCUPADO 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

void inicializarListaAutos(EAutos lista[],int limite)
{
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            lista[i].estadoAuto= LIBRE;
            lista[i].idAuto= 0;
        }
    }
}


void inicializarAutosHardCode(EAutos lista[], int limite)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        lista[i].idAuto=id[i];
        strcpy(lista[i].patente,patente[i]);
        lista[i].marca=marca[i];
        lista[i].propietario=propietario[i];
        lista[i].estadoAuto=OCUPADO;
    }
}

void mostrarListaAutos(EAutos listaAutos [],int limiteAutos, EPropietario listaProp [], int limiteProp)
{
    int i;
    int j;
    char marcas[][50]= {"ALPHA_ROMEO","FERRARI","AUDI","OTRO"};
    int nombreMarca;
    printf(" ID   PATENTE    MARCA     PROPIETARIO \n");
    printf("----------------------------------------\n\n");

    for(i=0; i<limiteAutos; i++)
    {
        for(j=0; j<limiteProp; j++)
        {
            if(listaAutos[i].propietario==listaProp[j].idPropietario)
            {
                if(listaAutos[i].estadoAuto==OCUPADO)
                {
                    nombreMarca=(listaAutos[i].marca -1);
                    printf("\t %d    %s      %s       %s  \n",listaAutos[i].idAuto,listaAutos[i].patente,marcas[nombreMarca],listaProp[j].nombre);
                }

            }
        }
    }
}

int buscarLugarLibreAuto(EAutos lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;


        for(i=0; i<limite; i++)
        {
            if(lista[i].estadoAuto == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteIdAutos(EAutos lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estadoAuto == OCUPADO)
            {
                if(lista[i].idAuto>retorno)
                {
                    retorno=lista[i].idAuto;
                }

            }
        }
    }

    return retorno+1;
}

void ingresoDeAutomovil(EAutos lista[],int limite)
{
    int auxId;

    auxId=buscarLugarLibreAuto(lista,limite);

    if(auxId>=0)
    {
        printf("\nIngrese Patente: ");
        fflush(stdin);
        gets(lista[auxId].patente);

        printf("\nIngrese Numero de marca: ");
        printf("\n1_ALPHA ROMEO\n2_FERRARI\n3_AUDI\n4_OTRO\n\n");
        scanf("%d",&lista[auxId].marca);

        printf("Ingresar Id del Propietario: ");
        scanf("%d",&lista[auxId].propietario);

        lista[auxId].idAuto=siguienteIdAutos(lista,limite);
        lista[auxId].estadoAuto=OCUPADO;
    }
    else
    {
        printf("NO HAY ESPACIO!\n");
    }

}
