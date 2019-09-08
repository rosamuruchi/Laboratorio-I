#include "LinkedList.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);
int getHoras(void* item);
int Empleado_getHoras(LinkedList* this, int index);
Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_print(Empleado* this);
int employee_listarEmpleado(LinkedList* pArrayListEmployee);


void employee_print(Empleado* this);
void employee_delete(Empleado* this);
int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);
int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int employee_setSueldo(Empleado* this,int sueldo);
int employee_getSueldo(Empleado* this,int* sueldo);
/////////////////////////////////////////////////



#endif // EMPLEADO_H_INCLUDED
