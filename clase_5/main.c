#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int retornarTotal(int listado[],int tamanio);
int retornarPromedio(int listado[],int tamanio);
int calcularMayor(int listado[],int tamanio);
int calcularMenor(int listado[],int tamanio);
int calcularPares(int listado[],int tamanio);
void cargarListado(int listado[],int tamanio);
void mostrarListado(int listado[],int tamanio);
void mostrarInformacionDelArray(int listado [], int tamanio);
int retornarCantidadEntreNotas(int listado[], int tamanio,int limInferior,int limSuperior);

int main()
{
    int listadoDeNotas [CANTIDAD];
    /*
    printf("tamano: %d\n",sizeof(numeroIngresado)); //
    printf("tamano: %d\n",sizeof(listadoDeNotas));
    printf("direccion: %d\n", &numeroIngresado);
    printf("direccion: %d\n", listadoDeNotas);*/

    cargarListado(listadoDeNotas,CANTIDAD);
    mostrarListado(listadoDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas,CANTIDAD);
    return 0;
}

int retornarTotal(int listado[],int tamanio)
{
    int sumaDeNotas=0;
    int i;
    for(i=0; i<tamanio; i++)
    {
        sumaDeNotas=sumaDeNotas+listado[i];
    }
    return sumaDeNotas;
}

int retornarPromedio(int listado[],int tamanio)
{
    int suma;
    int promedio;
    suma=retornarTotal(listado,tamanio);
    promedio=suma/tamanio;
    return promedio;
}
int calcularMayor(int listado[],int tamanio)
{
    int i;
    int mayor;
    //saca el mayor del ARRAY
    for(i=0; i<tamanio; i++)
    {
        if(i==0 || listado[i]>mayor)
        {
            mayor=listado[i];
        }
    }
    return mayor;
}
int calcularMenor(int listado[],int tamanio)
{
    int i;
    int menor;
    //saca el menor del ARRAY
    for(i=0; i<tamanio; i++)
    {
        if(i==0 || listado[i]<menor)
        {
            menor=listado[i];
        }
    }
    return menor;
}

int calcularPares(int listado[],int tamanio)
{
    int i;
    int acum=0;

    for(i=0; i<tamanio; i++)
    {
       if(listado[i] %2 ==0)
        {
            acum++;
        }
    }
    return acum;
}
void cargarListado(int listado[],int tamanio)
{
    int i;
    int numeroIngresado;
    for(i=0; i<tamanio; i++)
    {
        printf("\nIngrese Nota n %d:",i+1);
        scanf("%d",&numeroIngresado);
        listado[i]=numeroIngresado;
    }
}

void mostrarListado(int listado[],int tamanio)
{
    int i;
    //Muestra los valores del ARRAY
    for(i=0; i<tamanio; i++)
    {
        printf("\nLa Nota es: %d",listado[i]);
    }
}

void mostrarInformacionDelArray(int listado [], int tamanio)
{
    int sumaDeNotas;
    int promedio;
    int mayor;
    int menor;
    int cantidadPares;
    sumaDeNotas=retornarTotal(listado,CANTIDAD);
    promedio=retornarPromedio(listado,CANTIDAD);
    mayor=calcularMayor(listado,CANTIDAD);
    menor=calcularMenor(listado, CANTIDAD);
    cantidadPares=calcularPares(listado, CANTIDAD);

    printf("\n\n\tEl mayor es :%d\n",mayor);
    printf("\n\n\tEl menor es :%d\n",menor);
    printf("\n\n\tLa cantidad de Pares es: %d",cantidadPares);
    printf("\n\n\tLa suma total es: %d",sumaDeNotas);
    printf("\n\n\tEl promedio es: %d",promedio);
}

int retornarCantidadEntreNotas(int listado[], int tamanio,int limInferior,int limSuperior)
{

}
