#include "utn.h"
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int id;
    char apellido[51];
    char nombre[51];
    char sexo;
    char Domicilio [51];
    int isEmpty;
} eClientes;
#endif // CLIENTES_H_INCLUDED
void inicializarClientes( eClientes x[], int tam);
int buscarLibreClientes( eClientes x[], int tam);
int buscarIdClientes(eClientes x[], int tam, int id);
int nextIdClientes (eClientes lista[], int len);
void listadoDeClientes(eClientes lista[], int length);
void harcodearClientes(eClientes x[]);

int addClientes(eClientes lista[], int len, int id, char nombre[],char apellido[],char sexo,char domicilio[]);
int altaClientes(eClientes lista[],int tam);
void modificarClientes(eClientes lista[], int len);
int removeClientes(eClientes lista[], int len, int id);
int BajaClientes(eClientes lista[], int len);
void ordenarClientes(eClientes lista[], int len);

int contadorDeAltas (eClientes lista[],int tam);
