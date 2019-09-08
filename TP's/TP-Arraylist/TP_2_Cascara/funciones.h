#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int cantidad);


/** \brief Inicializa los datos de la lista
 *
 * \param lista[] EPersona estructura
 * \param cantidad int tamaño maximo de personas
 * \return void no devuelve nada
 *
 */
void inicializarLista(EPersona lista[],int cantidad);


/** \brief Carga los datos Ingresados
 *
 * \param estructura de la persona
 * \param tamaño maximo de personas
 * \return no devuelve nada
 *
 */
void cargarDatos (EPersona lista[],int tamano);


/** \brief funcion que determina si es char o no
 *
 * \param lista de caracteres
 * \return Devuelve distinto de cero si es char (letra)
 *
 */
int esLetra (char lista[]);

/** \brief funcion que determina si es numero o no
 *
 * \param lista[] char lista de caracteres
 * \return int Devuelve distinto de cero si es numero
 *
 */
int esEntero(char lista[]);


/** \brief ordena cada nombre de la lista
 *
 * \param [] EPersona lista estructura de la persona
 * \param cantidad int tamaño maximo de personas
 * \return void no devuelve nada
 *
 */
void ordenarPorNombre(EPersona lista [],int cantidad);

/** \brief muestra solo una linea de la lista
 *
 * \param lista[] EPersona estructura de la persona
 * \param cantidad int tamaño maximo de personas
 * \return void no devuelve nada
 *
 */
void auxMostrarUnaLista(EPersona lista[], int cantidad);

/** \brief funcion que muestra la lista completa
 *
 * \param estructura de la persona
 * \param tamaño maximo de personas
 * \return no devuelve nada
 *
 */
void mostrarNombres (EPersona lista[], int cantidad);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int cantidad, int dni);

/** \brief Borra una persona de la lista
 *
 * \param estructura de la persona
 * \param tamaño maximo de personas
 * \return no devuelve nada
 *
 */
void borrarDatos (EPersona lista [], int limite);

/** \brief grafica todas las edades
 *
 * \param estructura de la persona
 * \param tamaño maximo de edades
 * \return no devuelve nada
 *
 */
void graficodeEdades (EPersona lista [], int edades);

#endif // FUNCIONES_H_INCLUDED
