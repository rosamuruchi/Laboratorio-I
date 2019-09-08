#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[100]="Hola Mundo!";

    mostrarCadena(cadena);

    return 0;
}

void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}
