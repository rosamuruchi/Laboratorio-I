#include "LinkedList.h"
#include "utn.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido [120];
    int dni;
    char clave[20];
}Employee;

typedef struct
{
    int idFichaje;
    int idSocio;
    int hora;
    int minutos;
    int dia;
    int mes;
    int anio;
    char ingresoEgreso[10];
}Fichaje;

int menu();

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* apellido,char* dni, char* clave);
void employee_delete(Employee* this);
void employee_print(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setApellido(Employee* this,char* apellido);
int employee_getApellido(Employee* this,char* apellido);


int employee_setDni(Employee* this,int dni);
int employee_getDni(Employee* this,int* dni);

int employee_setClave(Employee* this,char* clave);
int employee_getClave(Employee* this,char* clave);

int employee_buscarLibre(LinkedList* pArrayListEmployee,Employee* this);
int employee_siguienteId(LinkedList* pArrayListEmployee,Employee* this);
int employee_buscarId(LinkedList* pArrayListEmployee, LinkedList* listaFichaje,int id);

int employee_altaEmpleado(LinkedList* pArrayListEmployee);
int employee_modificarEmpleado(LinkedList* pArrayListEmployee);
int employee_bajaEmpleado(LinkedList* pArrayListEmployee, LinkedList* pArrayListEmployee2);
int employee_listarEmpleado(LinkedList* pArrayListEmployee, LinkedList* listaFichaje);
int employee_compareEmployeeByName(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeById(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeByHorasTrabajadas(void* pEmployeeA,void* pEmployeeB);
int employee_compareEmployeeBySueldo(void* pEmployeeA,void* pEmployeeB);

//////////////////
Fichaje* fichaje_new();

int fichaje_setId(Fichaje* this,int id);
int fichaje_getId(Fichaje* this,int* id);

int fichaje_setIdSocio(Fichaje* this,int idSocio);
int fichaje_getIdSocio(Fichaje* this,int* idSocio);

int fichaje_setHora(Fichaje* this,int hora);
int fichaje_getHora(Fichaje* this,int* hora);

int fichaje_setMinutos(Fichaje* this,int minutos);
int fichaje_getMinutos(Fichaje* this,int* minutos);

int fichaje_setDia(Fichaje* this,int dia);
int fichaje_getDia(Fichaje* this,int* dia);

int fichaje_setMes(Fichaje* this,int mes);
int fichaje_getMes(Fichaje* this,int* mes);

int fichaje_setAnio(Fichaje* this,int anio);
int fichaje_getAnio(Fichaje* this,int* anio);

int fichaje_getInOut(Fichaje* this,char* inOut);
int fichaje_setInOut(Fichaje* this,char* inOut);

Fichaje* fichaje_newParametros(char* idStr,char* idSocio,char* hora,char* minutos, char* dia, char* mes, char* anio, char* inOut);
int employee_buscarFecha(LinkedList* pArrayListEmployee,LinkedList* listaFichaje ,int dia, int mes, int anio);
void employee_ListaSociosPresentes(LinkedList* pArrayListEmployee,LinkedList* listaFichaje);

#endif // employee_H_INCLUDED
