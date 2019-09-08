/** \brief determina si es una cadena de caracteres por letras
 *
 * \param cadena de caracteres
 * \return devuelve un valor distinto a 0 si no es una cadena de carcateres
 *
 */
int esString (char lista[]);
/** \brief determina si es un numero entero
 *
 * \param lista[] char cadena
 * \return int devuelve un valor distinto a 0 si no es Entero
 *
 */
int esEntero(char lista[]);

/** \brief determina si es un caracter
 *
 * \param cadena de caracteres
 * \return devuelve un valor distinto a 0 si no es caracter
 *
 */
int esCaracter (char letra);
/** \brief valida el numero ingresado si es entero entre los parametros que le asigno
 *
 * \param el numero donde se va a guardar
 * \param mensaje de entrada
 * \param mensaje de error
 * \param limite menor a ser comparado
 * \param limite mayor a ser comparado
 * \return devuelve un valor distinto a 0 si no cumple con la funcion
 *
 */
int getEntero (int* numero,char message[], char messageError[], int lowlimit,int hilimit);
/** \brief valida la palabra ingresada si es una cadena de caracteres de letras
 *
 * \param mensaje de entrada
 * \param mensaje de error
 * \return devuelve un valor distinto a 0 si no lo valida
 *
 */
int getString (char palabra[], char message[], char messageError[]);
/** \brief valida el caracter ingresado es un caracter y si es igual a los parametros que le asigno
 *
 * \param el numero donde se va a guardar
 * \param mensaje de entrada
 * \param mensaje de error
 * \param limite a ser comparado
 * \param limite a ser comparado
 * \return devuelve un valor distinto a 0 si no lo valida
 *
 */
int getCaracter (char* caracter ,char message[], char messageError[],char lowlimit, char hilimit);

int getFlotante (float* numero,char message[], char messageError[]);
