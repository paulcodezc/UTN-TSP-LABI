#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


typedef struct
{
    int id;
    char descripcion[30];

} Sector;


/**
 * \brief inicializa a todos los empleados
 * \param la estructura de empleados
 * \param la cantidad de empleados
 * \return -
 *
 */
void initEmployees(Employee* list, int len);


/**
 * \brief Agrega un nuevo empleado a la estructura empleado
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \param id el id del empleado
 * \param name nombre del empleado
 * \param lastname apellido o last name de empleados
 * \param salary el salario del empleado
 * \param sector el sector del empleado
 * \param index la posicion del empleado
 * \return 0 si salio todo bien
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int index);


/**
 * \brief Remueve a un empleado mediante un id que se le pasa
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \param id el id a remover
 * \return [-1] si hubo un error [1] si salio todo bien
 *
 */
int removeEmployee(Employee* list, int len, int id);


/**
 * \brief Busca a un empleado por medio de su ID
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \param auxID el ID a buscar en la estructura
 * \return el indice del empleado encontrado, si no [-1]
 *
 */
int findEmployeeById(Employee* list, int len, int auxID);


/**
 * \brief Ordena a los empleados
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \param order si es [1] ascendente [2] descendente
 * \return
 *
 */
void sortEmployees(Employee* list, int len, int order);


/**
 * \brief Imprime a los empleados en forma de columna
 * \param Employee* list la estructura de empleados
 * \param length la cantidad de empleados
 * \return [-1] si no hay empleados que mostrar [0] si salio todo bien
 *
 */
int printEmployees(Employee* list, int length);



/**
 * \brief Muestra el menu de opciones del sistema
 * \param
 * \param
 * \return -
 *
 */
int menu();



/**
 * \brief Deja un poco de espacio y espera que ingreses una tecla para continuar
 * \param
 * \param
 * \return -
 *
 */
void wait();


/**
 * \brief Busca un espacio libre en la estructura
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return el indice del espacio libre, si no [-1]
 *
 */
int buscarEspacioLibre(Employee list[], int len);



/**
 * \brief Devuelve el siguiente ID libre
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return devuelve el siguiente indice (en este caso ID) libre
 *
 */
int SiguienteID(Employee* list, int len);


/**
 * \brief Muestra un solo empleado
 * \param
 * \param
 * \return -
 *
 */
void showEmployee(Employee* list, int i);


/**
 * \brief Harcodea la estructura
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void hardcodeo(Employee* list, int len);

/**
 * \brief Valida que el string pasado contenga solo letras
 * \param str[] la cadena a validar
 * \param
 * \return [0] si contiene solo letras, caso contrario [-1]
 *
 */
int esSoloLetras(char str[]);



/**
 * \brief Obtiene un string con algunas validaciones en cuenta
 * \param input donde cargara el string
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien
 *
 */
int getStringV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);


/**
 * \brief Comprueba si una cadena tiene numeros
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return [-1] si NO es numero [0] si es numero.
 *
 */
int esNumerico (char str[]);


/**
 * \brief Obtiene un flotante con algunas validaciones en cuenta
 * \param input donde cargara el flotante
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien
 *
 */
int getFloatV(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);



/**
 * \brief Obtiene un entero con algunas validaciones en cuenta
 * \param input donde cargara el flotante
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien
 *
 */
int getIntV(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);



/**
 * \brief Muestra por pantalla informes que se piden del sistema
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \param total el total de los sueldos
 * \param promedio el promedio de lo que gana cada empleado
 * \param superaron la cantidad de empleados que superaron el promedio
 * \return -
 *
 */
void informes(Employee* list, int len, float total, float promedio, int superaron);


/**
 * \brief Permite dar de alta a un empleado
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void alta(Employee* list, int len);



/**
 * \brief Informa las dos opciones de informaciones que pide el sistema
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void informarOPC(Employee* list, int len);



/**
 * \brief Lista ordenado por Apellido y Sector
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void informarA(Employee* list, int len);




/**
 * \brief Muestra el total, promedio de los salarios y salario promedio
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void informarB(Employee* list, int len);

/**
 * \brief Permite dar de baja a un empleado
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void baja(Employee* list, int len);


/**
 * \brief Permite modificar a un empleado
 * \param Employee* list la estructura de empleados
 * \param len la cantidad de empleados
 * \return -
 *
 */
void modificar(Employee* list, int len);

#endif // INPUT_H_INCLUDED
