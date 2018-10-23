#include <stdio.h>
#include <stdlib.h>
#include "pendrive.h"


int main()
{
    char seguir = 's';

    ePendrive pendrive;

    do
    {
        switch(menu())
        {
        case 1:
            cargarPendrive(&pendrive);
            system("pause");
            break;
        case 2:
            mostrarPendrive(&pendrive);
            system("pause");
            break;
        case 3:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion no valida!\n");
            break;
        }

    }
    while (seguir == 's');


        return 0;
}


