#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "ArrayEmployee.h"

#define TAM_EMPLEADO 10
#define TAM_SECTOR 5
#define TAM_COMIDAS 5
#define TAM_ALMUERZOS 21

int main()
{

    char seguir = 's';
    eEmpleado lista[TAM_EMPLEADO];
    eAlmuerzo listaDeAlmuerzos [TAM_ALMUERZOS];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    eComida comidas[] =
    {
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Pizza"},
        {4, "Sopa"},
        {5, "Pescado"}
    };

    inicializarEmpleados(lista, TAM_EMPLEADO);
    harcodearEmpleados(lista);

    harcodearAlmuerzos(listaDeAlmuerzos);

    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            break;
        case 3:
            modificarEmpleado(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            break;
        case 4:
            mostrarEmpleados(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 6:
            ordenarXSectorYNombre(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 7:
            mostrarEmpleadosMasGanadores(lista, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 8:
                mostrarAlmuerzos(listaDeAlmuerzos,TAM_ALMUERZOS,lista,TAM_EMPLEADO,comidas,TAM_COMIDAS);
                system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

