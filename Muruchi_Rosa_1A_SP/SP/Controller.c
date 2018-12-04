#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* archivo;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivo=fopen(path,"r");
        if(archivo != NULL)
        {
            if(parser_EmployeeFromText(archivo,pArrayListEmployee)==0)
            {
                retorno=0;
                printf("Se Cargo exitosamente!\n");
                //fclose(archivo);
            }
        }
        else
        {
            printf("NO ABRE...");
        }
    }
    else
    {
        printf("Error!!!\n");
    }
    return retorno;//return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int abrir;
    FILE* archivoBin;
    archivoBin=fopen(path,"rb");

    if(archivoBin==NULL && pArrayListEmployee==NULL)
    {
        printf("El archivo no existe!\n");
    }
    else
    {
        abrir=parser_EmployeeFromBinary(archivoBin,pArrayListEmployee);
        if(abrir==0)
        {
            retorno=0;
            printf("El archivo se Cargo exitosamente!\n");
        }
        else
        {
            printf("El archivo no se pudo abrir!\n");
        }

    }
    return retorno;//return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        if(employee_altaEmpleado(pArrayListEmployee)==0)
        {
            retorno=0;
            printf("Empleado Cargado!\n");
            system("pause");
        }
        else
        {
            printf("Error! No se pudo Cargar empleado!\n");
            system("pause");
        }
    }
    return retorno;
}*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_editEmployee(LinkedList* pArrayListEmployee)
{
   int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        if(employee_modificarEmpleado(pArrayListEmployee)==0)
        {
            retorno=0;
            printf("Empleado Modificado!\n");
            system("pause");
        }
        else
        {
            printf("Error! No se pudo modificar empleado!\n");
            system("pause");
        }
    }

    return retorno;
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        if(employee_bajaEmpleado(pArrayListEmployee)==0)
        {
            retorno=0;
            printf("Empleado Eliminado!\n");
            system("pause");
        }
        else
        {
            printf("Error! No se pudo Eliminar empleado!\n");
            system("pause");
        }
    }

    return retorno;
}*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        printf("ID   NOMBRE   HORAS TRABAJADAS   SUELDO\n\n");
        if(employee_listarEmpleado(pArrayListEmployee)==0)
        {
            retorno=0;
            system("pause");
        }
        else
        {
            printf("No hay Ningun empleado en la lista\n");
            system("pause");
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        do
        {
            system("cls");
            printf(" 1. Ordenar por Id\n");
            printf(" 2. Ordenar por nombre\n");
            printf(" 3. Ordenar por horas trabajadas\n");
            printf(" 4. Ordenar por sueldo\n");
            printf(" 5. Salir\n");
            printf(" Seleccione una opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                ll_sort(pArrayListEmployee, employee_compareEmployeeById, 0);
                printf("Se ordeno con exito\n");
                system("pause");
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_compareEmployeeByName, 0);
                printf("Se ordeno con exito\n");
                system("pause");
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_compareEmployeeByHorasTrabajadas, 0);
                printf("Se ordeno con exito\n");
                system("pause");
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_compareEmployeeBySueldo, 0);
                printf("Se ordeno con exito\n");
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("Opcion no valida!\n");
            }
        }
        while(opcion!=5);
    }

    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivoTexto;
    Empleado *emp;
    int retorno=-1;
    int i;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivoTexto= fopen(path,"w");
        if(archivoTexto==NULL)
        {
            printf("El archivo no se pudo guardar!\n");
        }
        else
        {
            for(i=0; i < ll_len(pArrayListEmployee); i++)
            {
                emp = ll_get(pArrayListEmployee, i);
                fprintf(archivoTexto, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            }
            fclose(archivoTexto);
            printf("El archivo se guardo exitosamente!\n");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivoBin;
    Empleado* empleado;
    int retorno=-1;
    int i;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivoBin=fopen(path,"wb");

        if(archivoBin!=NULL)
        {
            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                empleado =(Empleado*) ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    fwrite(empleado,sizeof(Empleado),1,archivoBin);
                }
            }
            retorno=0;
            fclose(archivoBin);
            printf("El archivo se guardo exitosamente!\n");
        }
        else
        {
            printf("El archivo no se pudo guardar!\n");
        }
    }
    return retorno;//return 1;
}

int controller_ListEmployeeBySueldo(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Empleado* empleadoAux;
    int i;
    printf("\tLISTA DE EMPLEADOS\n");

    for(i=0; i< ll_len(pArrayListEmployee); i++)
    {
        empleadoAux=(Empleado*)ll_get(pArrayListEmployee,i);
        //employee_printdatasueldo (empleadoaux);
        retorno=0;
    }
    return retorno;
}
 int controller_LoadSueldos (LinkedList* pArrayListEmployee)
 {
     int retorno=-1;
     if(ll_map(pArrayListEmployee,em_calcularSueldo)==0)
     {
         retorno=0;
     }

     return retorno;
 }
