#include "funciones.h"
#include "autos.h"

#ifndef EGRESOS_H_INCLUDED
#define EGRESOS_H_INCLUDED

typedef struct {

    int marca;
    float importe;

}EEgresos;

#endif

//EGRESOS//

int buscarPorIdAuto(EAutos lista[],int limite, int auxId);
void inicializarEgresosHardCode(EEgresos listaEgresos[],int limite);

int devolverHorasEstadia();

float devolverValorEstadia(int lista);

void egresodeAutos (EEgresos listaEgresos [], int limiteAuto, EPropietario listaProp [],int limiteProp,EAutos listaAutos[]);

void recaudacionTotal( EEgresos listaEgresos [], int limite);

void recaudacionPorMarca(EEgresos listaEgresos[], int limite);

void listaPropietarioConAutos(EPropietario listaProp[], int limiteProp,EAutos listaAutos[], int limiteAutos);

void listaAutoPorMarcaAudi(EAutos listaAutos[],int limiteAutos, EPropietario listaProp[],int limiteProp, int marca);

void listaAutosPorPatente(EAutos listaAutos[],int limiteAutos, EPropietario listaProp[], int limiteProp);
