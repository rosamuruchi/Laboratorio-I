#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0


int inicializarListaUsuarios( eUsuarios lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            lista[i].estado= LIBRE;
            lista[i].idUsuarios= 0;
        }
    }
    return retorno;
}

void inicializarUsuariosHardCode(eUsuarios usuarios[], int limite)
{
    int id[10] = {1,2,3,4, 5,6,7,8,9, 10};
    char nombre [][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria"};
    int password [10]= {0000,1111,2222,3333,4444,5555,6666,7777,8888,9999};
    int calificacion[5] = {1,2,3,4,5};


    int i;

    for(i=0; i<10; i++)
    {
        usuarios[i].idUsuarios=id[i];
        strcpy(usuarios[i].nombre, nombre[i]);
        usuarios[i].password=password[i];
        usuarios[i].calificacion=calificacion[i];
        usuarios[i].estado = OCUPADO;
    }
}

int inicializarListaProductos( eProductos lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            lista[i].estado= LIBRE;
            lista[i].idProducto= 0;
        }
    }
    return retorno;
}

void inicializarProductosHardCode(eProductos productos[], int limite)
{
    int id[10] = {1,2,3,4,5,6,7,8,9, 10};
    char nombre[][50]= {"Tv21","Celular","Parlante","Play3","Lavarropas","Heladera","Perfume","Cartera","Cocina","AutoFiat"};
    float precio [10]= {5000 ,12500 ,850.5, 13550, 11320.90, 22690,23.69, 960, 5399.99,213566.90};
    int stock[10] = {15,22,37,41,58,12,63,55,9,100};
    int cantidadVendida[5]={10,20,30,40,50};
    int idUsuario[10] = {1,1,3,4, 9,6,8,8,9, 10};

    int i;

    for(i=0; i<10; i++)
    {
        productos[i].idProducto=id[i];
        productos[i].idUsuario=idUsuario[i];
        strcpy(productos[i].nombre, nombre[i]);
        productos[i].precio=precio[i];
        productos[i].stock=stock[i];
        productos[i].cantidadVendida=cantidadVendida[i];
        productos[i].estado = OCUPADO;
    }
}



int buscarLugarLibre(eUsuarios lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;


        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteId(eUsuarios lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                    if(lista[i].idUsuarios>retorno)
                    {
                         retorno=lista[i].idUsuarios;
                    }

            }
        }
    }

    return retorno+1;
}


void mostrarListaUsuarios(eUsuarios lista[],int limite)
{

    int i;
    printf(" Nombres   ID \n");
    for(i=0; i<limite; i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                printf("\n %s     %d \n",lista[i].nombre,lista[i].idUsuarios);
            }
        }
}


void altadeUsuarios(eUsuarios  lista[],int limite)
{
    int index;
    char respuesta='s';
    index=buscarLugarLibre(lista,limite);


          while(respuesta!='n')
         {
            if(index != -1)
            {
                printf("\nIngrese el nombre: ");
                fflush(stdin);
                gets(lista[index].nombre);

                printf("\nIngrese Password: ");
                scanf("%d",&lista[index].password);

                lista[index].idUsuarios= siguienteId(lista,limite);
                lista[index].estado=OCUPADO;
            }
            else
            {
                printf("\nNo hay Espacio!!!");
            }

            printf("\nDesea agregar otra persona? \nResponder con s/n: ");
            respuesta= getche();
            printf("\n");
         }

}




int buscarPorId(eUsuarios lista[] ,int limite, int auxId)
{
    int retorno = -1;
    int i;

        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == OCUPADO && lista[i].idUsuarios == auxId)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}


void modificarDatos(eUsuarios lista[], int limite)
{
    int valor;
    int auxId;
    char respuesta='s';

    eUsuarios auxNombre;
    eUsuarios auxPassword;

    printf("Ingrese el Id para modificar: ");
    scanf("%d",&valor);

    auxId= buscarPorId(lista,limite,valor);

    if(auxId == -1)
    {
        printf("Id INCORRECTO\n\n");
    }
    else
        {
            printf("El usuario ha modificar es : %s ", lista[auxId].nombre);
            printf("\nresponder s/n : ");
            respuesta= getche();
            printf("\n");

            if(respuesta=='s')
            {
                printf("\nIngrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxNombre.nombre);

                strcpy(lista[auxId].nombre,auxNombre.nombre);

                printf("\nIngrese nuevo Password: ");
                scanf("%d",&auxPassword.password);



                system("cls");
                printf("Usuario Cargado con exito!\n");
                mostrarListaUsuarios(lista,limite);
                getch();


            }
            else
            {
                printf("Usuario Cancelado!\n");
            }

        }


}


void bajaUsuarios (eUsuarios lista[], int limite)
{
    int valor;
    int auxId;
    char respuesta='s';

    mostrarListaUsuarios(lista,limite);

    printf("\nIngrese el Id para dar de Baja: ");
    scanf("%d",&valor);

    auxId= buscarPorId(lista,limite,valor);


    if(auxId == -1)
    {
        printf("Id INCORRECTO\n");
    }
    else
        {
            printf("El usuario para dar de baja es : %s ", lista[auxId].nombre);
            printf("\nresponder s/n : ");
            respuesta= getche();
            printf("\n");

            if(respuesta=='s')
            {
                lista[auxId].estado=-1;
                system("cls");
                printf("Usuario Borrado con exito!\n");
            }
            else
            {
                printf("baja cancelada!\n");
            }
        }


}

int buscarLugarLibreProducto(eProductos lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;


        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteIdProducto(eProductos lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                    if(lista[i].idProducto>retorno)
                    {
                         retorno=lista[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}

void publicarProductos (eProductos lista[], int limite)
{
    int auxId;
    int valor;

    printf("Ingresar Id de Usuario: ");
    scanf("%d",&valor);

    auxId=buscarLugarLibreProducto(lista,limite);

    if(auxId!=-1)
    {
        printf("\nIngrese un nombre del Producto: ");
        fflush(stdin);
        gets(lista[auxId].nombre);

        printf("Ingrese el precio: ");
        scanf("%f",&lista[auxId].precio);

        printf("Ingrese el stock del producto: ");
        scanf("%d",&lista[auxId].stock);

        lista[auxId].idProducto=siguienteIdProducto(lista,limite);
        lista[auxId].idUsuario=auxId;
        lista[auxId].estado=OCUPADO;
    }
    else
    {
        printf("NO HAY ESPACIO!\n");
    }

}

void modificarPublicacion(eProductos lista [],int limite)
{

    int auxIdProducto;
    int i;

    mostrarListaProductos(lista,limite);

    printf("Ingresar Id del Producto: ");
    scanf("%d",&auxIdProducto);

    for(i=0; i<limite; i++)
        {
            if(lista[i].idProducto==auxIdProducto && lista[i].estado==OCUPADO)
            {
                printf("\nIngrese nuevo precio del Producto: ");
                scanf("%f", &lista[i].precio);

                printf("\nIngrese nuevo stock del Producto: ");
                scanf("%d", &lista[i].stock);
                break;
            }

        }
    printf(" ID    NOMBRE     PRECIO   CANT.VENDIDA      STOCK\n");

        for(i=0; i<limite; i++)
        {
            if(lista[i].idUsuario==auxIdProducto && lista[i].estado==OCUPADO)
            {
                printf("\n %d      %s     %.2f     %d           %d \n",lista[i].idProducto ,lista[i].nombre,lista[i].precio,lista[i].cantidadVendida,lista[i].stock);
            }
        }



}



void mostrarListaProductos(eProductos lista[],int limite)
{
    int auxId;
    int i;

    printf("Ingresar Id de Usuario: ");
    scanf("%d",&auxId);

    printf(" ID    NOMBRE     PRECIO   CANT.VENDIDA      STOCK\n");

        for(i=0; i<limite; i++)
        {
            if(lista[i].idUsuario==auxId && lista[i].estado==OCUPADO)
            {
                printf("\n %d      %s     %.2f     %d           %d \n",lista[i].idProducto ,lista[i].nombre,lista[i].precio,lista[i].cantidadVendida,lista[i].stock);
            }
        }


}







