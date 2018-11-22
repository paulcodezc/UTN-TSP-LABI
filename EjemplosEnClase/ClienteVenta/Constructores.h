#ifndef CONSTRUCTORES_H_INCLUDED
#define CONSTRUCTORES_H_INCLUDED

#include "LinkedList.h"
#include "negocio.h"


/** \brief Reserva memoria dinamica para la estructura de tipo "Employee"
 *
 * \return Employee* devuelve la direccion de memoria que se reservo
 *
 */
eCliente* cliente_new();


/** \brief Reserva memoria dinamica para la estructura de tipo "Employee"
 *
 * \return Employee* devuelve la direccion de memoria que se reservo
 *
 */
eVenta* venta_new();


/** \brief Asigna lo que se le pasa por parametros a una estructura
 *
 * \param idStr char* id del empleado pasado como string despues se convierte a entero
 * \param nombreStr char* nombre del empleado
 * \param horasTrabajadasStr char* horas trabajadas del empleado como string despues se convierte a entero
 * \param sueldoStr char* sueldo del empleado como string despues se convierte a flotante
 * \return Employee* devuelve la direccion de memoria de la estrucuta con los datos asignados
 *
 */
eCliente* cliente_newParametros(char* idStr, char* nombreStr, char* apellidoStr);



/** \brief Asigna lo que se le pasa por parametros a una estructura
 *
 * \param idStr char* id del empleado pasado como string despues se convierte a entero
 * \param nombreStr char* nombre del empleado
 * \param horasTrabajadasStr char* horas trabajadas del empleado como string despues se convierte a entero
 * \param sueldoStr char* sueldo del empleado como string despues se convierte a flotante
 * \return Employee* devuelve la direccion de memoria de la estrucuta con los datos asignados
 *
 */
eVenta* venta_newParametros(char* idVentaStr, char* idClienteStr, char* precioStr);


/** \brief Elimina la memoria reservada de un empleado (libera la memoria)
 *
 * \param Employee *this puntero del empleado a liberar
 * \return void
 *
 */
void cliente_delete(eCliente *this);


/** \brief Elimina la memoria reservada de un empleado (libera la memoria)
 *
 * \param Employee *this puntero del empleado a liberar
 * \return void
 *
 */
void venta_delete(eVenta *this);

/** \brief Asigna el id al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int el id a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_setId(eCliente* this, int id);

/** \brief Asigna el id al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int el id a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_setIdVenta(eVenta* this, int id);


/** \brief Obtiene el id del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int* id a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_getId(eCliente* this, int* id);


/** \brief Obtiene el id del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param id int* id a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_getIdVenta(eVenta* this, int* id);


/** \brief Asigna el nombre al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* el nombre a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_setNombre(eCliente* this, char* nombre);

/** \brief Asigna el nombre al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* el nombre a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_setApellido(eCliente* this, char* apellido);


/** \brief Obtiene el nombre del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* nombre a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_getNombre(eCliente* this, char* nombre);


/** \brief Obtiene el nombre del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param nombre char* nombre a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int cliente_getApellido(eCliente* this, char* apellido);


/** \brief Asigna las horas trabajadas al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param horasTrabajadas int horas trabajadas a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_setIdCliente(eVenta* this, int id);


/** \brief Obtiene las horas trabajadas del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param horasTrabajadas int* horas trabajadas a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_getIdCliente(eVenta* this, int* id);


/** \brief Asigna el sueldo al campo de la estrucutura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param sueldo float sueldo a asignar
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_setPrecio(eVenta* this, float precio);


/** \brief Obtiene el sueldo del campo de la estructura "Employee"
 *
 * \param this Employee* puntero del empleado
 * \param sueldo float* el sueldo a obtener
 * \return int retorna [1] si salio todo bien, caso contrario [-1]
 *
 */
int venta_getPrecio(eVenta* this, float* precio);


/** \brief Compara el ID de dos empleados
 *
 * \param employeeA void* primer empleado a comparar
 * \param employeeB void* segundo empleado a comparar
 * \return int si employeeA es mayor retorna [1], si employeeB es mayor retorna [-1], si son iguales [0]
 *
 */
eVenta* venta_searchIDVenta(LinkedList* pArrayListEmployee, int IdVentaABuscar);

int cliente_sortById(void* clienteA, void* clienteB);
int cliente_sortByNombre(void* clienteA, void* clienteB);
int cliente_sortByApellido(void* clienteA, void* clienteB);


#endif // CONSTRUCTORES_H_INCLUDED
