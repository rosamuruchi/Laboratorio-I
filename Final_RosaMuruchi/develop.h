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






int employeeSortById(void* empleadoA, void* empleadoB);
int abonoSortByImporte(void* empleadoA, void* empleadoB);

