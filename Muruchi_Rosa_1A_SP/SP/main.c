#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados=ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(controller_loadFromText("data.csv",listaEmpleados)==0)
    {

        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        if(ll_map(listaEmpleados,em_calcularSueldo)==0)
        {
            printf("Mapeo correcto!\n");
        }
        else
        {
            printf("Incorrecto mapeo!");
        }

        // Generar archivo de salida
        //if(generarArchivoSueldos("info.csv",listaEmpleados)==1)
        if(generarArchivoSueldos("info.csv",listaEmpleados)==0)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    FILE* miArchivo;
    Empleado* EmpleadoAux;
    //char buffer[500]= {};
    //char bufferAux[500]= {};
    int i,retorno=-1;

    if(listaEmpleados!=NULL)
    {
        miArchivo = fopen(fileName,"w");

        if(miArchivo!=NULL)
        {
            for(i=0; i<ll_len(listaEmpleados); i++)
            {
                EmpleadoAux=(Empleado*)ll_get(listaEmpleados,i);

                fprintf(miArchivo,"%d, %s, %d, %d\n",EmpleadoAux->id,EmpleadoAux->nombre,EmpleadoAux->horasTrabajadas,EmpleadoAux->sueldo);//eEmpleados_getId(listaEmpleados,i),eEmpleados_getNombre(listaEmpleados,i),eEmpleados_getHoras(listaEmpleados,i),eEmpleados_getSueldo(listaEmpleados,i));

               /* //funcion que escribe el int en una string
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
                strcat(buffer,bufferAux);
                //strcat(buffer,"\n");
                fprintf(miArchivo,buffer);*/

            }
            retorno=0;
            fclose(miArchivo);
        }
    }
    return retorno;
}
