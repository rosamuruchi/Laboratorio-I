#include "LinkedList.h"
#include "utn.h"

typedef struct
{
    int id;
    char nombre[51];
    char sexo[2];
    char numeroTelefono[21];
    int importe;
}eClientes;

typedef struct
{
    int id;
    int tipo;
    int idCliente;
    float importeFinal;
}eAbono;

eClientes* newClientes();
eClientes* newParametros(char* id,char* nombre, char* sexo, char* numero, char* importe);

eAbono* newAbono();

int clientes_set_id(eClientes* this, int id);
int clientes_set_nombre(eClientes* this, char* nombre);
int clientes_set_sexo(eClientes* this, char* sexo);
int clientes_set_telefono(eClientes* this, char* telefono);
int clientes_set_importe(eClientes* this, int importe);
//////
int clientes_get_id(eClientes* lista,int* id);
int clientes_get_sexo(eClientes* lista,char* sexo);
int clientes_get_nombre(eClientes* lista,char* nombre);
int clientes_get_telefono(eClientes* lista,char* telefono);
int clientes_get_importe(eClientes* lista,int* importe);
//////
int abono_set_id(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,int* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float importeFinal);
int abono_getImporteFinal(eAbono* this,float* importeFinal);

int employeeSortById(void* empleadoA, void* empleadoB);
void abonos_lista(eAbono* lista);
int lista_abonos(void* pElement);
int abonoSortByImporte(void* empleadoA, void* empleadoB);
LinkedList* crearListaAbono(LinkedList* this);

///////
//int compararNumeros(void* numero1, void* numero2);
int employeeSortById(void* empleadoA, void* empleadoB);
void listarClientes (LinkedList* lista);
void clientes_lista (eClientes* lista);
void ListarAbonosYClientes (LinkedList* listaAbono, LinkedList* listaClientes);
