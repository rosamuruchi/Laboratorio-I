#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "clientes.h"
#include "juegos.h"
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarClientes( eClientes x[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = LIBRE;
        x[i].id=0;
    }
}
int buscarLibreClientes( eClientes x[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i< tam; i++)
    {
        if( x[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
int buscarIdClientes(eClientes x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( x[i].id == id && x[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int nextIdClientes (eClientes lista[], int len)
{
    int retorno = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(lista[i].id>retorno)
            {
                retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}

void harcodearClientes(eClientes x[])
{
    int i;
    eClientes y[]=
    {
        {100,"Martinez","ana", 'f', "Avellaneda", 1},
        {101,"Moyano","luis", 'm', "Suarez", 1},
        {102,"Marino","alberto", 'm', "Maipu", 1},
        {103,"Arevalos","julia", 'f', "Rivadavia", 1},
        {104,"Dominguez","julieta", 'f', "Corrientes", 1},
        {105,"Rincon","andrea", 'f', "Zarate", 1},
        {106,"Romero","mauro", 'm', "Mitre", 1}
    };
    for(i=0; i<7; i++)
    {
        x[i] = y[i];
    }
}


void listadoDeClientes(eClientes lista[], int length)
{
    int i;
    printf("\n----------------------------------------------------------\n");
    printf("ID\tNOMBRE\t APELLIDO\tSEXO\tDOMICILIO\n");
    printf("\n----------------------------------------------------------\n");

    for(i=0; i<length; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            printf("%d\t%s\t %s \t%c \t%s\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].sexo,lista[i].Domicilio);
        }
    }
}

int addClientes(eClientes lista[], int len, int id, char nombre[],char apellido[],char sexo,char domicilio[])
{
    int returnAux= -1;
    int libre;
    int siguienteId;
    libre=buscarLibreClientes(lista,len);
    siguienteId=nextIdClientes(lista,id);

    lista[libre].id = siguienteId;
    strcpy(lista[libre].nombre,nombre);
    strcpy(lista[libre].apellido,apellido);
    lista[libre].sexo = sexo;
    strcpy(lista[libre].Domicilio,domicilio);
    lista[libre].isEmpty = OCUPADO;
    returnAux = 0;

    return returnAux;

}
int altaClientes(eClientes lista[],int tam)
{
    int retorno=-1;
    int indice;
    int clienteBuscado;
    int agregarCliente;
    int validarNombre;
    int validarId;
    int validarSexo;
    int validarDomicilio;
    int validarApellido;

    int auxiliarId;
    char auxiliarNombre[50];
    char auxiliarApellido[50];
    char auxiliarDomicilio[50];
    char auxiliarCaracter;

    indice = buscarLibreClientes(lista, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        listadoDeClientes(lista,tam);
        validarId=getEntero(&auxiliarId,"Ingrese Id:","ERROR! Reingrese Id:",0,999);
        if(validarId!=0)
        {
            printf("ID: %d\n",auxiliarId);
        }
        clienteBuscado= buscarIdClientes(lista,tam,auxiliarId);
        if(clienteBuscado != -1)
        {
            printf("Existe un cliente con el ID %d\n", auxiliarId);
        }
        else
        {
            validarNombre= getString(auxiliarNombre,"Ingrese Nombre:","ERROR! Reingrese su Nombre:");
            validarApellido= getString(auxiliarApellido,"Ingrese Apellido:","ERROR! Reingrese su Apellido:");
            validarSexo= getCaracter(&auxiliarCaracter,"Ingrese Sexo [F/M]:","ERROR! Reingrese su Sexo [F/M]:",'F','M');
            validarDomicilio= getStringAlfaNumerico(auxiliarDomicilio,"Ingrese Domicilio:","ERROR! Reingrese su Domicilio:");

            if(validarNombre != 0)
            {
                printf("NOMBRE: %s\n",auxiliarNombre);
            }
            if(validarApellido != 0)
            {
                printf("APELLIDO: %s\n",auxiliarApellido);
            }
            if(validarSexo != 0)
            {
                printf("SEXO: %c\n",toupper(auxiliarCaracter));
            }
            if(validarDomicilio != 1)
            {
                printf("DOMICILIO: %s\n\n",auxiliarNombre);
            }
            agregarCliente=addClientes(lista,tam,indice,auxiliarNombre,auxiliarApellido,auxiliarCaracter,auxiliarDomicilio);

            if(agregarCliente== -1)
            {
                printf("No se pudo Cargar el cliente!\n");
            }
            else
            {
                retorno=0;
                printf("cliente Cargado!\n");
            }
        }
    }
    return retorno;
}
void modificarClientes(eClientes lista[], int len)
{
    int auxiliarId;
    int clienteBuscado;
    char respuesta;
    int opcion;

    int validarNombre;
    int validarSexo;
    int validarDomicilio;
    int validarApellido;

    char auxiliarNombre[50];
    char auxiliarApellido[50];
    char auxiliarDomicilio[50];
    char auxiliarCaracter;


    listadoDeClientes(lista,len);

    printf("Ingrese Id: ");
    scanf("%d", &auxiliarId);

    clienteBuscado = buscarIdClientes(lista,len,auxiliarId);

    if( clienteBuscado == -1)
    {
        printf("No hay ningun Cliente con el ID %d\n", auxiliarId);
    }
    else
    {
        printf("El Id corresponde a : %s", lista[clienteBuscado].nombre);
        printf("\nModificar?s/n: ");
        respuesta=tolower(getche());
        if(respuesta== 's')
        {
            printf("\nIngrese que desea modificar:\n1.APELLIDO\n2.NOMBRE\n3.SEXO\n4.DOMICILIO\n5.Cancelar\nOpcion:");
            fflush(stdin);
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                validarApellido= getString(auxiliarApellido,"Ingrese Apellido:","ERROR! Reingrese su Apellido:");
                if(validarApellido != 0)
                {
                    strcpy(lista[clienteBuscado].apellido,auxiliarApellido);
                    printf("APELLIDO: %s\n",auxiliarApellido);
                }
                break;
            case 2:
                validarNombre= getString(auxiliarNombre,"Ingrese Nombre:","ERROR! Reingrese su Nombre:");
                if(validarNombre != 0)
                {
                    strcpy(lista[clienteBuscado].nombre,auxiliarNombre);
                    printf("NOMBRE: %s\n",auxiliarNombre);
                }
                break;
            case 3:
                validarSexo= getCaracter(&auxiliarCaracter,"Ingrese Sexo [F/M]:","ERROR! Reingrese su Sexo [F/M]:",'F','M');
                if(validarSexo != 0)
                {
                    lista[clienteBuscado].sexo=auxiliarCaracter;
                    printf("SEXO: %c\n",toupper(auxiliarCaracter));
                }
                break;
            case 4:
                validarDomicilio= getStringAlfaNumerico(auxiliarDomicilio,"Ingrese Domicilio:","ERROR! Reingrese su Domicilio:");
                if(validarDomicilio == 0)
                {
                    strcpy(lista[clienteBuscado].Domicilio,auxiliarDomicilio);
                    printf("DOMICILIO: %s\n",auxiliarNombre);
                }
                break;

            case 5:
                system("pause");
                break;
            }
        }
        else if(respuesta == 'n')
        {
            printf("\nEmpleado Cancelado\n");
        }
        else
        {
            printf("\nPor favor Ingresar s/n!\n");
        }
    }

}
int removeClientes(eClientes lista[], int len, int id)
{
    int retorno= -1;
    int indice;

    indice = buscarIdClientes(lista,len,id);
    if( indice == -1)
    {
        printf("No hay ningun CLIENTE con el Id: %d\n", id);
    }
    else
    {
        lista[indice].isEmpty = LIBRE;
        retorno=0;
    }
    return retorno;
}
int BajaClientes(eClientes lista[], int len)
{
    int retorno=-1;
    char borrar;
    int indice;
    int auxiliarId;
    int clienteBorrado;

    listadoDeClientes(lista,len);

    printf("Ingrese Id Del Cliente: ");
    fflush(stdin);
    scanf("%d", &auxiliarId);

    indice = buscarIdClientes(lista,len,auxiliarId);

    if( indice == -1)
    {
        printf("No hay ningun cliente con el Id: %d\n", auxiliarId);
    }
    else
    {
        printf("El Cliente corresponde a: %s %s\n",lista[indice].nombre,lista[indice].apellido);

        printf("\nConfirma borrado?[s/n]: ");
        fflush(stdin);
        borrar=tolower(getche());
        if(borrar == 'n')
        {
            printf("\nBorrado cancelado\n\n");
        }
        else if(borrar == 's')
        {
            clienteBorrado=removeClientes(lista,len,auxiliarId);
            if(clienteBorrado==0)
            {
                retorno=0;
                printf("\nSe ha eliminado el cliente\n\n");
            }
            else
            {
                printf("\nNo se ha podido borrar el cliente\n\n");
            }
        }
    }
    return retorno;
}
void ordenarClientes(eClientes lista[], int len)
{
    eClientes AuxClientes;
    int i,j;

    for(i=0; i<len -1; i++)
    {
        for(j = i +1; j < len; j++)
        {
            if( stricmp(lista[i].apellido,lista[j].apellido)>0)
            {
                AuxClientes = lista[i];
                lista[i] = lista[j];
                lista[j] = AuxClientes;
            }
            else if( (stricmp(lista[i].apellido,lista[j].apellido)==0) && stricmp(lista[i].nombre,lista[j].nombre)>0)
            {
                AuxClientes = lista[i];
                lista[i] = lista[j];
                lista[j] = AuxClientes;
            }
        }
    }
    printf("\n----------------------------------------------------------\n");
    printf("\tLISTA ORDENADA POR APELLIDO Y NOMBRE ascendente\n");
    listadoDeClientes(lista,len);
}
