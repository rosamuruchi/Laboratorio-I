#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float pedirNumero(char Texto[])
{
    float numero;
    printf("%s",Texto);
    scanf("%f",&numero);
    return numero;
}

void suma(float numero1,float numero2)
{
    float resultado;
    resultado = numero1+numero2;
    printf("La suma de A y B es: %.2f\n",resultado);
}

void resta(float numero1,float numero2)
{
    float resultado;
    resultado = numero1-numero2;
    printf("\nLa resta de A y B es: %.2f\n",resultado);
}

void division(float numero1,float numero2)
{
    if(numero2!=0)
    {
        float resultado;
        resultado = numero1/numero2;
        printf("\nLa division de A y B es: %.2f\n",resultado);
    }
    else
    {
        printf("\n ERROR!!!Reingrese el valor B.\n");
    }
}

void multiplicacion(float numero1,float numero2)
{
    float resultado;
    resultado = numero1*numero2;
    printf("\nLa multiplicacion de A y B es: %.2f\n",resultado);
}


void factorialfinal(int numero)
{
        if(numero>=0)
        {
            int i;
            int acum=1;
            for(i=numero;i>1;i--)
                {
                    acum=acum*i;
                }
            printf("\nEl factorial de %d es: %d\n",numero,acum);
        }
        else
        {
            printf("\n ERROR!!!El factorial es mayor a 0, Reingrese A.\n\n");
        }

}
