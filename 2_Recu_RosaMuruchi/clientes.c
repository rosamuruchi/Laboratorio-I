#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "clientes.h"
#include "LinkedList.h"

#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;
    id ++;
    return id;
}

eClientes* newClientes()
{
    eClientes* aux;
    aux=(eClientes*)malloc(sizeof(eClientes));
    if(aux!=NULL)
    {
        aux->id=0;
        strcpy(aux->nombre, "");
        strcpy(aux->sexo, "");
        strcpy(aux->numeroTelefono, "");
        aux->importe=0;
    }
    return aux;
}

eAbono* newAbono()
{
    eAbono* abonoAux;
    abonoAux=(eAbono*)malloc(sizeof(eAbono));
    return abonoAux;
}

eClientes* newParametros(char* id,char* nombre, char* sexo, char* numero, char* importe)
{
    eClientes* clientes;
    clientes= newClientes();
    if(clientes!= NULL)
    {
        clientes_set_id(clientes,atoi(id));
        clientes_set_nombre(clientes,nombre);
        clientes_set_sexo(clientes,sexo);
        clientes_set_telefono(clientes,numero);
        clientes_set_importe(clientes,atoi(importe));
    }
    return clientes;
}
                    ///CLIENTES//

///SETTERS///

int clientes_set_id(eClientes* lista, int id)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->id=id;
        set=0;
    }
    return set;
}

int clientes_set_nombre(eClientes* lista, char* nombre)
{
    int set=-1;
    if(lista!=NULL)
    {
        strcpy(lista->nombre,nombre);
        set=0;
    }
    return set;
}

int clientes_set_sexo(eClientes* lista, char* sexo)
{
    int set=-1;
    if(lista!=NULL)
    {
        strcpy(lista->sexo,sexo);
        set=0;
    }
    return set;
}

int clientes_set_telefono(eClientes* lista, char* telefono)
{
    int set=-1;
    if(lista!=NULL)
    {
        strcpy(lista->numeroTelefono,telefono);
        set=0;
    }
    return set;
}

int clientes_set_importe(eClientes* lista, int importe)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->importe=importe;
        set=0;
    }
    return set;
}
////////////////////////////////////////////
///GETTTERS
int clientes_get_id(eClientes* lista,int* id)
{
    int retorno=-1;
    if(lista!=NULL)
    {
        *id=lista->id;
        retorno=0;
    }
    return retorno;
}

int clientes_get_sexo(eClientes* lista,char* sexo)
{
    int retorno=-1;
    if(lista!=NULL)
    {
        strcpy(sexo,lista->sexo);
        retorno=0;
    }
    return retorno;
}

int clientes_get_nombre(eClientes* lista,char* nombre)
{
    int retorno=-1;
    if(lista!=NULL)
    {
        strcpy(nombre,lista->nombre);
        retorno=0;
    }
    return retorno;
}

int clientes_get_telefono(eClientes* lista,char* telefono)
{
    int retorno=-1;
    if(lista!=NULL)
    {
        strcpy(telefono,lista->numeroTelefono);
        retorno=0;
    }
    return retorno;
}

int clientes_get_importe(eClientes* lista,int* importe)
{
    int retorno=-1;
    if(lista!=NULL)
    {
        *importe=lista->importe;
        retorno=0;
    }
    return retorno;
}


                              ///A B O N O ///
///SETTERS///
int abono_setId(eAbono* this, int id)
{
    int retorno = -1;
    if( this !=NULL )
    {
        if( id > 0 )
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}

int abono_setTipo(eAbono* lista, int tipo)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->tipo=tipo;
        set=0;
    }
    return set;
}

int abono_setIdCliente(eAbono* lista, int idCliente)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->idCliente=idCliente;
        set=0;
    }
    return set;
}

int abono_setImporteFinal(eAbono* lista, float importe)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->importeFinal=importe;
        set=0;
    }
    return set;
}
///GETTERS///

int abono_get_id(eAbono* this,int* id)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int abono_get_tipo(eAbono* this, int* tipo)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *tipo = this->tipo;
        retorno = 0;
    }
    return retorno;
}

int abono_get_importeFinal(eAbono* this, float* importeFinal )
{
    int retorno = -1;
    if ( this != NULL)
    {
        *importeFinal = this->importeFinal;
        retorno = 0;
    }
    return retorno;
}

int abono_get_idCliente(eAbono* this, int* idCliente)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 0;
    }
    return retorno;
}

///////////////FUNCIONES/////////////////////////
int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno;

    eClientes* empA;
    eClientes* empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eClientes*) empleadoA;
        empB = (eClientes*) empleadoB;
        if(empA->id == empB->id)
        {
             retorno = 1;
        }
        if(empA->id > empB->id)
        {
            retorno = -1;
        }
        if(empA->id < empB->id)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int abonoSortByImporte(void* empleadoA, void* empleadoB)
{
    int retorno;

    eAbono* empA;
    eAbono*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (eAbono*) empleadoA;
        empB = (eAbono*) empleadoB;
        if(empA->importeFinal == empB->importeFinal)
        {
             retorno = 1;
        }
        else if(empA->importeFinal > empB->importeFinal)
        {
            retorno = -1;
        }
        else if(empA->importeFinal < empB->importeFinal)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/*int compararNumeros(void* numero1, void* numero2)
{
    int retorno;
    if(abono_get_importeFinal((eAbono*)numero1)>abono_get_importeFinal((eAbono*)numero2))
    {
        retorno=1;
    }
    else if(abono_get_importeFinal((eAbono*)numero1)<abono_get_importeFinal((eAbono*)numero2))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}*/

void abonos_lista(eAbono* lista)
{
    int auxIdAbono;
    int auxTipo;
    int auxIdCliente;
    float auxImporte;

    if(lista!=NULL)
    {
        if(lista>0)
        {
            abono_get_id(lista,&auxIdAbono);
            abono_get_tipo(lista,&auxTipo);
            abono_get_idCliente(lista,&auxIdCliente);
            abono_get_importeFinal(lista,&auxImporte);
            printf("%3d\t%d\t%d\t\t%.2f\n",auxIdAbono,auxTipo,auxIdCliente,auxImporte);
        }
    }
}

void clientes_lista (eClientes* lista)
{
    int auxId;
    char auxNombre[50];
    char auxTelefono[50];
    char auxSexo[2];
    int auxImporte;

    if(lista!=NULL)
    {
        if(clientes_get_id(lista,&auxId)==0 && clientes_get_nombre(lista,auxNombre)==0 && clientes_get_telefono(lista,auxTelefono)==0 && clientes_get_importe(lista,&auxImporte)==0 && clientes_get_sexo(lista,auxSexo)==0)
        {
            clientes_get_id(lista,&auxId);
            clientes_get_nombre(lista,auxNombre);
            clientes_get_sexo(lista,auxSexo);
            clientes_get_telefono(lista,auxTelefono);
            clientes_get_importe(lista,&auxImporte);
            printf("%3d  %21s %3s  %10s  %7d\n",auxId,auxNombre,auxSexo,auxTelefono,auxImporte);
        }
        else
        {
            printf("No se cargaron los Datos\n\n");
        }
    }
}

void listarClientes (LinkedList* lista)
{
    eClientes* clientes;
    int i;
    if(lista!=NULL)
    {
        printf("ID\t\tNOMBRE\t  SEXO\t  TELEFONO\t IMPORTE\n\n");
        for(i=0; i<ll_len(lista); i++)
        {
            clientes=ll_get(lista,i);
            clientes_lista(clientes);
        }
    }
}

LinkedList* crearListaAbono(LinkedList* this)
{
    eAbono* abono;
    eClientes* clienteActual; ///Creamos un puntero a la posicion actual del cliente
    eClientes* clienteSiguiente;  ///Creamos un puntero a la posicion proxima del cliente
    LinkedList* listaAbono = ll_newLinkedList();  ///Se declara la nueva linkedlist
    int contador=0;
    int importeTotal=0;  ///Definimos el importe total
    int i;

    if(this != NULL)
    {
        for( i=0; i<ll_len(this); i++)
        {
            clienteActual = (eClientes*)ll_get(this, i);
            if(i+1 < ll_len(this)) ///Si la posicion sumandelo uno, es menor a la lista (esto se hace una vez que se llega al final de la lista)
            ///Lo que se quiere lograr es analizar si el cliente actual y proximo coinciden, se empizan a contar, y antes de llegar a la lista y que el cliente proximo no exista, se declara la condicion del if
            clienteSiguiente = (eClientes*)ll_get(this, i+1);
            contador++;
            importeTotal=importeTotal+clienteActual->importe; ///Se va calculando el importe

            if((clienteActual->id != clienteSiguiente->id) || i+1 == ll_len(this)) ///Se verifica que los id no coincidan para ir creando la nueva lista y que (ademas) no se termine de recorrer la lista por completo
            {
                abono = newAbono();

                if(contador==1)
                {
                    abono_setTipo(abono, PERSONAL);
                    abono_setImporteFinal(abono, importeTotal);
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else if(contador>=2 && contador <=4)
                {
                    abono_setTipo(abono, FAMILIAR);
                    abono_setImporteFinal(abono, importeTotal*1.1); // CASTEAR A FLOAT
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else
                {
                    abono_setTipo(abono, CORPORATIVO);
                    abono_setImporteFinal(abono, importeTotal*1.2); // CASTEAR A FLOAT
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                ll_add(listaAbono, abono);

                contador = 0;
                importeTotal = 0;
            }
        }
    }
    return listaAbono;
}

void ListarAbonosYClientes (LinkedList* listaAbono, LinkedList* listaClientes)
{
    eAbono* auxListaAbono;
    eClientes* auxListaClientes;
    int i,j;

    if(listaAbono!= NULL && listaClientes!= NULL)
    {
        printf("ID\tTIPO\tID_CLIENTE\tIMPORTE_TOTAL\n");
        for(i=0; i<ll_len(listaAbono); i++)
        {
            auxListaAbono=(eAbono*)ll_get(listaAbono,i);
            abonos_lista(auxListaAbono);
            for(j=0; j<ll_len(listaClientes); j++)
            {
                auxListaClientes=(eClientes*)ll_get(listaClientes,j);
                if(auxListaAbono->id == auxListaClientes->id)
                {
                    printf("Cliente:");
                    clientes_lista(auxListaClientes);
                }
            }
        }
    }
}
