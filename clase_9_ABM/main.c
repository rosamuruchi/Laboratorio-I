#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 3

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona personas[CANT];

    init(personas, CANT);

    do{
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Modificar persona\n");
        printf("4- Imprimir lista ordenada por apellido y nombre\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(personas, CANT);
                mostrarListaPersonas(personas,CANT);
                break;
            case 2:
                baja(personas, CANT);
                break;
            case 3:
                modificacion(personas,CANT);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    return 0;
}
