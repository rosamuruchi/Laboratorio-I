#include "utn.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

void menuDeTodo(eClientes listaClientes[], int tamClientes, eJuegos listaJuegos[], int tamJuegos,eAlquileres listaAlquileres[],int tamAlquieleres);
int menuJuegos();
int menuClientes();
int menuAlquileres();
int menuInformes();

void recaudacionTotalDeAlquileres(eAlquileres listaAlquiler[], int tamAlquiler,eJuegos listaJuegos[],int tamJuegos);
void mostrarListaAlquileresxClientes(eAlquileres listaAlquiler[],int tamAlquiler,eClientes listaClientes[],int tamClientes);

void mostrarListaAlquileresxJuegos(eAlquileres listaAlquiler[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos);
void mostrarListaDeJuegosxFechaDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos);

int cantidadDeAlquileresPorJuego(eAlquileres listaAlquileres[],int tamAlquiler,int idJuego);
int minimaCantidadDeJuegos (eAlquileres listaAlquileres[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos);
void mostrarListaJuegosMenosAlquilados(eAlquileres listaAlquiler[],int tamAlquiler,eJuegos listaJuegos[],int tamJuegos);

void mostrarListaAlquileresxClientes(eAlquileres listaAlquiler[],int tamAlquiler,eClientes listaClientes[],int tamClientes);
void mostrarListaDeClientesxFechaDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes);

int cantidadDeAlquileresPorClientes(eAlquileres listaAlquileres[],int tamAlquiler,int idCliente);
int maximaCantidadClientesDeAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes);
void mostrarListaClientesConMasAlquileres(eAlquileres listaAlquileres[],int tamAlquiler,eClientes listaClientes[],int tamClientes);

