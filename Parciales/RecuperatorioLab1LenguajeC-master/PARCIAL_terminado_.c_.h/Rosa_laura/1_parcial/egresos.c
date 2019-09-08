#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "egresos.h"
#include "funciones.h"
#include "autos.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

#define LIBRE 1
#define OCUPADO 0

void inicializarEgresosHardCode(EEgresos listaEgresos[],int limite)
{
    int i;
    int marca[]= {ALPHA_ROMEO,ALPHA_ROMEO,FERRARI,AUDI,FERRARI,FERRARI,AUDI,OTRO,ALPHA_ROMEO,ALPHA_ROMEO};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(i=0; i<10; i++)
    {
        listaEgresos[i].marca=marca[i];
        listaEgresos[i].importe=importe[i];
    }
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

float devolverValorEstadia(int lista)
{
    float valorEstadia;
    float valorALPHA=devolverHorasEstadia()*150;
    float valorFERRARI=devolverHorasEstadia()*175;
    float valorAUDI=devolverHorasEstadia()*200;
    float valorOTRO=devolverHorasEstadia()*250;

    if(lista==1)
    {
        valorEstadia=valorALPHA;
    }
    else if(lista==2)
    {
        valorEstadia=valorFERRARI;
    }
    else if(lista==3)
    {
        valorEstadia=valorAUDI;
    }
    else
    {
        valorEstadia=valorOTRO;
    }
    return valorEstadia;
}


int buscarPorIdAuto(EAutos lista[],int limite, int auxId)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if(lista[i].estadoAuto == OCUPADO && lista[i].idAuto == auxId)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


void egresodeAutos (EEgresos listaEgresos [], int limiteAuto, EPropietario listaProp [],int limiteProp,EAutos listaAutos[])
{
    int i;
    int j;
    int z;
    char marcas[][50]= {"ALPHA_ROMEO","FERRARI","AUDI","OTRO"};

    printf("\nMarca\t\t\tPrecio Por Hora\n");
    printf("-------------------------------------------\n");
    printf("ALPHA_ROMEO\t\t     $150\n");
    printf("FERRARI\t\t\t     $175\n");
    printf("AUDI\t\t\t     $200\n");
    printf("OTROS\t\t\t     $250\n\n\n");

    printf("------- TICKET DE ESTADIA------   \n\n");
    printf("PROPIETARIO    PATENTE      MARCA     PRECIO \n");

    for(i=0; i<limiteProp; i++)
    {
        if(listaProp[i].estado==OCUPADO)
        {
            printf("\n %s ",listaProp[i].nombre);

            for(j=0; j<limiteAuto; j++)
            {
                //listaAutos[i].estadoAuto=-1;

                if(listaProp[i].idPropietario==listaAutos[j].propietario)
                {
                    if(listaAutos[j].estadoAuto==OCUPADO)
                    {
                        listaEgresos[i].importe=devolverValorEstadia(listaAutos[i].marca);
                        printf("\t       %s      %s",listaAutos[j].patente,marcas[ listaAutos[j].marca-1]);

                        for(z=0; z<limiteAuto; z++)
                        {
                            if(listaAutos[j].marca==listaEgresos[z].marca)
                            {
                                printf("\t      $%.2f \n",listaEgresos[z].importe);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }



    /* printf("\nIngrese el Id del Auto : ");
     scanf("%d",&valor);
     for(i=0; i<limiteAuto; i++)
     {
         if(listaEgresos[i].idAuto==valor)
         {
             printf("\nEsta seguro que quiere que salga del Estacionamiento?\n responder s/n : ");
             respuesta= getche();
             printf("\n");

             if(respuesta=='s' || respuesta=='S')
             {
                 printf("PROPIETARIO    PATENTE    MARCA     ESTADIA \n");

                 for(i=0; i<limiteAuto; i++)
                 {
                     if(listaEgresos[i].idAuto==valor)
                     {
                         listaEgresos[i].estadoAuto=-1;
                         listaEgresos[i].importe=devolverValorEstadia(listaEgresos[i].marca);
                         for(j=0; j<limiteProp; j++)
                         {
                             if(listaEgresos[i].propietario==listaProp[j].idPropietario)
                             {
                                 printf("\n %s           %s      %s       %.2f \n\n",listaProp[j].nombre,listaEgresos[i].patente,marcas[listaEgresos[i].marca -1],listaEgresos[i].importe);

                                 //listaProp[j].estado=LIBRE;
                             }
                         }
                     }

                 }
                 printf("Egreso de Auto con exito!\n\n");
             }
             else
             {
                 printf("Egreso de Auto cancelado!\n");
             }
         }
     }*/
}



void recaudacionTotal( EEgresos listaEgresos [], int limite)
{
    int i;
    float valorTotal=0;

    for(i=0; i<limite; i++)
    {
        valorTotal+=listaEgresos[i].importe;
    }
    printf("-------ESTACIONAMIENTO-------\n\n");
    printf("La recaudacion Total del Estacionamiento es: %.2f\n\n",valorTotal);
}

void recaudacionPorMarca(EEgresos listaEgresos[], int limite)
{
    int i;
    float valorAlpha=0;
    float valorFerrari=0;
    float valorAudi=0;
    float valorOtro=0;

    for(i=0; i<limite; i++)
    {

        if(listaEgresos[i].marca==1)
        {
            valorAlpha+=listaEgresos[i].importe;
        }
        else if(listaEgresos[i].marca==2)
        {
            valorFerrari+=listaEgresos[i].importe;
        }
        else if(listaEgresos[i].marca==3)
        {
            valorAudi+=listaEgresos[i].importe;
        }
        else
        {
            valorOtro+=listaEgresos[i].importe;
        }

    }
    printf("----RECAUDACION TOTAL:----\n\n");
    printf("ALPHA ROMEO: %.2f\nFERRARI: %.2f\nAUDI: %.2f\nOTRO: %.2f\n\n",valorAlpha,valorFerrari,valorAudi,valorOtro);
}

void listaPropietarioConAutos(EPropietario listaProp[], int limiteProp,EAutos listaAutos[], int limiteAutos)
{
    int i;
    int j;
    char marcas[][50]= {"ALPHA_ROMEO","FERRARI","AUDI","OTRO"};
    int valor;
    int auxId;
    int estadoProp;

    mostrarListaPropietario(listaProp,limiteProp);

    printf("\nIngrese el Id del Propietario: ");
    scanf("%d",&valor);

    auxId= buscarPorId(listaProp,limiteProp,valor);
    estadoProp=listaProp[auxId].estado;

    if(estadoProp!=OCUPADO)
    {
        printf("Id No se encuentra en la Lista\n");
    }
    else
    {
        printf("\n\n  PROPIETARIO   PATENTE    MARCA \n");
        printf("---------------------------------\n\n");
        for(i=0; i<limiteProp; i++)
        {
            if(listaProp[i].idPropietario==valor)
            {
                for(j=0; j<limiteAutos; j++)
                {
                    if(listaProp[auxId].idPropietario==listaAutos[j].propietario)
                    {

                        if(listaAutos[j].estadoAuto==OCUPADO)
                        {
                            printf("\t%s      %s      %s  \n\n",listaProp[auxId].nombre,listaAutos[j].patente,marcas[listaAutos[j].marca -1]);
                        }
                    }
                }
            }
        }
    }




}


void listaAutoPorMarcaAudi(EAutos listaAutos[],int limiteAutos, EPropietario listaProp[],int limiteProp, int marca)
{
    int i;
    int j;
    int flag=0;
    printf("Datos de Propietarios con Auto: AUDI\n\n");

    printf("ID   NOMBRE    DIRECCION   TARJETA\n\n");

    for (i=0; i<limiteAutos; i++)
    {
        if (listaAutos[i].marca==marca && listaAutos[i].estadoAuto==OCUPADO)
        {
            for (j=0; j<limiteAutos; j++)
            {
                if (listaAutos[i].propietario==listaProp[j].idPropietario)
                {
                    printf("%d    %s     %s       %s\n\n",listaProp[j].idPropietario, listaProp[j].nombre, listaProp[j].direccion, listaProp[j].numeroTarjeta);
                }
            }

            flag=1;
        }
    }

    if (flag==0)
    {
        printf("No se encontraron usuarios.");
    }


}

void listaAutosPorPatente(EAutos listaAutos[],int limiteAutos, EPropietario listaProp[], int limiteProp)
{
    int i;
    int j;
    char marca[][20]= {"ALPHA_ROMEO","FERRARI","AUDI","OTRO"};

    EAutos auxiliar;

    for (i=0; i<limiteAutos-1; i++)
    {
        for (j=i+1; j<limiteAutos; j++)
        {
            if(stricmp(listaAutos[i].patente,listaAutos[j].patente)>0)
            {
                auxiliar=listaAutos[i];
                listaAutos[i]=listaAutos[j];
                listaAutos[j]=auxiliar;
            }

        }

    }

    printf("       ID   PATENTE    MARCA      PROPIETARIO\n");
    printf("----------------------------------------------\n\n");

    for (i=0; i<limiteAutos; i++)
    {

        for (j=0; j<limiteProp; j++)
        {
            if (listaAutos[i].propietario==listaProp[j].idPropietario)
            {
                if(listaAutos[i].estadoAuto==OCUPADO)
                {
                    printf("\t%d    %s       %s        %s\n",listaAutos[i].idAuto, listaAutos[i].patente, marca[listaAutos[i].marca-1], listaProp[j].nombre);
                }

            }
        }
    }
}
