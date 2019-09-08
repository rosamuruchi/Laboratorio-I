#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
    int id;

}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie, int cantidad);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie, int cantidad);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[], int limite);


/** \brief inicializa los estados y el id de la lista
 *
 * \param movie EMovie* puntero a estructura de la funcion
 * \param cantidad int tamanio de la estructura
 * \return void no devuelve nada
 *
 */
void inicializarLista(EMovie* movie,int cantidad);

/** \brief Carga el archivo
 *
 * \param  EMovie* puntero estructura de la funcion
 * \param cantidad int tamanio de la funcion
 * \return int devuelve 1 si no se cargo y 0 si se cargo
 *
 */
int cargarDesdeArchivo(EMovie *,int cantidad);

/** \brief guarda todos los datos del archivo
 *
 * \param  EMovie* puntero a estructura de la funcion
 * \param cantidad int tamanio de la estructura
 * \return int devuelve 1 si no se cargo y 0 si se cargo
 *
 */
int guardarEnArchivo(EMovie *,int cantidad);

/** \brief
 *
 * \param peliculas EMovie* puntero estructura de la funcion
 * \param cantidad int tamanio de la estructura
 * \return int devuelve 1 si no se cargo y 0 si se cargo
 *
 */
int buscarLibre(EMovie *peliculas,int cantidad);

/** \brief verifica si la lista de caracteres contiene letras
 *
 * \param cadena de caracteres
 * \return int devuelve un valor distinto a cero si no lo es
 *
 */
int esLetra (char lista[]);

/** \brief verifica si la lista de caracteres contiene numeros
 *
 * \param lista[] char cadena de caracteres
 * \return int devuelve un valor distinto a cero si no lo es
 *
 */
int esEntero(char lista[]);


 /** \brief verifica si la lista contiene letras y numeros
  *
  * \param lista[] char cadena de caracteres
  * \return int devuelve 1 si no contiene letras y numeros
  *
  */
 int esAlfaNumerico(char lista[]);


/** \brief busca un id seleccionado en la lista cargada con todos los id
 *
 * \param peliculas EMovie* puntero a estructura
 * \param cantidad int tamanio de la estructura
 * \param auxid int id pasado a buscar
 * \return int devuelve -1 si no lo encontro
 *
 */
int buscarPorId(EMovie *peliculas,int cantidad, int auxid);

/** \brief muestra la lista de peliculas
 *
 * \param peliculas EMovie* puntero a estructura
 * \param cantidad int tamanio de la estructura
 * \return void nodevuelve nada
 *
 */
void mostrarUnaLista(EMovie *peliculas, int cantidad);

/** \brief modifica una pelicula segun lo que el usuario quiera cambiar
 *
 * \param movie EMovie* puntero a estructura
 * \param cantidad int tamanio de estructura
 * \return int devuelve 1 si no se cargo y 0 si se cargo
 *
 */
int modificarPelicula(EMovie* movie, int cantidad);



#endif // FUNCIONES_H_INCLUDED
