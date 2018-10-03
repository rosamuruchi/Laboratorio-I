#include "utn.h"
#include "comidas.h"

#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;
} eSector;

typedef struct {
    int dia, mes, anio;
}EFecha;

#endif
//MENU
int menu();

//EMPLEADOS
void inicializarEmpleados( eEmpleado x[], int tam);
void harcodearEmpleados(eEmpleado x[]);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);

//SECTOR
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
// fecha
/*bool IsNumber(char* szString)
{
 //Recorremos todos los caracteres y comprobamos que cada uno sea un número
 for(unsigned int i=0;i<strlen(szString);i++)
 {
  if(!(szString[i]>='0' && szString[i]<='9')) return false;
 }
 return true;
}

int main(){
char fecha[4];
printf("Introduce la fecha de nacimiento(4 digitos): ");
scanf("%s",fecha);
if(IsNumber(fecha)==1){
printf("\nNaciste: %i",atoi(fecha));
}
else{
printf("\nError, no has introducido numeros");
}
return 0;
}*/
