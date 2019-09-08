#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

typedef struct {

    int idPropietario;
    char nombre[50];
    char direccion[50];
    char numeroTarjeta[50];
    int estado;

}EPropietario;
#endif

//PROPIETARIOS//
void inicializarListaPropietario(EPropietario lista[],int limite);
void inicializarPropietariosHardCode(EPropietario lista[], int limite);
int buscarLugarLibre(EPropietario lista[],int limite);
int siguienteId(EPropietario lista[],int limite);

void altaDePropietario (EPropietario lista[], int limite);
void mostrarListaPropietario(EPropietario lista[],int limite);
void modificarDatos(EPropietario lista[], int limite);
void bajaPropietario (EPropietario lista[], int limite);
