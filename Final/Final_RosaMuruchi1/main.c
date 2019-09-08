#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
    int option = 0;
    char respuesta;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFichajes= ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("socios.csv",listaEmpleados);
            controller_loadFromTextFichaje("fichajes.csv",listaFichajes);
            printf("Desea agregar Nuevo socio?\n[s/n]:");
            respuesta= tolower(getche());
            printf("\n\n");
            while(respuesta=='s')
            {
                controller_addEmployee(listaEmpleados,listaFichajes);
                printf("Desea agregar Nuevo socio?\n[s/n]:");
                respuesta= tolower(getche());
            }
            system("pause");
            break;
        case 2:
            controller_editEmployee(listaEmpleados);
            break;
        case 3:
            controller_removeEmployee(listaEmpleados,listaFichajes);
            break;
        case 4:
            ll_sort(listaEmpleados,employee_compareEmployeeByDni,0);
            controller_ListEmployee(listaEmpleados, listaFichajes);
            break;
        case 5:
            employee_ListaSociosPresentes(listaEmpleados,listaFichajes);
            break;

        case 6:
            listarFichajes(listaFichajes);
            system("pause");
            break;
        case 7:
            break;
        default:
            break;
        }
    }
    while(option != 7);
    return 0;
}

