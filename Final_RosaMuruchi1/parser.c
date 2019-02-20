#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int r;
    char auxId[50];
    char auxApellido[50];
    char auxNombre[50];
    char auxDni[50];
    char auxClave[50];

    empleado = employee_new();

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxDni,auxClave);

        do
        {
            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxDni,auxClave);
            if(r==5)
            {
                empleado = employee_newParametros(auxId,auxNombre,auxApellido,auxDni,auxClave);

                if(empleado!=NULL)
                {
                    ll_add(pArrayListEmployee,empleado);
                    retorno=0;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));
    }
    return retorno;//return 1;
}

int parser_EmployeeFromTextFichaje(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Fichaje* empleado;
    int retorno=-1;
    int r;
    char auxId[50];
    char auxIdSocio[50];
    char auxHora[50];
    char auxMinutos[50];
    char auxDia[50];
    char auxMes[50];
    char auxAnio[50];
    char auxInOut[50];

    empleado = fichaje_new();

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdSocio,auxHora,auxMinutos,auxDia,auxMes,auxAnio,auxInOut);

        do
        {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdSocio,auxHora,auxMinutos,auxDia,auxMes,auxAnio,auxInOut);
            if(r==8)
            {
                empleado = fichaje_newParametros(auxId,auxIdSocio,auxHora,auxMinutos,auxDia,auxMes,auxAnio,auxInOut);

                if(empleado!=NULL)
                {
                    ll_add(pArrayListEmployee,empleado);
                    retorno=0;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));
    }
    return retorno;//return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int cantidad;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            empleado=employee_new();
            cantidad=fread(empleado,sizeof(Employee),1,pFile);
            if(empleado!=NULL && cantidad==1)
            {
                ll_add(pArrayListEmployee,empleado);
                retorno=0;
            }
        }
        while(!feof(pFile));
    }
    return retorno;//return 1;
}
