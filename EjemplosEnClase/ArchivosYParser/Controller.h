
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* de los empleados
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* de los empleados
 * \return int retorna [1] si salio todo bien, caso contrario [0]
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);


/** \brief Agrega un empleado
 *
 * \param pArrayListEmployee LinkedList* de los empleados
 *
 * \return int retorna [1] si salio todo bien, caso contrario [0]
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de un empleado
 *
 * \param pArrayListEmployee LinkedList* del empleado
 *
 * \return int retorna [1] si salio todo bien, caso contrario [0]
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* del empleado
 *
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Lista los empleados
 *
 * \param pArrayListEmployee LinkedList* del empleado
 *
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordena los empleados
 *
 * \param pArrayListEmployee LinkedList*
 *
 * \return int retorna [1] salio todo bien
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* de los empleados
 * \return int retorna [1] salio todo bien
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* de los empleados
 * \return int retorna [1] salio todo bien
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
