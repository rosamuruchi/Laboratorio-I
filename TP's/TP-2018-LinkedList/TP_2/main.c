#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "misFunciones.h"

#define ELEMENTS 1000

int main()
{
    char seguir = 's';
    int cargaValida;
    int empleadoCargado=0;
    Employee arrayEmployees[ELEMENTS];

    corroborarInicializacion(arrayEmployees,ELEMENTS);
//    harcodearEmpleados(arrayEmployees);
    system("pause");
    do
    {
        switch(menu())
        {

        case 1:
            cargaValida=findEmployeeFree(arrayEmployees,ELEMENTS);
            if(cargaValida!= -1
               )
            {
                altaEmpleados(arrayEmployees,ELEMENTS);
                empleadoCargado=1;
            }
            else
            {
                printf("No hay ningun Empleado Cargado!\n\n");
            }

            system("pause");
            break;
        case 2:
            if(empleadoCargado!=1)
            {
                printf("No hay ningun Empleado Cargado!\n\n");
            }
            else
            {
                modificarEmpleados(arrayEmployees,ELEMENTS);
            }

            system("pause");
            break;
        case 3:
            if(empleadoCargado!=1)
            {
                printf("No hay ningun Empleado Cargado!\n\n");
            }
            else
            {
                bajaEmpleados(arrayEmployees,ELEMENTS);
            }

            system("pause");
            break;
        case 4:
            if(cargaValida!=1)
            {
                printf("No hay ningun Empleado Cargado!\n\n");
            }
            else
            {
                subMenuListados(arrayEmployees,ELEMENTS);
            }

            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion no valida!\n");
            break;
        }

    }
    while(seguir == 's');

    return 0;
}
