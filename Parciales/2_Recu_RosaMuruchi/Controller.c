#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "clientes.h"
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
                //system("pause");
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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

   /* if(pArrayListEmployee!=NULL)
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
    }*/
    return retorno;
}


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

    /*if(pArrayListEmployee!=NULL)
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
    }*/
    return retorno;
}



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
    eAbono *fp;
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
            fprintf(archivoTexto, "Id,Tipo,Id Cliente,Importe final\n");
            for(i=0; i < ll_len(pArrayListEmployee); i++)
            {
                fp = ll_get(pArrayListEmployee, i);
                fprintf(archivoTexto, "%d,%d,%d,%.2f\n", fp->id, fp->tipo, fp->idCliente, fp->importeFinal);
            }
            fclose(archivoTexto);
            printf("El archivo Texto se guardo exitosamente!\n");
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
    eAbono* fp;
    int retorno=-1;
    int i;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivoBin=fopen(path,"wb");

        if(archivoBin!=NULL)
        {
            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                fp =(eAbono*) ll_get(pArrayListEmployee,i);
                if(fp!=NULL)
                {
                    fwrite(fp,sizeof(eAbono),1,archivoBin);
                }
            }
            retorno=0;
            fclose(archivoBin);
            printf("El archivo Binario se guardo exitosamente!\n");
        }
        else
        {
            printf("El archivo no se pudo guardar!\n");
        }
    }
    return retorno;//return 1;
}
