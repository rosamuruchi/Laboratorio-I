#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "comidas.h"
#include "utn.h"
#include "ArrayEmployee.h"
#include "almuerzos.h"

#define LIBRE 0
#define OCUPADO 1


void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[])
{
    int i;
    for(i=0; i < tamComida; i++)
    {
        if( comidas[i].id == idComida)
        {
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}
