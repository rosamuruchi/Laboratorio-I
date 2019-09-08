#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "numeroNatural.h"
#include "parser.h"

int main()
{
    LinkedList* numero;
    LinkedList* depurado;
    LinkedList* repetidos;
    repetidos=ll_newLinkedList();
    depurado=ll_newLinkedList();
    numero=ll_newLinkedList();
    int opcion=0;
    do
    {
        printf("\n1- Cargar archivo");
        printf("\n2- Mostrar Listado");
        printf("\n3- Completar Numeros");
        printf("\n4- Listar");
        printf("\n5- Generar");
        printf("\n6- Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            parserRead(numero);
            system("pause");
            break;
        case 2:
            printAllNumbers(numero);
            break;
        case 3:
            completarNumeros(numero);
            break;
        case 4:
            depurado=ll_clone(numero);
            buscarNumeroRepetido(numero,repetidos,depurado);
            break;
        case 5:
            //parserWrite(repetidos,"repetidos.csv");
            //parserWrite(depurado,"depurado.csv");
            //parserWrite(numero,"datos.csv");
            break;

        }
        system("pause");
        //system("cls");
    }while(opcion!=6);
    return 0;
}

