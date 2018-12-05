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

int clientes_set_id(eClientes* this, int id)
{
    int set=-1;
    if(this!=NULL)
    {
        this->id=id;
        set=0;
    }
    return set;
}

int clientes_set_nombre(eClientes* this, char nombre[])
{
    int set=-1;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        set=0;
    }
    return set;
}

int clientes_set_sexo(eClientes* this, char sexo[])
{
    int set=-1;
    if(this!=NULL)
    {
        strcpy(this->sexo,sexo);
        set=0;

    }
    return set;
}

int clientes_set_telefono(eClientes* this, char telefono[])
{
    int set=-1;
    if(this!=NULL)
    {
        strcpy(this->numeroTelefono,telefono);
        set=0;
    }
    return set;
}

int clientes_set_importe(eClientes* this, int importe)
{
    int set=-1;
    if(this!=NULL)
    {
        this->importe=importe;
        set=0;
    }
    return set;
}
////////////////////////////////////////////
int clientes_get_id(eClientes* this)
{
    return this->id;
}

char* clientes_get_sexo(eClientes* this)
{
    return this->sexo;
}

char* cleintes_get_nombre(eClientes* this)
{
    return this->nombre;
}

char* cleintes_get_telefono(eClientes* this)
{
    return this->numeroTelefono;
}

int clientes_get_importe(eClientes* this)
{
    return this->importe;
}


///////////////////////

int abono_set_id(eAbono* this, int id)
{
    return this->id=id;
}

int abono_set_tipo(eAbono* this, int tipo)
{
    int set=-1;
    if(this!=NULL)
    {
        this->tipo=tipo;
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

int abono_set_ImporteFinal(eAbono* this, int importe)
{
    int set=-1;
    if(this!=NULL)
    {
        this->importeFinal=importe;
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
void completarNumeros(LinkedList* this)
{
    int i;
    int contador;
    eClientes* aux1;
    eAbono* aux2;
    // eAbono* abono;



    if(this!=NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            aux2=ll_get(this,i);
            aux1=ll_get(this,i);
            if(comprobarSiElNumeroEsRepetido(this,aux1)==0)
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


void calcularImporteFinal (LinkedList* this)
{
    int i;
    int j;
    int contador;
    int importe;
    int suma;
    eAbono* aux;
    eClientes* listaclientes;

    for(i=0; i<ll_len(this); i++)
    {
        aux=ll_get(this,i);
        listaclientes=ll_get(this,i);
        if(aux!=NULL)
        {
            for(j=1; j<ll_len(this); j++)
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
    }
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

void ListarAbonos (LinkedList* lista)
{
    eAbono* abono;
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
    }
}

int comprobarSiElNumeroEsRepetido(LinkedList* repetido, eClientes* aux)
{
    int retorno=-1;
    eClientes* auxiliar;
    int i;
    for(i=0; i<ll_len(repetido); i++)
    {
        auxiliar=ll_get(repetido,i);
        if(cleintes_get_telefono(auxiliar)==cleintes_get_telefono(aux))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int buscarNumeroRepetido(LinkedList* this)
{
    int retorno=-1;
    int i;
    int j;
    int flag=0;
    int contador=0;
    eClientes* numero;
    eClientes* aux;
    LinkedList* repetidos;

    if(this!=NULL )
    {
        for(i=0; i<ll_len(this)-1; i++)
        {
            aux=ll_get(this,i);
            if(comprobarSiElNumeroEsRepetido(this,aux)==0)
            {
                flag=0;
                for(j=i+1; j<ll_len(this); j++)
                {
                    numero=ll_get(this,j);
                    if(cleintes_get_telefono(aux)==cleintes_get_telefono(numero))
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
