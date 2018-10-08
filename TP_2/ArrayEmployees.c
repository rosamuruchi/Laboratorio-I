#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "misFunciones.h"

#define FREE 0
#define FILLED 1

#define RRHH 1
#define VENTAS 2
#define SISTEMAS 3
#define CONTABLE 4

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informes\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno= -1;

    for(i=0; i < len; i++)
    {
        list[i].isEmpty = FREE;
        list[i].id=0;
        retorno=0;
    }
    return retorno;
}

int findEmployeeFree(Employee* list, int len)
{
    int indice = -1;
    int i;
    for(i=0; i< len; i++)
    {
        if( list[i].isEmpty == FREE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;
    int i;
    for(i=0; i < len; i++)
    {
        if( list[i].id == id && list[i].isEmpty == FILLED)
        {
            retorno= i;
            break;
        }
    }
    return retorno;
}

int nextId (Employee* list, int len)
{
    int retorno = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == FILLED)
        {
            if(list[i].id>retorno)
            {
                retorno=list[i].id;
            }
        }
    }
    return retorno+1;
}

void corroborarInicializacion(Employee* list, int len)
{
    int corroborrar;
    corroborrar=initEmployees(list,len);
    if(corroborrar!= -1)
    {
        printf("Se Inicializo la lista con Exito!\n\n");
    }
    else
    {
        printf("No se pudo cargar la Inicializacion!\n");
    }
}
int findEmployeeBySalary(Employee* list, int len,float salary)
{
    int retorno = -1;
    int i;
    for(i=0; i < len; i++)
    {
        if( list[i].salary >= salary && list[i].isEmpty == FILLED)
        {
            retorno= i;
            break;
        }
    }
    return retorno;
}

/*void harcodearEmpleados(Employee* list)
{
    int i;
    Employee y[]=
    {
        {1, "ana", "Martinez", 15000, 3, 1},
        {2, "luis", "Freys", 25000, 4, 1},
        {3, "alberto", "Gonzalez", 10000, 4, 1},
        {4, "julia", "Arana", 30000, 1, 1},
        {5, "julieta", "Zenteno", 23000, 2, 1},
        {6, "andrea", "Apple", 10000, 4, 1},
        {7, "mauro", "Arco", 27000, 2, 1},
    };
    for(i=0; i<7; i++)
    {
        list[i] = y[i];
    }
}*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int returnAux= -1;
    int libre;
    int siguienteId;
    libre=findEmployeeFree(list,len);
    siguienteId=nextId(list,id);

    list[libre].id = siguienteId;
    strcpy(list[libre].name,name);
    strcpy(list[libre].lastName,lastName);
    list[libre].salary = salary;
    list[libre].sector = sector;
    list[libre].isEmpty = FILLED;
    returnAux = 0;

    return returnAux;
}

void altaEmpleados(Employee* list, int len)
{
    int agregarEmpleado;
    int lugarLibre;
    int empleadoBuscado;

    int validarId;
    int validarName;
    int validarLastName;
    int validarSueldo;
    int auxiliarId;
    int auxiliarSector;
    char auxiliarName[50];
    char auxiliarLastName[50];
    float auxiliarSueldo;
    //char sector[][50]={"RR.HH","VENTAS","SISTEMAS","CONTABLE"};
    //int nombreSector;

    lugarLibre=findEmployeeFree(list,len);
    if(lugarLibre == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        validarId=getEntero(&auxiliarId,"Ingrese Id:","ERROR! Reingrese Id:",0,9999);
        if(validarId!=0)
        {
            printf("ID: %d\n",auxiliarId);
        }
        empleadoBuscado= findEmployeeById(list,len,auxiliarId);
        if(empleadoBuscado != -1)
        {
            printf("Existe un empleado con el ID %d\n", auxiliarId);
        }
        else
        {
            validarName= getString(auxiliarName,"Ingrese Name:","ERROR! Reingrese:");
            validarLastName= getString(auxiliarLastName,"Ingrese LastName:","ERROR! Reingrese:");
            validarSueldo= getFlotante(&auxiliarSueldo,"Ingrese Sueldo:","ERROR! Reingrese:");
            printf("Ingrese Sector:\n1.RRHH\n2.Ventas\n3.Sistemas\n4.Contable\nRta:");
            fflush(stdin);
            scanf("%d",&auxiliarSector);

            if(validarName != 0)
            {
                printf("NAME: %s\n",auxiliarName);
            }
            if(validarLastName != 0)
            {
                printf("LAST NAME: %s\n",auxiliarLastName);
            }
            if(validarId!=0)
            {
                printf("ID: %d\n",auxiliarId);
            }
            if(validarSueldo!=0)
            {
                printf("SUELDO: %.2f\n",auxiliarSueldo);
            }
            agregarEmpleado=addEmployee(list,len,auxiliarId,auxiliarName,auxiliarLastName,auxiliarSueldo,auxiliarSector);
            if(agregarEmpleado== -1)
            {
                printf("No se pudo Cargar el Empleado!\n");
            }
            else
            {
                printf("Empleado Cargado!\n");
            }
        }
    }
}

void modificarEmpleados(Employee* list, int len)
{

    int auxiliarId;
    int empleadoBuscado;
    char respuesta;
    int opcion;
    int validarName;
    int validarLastName;
    char auxiliarName[50];
    char auxiliarLastName[50];

    printEmployees(list,len);

    printf("Ingrese Id: ");
    scanf("%d", &auxiliarId);

    empleadoBuscado = findEmployeeById(list,len,auxiliarId);

    if( empleadoBuscado == -1)
    {
        printf("No hay ningun empleado con el ID %d\n", auxiliarId);
    }
    else
    {
        printf("El Id corresponde a : %s", list[empleadoBuscado].name);
        printf("\nModificar?s/n: ");
        respuesta=tolower(getche());
        if(respuesta== 's')
        {
            printf("\nIngrese que desea modificar:\n1.Name\n2.LastName\n3.Salary\n4.Sector\n5.Cancelar\nOpcion:");
            fflush(stdin);
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                validarName= getString(auxiliarName,"Ingrese Name:","ERROR! Reingrese:");
                if(validarName != 0)
                {
                    strcpy(list[empleadoBuscado].name,auxiliarName);
                    printf("NAME: %s\n",auxiliarName);
                }
                break;
            case 2:
                validarLastName= getString(auxiliarLastName,"Ingrese LastName:","ERROR! Reingrese:");
                if(validarLastName != 0)
                {
                    strcpy(list[empleadoBuscado].lastName,auxiliarLastName);
                    printf("LAST NAME: %s\n",auxiliarLastName);
                }
                break;
            case 3:
                printf("Ingrese sueldo: ");
                fflush(stdin);
                scanf("%f", &list[empleadoBuscado].salary);
                break;
            case 4:
                printf("Ingrese Sector:\n1.RRHH\n2.Ventas\n3.Sistemas\n4.Contable\nRta:");
                fflush(stdin);
                scanf("%d",&list[empleadoBuscado].sector);
                break;
            case 5:
                system("pause");
                break;
            }
        }
        else if(respuesta == 'n')
        {
            printf("\nEmpleado Cancelado\n");
        }
        else
        {
            printf("\nPor favor Ingresar s/n!\n");
        }
    }
}


int removeEmployee(Employee* list, int len, int id)
{
    int retorno= -1;
    int indice;

    indice = findEmployeeById(list,len,id);
    if( indice == -1)
    {
        printf("No hay ningun Empleado con el Id: %d\n", id);
    }
    else
    {
        list[indice].isEmpty = FREE;
        retorno=0;
    }
    return retorno;
}

void bajaEmpleados (Employee* list, int len)
{
    char borrar;
    int indice;
    int auxiliarId;
    int empleadoBorrado;

    printEmployees(list,len);

    printf("Ingrese Id Del Empleado: ");
    fflush(stdin);
    scanf("%d", &auxiliarId);

    indice = findEmployeeById(list,len,auxiliarId);

    if( indice == -1)
    {
        printf("No hay ningun Empleado con el Id: %d\n", auxiliarId);
    }
    else
    {
        printAEmployeeFound(list,len,auxiliarId);
        //printf("El empleado corresponde a: %s\t%s\n",list[indice].name,list[indice].lastName);

        printf("\nConfirma borrado?[s/n]: ");
        fflush(stdin);
        borrar=tolower(getche());
        if(borrar == 'n')
        {
            printf("\nBorrado cancelado\n\n");
        }
        else if(borrar == 's')
        {
            empleadoBorrado=removeEmployee(list,len,auxiliarId);
            if(empleadoBorrado==0)
            {
                printf("\nSe ha eliminado el empleado\n\n");
            }
            else
            {
                printf("\nNo se ha podido borrar el empleado\n\n");
            }
        }
    }
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;
    int retorno=-1;
    int i,j;
    if(order==0 || order==1) //0=down ; 1=up
    {
        for(i=0; i<len -1; i++)
        {
            for(j = i +1; j < len; j++)
            {
                if(order==1)
                {
                    if( strcmp(list[i].lastName, list[j].lastName) > 0)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    else if( (list[i].sector > list[j].sector) && strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                        retorno=0;
                    }
                }
                if(order ==0)
                {
                    if( strcmp(list[i].lastName, list[j].lastName) < 0)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    else if( (list[i].sector < list[j].sector) && strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

void printAEmployeeFound(Employee* list,int len,int id)
{
    int employeeFound;

    employeeFound = findEmployeeById(list,len,id);

    printf("%s\t%s\n",list[employeeFound].name,list[employeeFound].lastName);
}


int printEmployees(Employee* list, int length)
{
    int retorno= -1;
    int i;
    printf("ID\tNAME\t\tLASTNAME\tSALARY\tSECTOR\n\n");
    for(i=0; i<length; i++)
    {
        if(list[i].isEmpty == FILLED)
        {
            printf("%d\t%s\t\t%s\t\t%.2f\t%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            retorno=0;
        }
    }
    return retorno;
}

void listarEmpleadosOrdenados(Employee* list,int len)
{
    int ordenar;
    int opcion;

    printf("Desea Ordenar:\n1.ascendente\n2.descendente\nRta:");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        ordenar= sortEmployees(list,len,1);
        if(ordenar==0)
        {
            printEmployees(list,len);
        }
        break;
    case 2:
        ordenar= sortEmployees(list,len,0);
        if(ordenar==0)
        {
            printEmployees(list,len);
        }
        break;
    default:
        printf("\nOpcion no valida!\n");
        break;
    }

}

void recaudacionTotal( Employee* list, int limite)
{
    int i;
    float valorTotal=0;
    int contador=0;
    int contadorDeEmpleados=0;
    float promedioDeSalarios;

    for(i=0; i<limite; i++)
    {
        if(list[i].isEmpty==FILLED)
        {
            valorTotal+=list[i].salary;
            contador++;
        }
    }
    promedioDeSalarios=(float)valorTotal/contador;

    for (i=0; i<contador; i++){
        if ((list[i].isEmpty == FILLED) && (list[i].salary >= promedioDeSalarios))
        {
            contadorDeEmpleados++;
        }
    }

    printf("-------SUELDOS-------\n\n");
    printf("La Recaudacion Total de Salarios es: %.2f\n\n",valorTotal);
    printf("El promedio de los Salarios es: %.2f\n\n",promedioDeSalarios);
    printf("Los empleados que sobrepasan el salario promedio son: %d\n\n",contadorDeEmpleados);

}

void subMenuListados (Employee* list,int len)
{
    int opcion;
    printf("\n-------LISTADOS--------\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\nRespuesta:");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        listarEmpleadosOrdenados(list,len);
        break;
    case 2:
        recaudacionTotal(list,len);
        break;
    default:
        printf("\nOpcion no valida!\n");
        break;
    }
}

