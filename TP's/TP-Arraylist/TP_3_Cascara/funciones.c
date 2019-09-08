#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

#include "funciones.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarLista(EMovie *movie,int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        (movie+i)->estado=LIBRE;
        (movie+i)->id= 0;
    }
}

int cargarDesdeArchivo(EMovie *movie,int cantidad)
{
    int flag = 0;
    FILE *f;

    f=fopen("peliculas.dat", "rb+");
    if(f==NULL)
    {
        f= fopen("peliculas.dat", "wb+");
        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag ==0)
    {
        fwrite(movie,sizeof(EMovie),cantidad,f);
    }

    fclose(f);
    return 0;

}

int guardarEnArchivo(EMovie * movie,int cantidad)
{

    FILE *f;

    f=fopen("peliculas.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

    fwrite(movie,sizeof(EMovie),cantidad,f);

    fclose(f);

    return 0;
}

int esLetra (char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isalpha(lista[i]);

        if (index==0)
        {
            break;
        }
    }
    return index;

}

int esEntero(char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isdigit(lista[i]);

        if (index==0) //si no es numero
        {
            break;
        }
    }
    return index;
}

int esAlfaNumerico(char lista[])
{
    int i=0;
    while(lista[i] != '\0')
    {
        if((lista[i] != ' ') && (lista[i] < 'a' || lista[i] > 'z') && (lista[i] < 'A' || lista[i] > 'Z') && (lista[i] < '0' || lista[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int buscarLibre(EMovie *peliculas,int cantidad)
{
    int index = -1;
    int i;
    if(cantidad > 0 && peliculas != NULL)
    {
        index = -2;
        for(i=0 ; i<cantidad ; i++)
        {
            if((peliculas+i)->estado == LIBRE)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int siguienteId(EMovie *peliculas,int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && peliculas != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if((peliculas+i)->estado == OCUPADO)
            {
                if((peliculas+i)->id>retorno)
                {
                    retorno=(peliculas+i)->id;
                }

            }
        }
    }

    return retorno+1;
}

int validacionPeliculas(int validar)
{
    int index;
    if(validar==0)
    {
        printf("ERROR!!! Por favor Reingrese!!\n");
        index=1;
    }
    else
    {
        printf("Ingreso Correcto!\n");
    }
    return index;
}


int agregarPelicula(EMovie *movie, int cantidad)
{
    int index;
    char auxiliar[50];
    int validar=0;
    int longitud;
    int valor=0;

    index=buscarLibre(movie,cantidad);

    if(movie==NULL)
    {
        printf("No se pudo abrir fichero!\n");
    }
    else
    {
        if(index!=-1)
        {
            printf("\nIngrese Titulo de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);

            validar=esAlfaNumerico(auxiliar);
            while (validacionPeliculas(validar)==1)
            {
                printf("\nReingrese nombre de Pelicula: ");
                fflush(stdin);
                gets(auxiliar);
                validar=esAlfaNumerico(auxiliar);
            }
            strcpy((movie+index)->titulo,auxiliar);
            validar=0;

            printf("\nIngrese Genero de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);

            validar=esLetra(auxiliar);
            while (validacionPeliculas(validar)==1)
            {
                printf("\nReingrese Genero de Pelicula: ");
                fflush(stdin);
                gets(auxiliar);
                validar=esLetra(auxiliar);
            }
            strcpy((movie+index)->genero,auxiliar);
            validar=0;


            printf("\nIngrese Descripcion de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);
            validar=esAlfaNumerico(auxiliar);
            while (validacionPeliculas(validar)==1)
            {
                printf("\nReingrese Descripcion de Pelicula: ");
                fflush(stdin);
                gets(auxiliar);
                validar=esAlfaNumerico(auxiliar);
            }
            strcpy((movie+index)->descripcion,auxiliar);
            validar=0;

            printf("\nIngrese Duracion de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);
            longitud=strlen(auxiliar);

            validar=esEntero(auxiliar);
            while (validacionPeliculas(validar)==1 && (longitud<0 || longitud>5)) //pelicula mas larga dura 5220 minutos
            {
                printf("\nReingrese Duracion de Pelicula: ");
                fflush(stdin);
                gets(auxiliar);
                validar=esEntero(auxiliar);
            }
            (movie+index)->duracion=atoi(auxiliar);
            validar=0;

            printf("\nIngrese Puntaje de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);
            longitud=strlen(auxiliar);

            validar=esEntero(auxiliar);

            while (validacionPeliculas(validar)==1 && longitud<0 )
            {
                printf("\nReingrese Puntaje de Pelicula: ");
                fflush(stdin);
                gets(auxiliar);
                validar=esEntero(auxiliar);
            }
            (movie+index)->puntaje=atoi(auxiliar);
             validar=0;

            printf("\nIngrese Link de Imagen de Pelicula: ");
            fflush(stdin);
            gets(auxiliar);
            strcpy((movie+index)->linkImagen,auxiliar);
            validar=0;

            (movie+index)->id=siguienteId(movie,cantidad);
            (movie+index)->estado=OCUPADO;
            valor=1;

        }
        else
        {
            printf("ERROR!!! No hay espacio!\n");
        }
    }

    return valor;
}


int buscarPorId(EMovie *peliculas,int cantidad, int auxid)
{
    int i;
    int index=-1;

    for(i=0 ; i<cantidad ; i++)
    {
        if((peliculas+i)->id==auxid)
        {
            return i;
        }
    }
    return index;
}

void mostrarUnaLista(EMovie *peliculas, int cantidad)
{
    int i;
    for(i=0; i < cantidad; i++)
    {
        if((peliculas+i)->estado!= -1 && (peliculas+i)->estado==OCUPADO)
        {
            printf("\t%d        %s    %s\n\n",(peliculas+i)->id,(peliculas+i)->titulo,(peliculas+i)->genero);
        }
    }
}


int borrarPelicula(EMovie *movie, int cantidad)
{
    int borrar;
    int auxId;
    char respuesta;
    int valor=0;

    printf("\tID    TITULO    GENERO\n\n");
    mostrarUnaLista(movie,cantidad);

    printf("Ingrese Id de la Pelicula para Eliminar : ");
    scanf("%d",&auxId);
    borrar=buscarPorId(movie,cantidad,auxId);

    if(movie== NULL)
    {
        printf("No se pudo abrir fichero!\n");
    }
    else
    {
        if(borrar == -1)
        {
            printf("NO se encuentra el Id ingresado\n");
        }
        else
        {
            printf("\nEl Id ingresado corresponde a: \n\nNOMBRE: %s\n\nGenero: %s\n\n",movie[borrar].titulo, movie[borrar].genero);
            printf("\nSeguro desea Borrar?\nResponda s/n: ");
            respuesta=tolower(getche());

            if(respuesta=='s')
            {
                (movie+borrar)->estado=LIBRE;
                (movie+borrar)->id=-1;
                printf("\n\nEl Usuario fue BORRADO!!!!!\n\n");
            }
            else
            {
                printf("Usuario Cancelado\n\n");
            }
        }
    }
    return valor;

}


int modificarPelicula(EMovie* movie, int cantidad)
{
    int auxId;
    int index;
    int opcion,i;
    char auxiliar [50];
    int validar;
    int longitud;
    int valor=0;

    printf("\tID    TITULO    GENERO\n\n");
    mostrarUnaLista(movie,cantidad);

    printf("Ingrese Id de la Pelicula para Modificar: ");
    scanf("%d",&auxId);
    index=buscarPorId(movie,cantidad,auxId);

    if(movie==NULL)
    {
        printf("No se pudo abrir fichero!\n");
    }
    else
    {
        if(index!=-1)
        {
            for(i=0; i<cantidad; i++)
            {
                if(movie[i].id==auxId && movie[i].estado==OCUPADO)
                {
                    printf("\nLa pelicula ha modificar es: %s\n",movie[i].titulo);
                    printf("\nEsta seguro que quiero modificar\nResponder S/N: ");
                    printf("\nRespuesta: ");
                    opcion = tolower(getche());
                }
            }
            if(opcion=='s')
            {
                printf("\nSeleccione que es lo que desea Modificar:");
                printf("\n1.TITULO\n2.GENERO\n3.DESCRIPCION\n4.LINK DE IMAGEN\n5.DURACION\n6.PUNTAJE\n7.CANCELAR\n");
                printf("\nRespuesta: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese Titulo de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);

                    validar=esAlfaNumerico(auxiliar);
                    while (validacionPeliculas(validar)==1)
                    {
                        printf("\nReingrese nombre de Pelicula: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validar=esAlfaNumerico(auxiliar);
                    }
                    strcpy((movie+index)->titulo,auxiliar);
                    validar=0;
                    break;
                case 2:
                    printf("\nIngrese Genero de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);

                    validar=esLetra(auxiliar);
                    while (validacionPeliculas(validar)==1)
                    {
                        printf("\nReingrese Genero de Pelicula: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validar=esLetra(auxiliar);
                    }
                    strcpy((movie+index)->genero,auxiliar);
                    validar=0;
                    break;
                case 3:
                    printf("\nIngrese Descripcion de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);
                    validar=esAlfaNumerico(auxiliar);
                    while (validacionPeliculas(validar)==1)
                    {
                        printf("\nReingrese Descripcion de Pelicula: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validar=esAlfaNumerico(auxiliar);
                    }
                    strcpy((movie+index)->descripcion,auxiliar);
                    validar=0;
                    break;
                case 4:
                    printf("\nIngrese Link de Imagen de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);
                    strcpy(movie[index].linkImagen,auxiliar);
                    validar=0;
                    break;
                case 5:

                    printf("\nIngrese Duracion de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);
                    longitud=strlen(auxiliar);

                    validar=esEntero(auxiliar);
                    while (validacionPeliculas(validar)==1 && longitud<0 )
                    {
                        printf("\nReingrese Duracion de Pelicula: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validar=esEntero(auxiliar);
                    }
                    (movie+index)->duracion=atoi(auxiliar);
                    validar=0;
                    break;
                case 6:
                    printf("\nIngrese Puntaje de Pelicula: ");
                    fflush(stdin);
                    gets(auxiliar);
                    longitud=strlen(auxiliar);

                    validar=esEntero(auxiliar);
                    while (validacionPeliculas(validar)==1 && longitud<0 )
                    {
                        printf("\nReingrese Puntaje de Pelicula: ");
                        fflush(stdin);
                        gets(auxiliar);
                        validar=esEntero(auxiliar);
                    }
                    (movie+index)->puntaje=atoi(auxiliar);
                    validar=0;
                    break;
                case 7:
                    printf("Modificacion Cancelada!\n");
                    break;
                }
            }
            valor=1;
        }
        else
        {
            printf("El Id Ingresado No se encuentra!\n");
        }
    }
    return valor;
}

void generarPagina(EMovie lista[], char nombre[],int limite)
{
    FILE *archivo;
    int i;

    archivo=fopen("peliculas.html","w");

    if(archivo==NULL)
    {
        printf("No se pudo Abrir el archivo\n");
    }
    else
    {
        for (i=0; i<limite; i++)
        {
            if((lista+i)->estado==OCUPADO )
            {
                fprintf(archivo,"<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s'alt=''>                </a>                <h3>                    <a href='#'>%s</a>                </h3> <ul> <li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul> <p>%s</p></article>",lista[i].linkImagen,lista[i].titulo,lista[i].genero,lista[i].puntaje,lista[i].duracion,lista[i].descripcion);
            }
        }
    }

    fclose(archivo);
}





