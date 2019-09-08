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

float sumaDeNumerosFlotantes(float numero1,float numero2)
{
    float resultado;
    resultado = numero1+numero2;
    return resultado;
}

float restaDeNumerosFlotantes(float numero1,float numero2)
{
    float resultado;
    resultado = numero1-numero2;
    return resultado;
}

float divisionDeNumerosFlotantes(float numero1,float numero2)
{
    float retorno;
    float resultado;
    if(numero2!=0)
    {
        resultado = numero1/numero2;
        retorno=resultado;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

float multiplicacionDeNumerosFlotantes(float numero1,float numero2)
{
    float resultado;
    resultado = numero1*numero2;
    return resultado;
}

int factorialfinal(int numero)
{
    int resultado;
        if(numero>=0)
        {
            int i;
            int acum=1;
            for(i=numero;i>1;i--)
                {
                    acum=acum*i;
                }
            resultado=acum;
        }
        else
        {
            resultado=-1;
        }
    return resultado;
}

void mostrarResultadosDeLasOperaciones(float numeroUno,float numeroDos)
{
    float resultadoDeSuma;
    float resultadoDeResta;
    float resultadoDeDivision;
    float resultadoDeMultiplicacion;
    int resultadoDeFactorialUno;
    int resultadoDeFactorialDos;
    resultadoDeSuma=sumaDeNumerosFlotantes(numeroUno,numeroDos);
    resultadoDeResta=restaDeNumerosFlotantes(numeroUno,numeroDos);
    resultadoDeDivision=divisionDeNumerosFlotantes(numeroUno,numeroDos);
    resultadoDeMultiplicacion=multiplicacionDeNumerosFlotantes(numeroUno,numeroDos);
    resultadoDeFactorialUno=factorialfinal(numeroUno);
    resultadoDeFactorialDos=factorialfinal(numeroDos);
    printf("La suma de A y B es: %.2f\n",resultadoDeSuma);
    printf("\nLa resta de A y B es: %.2f\n",resultadoDeResta);
    printf("\nLa multiplicacion de A y B es: %.2f\n",resultadoDeMultiplicacion);
    if(resultadoDeDivision!=-1)
    {
        printf("\nLa division de A y B es: %.2f\n",resultadoDeDivision);
    }
    else
    {
        printf("\nERROR! No es posible Dividir por cero. Reingrese el valor B.\n");
    }

    if(resultadoDeFactorialUno!= -1 || resultadoDeFactorialDos!= -1)
    {
        printf("\nEl factorial de %.2f es: %d\n",numeroUno,resultadoDeFactorialUno);
        printf("\nEl factorial de %.2f es: %d\n",numeroDos,resultadoDeFactorialDos);
    }
    else
    {
        printf("\n ERROR! El factorial es mayor a 0, Reingrese.\n\n");
    }
}
