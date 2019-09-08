#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "funciones.h"
#include "autos.h"
#include "egresos.h"

#define TAMPROP 50
#define TAMAUTO 20


int main()
{
    EPropietario listaDePropietario[TAMPROP];
    inicializarListaPropietario(listaDePropietario,TAMPROP);
    inicializarPropietariosHardCode(listaDePropietario,TAMPROP);

    EAutos listaDeAutos[TAMAUTO];
    inicializarListaAutos(listaDeAutos,TAMAUTO);
    inicializarAutosHardCode(listaDeAutos,TAMAUTO);

    EEgresos listaDeEgresosAutos[TAMAUTO];
    inicializarEgresosHardCode(listaDeEgresosAutos,TAMAUTO);

    char seguir='s';
    int opcion=0;

    do
        {
        printf("---------------------------------------\n\n");
        printf("1- ALTA PROPIETARIO\n");
        printf("2- MODIFICACION PROPIETARIO\n");
        printf("3- BAJA PROPIETARIO\n");
        printf("4- INGRESO DE AUTO\n");
        printf("5- EGRESO DE AUTO\n");
        printf("6- RECAUDACION TOTAL DE ESTACIONAMIENTO\n");
        printf("7- RECAUDACION TOTAL POR MARCA\n");
        printf("8- MOSTRAR PROPIETARIO CON SU AUTO\n");
        printf("9- MOSTRAR LISTA AUTOS: AUDI\n");
        printf("10- MOSTRAR LISTA TODOS AUTOS\n");
        printf("11- Salir\n\n");

        printf("Respuesta: ");
        scanf("%d",&opcion);

        printf("---------------------------------------\n");

        switch(opcion)
        {
            case 1:
                    altaDePropietario(listaDePropietario,TAMPROP);

                break;
            case 2:
                    modificarDatos(listaDePropietario,TAMPROP);

                break;
            case 3:
                    bajaPropietario(listaDePropietario,TAMPROP);

                break;
            case 4:
                    ingresoDeAutomovil(listaDeAutos,TAMAUTO);
                    break;

            case 5:
                    egresodeAutos(listaDeEgresosAutos,TAMAUTO,listaDePropietario,TAMPROP,listaDeAutos);
                break;

            case 6:
                    recaudacionTotal(listaDeEgresosAutos,TAMAUTO);
                break;
            case 7:
                    recaudacionPorMarca(listaDeEgresosAutos,TAMAUTO);
                break;
            case 8:
                    listaPropietarioConAutos(listaDePropietario,TAMPROP,listaDeAutos,TAMAUTO);
                break;
            case 9:
                    listaAutoPorMarcaAudi(listaDeAutos,TAMAUTO,listaDePropietario,TAMPROP,3);
                break;
            case 10:
                    listaAutosPorPatente(listaDeAutos,TAMAUTO,listaDePropietario,TAMPROP);
                break;
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }while(seguir=='s');


    return 0;

}




