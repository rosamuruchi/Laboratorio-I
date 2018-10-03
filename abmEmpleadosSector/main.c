#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "utn.h"
#include "ArrayEmployee.h"
#include "comidas.h"
#include "almuerzos.h"

#define TAM_EMPLEADO 10
#define TAM_SECTOR 5
#define TAM_COMIDAS 5
#define TAM_ALMUERZOS 21

int main()
{

    char seguir = 's';
    eEmpleado listaDeEmpleados[TAM_EMPLEADO];
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

    inicializarEmpleados(listaDeEmpleados, TAM_EMPLEADO);
    harcodearEmpleados(listaDeEmpleados);
    harcodearAlmuerzos(listaDeAlmuerzos);

    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            break;
        case 3:
            modificarEmpleado(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            break;
        case 4:
            mostrarEmpleados(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 6:
            ordenarXSectorYNombre(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 7:
            mostrarEmpleadosMasGanadores(listaDeEmpleados, TAM_EMPLEADO, sectores, TAM_SECTOR);
            system("pause");
            break;
        case 8:
            mostrarAlmuerzos(listaDeAlmuerzos,TAM_ALMUERZOS,listaDeEmpleados,TAM_EMPLEADO,comidas,TAM_COMIDAS);
            system("pause");
            break;
        case 9:
            mostrarAlmuerzoPorEmpleados (listaDeAlmuerzos,TAM_ALMUERZOS,listaDeEmpleados,TAM_EMPLEADO,comidas,TAM_COMIDAS,sectores,TAM_SECTOR);
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

