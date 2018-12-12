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

eAbono* new_abono()
{
    eAbono* abono;
    abono=(eAbono*)malloc(sizeof(eAbono));
    return abono;
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

int clientes_set_telefono(eClientes* lista, char telefono[])
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
int get_numero(eClientes* lista)
{
    return lista->id;
}

///////////////////////ABONOSSS



int abono_set_id(eAbono* this, int id)
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

int abono_set_tipo(eAbono* lista, int tipo)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->tipo=tipo;
        set=0;
    }
    return set;
}

int abono_set_idCliente(eAbono* lista, int idCliente)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->idCliente=idCliente;
        set=0;
    }
    return set;
}

int abono_set_ImporteFinal(eAbono* lista, int importe)
{
    int set=-1;
    if(lista!=NULL)
    {
        lista->importeFinal=importe;
        set=0;
    }
    return set;
}

int abono_getId(eAbono* this,int* id)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int abono_get_importeFinal(eAbono* this, int* importeFinal)
{
    int retorno = -1;
    if( this !=NULL )
    {
        if( importeFinal > 0 )
        {
            this->importeFinal = importeFinal;
            retorno = 0;
        }
    }
    return retorno;
}

/*int abono_getId(eAbono* this,int* id)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}*/

int abono_getTipo(eAbono* this,int* tipo)
{
    int retorno = -1;
    if ( this != NULL)
    {
        *tipo = this->tipo;
        retorno = 0;
    }
    return retorno;
}

int abono_getIdCliente(eAbono* this,int* idCliente)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *idCliente = this->idCliente;
        retorno = 1;
    }
    return retorno;
}

int abono_getImporteFinal(eAbono* this,float* importeFinal)
{
    int retorno = 0;
    if ( this != NULL)
    {
        *importeFinal = this->importeFinal;
        retorno = 1;
    }
    return retorno;
}
////////////////////////////////////////

void completarNumeros(LinkedList* lista, LinkedList* abono)
{
    int i;
    int contador;
    eClientes* aux1;
    eAbono* abono2;

    if(lista!=NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            aux1=ll_get(lista,i);
            abono2=ll_get(lista,i);
            if(comprobarIdClienteRepetido(lista,aux1)== 0)
            {
                contador++;
            }
        }
        ll_add(abono,abono2);

        if(contador==1)
        {
            abono_set_tipo(abono2,PERSONAL);
        }
        else
        {
            if(contador>1 && contador<5)
            {
                abono_set_tipo(abono2,FAMILIAR);
            }
            else
            {
                abono_set_tipo(abono2,CORPORATIVO);
            }
        }
        printf("Se completo!\n");
        abono_set_idCliente(abono2,aux1->id);

    }
}

int compararNumeros(void* numero1, void* numero2)
{
    int retorno;
    /*if(abono_get_importeFinal((eAbono*)numero1)>abono_get_importeFinal((eAbono*)numero2))
    {
        retorno=-1;
    }
    else if(abono_get_importeFinal((eAbono*)numero1)<abono_get_importeFinal((eAbono*)numero2))
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }*/
    return retorno;
}

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


void clientes_lista (eClientes* lista)
{
    int auxId;
    char auxNombre[50];
    char auxTelefono[50];
    char sexo[1];
    int auxImporte;

    if(lista!=NULL)
    {
        if(clientes_get_id(lista,&auxId)==0 && clientes_get_nombre(lista,auxNombre)==0 && clientes_get_telefono(lista,auxTelefono)==0 && clientes_get_importe(lista,&auxImporte)==0 && clientes_get_sexo(lista,sexo)==0)
        {
            printf("%d\t%s\t\t%s\t%s\t%d\n",lista->id,lista->nombre,lista->sexo,lista->numeroTelefono,lista->importe);
        }
    }
}

void listarClientes (LinkedList* lista)
{
    eClientes* clientes;
    int i;
    if(lista!=NULL)
    {
        printf("ID\tNOMBRE\t\t\tSEXO\t\tTELEFONO\tIMPORTE\n");
        for(i=0; i<ll_len(lista); i++)
        {
            clientes=ll_get(lista,i);
            clientes_lista(clientes);
        }
    }
    system("pause");
}

void ListarAbonos (LinkedList* listaAbono, LinkedList* listaCliente)
{
    eAbono* abono;
    eClientes* cliente;
    eAbono* abono2;
    int i,j,limite;

    if(listaCliente!=NULL)
    {
        printf("ID_ABONO  IMP.FINAL  TIPO  ID_CLIENTE  NOMBRE");  //SEXO TELEFONO  IMPORTE");
        limite=ll_len(listaAbono);

        for(i=1; i<limite; i++)
        {
            abono=ll_get(listaAbono,i);
            for(j=i+1; i<limite-1; i++)
            {
                abono2=ll_get(listaAbono,j);
                cliente=ll_get(listaAbono,j);
                if(abono!=NULL && listaCliente!=NULL)
                {
                    if(compararNumeros(abono,abono2)==1)
                    printf("%d\t%d\t%d\t%d\t%s\n",abono2->id,abono2->importeFinal,abono2->tipo,abono2->idCliente,cliente->nombre);
                system("pause");
                }
            }
        }

    }

}

int comprobarIdClienteRepetido(LinkedList* repetido, eClientes* lista)
{
    int retorno=-1;
    eClientes* auxiliar;
    int i;
    for(i=0; i<ll_len(repetido); i++)
    {
        auxiliar=ll_get(repetido,i);
        if(get_numero(auxiliar)==get_numero(lista))
        {
                retorno=0;
                break;
        }
    }
    return retorno;
}

int calcularImporteFinal(LinkedList* lista, LinkedList* abono)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    eClientes* numero;
    eClientes* aux;
    eAbono* abono2;
    int importe=0;
    int importeFinal=0;

    if(lista!=NULL )
    {
        for(i=0; i<ll_len(lista)-1; i++)
        {
            aux=ll_get(lista,i);
            abono2=ll_get(abono,i);
            if(comprobarIdClienteRepetido(lista,aux)==0)
            {
                for(j=i+1; j<ll_len(lista); j++)
                {
                    numero=ll_get(lista,j);
                    if(get_numero(aux)==get_numero(numero))
                    contador++;
                    importe=importe+aux->importe;
                }
            }
        }
        if(contador==1)
        {
            importeFinal=aux->importe;
        }
        else
        {
            if(contador>1 && contador<5)
            {
                importeFinal=0.1*importe;
            }
            else
            {
                importeFinal=0.2*importe;
            }
        }
        retorno=0;
        abono_set_ImporteFinal(abono2,importeFinal);
        printf("Se completo!\n");
        system("pause");
    }
    return retorno;
}


LinkedList* crearListaAbono(LinkedList* this)
{
    eAbono* abono;
    eClientes* clienteActual;
    eClientes* clienteSiguiente;
    LinkedList* listaAbono = ll_newLinkedList();
    int contador=0;
    int importeTotal=0;
    int i;
    if(this != NULL)
    {
        for( i=0; i<ll_len(this); i++)
        {
            clienteActual = (eClientes*)ll_get(this, i);
            if(i+1 < ll_len(this))
            clienteSiguiente = (eClientes*)ll_get(this, i+1);
            contador++;
            importeTotal=importeTotal+clienteActual->importe;

            if((clienteActual->id != clienteSiguiente->id) || i+1 == ll_len(this))
            {
                abono = new_abono();
                if(contador==1)
                {
                    abono_set_tipo(abono, PERSONAL);
                    abono_set_ImporteFinal(abono, importeTotal);
                    abono_set_idCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else if(contador>=2 && contador <=4)
                {
                    abono_set_tipo(abono, FAMILIAR);
                    abono_set_ImporteFinal(abono, importeTotal*1.1);
                    abono_set_idCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else
                {
                    abono_set_tipo(abono, CORPORATIVO);
                    abono_set_ImporteFinal(abono, importeTotal*1.2);
                    abono_set_idCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                ll_add(listaAbono, abono);
                contador = 0;
                importeTotal = 0;
            }
        }
    }

    return listaAbono; //Me retorna la linkedlist
}

