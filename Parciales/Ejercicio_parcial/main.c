#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAMU 100
#define TAMP 1000

int main()
{
    char seguir='s';
    int opcion=0;

    eUsuarios ListadeUsuarios[TAMU];
    inicializarListaUsuarios(ListadeUsuarios,TAMU);
    inicializarUsuariosHardCode(ListadeUsuarios,TAMU);


    eProductos ListadeProductos [TAMP];
    inicializarListaProductos(ListadeProductos,TAMP);
    inicializarProductosHardCode(ListadeProductos,TAMP);


    while(seguir=='s')
    {
        printf("---------MENU---------\n");
        printf("----------------------\n\n");
        printf("1- Alta de Usuario\n");
        printf("2- Modificar Datos del Usuario\n");
        printf("3- Baja del Usuario\n");
        printf("4- Publicar Producto\n");
        printf("5- Modificar Publicacion\n");
        printf("6- Cancelar Publicacion\n");
        printf("7- Comprar Producto\n");
        printf("8- Listar Publicaciones de Usuario\n");
        printf("9- Listar Publicaciones\n");
        printf("10- Listar Usuarios\n\n");
        printf("11_ SALIR\n\n");
        printf("----------------------\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                 altadeUsuarios(ListadeUsuarios,TAMU);
                 mostrarListaUsuarios(ListadeUsuarios,TAMU);
                break;
            case 2:
                modificarDatos(ListadeUsuarios,TAMU);
                break;
            case 3:
                bajaUsuarios (ListadeUsuarios,TAMU);
                break;
            case 4:
                publicarProductos(ListadeProductos,TAMP);
                break;
            case 5:
                modificarPublicacion(ListadeProductos,TAMP);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                mostrarListaProductos(ListadeProductos,TAMP);
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
