#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "ArrayEmployee.h"

#define LIBRE 0
#define OCUPADO 1


void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = LIBRE;
    }
}

int buscarLibre( eEmpleado x[], int tam)
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

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("7- Mostrar los datos de o los empleados que mas ganan por sector\n");
    printf("8- Mostrar Almuerzos\n");
    printf("9- Mostrar Almuerzo por Empleado\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = OCUPADO;

            empleados[indice] = nuevoEmpleado;
        }
    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d\t %s\t\t %c\t %.2f\t\t %s\t \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i;
    printf("LEGAJO\t NOMBRE\t\t SEXO\t SUELDO\t\t\t DESCRIPCION\n\n");
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char borrar;

    mostrarEmpleados(empleados,tam,sectores,tamSector);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = LIBRE;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    mostrarEmpleados(empleados,tam,sectores,tamSector);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }
        system("pause");
    }
}


int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    int i;
    printf("\nSECTORES:\n\n");
    for(i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{
    int i;
    for(i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[])
{
    int i;
    for(i=0; i < tamComida; i++)
    {
        if( comidas[i].id == idComida)
        {
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}

void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    int idSector;
    char descripcion[20];
    int flag = 0;
    int i;
    idSector = elegirSector(sectores, tamSector);

    cargarDescripcion(sectores, tam, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(i=0; i< tam; i++)
    {
        if(x[i].isEmpty == OCUPADO && x[i].idSector == idSector)
        {
            mostrarEmpleado(x[i], sectores, tamSector);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;
    int i,j;
    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            cargarDescripcion(sectores, tamSector, x[i].idSector, descripcionI);
            cargarDescripcion(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
    mostrarEmpleados(x,tam,sectores,tamSector);

}
void harcodearEmpleados(eEmpleado x[])
{
    int i;
    eEmpleado y[]=
    {
        {1111, "ana", 'f', 15000, 5, 1},
        {3333, "luis", 'm', 25000, 4, 1},
        {4444, "alberto", 'm', 10000, 5, 1},
        {5555, "julia", 'f', 30000, 1, 1},
        {1313, "julieta", 'f', 23000, 2, 1},
        {4545, "andrea", 'f', 31000, 5, 1},
        {3232, "mauro", 'm', 27000, 5, 1},
    };
    for(i=0; i<7; i++)
    {
        x[i] = y[i];
    }
}

void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    float maxSueldo=0;
    char descripcion[20];
    int flag;
    int i,j;

    for(i=0; i < tamSector; i++)
    {
        cargarDescripcion(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n", descripcion);
        flag = 0;
        for(j=0; j < tam; j++)
        {
            if( x[j].isEmpty == OCUPADO && x[j].idSector == sectores[i].id)
            {
                if( x[j].sueldo > maxSueldo || flag == 0)
                {
                    maxSueldo = x[j].sueldo;
                    flag = 1;
                }
            }
        }

        for(j=0; j < tam; j++)
        {
            if( x[j].sueldo == maxSueldo && flag== 1)
            {
                mostrarEmpleado(x[j], sectores, tamSector);
            }
        }
        printf("\n\n");
    }
}

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


void mostrarComida(eEmpleado emp, eComida comidas[], int tamComida)
{
    char descripcion[20];

    cargarDescripcionComida(comidas, tamComida, emp.idSector, descripcion);

    printf("%d\t %s\t\t  %s\t \n\n", emp.legajo, emp.nombre, descripcion);

}

void mostrarAlmuerzos(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado, eComida comidas[] , int tamComidas)
{
    int i,j,k;
    char auxComida[20];
    char nombreEmpleado[20];
    system("cls");
    printf("\t\tLISTADO DE ALMUERZOS\t\t\n\n");
    printf("ID_COMIDA\t LEGAJO\t\t NOMBRE\t\t COMIDA\n\n");
    for(i=0; i< tamAlmuerzo; i++)
    {
        for(j=0; j<tamEmpleado ;j++)
        {
            if(almuerzos[i].idEmpleado==empleados[j].legajo)
            {
                strcpy(nombreEmpleado, empleados[j].nombre);
                break;
            }
        }
        for(k=0; k<tamComidas ;k++)
        {
            if(almuerzos[i].idComida==comidas[k].id)
            {
                strcpy(auxComida,comidas[k].descripcion);
                break;
            }
        }
        printf("%d\t\t %d\t\t  %s\t\t %s\t\n\n",almuerzos[i].id,almuerzos[i].idEmpleado,nombreEmpleado,auxComida);
    }
    printf("\n\n");
}

void mostrarAlmuerzoPorEmpleados(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas,eSector sectores[], int tamSector)
{
    mostrarEmpleado(empleados,sectores,tamSector);



}