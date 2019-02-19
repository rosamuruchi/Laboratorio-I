#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "clientes.h"
#include "parser.h"

int main()
{
    LinkedList* listaClientes;
    LinkedList* listaAbono;
    listaClientes=ll_newLinkedList();

    int opcion=0;
    do
    {
        printf("\n1- CARGAR ARCHIVO");
        printf("\n2- MOSTRAR LISTA");
        printf("\n3- CREAR Y COMPLETAR");
        printf("\n4- MOSTRAR LISTA ABONOS Y CLIENTES");
        printf("\n5- GENERAR ARCHIVO txt Y bin");
        printf("\n6- SALIR");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaClientes);
            ll_sort(listaClientes,employeeSortById,0);
            break;
        case 2:
            listarClientes(listaClientes);
            break;
        case 3:
            listaAbono=crearListaAbono(listaClientes);
            printf("Lista Creada Exitosamente!\n");
            break;
        case 4:
            ll_sort(listaAbono,abonoSortByImporte,0);
            ListarAbonosYClientes(listaAbono,listaClientes);
            break;
        case 5:
            controller_saveAsText("abonos.csv",listaAbono);
            controller_saveAsBinary("abonos.bin",listaAbono);
            break;
        default:
            printf("Opcion Incorrecta!\n");
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=6);
    return 0;
}
