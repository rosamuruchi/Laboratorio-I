#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct {
    char apellido[31];
    char nombre[31];
    long int dni;
    EFecha feNac;
    int isEmpty;
}EPersona;

void init(EPersona lista[], int len);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni,int len);

void alta(EPersona[], int len);

void baja(EPersona[], int len);

void modificacion(EPersona[], int len);

void mostrarListaDeUnaPersona (EPersona lista);
void mostrarListaPersonas (EPersona lista[], int len);

void ordenamientoDeLista (EPersona[], int len);

#endif // PERSONA_H_INCLUDED
