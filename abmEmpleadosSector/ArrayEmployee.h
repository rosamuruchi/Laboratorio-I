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

//MENU
int menu();
int esString (char lista[]);
int esEntero(char lista[]);
int esCaracter (char letra);
int getEntero (int* numero,char message[], char messageError[], int lowlimit,int hilimit);
int getString (char palabra[], char message[], char messageError[]);
int getCaracter (char* caracter ,char message[], char messageError[],char lowlimit, char hilimit);
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
//SECTOR
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);

//ALMUERZO
void harcodearAlmuerzos(eAlmuerzo x[]);

void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
void mostrarComidas(eEmpleado emp,eAlmuerzo almuerzos [], int tamAlmuerzo, eComida comidas[], int tamComida);

void mostrarAlmuerzos(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas);
void mostrarAlmuerzoPorEmpleados(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas,eSector sectores[], int tamSector);
