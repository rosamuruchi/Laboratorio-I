#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) y Alta de Socio\n");
    printf("2. Modificar datos de empleado\n");
    printf("3. Baja de empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Ordenar empleados\n");
    printf("6. Listado de Fichajes.\n");
    printf("7. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

Employee* employee_new()
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));//inicializar en cero todos los parametros
    if(empleado!=NULL)
    {
        empleado->id = 0;
        strcpy(empleado->nombre, "");
        strcpy(empleado->apellido, "");
        empleado->dni = 0;
        strcpy(empleado->clave, "");
    }
    return empleado;
}

Fichaje* fichaje_new()
{
    Fichaje* fj;
    fj = (Fichaje*)malloc(sizeof(Fichaje));//inicializar en cero todos los parametros

    return fj;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* apellido,char* dni, char* clave)
{
    Employee* empleado;
    empleado = employee_new();
    if(empleado!=NULL)
    {
        employee_setId(empleado,atoi(idStr));
        employee_setNombre(empleado,nombreStr);
        employee_setApellido(empleado,apellido);
        employee_setClave(empleado,clave);
        employee_setDni(empleado,atoi(dni));
    }
    return empleado;
}


void employee_print(Employee* this)
{
    int auxId;
    int auxdni;
    char auxNombre[50];
    char auxApellido[50];
    char auxClave[50];
    if(this!=NULL)
    {
        if(employee_getId(this,&auxId)==0 && employee_getNombre(this,auxNombre)==0 && employee_getApellido(this,auxApellido)==0 && employee_getDni(this,&auxdni)==0 && employee_getClave(this,auxClave))
        {
            printf("%d\t%s\t\t%s\t%d\t%s\n",auxId,auxNombre,auxApellido,auxdni,auxClave);
        }
    }
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this != NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && strlen(nombre)>2)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setApellido(Employee* this,char* apellido)
{
    int retorno=-1;

    if(this!=NULL && strlen(apellido)>2)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }

    return retorno;
}

int employee_getApellido(Employee* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int employee_setDni(Employee* this,int dni)
{
    int retorno=-1;
    if(this!=NULL && dni>0)
    {
        this->dni=dni;
        retorno=0;
    }
    return retorno;
}

int employee_getDni(Employee* this,int* dni)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dni=this->dni;
        retorno=0;
    }
    return retorno;
}

int employee_setClave(Employee* this,char* clave)
{
    int retorno=-1;

    if(this!=NULL && strlen(clave)>3)
    {
        strcpy(this->clave,clave);
        retorno=0;
    }

    return retorno;
}

int employee_getClave(Employee* this,char* clave)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(clave,this->clave);
        retorno=0;
    }
    return retorno;
}

///FICHAJE//

int fichaje_setId(Fichaje* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>0)
    {
        this->idFichaje=id;
        retorno=0;
    }
    return retorno;
}

int fichaje_getId(Fichaje* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->idFichaje;
        retorno=0;
    }
    return retorno;
}

int fichaje_setIdSocio(Fichaje* this,int idSocio)
{
    int retorno=-1;
    if(this!=NULL && idSocio>0)
    {
        this->idSocio=idSocio;
        retorno=0;
    }
    return retorno;
}

int fichaje_getIdSocio(Fichaje* this,int* idSocio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idSocio=this->idSocio;
        retorno=0;
    }
    return retorno;
}

int fichaje_setHora(Fichaje* this,int hora)
{
    int retorno=-1;
    if(this!=NULL && hora>0)
    {
        this->hora=hora;
        retorno=0;
    }
    return retorno;
}

int fichaje_getHora(Fichaje* this,int* hora)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *hora=this->hora;
        retorno=0;
    }
    return retorno;
}

int fichaje_setMinutos(Fichaje* this,int minutos)
{
    int retorno=-1;
    if(this!=NULL && minutos>0)
    {
        this->minutos=minutos;
        retorno=0;
    }
    return retorno;
}

int fichaje_getMinutos(Fichaje* this,int* minutos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *minutos=this->minutos;
        retorno=0;
    }
    return retorno;
}

int fichaje_setDia(Fichaje* this,int dia)
{
    int retorno=-1;
    if(this!=NULL && dia>0)
    {
        this->dia=dia;
        retorno=0;
    }
    return retorno;
}

int fichaje_getDia(Fichaje* this,int* dia)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dia=this->dia;
        retorno=0;
    }
    return retorno;
}

int fichaje_setMes(Fichaje* this,int mes)
{
    int retorno=-1;
    if(this!=NULL && mes>0)
    {
        this->mes=mes;
        retorno=0;
    }
    return retorno;
}

int fichaje_getMes(Fichaje* this,int* mes)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *mes=this->mes;
        retorno=0;
    }
    return retorno;
}

int fichaje_setAnio(Fichaje* this,int anio)
{
    int retorno=-1;
    if(this!=NULL && anio>0)
    {
        this->anio=anio;
        retorno=0;
    }
    return retorno;
}

int fichaje_getAnio(Fichaje* this,int* anio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *anio=this->anio;
        retorno=0;
    }
    return retorno;
}

int fichaje_getInOut(Fichaje* lista,char* inOut)
{
    int retorno=-1;

    if(lista!=NULL )
    {
        strcpy(inOut,lista->ingresoEgreso);
        retorno=0;
    }

    return retorno;
}

int fichaje_setInOut(Fichaje* this,char* inOut)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->ingresoEgreso,inOut);
        retorno=0;
    }
    return retorno;
}

Employee* employee_setEmployer(Employee* pEmployer,int id,char* nombre,char* apellido,int dni,char* clave)
{
    employee_setId(pEmployer,id);
    employee_setNombre(pEmployer,nombre);
    employee_setApellido(pEmployer,apellido);
    employee_setDni(pEmployer,dni);
    employee_setClave(pEmployer,clave);

    return pEmployer;
}

Fichaje* fichaje_setFichajes(Fichaje* fichajes,int idFich,int idSocio,int hora,int minutos,int dia,int mes,int anio, char* InOut)
{
    fichaje_setId(fichajes,idFich);
    fichaje_setIdSocio(fichajes,idSocio);
    fichaje_setHora(fichajes,hora);
    fichaje_setMinutos(fichajes,minutos);
    fichaje_setDia(fichajes,dia);
    fichaje_setMes(fichajes,mes);
    fichaje_setAnio(fichajes,anio);
    fichaje_setInOut(fichajes,InOut);

    return fichajes;
}


Fichaje* fichaje_newParametros(char* idStr,char* idSocio,char* hora,char* minutos, char* dia, char* mes, char* anio, char* inOut)
{
    Fichaje* fj;
    fj = fichaje_new();
    if(fj!=NULL)
    {
        fichaje_setId(fj,atoi(idStr));
        fichaje_setIdSocio(fj,atoi(idSocio));
        fichaje_setHora(fj,atoi(hora));
        fichaje_setMinutos(fj,atoi(minutos));
        fichaje_setDia(fj,atoi(dia));
        fichaje_setMes(fj,atoi(mes));
        fichaje_setAnio(fj,atoi(anio));
        fichaje_setInOut(fj,inOut);

    }
    return fj;
}




int employee_siguienteId(LinkedList* pArrayListEmployee,Employee* this)
{
    int retorno = 0;
    int i;
    int limite;
    limite=ll_len(pArrayListEmployee);
    if(limite > 0 && this != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if((this+i)->id>retorno)
            {
                retorno=(this+i)->id;
            }
        }
    }
    return retorno+1;
}

int employee_buscarInOut(LinkedList* listaSocios, LinkedList* listaFichaje)
{
    Employee* empleadoAux;
    Fichaje* fichajeActual;
    //Fichaje* fichajeInOut;
    int retorno=-1;
    int limite;
    int i,j;
    int contadorEntrada=0;
    int contadorSalida=0;

    if(listaSocios!=NULL && listaFichaje!= NULL)
    {
        limite=ll_len(listaSocios);
        for(i=0; i<ll_len(listaSocios); i++)
        {
            empleadoAux=(Employee*)ll_get(listaSocios,i);//i-1
           // fichajeInOut=fichaje_new();

            for(j=0; j<limite; j++)//1
            {
                fichajeActual=(Fichaje*)ll_get(listaFichaje,j);

                if(fichajeActual->idSocio == empleadoAux->id)
                {
                    if(strcmp(fichajeActual->ingresoEgreso,"IN"))
                    {
                        contadorEntrada++;
                    }
                    if(strcmp(fichajeActual->ingresoEgreso,"OUT"))
                    {
                        contadorSalida++;
                    }
                }

            }
            if(contadorEntrada!=contadorSalida)
            {
                retorno=1;/// NO SALIERON
            }
            else
            {
                if(contadorEntrada==contadorSalida)
                {
                    retorno=0;///SALIERON
                }
                else
                {
                    retorno=-1;
                }
            }
            contadorEntrada=0;
            contadorSalida=0;
        }
    }
    return retorno;
}

int employee_buscarId(LinkedList* pArrayListEmployee,int id)
{
    Employee* empleadoAux;
    int retorno=-1;
    int limite;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0; i<limite; i++)//1
        {
            empleadoAux=(Employee*)ll_get(pArrayListEmployee,i);//i-1

            if(empleadoAux->id==id )
            {
                printf(" %d\t%s\t%s\t%d\t %s\n",empleadoAux->id,empleadoAux->nombre,empleadoAux->apellido,empleadoAux->dni,empleadoAux->clave);
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_buscarFecha(LinkedList* pArrayListEmployee,LinkedList* listaFichaje,int dia, int mes, int anio)
{
    Employee* empleadoAux;
    Fichaje* fichajeAux;
    int retorno=-1;
    int limite;
    int i, j;

    if(pArrayListEmployee!=NULL && listaFichaje!= NULL)
    {
        limite=ll_len(listaFichaje);

        for(i=0; i<limite; i++)//1
        {
            fichajeAux=(Fichaje*)ll_get(listaFichaje,i);//i-1

            for(j=0; j<ll_len(pArrayListEmployee); j++)
            {
                empleadoAux=(Employee*)ll_get(pArrayListEmployee,j);
                if(fichajeAux->dia==dia && fichajeAux->mes== mes && fichajeAux->anio== anio && fichajeAux->idSocio==empleadoAux->id)
                {
                    printf("Id:%d  Dni:%d\n",fichajeAux->idSocio,empleadoAux->dni);
                    retorno=i;
                    break;
                }
            }
        }
    }
    return retorno;
}

void fichaje_lista(Fichaje* listaFichaje)
{
    int AuxidFichaje;
    int AuxidSocio;
    int Auxhora;
    int Auxminutos;
    int Auxdia;
    int Auxmes;
    int Auxanio;
    char AuxingresoEgreso[10];

    if(listaFichaje!= NULL)
    {
        fichaje_getId(listaFichaje,&AuxidFichaje);
        fichaje_getIdSocio(listaFichaje,&AuxidSocio);
        fichaje_getHora(listaFichaje,&Auxhora);
        fichaje_getMinutos(listaFichaje,&Auxminutos);
        fichaje_getDia(listaFichaje,&Auxdia);
        fichaje_getMes(listaFichaje,&Auxmes);
        fichaje_getAnio(listaFichaje,&Auxanio);
        fichaje_getInOut(listaFichaje,AuxingresoEgreso);
        printf("%d\t %d   %d    %d   %d/%d/%d   %s\n",AuxidFichaje,AuxidSocio,Auxhora,Auxminutos,Auxdia,Auxmes,Auxanio,AuxingresoEgreso);
    }
    else
    {
        printf("No se cargaron los Datos\n\n");
    }

}

void listarFichajes (LinkedList* lista)
{
    Fichaje* fichajes;
    int i;

    if(lista!= NULL)
    {
        printf("ID   ID_SOCIO  HORA  MINUTOS  DIA/MES/ANIO  INGRESO/EGRESO\n\n");
        for(i=0; i< ll_len(lista); i++)
        {
            fichajes=(Fichaje*)ll_get(lista,i);
            fichaje_lista(fichajes);
        }
    }
}

void socios_Lista(Employee* listaSocios)
{
    int Auxid;
    char Auxnombre[128];
    char Auxapellido [120];
    int Auxdni;
    char Auxclave[20];

    if(listaSocios!=NULL)
    {
        employee_getId(listaSocios,&Auxid);
        employee_getNombre(listaSocios,Auxnombre);
        employee_getApellido(listaSocios,Auxapellido);
        employee_getDni(listaSocios,&Auxdni);
        employee_getClave(listaSocios,Auxclave);

        printf("%d   %s     %s     %d    %s\n",Auxid,Auxnombre,Auxapellido,Auxdni,Auxclave);
    }
    else
    {
        printf("No se cargaron los Datos\n\n");
    }
}

void listarSocios (LinkedList* lista)
{
    Employee* empleados;
    int i;

    if(lista!= NULL)
    {
        printf("ID   NOMBRE   APELLIDO   DNI   CLAVE\n\n");
        for(i=0; i< ll_len(lista); i++)
        {
            empleados=(Employee*)ll_get(lista,i);
            socios_Lista(empleados);
        }
    }
}


void employee_ListaSociosPresentes(LinkedList* pArrayListEmployee,LinkedList* listaFichaje)
{
    Employee* empleadoAux;
    Fichaje* fichajeAux;

    int limite;
    int auxDia;
    int auxMes;
    int auxAnio;
    int i,j;
    int validarDia;
    int validarMes;
    int validarAnio;

    if(pArrayListEmployee!=NULL && listaFichaje!= NULL)
    {
        validarDia=getEntero(&auxDia,"Ingrese dia:","ERROR!\nReingrese dia:",0,31);
        validarMes=getEntero(&auxMes,"Ingrese Mes:","ERROR!\nReingrese mes:",0,12);
        validarAnio=getEntero(&auxAnio,"Ingrese Anio:","ERROR!\nReingrese Anio:",0,3000);

        if(validarAnio!=0 && validarDia!=0 && validarMes!=0)
        {
            printf("ID  NOMBRE   APELLIDO  DNI   CLAVE\n\n");
            limite=ll_len(listaFichaje);

            for(i=0; i<limite; i++)//1
            {
                fichajeAux=(Fichaje*)ll_get(listaFichaje,i);//i-1

                for(j=0; j<ll_len(pArrayListEmployee); j++)
                {
                    empleadoAux=(Employee*)ll_get(pArrayListEmployee,j);
                    if(fichajeAux->dia==auxDia && fichajeAux->mes== auxMes && fichajeAux->anio== auxAnio && fichajeAux->idSocio==empleadoAux->id)
                    {
                        printf("%d   %s  %s  %d   %s\n",empleadoAux->id,empleadoAux->nombre,empleadoAux->apellido,empleadoAux->dni,empleadoAux->clave);
                        //retorno=i;
                        //break;
                    }
                }
            }
        }
    }
}

int employee_altaEmpleado(LinkedList* pArrayListEmployee,LinkedList* listaFichajes)
{
    Employee* empleadoAux;
    Fichaje* fichajeAux;

    int retorno=-1;

    int auxId;
    char auxApellido[50];
    int auxDni;
    char auxNombre[50];
    char auxClave[50];

    int validarNombre;
    int validarApellido;
    int validarDni;
    int validarClave;
    int empleadoBuscado;

    int auxIdFichaje;
    int horaAux;
    int minutosAux;
    int diaAux;
    int mesAux;
    int anioAux;

    int validarHora;
    int validarMinutos;
    int validarDia;
    int validarMes;
    int validarAnio;

    char Ingreso[3]="IN";

    if(pArrayListEmployee!=NULL)
    {
        validarNombre=getString(auxNombre,"Ingrese Nombre: ","ERROR!\nReingrese Nombre: ");
        validarApellido=getString(auxApellido,"Ingrese Apellido: ","ERROR!\nReingrese Apellido: ");
        validarDni=getEntero(&auxDni,"Ingrese Dni: ","ERROR!\nReingrese Dni ",0,99999999);
        validarClave=getStringAlfaNumerico(auxClave,"Ingrese Clave: ","ERROR!\nReingrese Clave ");
        printf("---FICHAJE---\n\n");
        validarHora=getEntero(&horaAux,"Ingrese Hora: ","ERROR\n.Reingrese:",0,24);
        validarMinutos=getEntero(&minutosAux,"Ingrese Minutos: ","ERROR\n.Reingrese:",0,60);
        validarDia=getEntero(&diaAux,"Ingrese Dia: ","ERROR\n.Reingrese:",0,31);
        validarMes=getEntero(&mesAux,"Ingrese Mes: ","ERROR\n.Reingrese:",0,12);
        validarAnio=getEntero(&anioAux,"Ingrese Anio: ","ERROR\n.Reingrese:",0,2020);

        if(validarNombre!=0 && validarApellido!=0 && validarDni!=0 && validarClave!=0 && validarHora!=0 && validarMinutos!=0 && validarDia!=0 && validarMes!=0 && validarAnio!=0)
        {
            auxId=ll_len(pArrayListEmployee)+100;
            auxIdFichaje=ll_len(listaFichajes);
            empleadoAux=employee_new();
            empleadoAux=employee_setEmployer(empleadoAux,auxId,auxNombre,auxApellido,auxDni,auxClave);
            fichajeAux=fichaje_new();
            fichajeAux=fichaje_setFichajes(fichajeAux,auxIdFichaje,auxId,horaAux,minutosAux,diaAux,mesAux,anioAux,Ingreso);


            if(empleadoAux!=NULL)
            {
                empleadoBuscado=employee_buscarId(pArrayListEmployee,auxId);

                if(empleadoBuscado != -1)
                {
                    printf("Existe un empleado con el ID %d\n", auxId);
                }
                else
                {

                    ll_add(pArrayListEmployee,empleadoAux);
                    ll_add(listaFichajes,fichajeAux);
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}
int employee_modificarEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    int auxId;
    int auxDni;

    char auxNombre[50];
    char auxApellido[50];
    char auxClave[50];

    int validarId;
    int validarNombre;
    int validarApellido;
    int validarDni;
    int validarClave;
    int empleadoBuscado;

    char respuesta;
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        listarSocios(pArrayListEmployee);
        validarId=getEntero(&auxId,"Ingrese Id: ","ERROR!\nReingrese id: ",0,99999);
        if(validarId!=0)
        {
            empleado=employee_new();
            empleadoBuscado=employee_buscarId(pArrayListEmployee,auxId);
            if(empleadoBuscado != -1)
            {
                empleado=(Employee*)ll_get(pArrayListEmployee,empleadoBuscado);
                if(empleado!=NULL)
                {
                    if(employee_setId(empleado,empleadoBuscado)==0)
                    {
                        printf("El ID corresponde :%d\n",empleadoBuscado);
                        printf("\nModificar?s/n: ");
                        respuesta=tolower(getche());
                        if(respuesta== 's')
                        {
                            printf("\nIngrese que desea modificar:\n1.Id\n2.Nombre\n3.Apellido\n4.Dni\n5.Clave\n6.Cancelar\nOpcion:");
                            fflush(stdin);
                            scanf("%d", &opcion);
                            switch(opcion)
                            {
                            case 1:
                                validarId=getEntero(&auxId,"Ingrese Id: ","ERROR!\nReingrese id: ",0,99999);
                                if(validarId!=0)
                                {
                                    if(employee_setId(empleado,auxId)==0)
                                    {
                                        printf("Se cambio el Id!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 2:
                                validarNombre=getString(auxNombre,"Ingrese Nombre: ","ERROR!\nReingrese Nombre: ");
                                if(validarNombre!=0)
                                {
                                    if(employee_setNombre(empleado,auxNombre)==0)
                                    {
                                        printf("Se cambio el Nombre!\n");
                                        retorno=0;
                                    }
                                }
                                break;

                            case 3:
                                validarApellido=getString(auxApellido,"Ingrese Apellido: ","ERROR!\nReingrese Apellido: ");
                                if(validarApellido!=0)
                                {
                                    if(employee_setApellido(empleado,auxApellido)==0)
                                    {
                                        printf("Se cambio el Apellido!\n");
                                        retorno=0;
                                    }
                                }
                                break;

                            case 4:
                                validarDni=getEntero(&auxDni,"Ingrese Dni: ","ERROR!\nReingrese Dni: ",0,999999999);
                                if(validarDni!=0)
                                {
                                    if(employee_setDni(empleado,auxDni)==0)
                                    {
                                        printf("Se cambio el Dni!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 5:
                                validarClave=getStringAlfaNumerico(auxClave,"Ingrese clave: ","ERROR!\nReingrese clave: ");
                                if(validarClave!=0)
                                {
                                    if(employee_setClave(empleado,auxClave)==0)
                                    {
                                        printf("Se cambio la Clave!\n");
                                        retorno=0;
                                    }
                                }
                                break;
                            case 6:
                                break;
                            default:
                                printf("opcion invalida!\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Modificacion Cancelada!\n");
                    }
                }
            }
            else
            {
                printf("Empleado No encontrado!\n");
            }
        }
    }
    return retorno;
}
int employee_bajaEmpleado(LinkedList* listaSocio, LinkedList* listaFichaje)
{
    Employee* empleado;
    int retorno=-1;
    int auxId;
    int idBuscado;
    int validarId;

    if(listaFichaje!=NULL && listaSocio!=NULL)
    {
        listarSocios(listaSocio);
        validarId=getEntero(&auxId,"Ingrese Id:","ERROR!\nReingrese Id:",0,999999);
        if(validarId!= 0)
        {
            idBuscado=employee_buscarId(listaSocio,auxId);
            if(idBuscado != -1)
            {
                empleado=(Employee*)ll_get(listaSocio,auxId);
                if(empleado!=NULL)
                {
                    if(employee_buscarInOut(listaSocio,listaFichaje)==0)
                    {
                        ll_remove(listaSocio,auxId);
                        employee_delete(empleado);
                        retorno=0;
                    }
                    else
                    {
                        if(employee_buscarInOut(listaSocio,listaFichaje)==1)
                        {
                            printf("El socio No salio ");
                        }
                    }

                }
            }
            else
            {
                printf("No se encuentro Id\n");
            }
        }
    }
    return retorno;
}

int employee_listarEmpleado(LinkedList* pArrayListEmployee, LinkedList* listaFichaje)
{
    int retorno=-1;
    int auxDia;
    int auxMes;
    int auxAnio;

    int validarDia;
    int validarMes;
    int validarAnio;

    if(pArrayListEmployee!=NULL && listaFichaje!= NULL)
    {
        validarDia=getEntero(&auxDia,"Ingrese dia:","ERROR!\nReingrese dia:",0,31);
        validarMes=getEntero(&auxMes,"Ingrese Mes:","ERROR!\nReingrese mes:",0,12);
        validarAnio=getEntero(&auxAnio,"Ingrese Anio:","ERROR!\nReingrese Anio:",0,3000);

        if(validarAnio!=0 && validarDia!=0 && validarMes!=0)
        {
            employee_buscarFecha(pArrayListEmployee,listaFichaje,auxDia,auxMes,auxAnio);
        }
    }
    return retorno;
}
int employee_compareEmployeeById(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->id == empleadoDos->id)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->id > empleadoDos->id)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->id < empleadoDos->id)
                {
                    retorno=1;
                }
            }

        }
    }
    return retorno;
}
int employee_compareEmployeeByName(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno= (Employee*) pEmployeeA;
        empleadoDos= (Employee*) pEmployeeB;

        retorno = stricmp(empleadoDos->nombre, empleadoUno->nombre);
    }

    return retorno;
}

int employee_compareEmployeeByDni(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->dni == empleadoDos->dni)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->dni > empleadoDos->dni)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->dni < empleadoDos->dni)
                {
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}
/*int employee_compareEmployeeBySueldo(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=-1;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        empleadoUno = (Employee*) pEmployeeA;
        empleadoDos = (Employee*) pEmployeeB;

        if(empleadoUno->sueldo == empleadoDos->sueldo)
        {
            retorno=0;
        }
        else
        {
            if(empleadoUno->sueldo > empleadoDos->sueldo)
            {
                retorno=-1;
            }
            else
            {
                if(empleadoUno->sueldo < empleadoDos->sueldo)
                {
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}*/
