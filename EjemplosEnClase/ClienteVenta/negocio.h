#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[31];
    char apellido[31];
}eCliente;

typedef struct
{
    int idVenta;
    int idCliente;
    float precio;
}eVenta;

int fMenu(LinkedList* pArrayListClientes, LinkedList* pArrayListVentas);
int fMenuClientes(LinkedList* pArrayListClientes);
int agregarCliente (LinkedList* pArrayListClientes);
int listarClientes(LinkedList* pArrayListClientes);
eCliente* cliente_searchID(LinkedList* pArrayListClientes, int IdABuscar);
int modificarCliente(LinkedList* pArrayListCliente);
int eliminarCliente(LinkedList* pArrayListClientes);
int ordenarClientes(LinkedList* pArrayListClientes);


int fMenuVentas(LinkedList* pArrayListVentas);

#endif // NEGOCIO_H_INCLUDED
