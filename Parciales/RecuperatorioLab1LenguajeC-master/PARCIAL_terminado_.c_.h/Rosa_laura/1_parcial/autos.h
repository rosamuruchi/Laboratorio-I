#include "funciones.h"
#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
typedef struct {

    int idAuto;
    char patente[50];
    int marca;
    int propietario;
    int estadoAuto;

}EAutos;
#endif

//INGRESOS//
void inicializarListaAutos(EAutos lista[],int limite);
void inicializarAutosHardCode(EAutos lista[], int limite);
void mostrarListaAutos(EAutos listaAutos [],int limiteAutos, EPropietario listaProp [], int limiteProp);
int buscarLugarLibreAuto(EAutos lista[],int limite);
int siguienteIdAutos(EAutos lista[],int limite);
void ingresoDeAutomovil(EAutos lista[],int limite);



