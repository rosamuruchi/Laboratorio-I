#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "clientes.h"
#include "parser.h"

int main()
{
    LinkedList* listaClientes;
    listaClientes=ll_newLinkedList();


    int opcion=0;
    do
    {
        printf("\n1- Cargar archivo");
        printf("\n2- CREAR Y COMPLETAR");
        printf("\n3- MOSTRAR LISTA");
        printf("\n4- Generar");
        printf("\n5- Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaClientes);
            break;
        case 2:
            listarClientes(listaClientes);
            break;
        case 3:
            ListarAbonos(listaClientes);
            break;
        case 4:
            controller_saveAsText("abonos.csv",listaClientes);
            controller_saveAsBinary("abonos.bin",listaClientes);
            break;

        }
        system("pause");
        //system("cls");
    }while(opcion!=6);
    return 0;
}
