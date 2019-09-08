
#include "comidas.h"
#include "utn.h"
#include "ArrayEmployee.h"

#ifndef ALMUERZOS_H_INCLUDED
#define ALMUERZOS_H_INCLUDED
typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    int isEmpty;
    EFecha fechaAlmuerzo;
} eAlmuerzo;
#endif
//ALMUERZO
void harcodearAlmuerzos(eAlmuerzo x[]);
void mostrarAlmuerzos(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas);
void mostrarAlmuerzoPorEmpleados(eAlmuerzo almuerzos [], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleado,eComida comidas[], int tamComidas,eSector sectores[], int tamSector);
