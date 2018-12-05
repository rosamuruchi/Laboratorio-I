#include "LinkedList.h"

#ifndef NUMERONATURAL_H_INCLUDED
#define NUMERONATURAL_H_INCLUDED
typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;

}numeroNatural;
#endif // NUMERONATURAL_H_INCLUDED
numeroNatural* newNumero();
numeroNatural* newParametros(char* numero,char* nombre, char* par, char* impar, char* primo);
//SETTERS
int set_numero(numeroNatural* this, int dato);
int set_par(numeroNatural* this, int dato);
int set_impar(numeroNatural* this, int dato);
int set_primo(numeroNatural* this, int dato);
int set_nombre(numeroNatural* this, char dato[]);
//GETTERS
int get_numero(numeroNatural* this);
int get_par(numeroNatural* this);
int get_impar(numeroNatural* this);
int get_primo(numeroNatural* this);
char* get_nombre(numeroNatural* this);
//FUNCIONES
void printOne(numeroNatural* this);
void printAllNumbers (LinkedList* pArrayListEmployee);
void completarNumeros(LinkedList* this);
int compararNumeros(void* numero1, void* numero2);
int comprobarSiElNumeroEsRepetido(LinkedList* repetido, numeroNatural* aux);

