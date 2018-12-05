#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parser.h"

void parserRead(LinkedList* this)
{
    char nombre[50];
    char numero[10];
    char par[10];
    char impar[10];
    char primo[10];
    numeroNatural* aux;
    int leidos;
    FILE* pFile;
    pFile=fopen("date.csv","r");

    if(pFile!=NULL && this!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",numero,nombre,par,impar,primo);
            if(leidos==5)
            {
                aux=newNumero();
                if(aux!=NULL)
                {
                    /*if(atoi(numero)>=0 && strlen(nombre)<= 50 && atoi(par)== 0 || atoi(par)== 1 && atoi(impar)==0 || atoi(impar)==1 && atoi(primo)==0 || atoi(primo)==1)
                    {*/
                        set_numero(aux,atoi(numero));
                        set_nombre(aux,nombre);
                        set_par(aux,atoi(par));
                        set_impar(aux,atoi(impar));
                        set_primo(aux,atoi(primo));
                        ll_add(this,aux);
                   // }
                }
            }
        }while(!feof(pFile));
        printf("\nArchivo leido con exito\n");
    }
    else
    {
        printf("\nArchivo no encontrado\n");
        system("cls");
    }
    fclose(pFile);
}



int parser_NumerosFromText(FILE* pFile, LinkedList* listaNumeros)
{
    numeroNatural* auxNumeroNatural;
    int retorno=-1;
    int r;
    char auxNumero[20];
    char auxPar[20];
    char auxImpar[20];
    char auxPrimo[20];
    char auxNombre[50];

    auxNumeroNatural=newNumero();

    if(listaNumeros!=NULL &&  pFile!=NULL)
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);

        do
        {
            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);
            if(r==5)
            {
                auxNumeroNatural = newParametros(auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);
                //auxNumeroNatural=(numeroNatural*)malloc(sizeof(numeroNatural)*cantidadEstructuras);
                if(auxNumeroNatural!=NULL)
                {
                    ll_add(listaNumeros,auxNumeroNatural);
                    retorno=0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));
    }
    return retorno;//return 1;
    //return 1; // OK
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_NumerosFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    numeroNatural* numeroAux;
    int retorno=-1;
    int cantidad;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            numeroAux=newNumero();
            cantidad=fread(numeroAux,sizeof(numeroAux),1,pFile);
            if(numeroAux!=NULL && cantidad==1)
            {
                ll_add(pArrayListEmployee,numeroAux);
                retorno=0;
            }
        }
        while(!feof(pFile));
    }
    return retorno;//return 1;
}
