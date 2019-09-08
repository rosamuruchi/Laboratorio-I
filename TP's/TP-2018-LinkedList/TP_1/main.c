#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    float numero1;
    float numero2;
    int opcion=0;

    while(seguir=='s')
    {
        printf("------------CALCULADORA---------------\n");
        printf("\n--------------------------------------\n\n");
        printf("-  1- Ingresar 1er operando (A=%.2f)\n",numero1);
        printf("-  2- Ingresar 2do operando (B=%.2f)\n",numero2);
        printf("-  3- Calcular todas las operacione\n");
        printf("-     Calcular la suma (A+B)\n");
        printf("-     Calcular la resta (A-B)\n");
        printf("-     Calcular la division (A/B)\n");
        printf("-     Calcular la multiplicacion (A*B)\n");
        printf("-     Calcular el factorial (A!)\n");
        printf("-  4_ Informar Resultados\n");
        printf("-  9- Salir\n");
        printf("\n -------------------------------------\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                   {
                    numero1=pedirNumero("Ingrese el valor A: ");
                    break;
                   }
            case 2:
                    {
                    numero2=pedirNumero("Ingrese el valor B: ");
                    break;
                    }

            case 3:
                {
                    sumaDeNumerosFlotantes(numero1,numero2);
                    restaDeNumerosFlotantes(numero1,numero2);
                    divisionDeNumerosFlotantes(numero1,numero2);
                    multiplicacionDeNumerosFlotantes(numero1,numero2);
                    factorialfinal(numero1);
                    factorialfinal(numero2);
                    break;
                }

            case 4:
                {
                    mostrarResultadosDeLasOperaciones(numero1,numero2);
                    break;
                }
            case 5:
                {
                    seguir = 'n';
                    break;
                }
        }
        system("pause");
        system("cls");
        }
            return 0;

}
