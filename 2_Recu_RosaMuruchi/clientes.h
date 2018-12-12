#include "LinkedList.h"
#include "utn.h"

typedef struct
{
    int id;
    char nombre[51];
    char sexo[1];
    char numeroTelefono[21];
    int importe;
}eClientes;

typedef struct
{
    int id;
    int tipo;
    int idCliente;
    int importeFinal;
}eAbono;

eClientes* newClientes();
eClientes* newParametros(char* id,char* nombre, char* sexo, char* numero, char* importe);
int clientes_set_id(eClientes* this, int id);
int clientes_set_nombre(eClientes* this, char* nombre);
int clientes_set_sexo(eClientes* this, char sexo[]);
int clientes_set_telefono(eClientes* this, char telefono[]);
int clientes_set_importe(eClientes* this, int importe);
//////
int clientes_get_id(eClientes* lista,int* id);
int clientes_get_sexo(eClientes* lista,char* sexo);
int clientes_get_nombre(eClientes* lista,char* nombre);
int clientes_get_telefono(eClientes* lista,char* telefono);
int clientes_get_importe(eClientes* lista,int* importe);

eAbono* new_abono();
LinkedList* crearListaAbono(LinkedList* this);
int employeeSortById(void* empleadoA, void* empleadoB);
int abono_getId(eAbono* this,int* id);
void completarNumeros(LinkedList* lista, LinkedList* abono);
void ListarAbonos (LinkedList* listaAbono, LinkedList* listaCliente);
void listarClientes (LinkedList* lista);
void clientes_lista (eClientes* lista);
int comprobarIdClienteRepetido(LinkedList* repetido, eClientes* lista);
int calcularImporteFinal(LinkedList* lista, LinkedList* abono);
