#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

#include "funciones.h"

#define TAM 50

int main()
{
    EMovie ListadePeliculas[TAM];

    char seguir='s';
    char guardar= 's';
    char nombreArchivo[100];
    int retorno;
    int opcion=0;

    inicializarLista(ListadePeliculas,TAM);

    if(cargarDesdeArchivo(ListadePeliculas,TAM))
    {
        printf("No se pudo abrir el Archivo");
    }
    else
    {
        printf("El Archivo se cargo Exitosamente!\n");
    }

    system("pause");
    system("cls");

    while(seguir=='s')
    {
        printf("-------------------------------\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Guardar y Salir\n\n");
        printf("Respuesta: ");
        scanf("%d",&opcion);
        printf("--------------------------------\n");

        switch(opcion)
        {
        case 1:
            retorno=agregarPelicula(ListadePeliculas,TAM);

            if( retorno==0)
            {
                printf("No se pudo cargar el Archivo");
            }
            else
            {
                printf("El Archivo se Cargo Exitosamente!\n");
            }
            break;
        case 2:
            retorno=borrarPelicula(ListadePeliculas,TAM);

            if( retorno==0)
            {
                printf("No se pudo borrar el Archivo");
            }
            else
            {
                printf("El Archivo se elimino Exitosamente!\n");
            }

            break;
        case 3:
            retorno=modificarPelicula(ListadePeliculas,TAM);

            if( retorno==0)
            {
                printf("No se pudo Modificar el Archivo");
            }
            else
            {
                printf("El Archivo se modifico Exitosamente!\n");
            }

            break;
        case 4:
            printf("Ingrese el nombre de su archivo:");
            fflush(stdin);
            gets(nombreArchivo);

            generarPagina(ListadePeliculas,nombreArchivo,TAM);
            retorno=guardarEnArchivo(ListadePeliculas,TAM);
            if(retorno==0)
            {
                printf("No se pudo abrir el Archivo");
            }
            else
            {
                printf("El Archivo se guardo Exitosamente!\n");
            }

            break;
        case 5:
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getche());

            if(guardar == 's')
            {
                if(guardarEnArchivo(ListadePeliculas,TAM))
                {
                    printf("\nNo se pudo abrir el Archivo\n");
                }
                else
                {
                    printf("\nSe guardo la informacion exitosamente!!!\n");
                }
            }

            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
