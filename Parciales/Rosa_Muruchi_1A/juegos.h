#include "utn.h"
#include "clientes.h"
#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;
    float importe;
} eJuegos;

#endif
void inicializarJuegos( eJuegos x[], int tam);
int buscarLibreJuegos( eJuegos x[], int tam);
int buscarIdJuegos(eJuegos x[], int tam, int id);
int nextIdJuegos (eJuegos lista[], int len);

void harcodearJuegos(eJuegos x[]);
void listadoDeJuegos(eJuegos lista[], int length);
int addJuegos(eJuegos lista[], int len, int id, char descripcion[],float importe);
int altaJuegos(eJuegos lista[],int tam);
void modificarJuegos(eJuegos lista[], int len);
int removeJuegos(eJuegos lista[], int len, int id);
int BajaJuegos(eJuegos lista[], int len);
void ordenarJuegos(eJuegos lista[], int len);
