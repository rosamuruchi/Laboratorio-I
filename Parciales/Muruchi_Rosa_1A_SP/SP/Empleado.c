#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"

void em_calcularSueldo(void* p)
{
    Empleado* empleadoAux;
    int sueldo;
    int horasTrabajadas;

    empleadoAux= (Empleado*)p; //castepo p

    if(employee_getHorasTrabajadas(p,&horasTrabajadas)==-1)
    {
        printf("Error!");
    }
    else
    {
        if(horasTrabajadas<=176)
        {
            sueldo=horasTrabajadas *180;
        }
        else
        {
            if(horasTrabajadas>=177 && horasTrabajadas<=208)
            {
                sueldo=horasTrabajadas *270;
            }
            else
            {
                if(horasTrabajadas>=209 && horasTrabajadas<=240)
                {
                    sueldo=horasTrabajadas *360;
                }
            }
        }
    }
    employee_setSueldo(empleadoAux,sueldo);
}

int getHoras(void* item)
{
    //Tengo que pasar el puntero a void a un auxiliar
    //sino no puedo usar operador flecha
    Empleado* auxiliar;
    int retorno=-1;

    if(item!=NULL)
    {
        //Hay que parsearlo a estructura
        auxiliar=(Empleado*)item;
        retorno=auxiliar->horasTrabajadas;
    }
    return retorno;
}

int Empleado_getHoras(LinkedList* this, int index)
{
    int retorno=-1;
    Empleado* auxiliar;
    auxiliar=employee_new();

    if(this != NULL)
    {
        auxiliar=ll_get(this,index);
        retorno=auxiliar->horasTrabajadas;
    }
    return retorno;
}


Empleado* employee_new()
{
    Empleado* empleado;
    empleado = (Empleado*)malloc(sizeof(Empleado));//inicializar en cero todos los parametros
    if(empleado!=NULL)
    {
        empleado->id = 0;
        strcpy(empleado->nombre, "");
        empleado->horasTrabajadas = 0;
        empleado->sueldo = 0;
    }
    return empleado;
}

Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Empleado* empleado;
    empleado = employee_new();
    if(empleado!=NULL)
    {
        employee_setId(empleado,atoi(idStr));
        employee_setNombre(empleado,nombreStr);
        employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
        employee_setSueldo(empleado,atoi(sueldoStr));
    }
    return empleado;
}
void employee_print(Empleado* this)
{
    int auxId;
    int auxHorasTrabajadas;
    char auxNombre[50];
    int auxSueldo;

    if(this!=NULL)
    {
        if(employee_getId(this,&auxId)==0 && employee_getNombre(this,auxNombre)==0 && employee_getHorasTrabajadas(this,&auxHorasTrabajadas)==0 && employee_getSueldo(this,&auxSueldo)==0)
        {
            printf("%d\t%s\t\t%d\t\t%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }
    }
}

void employee_delete(Empleado* this)
{
    free(this);
}

int employee_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this != NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Empleado* this,int* id)
{
    int retorno=-1;

    if (this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/////////////////////////////////////////////////

int eEmpleados_getId(LinkedList* this, int index)
{
    int retorno;
    Empleado* auxiliar;
    auxiliar=employee_new();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=ll_get(this, index);
        retorno=auxiliar->id;
    }

    return retorno;
}


char* eEmpleados_getNombre(LinkedList* this, int index)
{
    char* retorno= NULL;
    Empleado* auxiliar;
    auxiliar=employee_new();

    if(this != NULL)
    {
        auxiliar=ll_get(this, index);
        retorno=auxiliar->nombre;
    }
    return retorno;
}

int eEmpleados_getSueldo(LinkedList* this, int index)
{
    int retorno;
    Empleado* auxiliar;
    auxiliar=employee_new();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=ll_get(this, index);
        retorno=auxiliar->sueldo;
    }
    return retorno;
}

int eEmpleados_getHoras(LinkedList* this, int index)
{
    int retorno;
    Empleado* auxiliar;
    auxiliar=employee_new();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=ll_get(this, index);
        retorno=auxiliar->horasTrabajadas;
    }

    return retorno;
}

int employee_listarEmpleado(LinkedList* pArrayListEmployee)
{
    Empleado* empleado;
    int retorno=-1;
    int i,limite;

    if(pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0; i<limite; i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            if(empleado!=NULL)
            {
                employee_print(empleado);
                retorno=0;
            }
        }
    }
    return retorno;
}
