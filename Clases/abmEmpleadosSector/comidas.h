/*#include "almuerzos.h"
#include "utn.h"
#include "ArrayEmployee.h"*/

#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;
} eComida;
#endif
//COMIDA
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
//void mostrarComidas(eEmpleado emp,eAlmuerzo almuerzos [], int tamAlmuerzo, eComida comidas[], int tamComida);
