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


///////////////////////

int abono_set_id(eAbono* lista, int id)
{
    return lista->id=id;
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

int abono_get_idCliente(eAbono* lista)
{
    return lista->idCliente;
}

int abono_get_importeFinal(eAbono* lista)
{
    return lista->importeFinal;
}

int abono_get_id(eAbono* lista)
{
    return lista->id;
}

int abono_get_tipo(eAbono* lista)
{
    return lista->tipo;
}

////////////////////////////////////////
void completarNumeros(LinkedList* lista)
{
    int i;
    int contador;
    eClientes* aux1;
    eAbono* aux2;
    // eAbono* abono;
    if(lista!=NULL)
    {
        for(i=0; i<ll_len(lista); i++)
        {
            aux2=ll_get(lista,i);
            aux1=ll_get(lista,i);
            if(comprobarIdClienteRepetido(lista,aux1)==0)
            {
                contador++;
            }
        }
        if(contador==1)
        {
            abono_set_tipo(aux2,PERSONAL);
        }
        else
        {
            if(contador>1 && contador<5)
            {
                abono_set_tipo(aux2,FAMILIAR);
            }
            else
            {
                abono_set_tipo(aux2,CORPORATIVO);
            }
        }

    }
}


void calcularImporteFinal (LinkedList* lista)
{
    /*int i;
    int j;
    int contador;
    int importe;
    int suma;
    eAbono* aux;
    eClientes* listaclientes;

    for(i=0; i<ll_len(lista); i++)
    {
        aux=ll_get(lista,i);
        listaclientes=ll_get(lista,i);
        if(aux!=NULL)
        {
            for(j=1; j<ll_len(lista); j++)
            {
                contador=0;
                if(abono_get_idCliente(aux)>0)
                {
                    contador++;
                }
                if(clientes_get_importe(listaclientes)>0)
                {
                    suma=suma+clientes_get_importe(listaclientes);
                }
            }

            if(contador==1)
            {
                importe=listaclientes->importe;
            }
            else
            {
                if(contador>1 && contador<5)
                {
                    importe=suma*0.1;
                }
                else
                {
                    importe=suma*0.2;
                }
            }
            abono_set_ImporteFinal(aux,importe);

        }
    }*/
}

int compararNumeros(void* numero1, void* numero2)
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
            printf("%d\t%s\t\t%s\t\t%s\t\t%d\n",lista->id,lista->nombre,lista->sexo,lista->numeroTelefono,lista->importe);
        }
    }
}

void listarClientes (LinkedList* lista)
{
    eClientes* clientes;
    int i;
    if(lista!=NULL)
    {
        printf("ID  NOMBRE  SEXO  TELEFONO  IMPORTE\n");
        for(i=0; i<ll_len(lista); i++)
        {
            clientes=ll_get(lista,i);
            clientes_lista(clientes);
        }
    }
}

void ListarAbonos (LinkedList* lista)
{
   /* eAbono* abono;
    eClientes* cliente;
    int i,j,limite;

    if(lista!=NULL)
    {
        printf("ID_ABONO  IMP.FINAL  TIPO  ID_CLIENTE  NOMBRE  SEXO TELEFONO  IMPORTE");
        limite=ll_len(lista);
        for(i=1; i<limite; i++)
        {
            abono=ll_get(lista,i);
            for(j=i+1; i<limite-1; i++)
            {
                cliente=ll_get(lista,j);
                if(abono!=NULL && cliente!=NULL)
                {
                    printf("%d\t%d\t%d\t%d\t%s\t%s\t%s\%d\n",abono_get_id(abono),abono_get_importeFinal(abono),abono_get_tipo(abono),clientes_get_id(cliente),cleintes_get_nombre(cliente),clientes_get_sexo(cliente),cleintes_get_telefono(cliente),clientes_get_importe(cliente));
                }
            }

        }
    }*/
}

int comprobarIdClienteRepetido(LinkedList* repetido, char* idCliente)
{
    int retorno=-1;
    eClientes* auxiliar;
    int auxIdCliente;
    int i;
    for(i=0; i<ll_len(repetido); i++)
    {
        auxiliar=ll_get(repetido,i);
        if(clientes_get_id(auxiliar,&auxIdCliente)==0)
        {
            if(strcmp(idCliente,auxIdCliente)==0)
            {
                retorno=0;
                break;
            }
        }

    }
    return retorno;
}

int buscarNumeroRepetido(LinkedList* lista)
{
    int retorno=-1;
    int i;
    int j;
    int flag=0;
    int contador=0;
    eClientes* numero;
    eClientes* aux;
    LinkedList* repetidos;

    if(lista!=NULL )
    {
        for(i=0; i<ll_len(lista)-1; i++)
        {
            aux=ll_get(lista,i);
            if(comprobarSiElNumeroEsRepetido(lista,aux)==0)
            {
                flag=0;
                for(j=i+1; j<ll_len(lista); j++)
                {
                    numero=ll_get(lista,j);
                    //if(cleintes_get_telefono(aux)==cleintes_get_telefono(numero))
                    {
                        contador++;
                        //ll_add(repetidos,numero);
                    }


                    /*if(flag==0)
                    {
                        if(ll_remove(depurada,i)==0)
                        {
                            flag==1;
                        }

                    }*/
                }
            }
        }
        ll_sort(repetidos,compararNumeros,0);
        printf("\nNumeros repetidos\n");
//        printAllNumbers(repetidos);
        system("pause");
        system("cls");
//        ll_sort(depurada,compararNumeros,1);
        //printf("\nNumeros que no se repitieron\n");
      //  printAllNumbers(depurada);
        printf("\n\ncontador: %d\n\n",contador);
        retorno=flag;
    }
    return retorno;
}
