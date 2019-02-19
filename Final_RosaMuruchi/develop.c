#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "develop.h"
#include "LinkedList.h"

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;
    id ++;
    return id;
}

eClientes* newClientes()
{
    eClientes* aux;
    aux=(eClientes*)malloc(sizeof(eClientes));
    if(aux!=NULL)
    {
        aux->id=0;
        strcpy(aux->nombre, "");
        strcpy(aux->sexo, "");
        strcpy(aux->numeroTelefono, "");
        aux->importe=0;
    }
    return aux;
}

eAbono* newAbono()
{
    eAbono* abonoAux;
    abonoAux=(eAbono*)malloc(sizeof(eAbono));
    return abonoAux;
}

eClientes* newParametros(char* id,char* nombre, char* sexo, char* numero, char* importe)
{
    eClientes* clientes;
    clientes= newClientes();
    if(clientes!= NULL)
    {
        /*clientes_set_id(clientes,atoi(id));
        clientes_set_nombre(clientes,nombre);//STRING
        clientes_set_sexo(clientes,sexo);//STRING
        clientes_set_telefono(clientes,numero);//STRING
        clientes_set_importe(clientes,atoi(importe));*/
    }
    return clientes;
}

///SETTERS Y GETTERS///




///////////////FUNCIONES/////////////////////////
int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno;

    eClientes* empA;
    eClientes* empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eClientes*) empleadoA;
        empB = (eClientes*) empleadoB;
        if(empA->id == empB->id)
        {
             retorno = 1;
        }
        if(empA->id > empB->id)
        {
            retorno = -1;
        }
        if(empA->id < empB->id)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int abonoSortByImporte(void* empleadoA, void* empleadoB)
{
    int retorno;

    eAbono* empA;
    eAbono*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eAbono*) empleadoA;
        empB = (eAbono*) empleadoB;
        if(empA->importeFinal == empB->importeFinal)
        {
             retorno = 1;
        }
        else if(empA->importeFinal > empB->importeFinal)
        {
            retorno = -1;
        }
        else if(empA->importeFinal < empB->importeFinal)
        {
            retorno = 0;
        }
    }
    return retorno;
}
