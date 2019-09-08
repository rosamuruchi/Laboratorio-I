#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define TAM 20

void inicializarLista(EPersona lista[],int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        lista[i].estado=0;
        lista[i].dni=0;
        lista[i].edad=0;
    }
}



int obtenerEspacioLibre(EPersona lista[],int cantidad)
{
    int index = -1;
    int i;
    if(cantidad > 0 && lista != NULL)
    {
        index = -2;
        for(i=0 ; i<cantidad ; i++)
        {
            if(lista[i].estado == 0)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int buscarPorDni(EPersona lista[],int cantidad, int dni)
{
    int i;
    int index=-1;

    for(i=0 ; i<cantidad ; i++)
    {
        if(lista[i].dni==dni)
        {
            return i;
        }
    }
    return index;
}



int esLetra (char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0;i<limite;i++)
    {
        index=isalpha(lista[i]);

        if (index==0)
        {
            break;
        }
    }
    return index;

}

int esEntero(char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0;i<limite;i++)
    {
        index=isdigit(lista[i]);

        if (index==0)
        {
            break;
        }
    }
    return index;
}


void cargarDatos (EPersona lista[],int tamano)
{
    int numeroUbicado;
    int longitudValidacion=0;
    int validacion=0;
    char auxiliar[50];



            numeroUbicado=obtenerEspacioLibre(lista,tamano);
            if(numeroUbicado != -1)
            {
                printf("\nIngrese el DNI: ");
                fflush(stdin);
                gets(auxiliar);
                validacion=esEntero(auxiliar);
                longitudValidacion=strlen(auxiliar);


                 while (validacion==0 || longitudValidacion!=8)
                {
                    printf("\nERROR! Reingrese el DNI nuevamente: ");
                    fflush(stdin);
                    gets(auxiliar);
                    validacion=esEntero(auxiliar);
                    longitudValidacion=strlen(auxiliar);


                }
                lista[numeroUbicado].dni=atoi(auxiliar);
                validacion=0;

                    printf("\nIngrese el nombre: ");
                    fflush(stdin);
                    gets(auxiliar);
                    validacion=esLetra(auxiliar);

                    while (validacion==0)
                    {
                        printf("\nERROR!!! Reingrese el nombre: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validacion=esLetra(auxiliar);
                    }
                    strcpy(lista[numeroUbicado].nombre,auxiliar);

                    validacion=0;

                    printf("\nIngrese edad: ");
                    fflush(stdin);
                    gets(auxiliar);
                    validacion=esEntero(auxiliar);
                    longitudValidacion=strlen(auxiliar);

                    while (validacion==0 || longitudValidacion>=3)
                    {
                        printf("\nERROR! Reingrese edad: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validacion=esEntero(auxiliar);
                        longitudValidacion=strlen(auxiliar);
                    }

                    lista[numeroUbicado].edad=atoi(auxiliar);
                    validacion=0;

                    lista[numeroUbicado].estado=1;

                    printf("\nSe cargo la persona exitosamente!!!\n");


            }
            else
            {
                printf("Error! No hay espacio!");
            }


}

void ordenarPorNombre(EPersona lista [],int cantidad)
{
    EPersona auxiliar;
    int i;
    int j;

    for(i=0 ; i<cantidad-1; i++)
    {
        for(j=i+1 ; j<cantidad; j++)
        {
            if(stricmp(lista[i].nombre, lista[j].nombre)>0)  //
            {
                auxiliar=lista[j];
                lista[j]=lista[i];
                lista[i]=auxiliar;
            }
        }
    }
}

void mostrarNombres (EPersona lista[], int cantidad)
{
    int i;
    int flag=1;
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estado==flag)
        {
            printf("\n--- NOMBRES --- EDAD --- DNI\n\n");
            auxMostrarUnaLista(lista, cantidad);
            flag=1;
            break;
        }

        else if (flag==0)
        {
            printf("NO se ingresaron datos!!!\n\n");
            break;
        }
    }
}
void auxMostrarUnaLista(EPersona lista[], int cantidad)
{
    int ocupado=0;

        for(int i=0;i < cantidad; i++)
        {
            if(lista[i].estado != -1 && lista[i].estado!=ocupado)
            {
                printf("\n   %s         %d    %d\n\n",lista[i].nombre,lista[i].edad,lista[i].dni);
            }
        }

}


void borrarDatos (EPersona lista [], int limite)
{
    int borrar;
    int auxDni;
    char respuesta;

    printf("Ingrese DNI del usuario para Eliminar : ");
    scanf("%d",&auxDni);
    borrar=buscarPorDni(lista,limite,auxDni);

    if(borrar == -1)
    {
        printf("NO se encuentra el DNI ingresado");
    }
    else
    {
        printf("El DNI ingresado corresponde a: \n\nNOMBRE: %s\n\nEDAD: %d\n\n",lista[borrar].nombre, lista[borrar].edad);
        printf("Responda s/n: ");
        respuesta=getche();

        if(respuesta=='s'||respuesta=='S')
        {
            lista[borrar].estado=-1;
            printf("\n\nEl Usuario fue BORRADO!!!!!\n\n");
        }
        else
        {
            printf("Usuario Cancelado\n\n");
        }
    }
}


void graficodeEdades(EPersona lista[], int limite)
{
    int i;
    int j;
    int contadorEdad[3]={};
    int EdadMaxima;
    int flag=0;

    for (i=0; i<limite; i++)
    {
        if (lista[i].estado==1)
        {
            if (lista[i].edad>35)
            {
                contadorEdad[2]=contadorEdad[2]+1;
            }
            else
            {
                if (lista[i].edad>17 && lista[i].edad<36)
                {
                   contadorEdad[1]=contadorEdad[1]+1;
                }
                else
                {
                    contadorEdad[0]=contadorEdad[0]+1;
                }
            }

        }
    }

    for (i=0; i<3;i++)
    {
        if(flag==0 || contadorEdad[i]>EdadMaxima)
        {
            EdadMaxima=contadorEdad[i];
            flag=1;
        }
    }

    for (i=EdadMaxima;i>0;i--)
    {
        printf("%5d-", i);

        for (j=0;j<3;j++)
        {
            if (contadorEdad[j]>=i)
            {
                printf("  *  ");
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("       <18 19-35 >35\n");

}













