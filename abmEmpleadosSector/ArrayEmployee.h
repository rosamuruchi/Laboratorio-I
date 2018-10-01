#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
} eSector;

typedef struct
{
    int id;
    char descripcion[20];
} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;

} eAlmuerzo;

void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void harcodearEmpleados(eEmpleado x[]);
int menu();

//COMIDAS
void harcodearAlmuerzos(eAlmuerzo x[]);
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
void mostrarAlmuerzos(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas);
void mostrarAlmuerzoPorEmpleados(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas);
