/*\fn arrayLength
 * \brief Retornar longitud de un array
 * \param arrayChar[] char
 * \return int Retorna la longitud del array pasado como parámetro.
 * */
int arrayLength(char arrayChar[]);

/*\fn InputArray
 * \brief Solicita al usuario ingresar un valor tipo char []
 * \param arrayChar char []
 * \param longitudMaxima int
 * \param mensajeIngreso[] char []
 * \return void
 * */
void inputArray (char arrayChar[],int longitudMaxima, char mensajeIngreso[]);

/*\fn quitarSaltosArray
 * \brief reemplaza los \n de un array por \0
 * \param arrayChar char[]
 * \param longitudMaxima int
 * \param mensajeIngreso char[]
 * \return void
 * */
void quitarSaltosArray(char arrayChar[], int length);

/*\fn getInt
 * \brief muestra un mensaje en pantalla y solicita al usuario ingresar un entero
 * \param mensajeIngreso char []
 * \return int: Retorna número ingresado
 * */
int getInt(char mensajeIngreso[]);

/*\fn getIntValidacion
 * \brief muestra un mensaje en pantalla y solicita al usuario ingresar un entero, valida que el mismo esté entre un mínimo y máximo
 * \param mensajeIngreso char []
 * \param errorIngreso char []
 * \param minimo int
 * \param maximo int
 * \return int: Retorna número ingresado validado
 * */
int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int minimo, int maximo);


/**
 * \fn void ArrayToLower(char arrayChar[])
 * \brief Transforma todo caracter de un array a lower case.
 * \param char arrayChar[]: array a modificarse.
 * \return void
 */
void ArrayToLower(char arrayChar[]);

/**
 * \fn void UpperPrimerasLetras(char arrayChar[])
 * \brief Se hace una capitalización de la primer letra de cada string en un array.
 * \param char arrayChar[]: array a modificarse.
 * \return void
 */
void UpperPrimerasLetras(char arrayChar[]);



float getFloat(char mensaje[], char mensajeError[], float minimo);

int msjConfirmar(char mensaje[]);


double getProm(double value, int quantity);
