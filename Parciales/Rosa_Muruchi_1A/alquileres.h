#include "utn.h"
#include "juegos.h"
#include "clientes.h"
#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct
{
    int idAlquiler;
    int idJuego;
    int idCliente;
    int isEmpty;
    EFecha fecha;
} eAlquileres;

void inicializarAlquiler( eAlquileres x[], int tam);
int buscarLibreAlquiler( eAlquileres x[], int tam);
int buscarIdAlquiler(eAlquileres x[], int tam, int id);
int buscarFechaAlquiler(eAlquileres x[], int tam, int dia, int mes, int anio);
int nextIdAlquiler (eAlquileres lista[], int len);
void harcodearAlquileres(eAlquileres x[]);

void listadoDeAlquileres(eAlquileres listaAlquileres[], int tamAlquiler);
int addAlquiler(eAlquileres lista[], int len, int idAlquiler,int idJuego,int idCliente, int dia, int mes, int anio);
void altaAlquileres (eAlquileres listaAlquileres[], int tamAlquiler, eJuegos listaJuegos[],int tamJuegos, eClientes listaClientes[],int tamClientes);
void modificarAlquileres(eAlquileres listaAlquileres [], int tam);
int removeAlquiler(eAlquileres lista[], int len, int id);
void BajaAlquiler(eAlquileres lista[], int len);
#endif
