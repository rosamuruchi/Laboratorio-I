#include "LinkedList.h"
#include "utn.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int menu();

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);
void employee_print(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_buscarLibre(LinkedList* pArrayListEmployee,Employee* this);
int employee_siguienteId(LinkedList* pArrayListEmployee,Employee* this);
int employee_buscarId(LinkedList* pArrayListEmployee,int id);

int employee_altaEmpleado(LinkedList* pArrayListEmployee);
int employee_modificarEmpleado(LinkedList* pArrayListEmployee);
int employee_bajaEmpleado(LinkedList* pArrayListEmployee);
int employee_listarEmpleado(LinkedList* pArrayListEmployee);
int employee_compareEmployeeByName(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeById(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeByHorasTrabajadas(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeBySueldo(void* pEmployeeA,void* pEmployeeB);
#endif // employee_H_INCLUDED
