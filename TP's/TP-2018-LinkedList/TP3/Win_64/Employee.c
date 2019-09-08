#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

Employee* employee_new()
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));//inicializar en cero todos los parametros
    if(empleado!=NULL)
    {
        empleado->id = 0;
        strcpy(empleado->nombre, "");
        empleado->horasTrabajadas = 0;
        empleado->sueldo = 0;
    }
    return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empleado;
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

void employee_print(Employee* this)
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

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this != NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_siguienteId(LinkedList* pArrayListEmployee,Employee* this)
{
    int retorno = 0;
    int i;
    int limite;
    limite=ll_len(pArrayListEmployee);
    if(limite > 0 && this != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if((this+i)->id>retorno)
            {
                retorno=(this+i)->id;
            }
        }
    }
    return retorno+1;
}
int employee_buscarId(LinkedList* pArrayListEmployee,int id)
{
    Employee* empleadoAux;
    int retorno=-1;
    int limite;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);

        for(i=0; i<limite; i++)//1
        {
            empleadoAux=(Employee*)ll_get(pArrayListEmployee,i);//i-1
            if(empleadoAux->id==id)
            {
                printf(" %d\t%s\t\t%d\t %d\n",empleadoAux->id,empleadoAux->nombre,empleadoAux->horasTrabajadas,empleadoAux->sueldo);
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_altaEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[50];

    char Id[50];
    char HorasTrabajadas[50];
    char Sueldo[50];

    int validarId;
    int validarNombre;
    int validarHorasTrabajadas;
    int validarSueldo;
    int empleadoBuscado;

    if(pArrayListEmployee!=NULL)
    {
        validarId=getEntero(&auxId,"Ingrese Id: ","ERROR!\nReingrese id: ",0,99999);
        validarNombre=getString(auxNombre,"Ingrese Nombre: ","ERROR!\nReingrese Nombre: ");
        validarHorasTrabajadas=getEntero(&auxHorasTrabajadas,"Ingrese Horas trabajadas: ","ERROR!\nReingrese Horas trabajadas: ",0,99999);
        validarSueldo=getEntero(&auxSueldo,"Ingrese Sueldo: ","ERROR!\nReingrese id: ",0,999999);

        if(validarId!=0 && validarNombre!=0 && validarHorasTrabajadas!=0 && validarSueldo!=0 )
        {
            sprintf(Id,"%d",auxId);
            sprintf(HorasTrabajadas,"%d",auxHorasTrabajadas);
            sprintf(Sueldo,"%d",auxSueldo);
            empleado=employee_newParametros(Id,auxNombre,HorasTrabajadas,Sueldo);
            if(empleado!=NULL)
            {
                empleadoBuscado=employee_buscarId(pArrayListEmployee,auxId);
                //printf("%d\n",empleadoBuscado);
                if(empleadoBuscado != -1)
                {
                    printf("Existe un empleado con el ID %d\n", auxId);
                }
                else
                {
                    ll_add(pArrayListEmployee,empleado);
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}
int employee_modificarEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[50];

    int validarId;
    int validarNombre;
    int validarHorasTrabajadas;
    int validarSueldo;
    int empleadoBuscado;

    char respuesta;
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        validarId=getEntero(&auxId,"Ingrese Id: ","ERROR!\nReingrese id: ",0,99999);
        if(validarId!=0)
        {
            empleado=employee_new();
            empleadoBuscado=employee_buscarId(pArrayListEmployee,auxId);
            if(empleadoBuscado != -1)
            {
                empleado=(Employee*)ll_get(pArrayListEmployee,empleadoBuscado);
                if(empleado!=NULL)
                {
                    if(employee_setId(empleado,empleadoBuscado)==0)
                    {
                        printf("El ID corresponde :%d\n",empleadoBuscado);
                        printf("\nModificar?s/n: ");
                        respuesta=tolower(getche());
                        if(respuesta== 's')
                        {
                            printf("\nIngrese que desea modificar:\n1.Id\n2.Nombre\n3.Horas Trabajadas\n4.Sueldo\n5.Cancelar\nOpcion:");
                            fflush(stdin);
                            scanf("%d", &opcion);
                            switch(opcion)
                            {
                            case 1:
                                validarId=getEntero(&auxId,"Ingrese Id: ","ERROR!\nReingrese id: ",0,99999);
                                if(validarId!=0)
                                {
                                    if(employee_setId(empleado,auxId)==0)
                                    {
                                        printf("Se cambio el Id!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 2:
                                validarNombre=getString(auxNombre,"Ingrese Nombre: ","ERROR!\nReingrese Nombre: ");
                                if(validarNombre!=0)
                                {
                                    if(employee_setNombre(empleado,auxNombre)==0)
                                    {
                                        printf("Se cambio el Nombre!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 3:
                                validarHorasTrabajadas=getEntero(&auxHorasTrabajadas,"Ingrese Horas trabajadas: ","ERROR!\nReingrese Horas trabajadas: ",0,99999);
                                if(validarHorasTrabajadas!=0)
                                {
                                    if(employee_setHorasTrabajadas(empleado,auxHorasTrabajadas)==0)
                                    {
                                        printf("Se cambio las Horas Trabajadas!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 4:
                                validarSueldo=getEntero(&auxSueldo,"Ingrese Sueldo: ","ERROR!\nReingrese id: ",0,999999);
                                if(validarSueldo!=0)
                                {
                                    if(employee_setSueldo(empleado,auxSueldo)==0)
                                    {
                                        printf("Se cambio el Sueldo!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 5:
                                break;
                            default:
                                printf("opcion invalida!\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Modificacion Cancelada!\n");
                    }
                }
            }
            else
            {
                printf("Empleado No encontrado!\n");
            }
        }
    }
    return retorno;
}
int employee_bajaEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int auxId;
    int idBuscado;
    int validarId;

    if(pArrayListEmployee!=NULL)
    {
        validarId=getEntero(&auxId,"Ingrese Id:","ERROR!\nReingrese Id:",0,999999);
        if(validarId!= 0)
        {
            idBuscado=employee_buscarId(pArrayListEmployee,auxId);
            if(idBuscado != -1)
            {
                empleado=ll_get(pArrayListEmployee,auxId);
                if(empleado!=NULL)
                {
                    ll_remove(pArrayListEmployee,auxId);
                    retorno=0;
                }
            }
            else
            {
                printf("No se encuentro Id\n");
            }
        }
    }
    return retorno;
}

int employee_listarEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
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
int employee_compareEmployeeById(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->id == empleadoDos->id)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->id > empleadoDos->id)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->id < empleadoDos->id)
                {
                    retorno=1;
                }
            }

        }
    }
    return retorno;
}
int employee_compareEmployeeByName(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno= (Employee*) pEmployeeA;
        empleadoDos= (Employee*) pEmployeeB;

        retorno = stricmp(empleadoDos->nombre, empleadoUno->nombre);
    }

    return retorno;
}

int employee_compareEmployeeByHorasTrabajadas(void* pEmployeeA,void* pEmployeeB)
{
        int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->horasTrabajadas == empleadoDos->horasTrabajadas)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->horasTrabajadas < empleadoDos->horasTrabajadas)
                {
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}
int employee_compareEmployeeBySueldo(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->sueldo == empleadoDos->sueldo)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->sueldo > empleadoDos->sueldo)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->sueldo < empleadoDos->sueldo)
                {
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}
