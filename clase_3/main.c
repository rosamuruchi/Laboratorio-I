#include <stdio.h>
#include <stdlib.h>

int pedirEdad (); //getEdad
int validarEdad(int edad,int minimo,int maximo); //

int main()
{
    int edad;

    edad=pedirEdad();
    printf("La edad Ingresada Fue: %d",edad);

    //int esValidaLaEdad;

    /*do
    {
        edad=pedirEdad();    //pido la edad
        esValidaLaEdad=validarEdad(edad,1,100);       //valido esa edad

    }while(esValidaLaEdad!=1); //repetir si no esta validado la edad*/
    return 0;
}

int pedirEdad ()
{
    int numero;
    printf("Ingrese Edad:");
    scanf("%d",&numero);

    numero=validarEdad(numero,1,100);

    return numero;
}

int validarEdad(int edad,int minimo,int maximo)
{
    int contador;
    contador=0;
    do
    {
        contador++;
        if(contador==3)
        {
            edad=-1;
            break;
        }
        printf("Ingrese su Edad Nuevamente:");
        scanf("%d",&edad);
    }while(edad<minimo || edad>maximo);
}
