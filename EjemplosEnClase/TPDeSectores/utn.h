/**
 * \brief Valida que un string que se le pasa sea numerico
 * \param str[] string a validar
 * \param
 * \return devuelve [1] si es numerico, de lo contrrario [0]
 *
 */
int esNumerico(char str[]);


/**
 * \brief Valida que un string contenga solo espacios, letras y numeros
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si contiene solo espacio o letras y numeros, de lo contrario [0]
 *
 */
int esAlfaNumerico(char str[]);


/**
 * \brief Valida que un string contenga solo letras
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si contiene solo letras , de lo contrario [0]
 *
 */
int esSoloLetras(char str[]);


/**
 * \brief Valida que sea entero
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si es un digito, [0] si no lo es
 *
 */
int esEntero(char str[]);



/**
 * \brief Valida que sea entero flotante
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si está todo bien, [0] cuando hay algun caracter no numerico, [-1] cuando hay más de 2 puntos decimales
 *
 */
int validarFlotante(char lista[]);


/**
 * \brief Cuenta los caracteres de un string que le pasamos
 * \param campo[] string a contar
 * \param tamano el tamaño que no puede superar
 * \return flag [0] si NO supero el tamaño, caso contrario [-1]
 *
 */
int contarCaracteres(char campo[], int tamano);


/**
 * Valida que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \param
 * \return flag [1] si no esta compuesto de numeros positivos o caracteres, [0] si son numeros positivos
 *
 */
int funChequeoNumero(char num[]);



/**
 * \brief Valida que sea entero
 * \param char str[] string a validar
 * \param
 * \return devuelve un valor distinto a 0 si no es caracter
 *
 */
int esCaracter (char letra);



/**
 * \brief Obtiene un string con algunas validaciones en cuenta - que sean solo letras y respete los limites
 * \param input donde cargara el string
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getStringV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);



/**
 * \brief Obtiene un entero que tenga en cuenta los limites
 * \param input donde cargara el entero
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getIntV(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);



/**
 * \brief Obtiene un flotante que tenga en cuenta los limites
 * \param input donde cargara el flotante
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getFloatV(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);



/**
 * \brief Obtiene un flotante verificando que sea flotante
 * \param input donde cargara el flotante
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getFlotanteV(float* input, char message[], char messageError[]);




/**
 * \brief Obtiene un char y tiene en cuenta los limites
 * \param input donde cargara el char en caso de salir todo bien
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getCharV(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);




/**
 * \brief Obtiene un caracter validando que sea S o N
 * \param input donde cargara el caracter
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getSN(char* input, char message[], char eMessage[]);


/**
 * \brief Confirma el sexo de una persona
 * \param input donde cargara el caracter
 * \param message[] el mensaje a ser mostrado
 * \return [0] si salio todo bien
 *
 */
int confirmaSexo(char* input, char message[]);
