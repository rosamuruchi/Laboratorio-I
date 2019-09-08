#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;

}eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados (eEmpleado employee[], int tam);
void ordenarEmpleados(eEmpleado lista[], int tam);

int main()
{
    eEmpleado empleados[] ={
    {123,"Juan",'m',12300},
    {185,"Luisa",'f',12500},
    {153,"Pedro",'m',18300},
    {125,"Laura",'f',15600},
    {183,"Hugo",'m',28300},
    {275,"Maria",'f',88500},
    {633,"Oscar",'m',7500}
    };

    /*eEmpleado unEmpleado[TAM];
    int i;
    for(i=0; i < TAM; i++)
    {
        printf("Ingrese legajo:");
    scanf("%d",&unEmpleado[i].legajo);

    printf("Ingrese nombre:");
    fflush(stdin);
    gets(unEmpleado[i].nombre);

    printf("ingrese sexo:");
    scanf("%c",&unEmpleado[i].sexo);

    printf("Ingrese Sueldo:");
    scanf("%f",&unEmpleado[i].sueldo);
    }*/

    mostrarEmpleados(empleados,TAM);
    ordenarEmpleados(empleados,TAM);
        mostrarEmpleados(empleados,TAM);


    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("\n%d\t %s\t  %c\t %.2f\t\n", employee.legajo,employee.nombre,employee.sexo,employee.sueldo);
}

void mostrarEmpleados (eEmpleado lista[], int tam)
{
    int i;

    printf("LEGAJO\t NOMBRE\t  SEXO\t SUELDO\t\n");
    for(i=0; i < tam ; i++)
    {
            mostrarEmpleado(lista[i]);

    }
}

void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    int i,j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].sexo> lista[j].sexo)
            {
                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
            else if(lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}
