#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;


/** \brief Reserva memoria dinamica para la estructura de tipo "Employee"
 *
 * \return Employee* devuelve la direccion de memoria que se reservo
 *
 */
Employee* employee_new();


/** \brief Asigna lo que se le pasa por parametros a una estructura
 *
 * \param idStr char* id del empleado pasado como string despues se convierte a entero
 * \param nombreStr char* nombre del empleado
 * \param horasTrabajadasStr char* horas trabajadas del empleado como string despues se convierte a entero
 * \param sueldoStr char* sueldo del empleado como string despues se convierte a flotante
 * \return Employee* devuelve la direccion de memoria de la estrucuta con los datos asignados
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr,char* sueldoStr);


/** \brief Elimina la memoria reservada de un empleado (libera la memoria)
 *
 * \param Employee *this puntero del empleado a liberar
 * \return void
 *
 */
void employee_delete(Employee *this);


/** \brief Asigna el id al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int el id a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Obtiene el id del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int* id a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Asigna el nombre al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* el nombre a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Obtiene el nombre del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* nombre a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Asigna las horas trabajadas al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param horasTrabajadas int horas trabajadas a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Obtiene las horas trabajadas del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param horasTrabajadas int* horas trabajadas a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Asigna el sueldo al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param sueldo float sueldo a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_setSueldo(Employee* this,float sueldo);


/** \brief Obtiene el sueldo del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param sueldo float* el sueldo a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int employee_getSueldo(Employee* this,float* sueldo);


/** \brief Compara el ID de dos empleados
 *
 * \param employeeA void* primer empleado a comparar
 * \param employeeB void* segundo empleado a comparar
 * \return int si employeeA es mayor retorna [1], si employeeB es mayor retorna [-1], si son iguales [0]
 *
 */
int employee_sortById(void* employeeA, void* employeeB);


/** \brief Compara el Nombre de dos empleados
 *
 * \param employeeA void* primer empleado a comparar
 * \param employeeB void* segundo empleado a comparar
 * \return int si employeeA es mayor retorna [1], si employeeB es mayor retorna [-1], si son iguales [0]
 *
 */
int employee_sortByNombre(void* employeeA, void* employeeB);


/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param employeeA void* primer empleado a comparar
 * \param employeeB void* segundo empleado a comparar
 * \return int si employeeA es mayor retorna [1], si employeeB es mayor retorna [-1], si son iguales [0]
 *
 */
int employee_sortByHorasTrabajadas(void* employeeA, void* employeeB);


/** \brief Compara el sueldo de dos empleados
 *
 * \param employeeA void* primer empleado a comparar
 * \param employeeB void* segundo empleado a comparar
 * \return int si employeeA es mayor retorna [1], si employeeB es mayor retorna [-1], si son iguales [0]
 *
 */
int employee_sortBySueldo(void* employeeA, void* employeeB);


/** \brief Busca el ID pasado por parametro para comprobar si existe
 *
 * \param pArrayListEmployee LinkedList* donde se encuentran los empleados
 * \param IdABuscar int el id a buscar
 * \return Employee* retorna la direccion de memoria que coincide con el ID, si no existe devuelve NULL
 *
 */
Employee* employee_searchID(LinkedList* pArrayListEmployee, int IdABuscar);


#endif // EMPLOYEE_H_INCLUDED
