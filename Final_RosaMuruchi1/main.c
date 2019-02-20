#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFichajes= ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("socios.csv",listaEmpleados);
            controller_loadFromTextFichaje("fichajes.csv",listaFichajes);
            controller_addEmployee(listaEmpleados);
            system("pause");
            break;
        case 2:
            controller_editEmployee(listaEmpleados);
            break;
        case 3:
            controller_removeEmployee(listaEmpleados,listaFichajes);
            break;
        case 4:
            controller_ListEmployee(listaEmpleados, listaFichajes);
            break;
        case 5:
            employee_ListaSociosPresentes(listaEmpleados,listaFichajes);
            break;
        case 6:
            //controller_saveAsText("data.csv",listaEmpleados);
            system("pause");
            break;
        case 9:
            //controller_saveAsBinary("data.bin",listaEmpleados);
            system("pause");
            break;
        case 10:
            break;
        }
    }
    while(option != 10);
    return 0;
}

