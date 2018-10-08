#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "misFunciones.h"

int esString (char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isalpha(lista[i]);
        if (index==0)
        {
            break;
        }
    }
    return index;
}

int esEntero(char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isdigit(lista[i]);

        if (index==0)
        {
            break;
        }
    }
    return index;
}

int esFloat(char lista[])
{
    int i;
    int contador=0;
    int flag=1;


    for(i=0; lista[i] != '\0'; i++)
    {
        if(lista[i] == '.')
        {
            contador++;
            if(contador>1)
            {
                flag=0;
                break;
            }
        }
        else if(lista[i]<'0' || lista[i]>'9')
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int esCaracter (char letra)
{
    int index=-1;
    if (isalpha(letra)== 0)
    {
        index=0;
    }
    return index;
}

int getString (char palabra[],char message[], char messageError[])
{
    char auxiliar[50];
    int validacion=0;
    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    validacion=esString(auxiliar);

    while(validacion==0)
    {
        printf("%s",messageError);
        fflush(stdin);
        gets(auxiliar);
        validacion=esString(auxiliar);
    }
    strcpy(palabra,auxiliar);

    return validacion;
}

int getCaracter (char* caracter,char message[], char messageError[],char lowlimit, char hilimit)
{
    char auxiliar;
    int validacion=0;

    printf("%s",message);
    fflush(stdin);
    scanf("%c",&auxiliar);
    validacion=esCaracter(auxiliar);
    while(validacion==0 || (lowlimit != toupper(auxiliar) && hilimit != toupper(auxiliar)))
    {
        printf("%s",messageError);
        fflush(stdin);
        scanf("%c",&auxiliar);
        validacion=esCaracter(auxiliar);
    }
    *caracter=auxiliar;

    return validacion;
}
int getEntero (int* numero,char message[], char messageError[], int lowlimit,int hilimit)
{
    char auxiliar[50];
    int validacion=0;
    int longitudDeValidacion=0;

    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    validacion=esEntero(auxiliar);
    longitudDeValidacion=strlen(auxiliar);

    while((longitudDeValidacion< lowlimit && longitudDeValidacion > hilimit) || validacion == 0)
    {
        printf("%s",messageError);
        fflush(stdin);
        gets(auxiliar);
        validacion=esEntero(auxiliar);
        longitudDeValidacion=strlen(auxiliar);
    }
    *numero =atoi(auxiliar);
    return validacion;
}

int getFlotante (float* numero,char message[], char messageError[])
{
    char cadena [50];
    int validaFloat;

    printf("%s",message);
    fflush(stdin);
    gets(cadena);
    validaFloat=esFloat(cadena);

    while(validaFloat == 0)
    {
        printf("%s",messageError);
        fflush(stdin);
        gets(cadena);
        validaFloat=esFloat(cadena);
    }
    *numero =atof(cadena);
    return validaFloat;
}


