#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int maximo;
    int minimo;
    printf("Ingrese un numero:");
    scanf("%d", &numeroUno);

    maximo=numeroUno;
    minimo=numeroUno;

    printf("Ingrese un numero:");
    scanf("%d", &numeroDos);

    if (numeroDos<minimo)
    {
        minimo=numeroDos;
    }
    else if(numeroDos>maximo)
    {
        maximo=numeroDos;
    }

    printf("Ingrese un numero:");
    scanf("%d", &numeroTres);

    if (numeroTres<minimo)
    {
        minimo=numeroTres;
    }
    else if(numeroTres>maximo)
    {
        maximo=numeroTres;
    }
    printf("Minimo: %d  -- Maximo: %d",minimo,maximo);

    /*if((numeroDos<=numeroTres && numeroDos>=numeroUno) || (numeroDos<=numeroUno && numeroDos>=numeroTres ))
    {
        printf("El numero del medio es: %d",numeroDos);
    }
    else
    {
        if((numeroUno>numeroDos && numeroUno<numeroTres) || (numeroUno>numeroTres && numeroUno<numeroDos))
        {
            printf("El numero del medio es: %d",numeroUno);
        }
        else
        {
            printf("El numero del medio es: %d",numeroTres);
        }
    }*/
    return 0;
}
