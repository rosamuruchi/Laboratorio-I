#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "almuerzos.h"
#include "utn.h"
#include "ArrayEmployee.h"
#include "comidas.h"

#define LIBRE 0
#define OCUPADO 1

void harcodearAlmuerzos(eAlmuerzo x[])
{
    int i;
    eAlmuerzo y[] =
    {
        {100, 1111, 2 },
        {101, 5555, 1 },
        {102, 4545, 3 },
        {103, 3232, 4 },
        {104, 1111, 1 },
        {105, 5555, 5 },
        {106, 4545, 2 },
        {107, 3232, 5 },
        {108, 1111, 2 },
        {109, 4545, 1 },
        {110, 3232, 1 },
        {111, 1111, 4 },
        {112, 5555, 3 },
        {113, 4545, 5 },
        {114, 3232, 2 },
        {115, 5555, 5 },
        {116, 4545, 2 },
        {117, 3232, 3 },
        {118, 1111, 2 },
        {119, 5555, 1 },
        {120, 4545, 3 }
    };

    for(i=0; i<21; i++)
    {
        x[i] = y[i];
    }
}

void mostrarAlmuerzos(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado, eComida comidas[], int tamComidas)
{
    int i,j,k;
    char auxComida[20];
    char nombreEmpleado[20];
    system("cls");
    printf("\t\tLISTADO DE ALMUERZOS\t\t\n\n");
    printf("ID_COMIDA\tLEGAJO\tNOMBRE\tCOMIDA\n\n");
    for(i=0; i< tamAlmuerzo; i++)
    {
        for(j=0; j<tamEmpleado ; j++)
        {
            if(almuerzos[i].idEmpleado==empleados[j].legajo)
            {
                strcpy(nombreEmpleado, empleados[j].nombre);
                break;
            }
        }
        for(k=0; k<tamComidas ; k++)
        {
            if(almuerzos[i].idComida==comidas[k].id)
            {
                strcpy(auxComida,comidas[k].descripcion);
                break;
            }
        }
        printf("%d\t\t%d\t%s\t%s\n",almuerzos[i].id,almuerzos[i].idEmpleado,nombreEmpleado,auxComida);
    }
    printf("\n\n");
}

void mostrarAlmuerzoPorEmpleados(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas,eSector sectores[], int tamSector)
{
    int legajo;
    int flag = 0;
    int i,j;

    system("cls");

    mostrarEmpleados(empleados,tamEmpleado, sectores, tamSector);
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    system("cls");
    printf("  *** Listado de almuerzos legajo %d ***\n\n", legajo);

    for(i=0; i < tamAlmuerzo; i++)
    {
        if( almuerzos[i].idEmpleado == legajo)
        {
            for(j=0; j < tamComidas; j++)
            {
                if( comidas[j].id == almuerzos[i].idComida)
                {
                    printf("%d  %10s\n", almuerzos[i].id, comidas[j].descripcion);
                }
            }
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("El empleado no presenta almuerzos");
    }
    printf("\n\n");
}
