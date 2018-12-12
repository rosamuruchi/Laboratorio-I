#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "clientes.h"
#include "parser.h"

int main()
{
    LinkedList* listaClientes;
    LinkedList* listaAbonos;
    listaClientes=ll_newLinkedList();
    listaAbonos=ll_newLinkedList();

    int opcion=0;
    do
    {
        printf("\n1- Cargar archivo");
        printf("\n2- Lista Cargada");
        printf("\n3- Crear y completar Abono");
        printf("\n4- Lista Abonos");
        printf("\n5- Generar Archivo abonos.csv y abonos.bin");
        printf("\n6- Salir");
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
            crearListaAbono(listaAbonos);
            break;
        case 4:
            ListarAbonos(listaAbonos,listaClientes);
            break;
        case 5:
            controller_saveAsText("abonos.csv",listaAbonos);
            controller_saveAsBinary("abonos.bin",listaAbonos);
            break;
        case 6:
            break;
        }
        //system("pause");
        system("cls");
    }
    while(opcion!=6);
    return 0;
}
