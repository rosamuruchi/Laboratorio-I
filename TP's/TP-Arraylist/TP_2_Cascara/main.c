#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20


int main()
{
    EPersona listaDePersonas[TAM];



    char seguir='s';
    int opcion=0;

    inicializarLista(listaDePersonas,TAM);

    do
        {
        printf("---------------------------------------\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("Respuesta: ");
        scanf("%d",&opcion);

        printf("---------------------------------------\n");

        switch(opcion)
        {
            case 1:

                    cargarDatos(listaDePersonas,TAM);
                break;
            case 2:
                    borrarDatos (listaDePersonas, TAM);

                break;
            case 3:
                    ordenarPorNombre(listaDePersonas,TAM);
                    mostrarNombres (listaDePersonas,TAM);

                break;
            case 4:
                    graficodeEdades(listaDePersonas,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }while(seguir=='s');


    return 0;
}
