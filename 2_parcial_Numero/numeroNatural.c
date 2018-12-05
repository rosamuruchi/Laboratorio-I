#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numeroNatural.h"
//#include "LinkedList.h"

numeroNatural* newNumero()
{
    numeroNatural* aux;
    aux=(numeroNatural*)malloc(sizeof(numeroNatural));
    return aux;
}

numeroNatural* newParametros(char* numero,char* nombre, char* par, char* impar, char* primo)
{
    numeroNatural* numeroAux;
    numeroAux= newNumero();
    if(numeroAux!= NULL)
    {
        set_numero(numeroAux,atoi(numero));
        set_nombre(numeroAux,nombre);
        set_par(numeroAux,atoi(par));
        set_impar(numeroAux,atoi(impar));
        set_primo(numeroAux,atoi(primo));
    }
    return numeroAux;
}

int set_numero(numeroNatural* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->numero=dato;
        set=0;
    }
    return set;
}

int set_par(numeroNatural* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->par=dato;
        set=0;
    }
    return set;

}

int set_impar(numeroNatural* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->impar=dato;
        set=0;
    }
    return set;

}

int set_primo(numeroNatural* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->primo=dato;
        set=0;
    }
    return set;
}

int set_nombre(numeroNatural* this, char dato[])
{
    int set=-1;
    if(this!=NULL)
    {
    strcpy(this->nombre,dato);
    set=0;
    }
    return set;
}

int get_numero(numeroNatural* this)
{
    return this->numero;
}

int get_par(numeroNatural* this)
{
    return this->par;
}

int get_impar(numeroNatural* this)
{
    return this->impar;
}

int get_primo(numeroNatural* this)
{
    return this->primo;
}

char* get_nombre(numeroNatural* this)
{
    return this->nombre;
}

void printOne(numeroNatural* this)
{
    printf("%d\t%s\t%d\t%d\t%d\n",get_numero(this),get_nombre(this),get_par(this),get_impar(this),get_primo(this));
}

void printAllNumbers (LinkedList* pArrayListEmployee)
{
    numeroNatural* numeroAux;
    int i,limite;

    if(pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0; i<limite; i++)
        {
            numeroAux=ll_get(pArrayListEmployee,i);
            if(numeroAux!=NULL)
            {
                printOne(numeroAux);
            }
        }
    }
}

void completarNumeros(LinkedList* this)
{
    int i;
    int j;
    int contador;
    numeroNatural* aux;

    for(i=0; i<ll_len(this); i++)
    {
        aux=ll_get(this,i);
        if(aux!=NULL)
        {
            contador=0;
            if(get_numero(aux)%2==0)
            {
                set_par(aux,1);
            }
            else
            {
                set_impar(aux,1);
            }
            for(j=1; j<=get_numero(aux); j++)
            {
                if(get_numero(aux)%j==0)
                {
                    contador++;
                }
            }
            if(contador==2)
            {
                set_primo(aux,1);
            }
            else
            {
                set_primo(aux,0);
            }
        }
    }
}

int compararNumeros(void* numero1, void* numero2)
{
    int retorno;
    if(get_numero((numeroNatural*)numero1)>get_numero((numeroNatural*)numero2))
    {
        retorno=1;
    }
    else if(get_numero((numeroNatural*)numero1)<get_numero((numeroNatural*)numero2))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int comprobarSiElNumeroEsRepetido(LinkedList* repetido, numeroNatural* aux)
{
    int retorno=0;
    numeroNatural* auxiliar;
    int i;
    for(i=0; i<ll_len(repetido); i++)
    {
        auxiliar=ll_get(repetido,i);
        if(get_numero(auxiliar)==get_numero(aux))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int buscarNumeroRepetido(LinkedList* this, LinkedList* repetidos, LinkedList* depurada)
{
    int retorno=-1;
    int i;
    int j;
    int flag=0;
    int contador=0;
    numeroNatural* numero;
    numeroNatural* aux;

    if(this!=NULL && repetidos!=NULL && depurada!=NULL)
    {
        for(i=0; i<ll_len(this)-1; i++)
        {
            aux=ll_get(this,i);
            if(comprobarSiElNumeroEsRepetido(repetidos,aux)==0)
            {
                flag=0;
                for(j=i+1; j<ll_len(this); j++)
                {
                    numero=ll_get(this,j);
                    if(get_numero(aux)==get_numero(numero))
                    {
                        contador++;
                        ll_add(repetidos,numero);
                    }
                    if(flag==0)
                    {
                        if(ll_remove(depurada,i)==0)
                        {
                            flag==1;
                        }

                    }
                }
            }
        }

        ll_sort(repetidos,compararNumeros,0);
        printf("\nNumeros repetidos\n");
        printAllNumbers(repetidos);
        system("pause");
        system("cls");
        ll_sort(depurada,compararNumeros,1);
        printf("\nNumeros que no se repitieron\n");
        printAllNumbers(depurada);
        printf("\n\ncontador: %d\n\n",contador);
        retorno=flag;
    }
    return retorno;
}
