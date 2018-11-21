#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados=ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    FILE* miArchivo;
    char buffer[500]= {};
    char bufferAux[500]= {};

    int i;

    if(listaEmpleados!=NULL)
    {
        miArchivo = fopen(fileName,"w");

        if(miArchivo!=NULL)
        {
            for(i=0; i<ll_len(listaEmpleados); i++)
            {
                //funcion que escribe el int en una string
                sprintf(bufferAux,"%d",eEmpleados_getId(listaEmpleados,i));
                //strcpy para vaciar el buffer en la nueva iteración
                strcpy(buffer,bufferAux);
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getNombre(listaEmpleados,i));
                strcat(buffer,", ");
                sprintf(bufferAux,"%d",eEmpleados_getHoras(listaEmpleados,i));
                strcat(buffer,bufferAux);
                strcat(buffer,", ");
                sprintf(bufferAux,"%d",eEmpleados_getSueldo(listaEmpleados,i));
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getHoras(listaEmpleados,i));
                fprintf(miArchivo,"\n%s",buffer);

            }
            fclose(miArchivo);
        }
    }
    return 1;
}
