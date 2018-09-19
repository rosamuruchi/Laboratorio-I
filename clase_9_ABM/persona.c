#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "persona.h"

#define OCUPADO 0
#define LIBRE 1

void init(EPersona lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpty = LIBRE;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[], long int dni,int len)
{
    int i;
    int index=-1;
    for(i=0; i<len; i++)
    {
        if(lista[i].dni==dni)
        {
            index=i;
            break;
        }
    }
    return index;
}


void alta(EPersona lista[], int len)
{
    int index;
    int i;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1)
    {
        //hay espacio libre
        for(i=0; i<len; i++)
        {
            if(lista[i].isEmpty==1)
            {
                printf("Ingrese Nombre:");
                fflush(stdin);
                gets(lista[i].nombre);

                printf("Ingrese Apellido:");
                fflush(stdin);
                gets(lista[i].apellido);

                printf("Ingrese su dni:");
                scanf("%ld",&lista[i].dni);

                printf("Ingrese Fecha de Nacimiento:\n");
                printf("Dia:");
                scanf("%d",&lista[i].feNac.dia);
                printf("Mes:");
                scanf("%d",&lista[i].feNac.mes);
                printf("Anio:");
                scanf("%d",&lista[i].feNac.anio);

                lista[i].isEmpty=OCUPADO;
                break;
            }
        }
    }
    else
    {
        printf("No hay Espacio Libre!");
        //no hay espacio libre
    }
    return;
}

void baja(EPersona lista[], int len)
{
    int auxDni;
    int dnibuscado;
    int i;
    char respuesta;

    mostrarListaPersonas(lista,len);
    printf("\nIngrese el DNI para dar de Baja:");
    scanf("%d",&auxDni);
    dnibuscado=buscarPorDni(lista,auxDni,len);

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            if(dnibuscado == -1)
            {
                printf("\nEl dni NO corresponde a la lista\n");
            }
            else
            {
                printf("El dni corresponde a: %s  %s\n\n",lista[dnibuscado].nombre,lista[dnibuscado].apellido);
                printf("Continuar s/n:");
                respuesta=getche();

                if(respuesta== 's')
                {
                    lista[dnibuscado].isEmpty=LIBRE;
                    printf("\nPersona Eliminada\n");
                    break;
                }
                else if(respuesta == 'n')
                {
                    printf("\nPersona Cancelada\n");
                    break;
                }
                else
                {
                    printf("\nPor favor Ingresar s/n!\n");
                    break;
                }
            }
        }
        else
        {
            printf("\nEl dni no Existe!\n");
            break;
        }
    }

}

void mostrarListaDeUnaPersona (EPersona lista)
{
    printf("\n%s\t %s\t    %ld\t %02d/%02d/%4d\n", lista.nombre,lista.apellido,lista.dni,lista.feNac.dia,lista.feNac.mes,lista.feNac.anio);
}

void mostrarListaPersonas (EPersona lista[], int len)
{
    int i;
    printf("\nNOMBRE\t APELLIDO\t DNI\t FECHA DE NACIMIENTO\n");
    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrarListaDeUnaPersona(lista[i]);
        }
    }

}

void modificacion(EPersona lista[], int len)
{
    int auxDni;
    int dnibuscado;
    char respuesta;
    int opcion=0;

    mostrarListaPersonas(lista,len);
    printf("Ingrese el DNI para Modificar Persona:");
    scanf("%d",&auxDni);

    dnibuscado=buscarPorDni(lista,auxDni,len);

    if(dnibuscado == -1)
    {
        printf("El dni NO corresponde a la lista\n");
    }
    else
    {
        if(lista[dnibuscado].isEmpty==OCUPADO)
        {

            printf("El dni corresponde a: %s  %s\n\n",lista[dnibuscado].nombre,lista[dnibuscado].apellido);

            do{
                printf("Continuar s/n:");
                respuesta=getche();
                respuesta = tolower(respuesta);
            }while(respuesta != 's' && respuesta != 'n' );


            if(respuesta== 's')
            {
                do
                {
                    printf("Ingrese que desea modificar: \n1.Nombre \n2.Apellido \n3.Dni \n4.Fecha de Nacimiento \n5.Cancelar");
                    scanf("%d",&opcion);
                    switch (opcion)
                    {
                    case 1:
                        printf("Ingrese Nombre:");
                        fflush(stdin);
                        gets(lista[dnibuscado].nombre);
                        break;
                    case 2:
                        printf("Ingrese Apellido:");
                        fflush(stdin);
                        gets(lista[dnibuscado].apellido);
                        break;
                    case 3:
                        printf("Ingrese su dni:");
                        scanf("%ld",&lista[dnibuscado].dni);
                        break;
                    case 4:
                        printf("Ingrese Fecha de Nacimiento:\n");
                        printf("Dia:");
                        scanf("%d",&lista[dnibuscado].feNac.dia);
                        printf("Mes:");
                        scanf("%d",&lista[dnibuscado].feNac.mes);
                        printf("Anio:");
                        scanf("%d",&lista[dnibuscado].feNac.anio);
                        break;
                    case 5:
                        break;
                    default:
                        printf("Opcion incorrecta...");
                    }
                }while(opcion != 5);

                printf("\nPersona Modificada\n");
            }
            else
            {
                printf("\nPersona Cancelada\n");
            }
        }
    }
}


void ordenamientoDeLista (EPersona lista[], int len)
{
    int i,j;
    for(i=0;i<len-1;i++)
    {
        for(j=i+1; j<len; j++)
        {
            if()
        }
    }
}

