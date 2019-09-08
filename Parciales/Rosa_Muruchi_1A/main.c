#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "juegos.h"
#include "alquileres.h"
#include "utn.h"
#include "informes.h"

#define TAMJUEGO 20
#define TAMCLIENTES 100
#define TAMALQUILER 80
int main()
{
    eJuegos ListaDeJuegos [TAMJUEGO];
    eClientes ListaDeClientes[TAMCLIENTES];
    eAlquileres ListaDeAlquileres[TAMALQUILER];

    inicializarJuegos(ListaDeJuegos,TAMJUEGO);
    inicializarClientes(ListaDeClientes,TAMCLIENTES);
    inicializarAlquiler(ListaDeAlquileres,TAMALQUILER);

    //harcodearJuegos(ListaDeJuegos);
    harcodearClientes(ListaDeClientes);
    harcodearAlquileres(ListaDeAlquileres);

    menuDeTodo(ListaDeClientes,TAMCLIENTES,ListaDeJuegos,TAMJUEGO,ListaDeAlquileres,TAMALQUILER);
    return 0;
}
