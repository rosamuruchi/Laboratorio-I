#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;



void mostrarEmpleados (eEmpleado employee);

int main()
{

    eEmpleado unEmpleado;
    eEmpleado otroEmpleado={12345, "Analia",'f', 30000.17, {17, 9, 2018}};

    unEmpleado.legajo=1234;
    strcpy(unEmpleado.nombre,"juan");
    unEmpleado.sexo='m';
    unEmpleado.sueldo=10000.5;
    unEmpleado.fechaIngreso.dia=17;
    unEmpleado.fechaIngreso.mes=9;
    unEmpleado.fechaIngreso.anio=2018;


    printf("LEGAJO\t NOMBRE\t SEXO\t SUELDO\t FECHA DE INGRESO\n");
    mostrarEmpleados(unEmpleado);
    mostrarEmpleados(otroEmpleado);

    /*printf("Ingrese legajo;");
    scanf("%d",&unEmpleado.legajo);

    printf("Ingrese nombre:");
    fflush(stdin);
    gets(unEmpleado.nombre);

    printf("ingrese sexo:");
    scanf("%c",&unEmpleado.sexo);

    printf("Ingrese Sueldo:");
    scanf("%f",&unEmpleado.sueldo);*/




    return 0;
}

void mostrarEmpleados (eEmpleado employee)
{

    printf("\n%d\t %s\t %c\t %.2f\t %02d/%02d/%4d\n", employee.legajo,employee.nombre,employee.sexo,employee.sueldo,employee.fechaIngreso.dia,employee.fechaIngreso.mes,employee.fechaIngreso.anio);
}



/*
EN EL MAIN: cargar datos de estructuras basicas:
eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222,"jose",'m',20000.2};
    eEmpleado emp4;
    emp4=emp3;

    unEmpleado.legajo=1234;
    strcpy(unEmpleado.nombre,"juan");
    unEmpleado.sexo='m';
    unEmpleado.sueldo=10000.5;

    otroEmpleado.legajo=1134;
    strcpy(otroEmpleado.nombre,"Lucia");
    otroEmpleado.sexo='f';
    otroEmpleado.sueldo=15000.75;


    printf("LEGAJO\t NOMBRE\t SEXO\t SUELDO\n");
    mostrarEmpleados(unEmpleado);
    mostrarEmpleados(otroEmpleado);
    mostrarEmpleados(emp3);
    mostrarEmpleados(emp4);*/


