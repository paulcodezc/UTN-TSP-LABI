#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constructores.h"
#include "negocio.h"
#include "LinkedList.h"

#define MAXCARACTERES 1024
#define ASC 1
#define DES 0

/**************************** Constructores para CLIENTE **************************************/

eCliente* cliente_new()
{
    eCliente* this;
    this = (eCliente*) malloc(sizeof(eCliente));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->apellido, "");
    }

    return this;
}

int cliente_setId(eCliente *this, int id)
{
    int retorno = -1;
    int nuevoID = -1;

    if(this != NULL && id== -1)
    {
        nuevoID++;
        this->id = nuevoID;
        retorno = 1;
    }
    else if(id > nuevoID)
    {
        nuevoID = id;
        this->id = nuevoID;
        retorno = 1;
    }
    return retorno;
}

int cliente_getId(eCliente *this, int *id)
{
    int retorno = -1;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int cliente_setNombre(eCliente *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int cliente_getNombre(eCliente *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}


int cliente_setApellido(eCliente *this, char *apellido)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 1;
    }
    return retorno;
}

int cliente_getApellido(eCliente *this, char *apellido)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 1;
    }
    return retorno;
}



eCliente* cliente_newParametros(char *id, char *nombre, char *apellido)
{
    int auxId;
    eCliente* this;

    this = cliente_new();

    auxId = atoi(id);

    if(cliente_setId(this,auxId) && cliente_setNombre(this, nombre) && cliente_setApellido(this, apellido))
    {
        return this;
    }
    else
    {
        cliente_delete(this);
        return 0;
    }

}

void cliente_delete(eCliente *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

eCliente* cliente_searchID(LinkedList* pArrayListEmployee, int IdABuscar)
{
    eCliente* cliente = NULL;
    int i;
    int cant;
    int flag;

    cliente = cliente_new();
    cant = ll_len(pArrayListEmployee);

    for(i = 0 ; i < cant ; i++)
    {
        cliente = (eCliente*) ll_get(pArrayListEmployee, i);

        if(cliente->id == IdABuscar)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = -1;
        }
    }

    if(flag == -1)
    {
        cliente = NULL;
    }

    return cliente;
}


int cliente_sortById(void* clienteA, void* clienteB)
{
    int idA;
    int idB;
    int retorno = 0;

    cliente_getId(clienteA,&idA);
    cliente_getId(clienteB,&idB);

    if(idA > idB)
    {
        retorno = 1;
    }
    else if(idB > idA)
    {
        retorno = -1;
    }
    return retorno;
}


int cliente_sortByNombre(void* clienteA, void* clienteB)
{
    char nombreA[MAXCARACTERES];
    char nombreB[MAXCARACTERES];
    int retorno = 0;

    cliente_getNombre(clienteA,nombreA);
    cliente_getNombre(clienteB,nombreB);

    if(strcmp(nombreA, nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA, nombreB) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int cliente_sortByApellido(void* clienteA, void* clienteB)
{
    char apellidoA[MAXCARACTERES];
    char apellidoB[MAXCARACTERES];
    int retorno = 0;

    cliente_getApellido(clienteA,apellidoA);
    cliente_getApellido(clienteB,apellidoB);

    if(strcmp(apellidoA, apellidoB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(apellidoA, apellidoB) < 0)
    {
        retorno = -1;
    }

    return retorno;
}


/**************************** Constructores para VENTAS **************************************/

eVenta* venta_new()
{
    eVenta* this;
    this = (eVenta*) malloc(sizeof(eVenta));

    if(this != NULL)
    {
        this->idVenta = 0;
        this->idCliente = 0;
        this->precio = 0.0;
    }

    return this;
}

int venta_setIdVenta(eVenta *this, int id)
{
    int retorno = -1;
    int nuevoID = -1;

    if(this != NULL && id== -1)
    {
        nuevoID++;
        this->idVenta = nuevoID;
        retorno = 1;
    }
    else if(id > nuevoID)
    {
        nuevoID = id;
        this->idVenta = nuevoID;
        retorno = 1;
    }
    return retorno;
}

int venta_getIdVenta(eVenta *this, int *id)
{
    int retorno = -1;

    if(this != NULL)
    {
        *id = this->idVenta;
        retorno = 1;
    }
    return retorno;
}


int venta_setIdCliente(eVenta* this, int id)
{
    int retorno = -1;
    int nuevoID = -1;

    if(this != NULL && id == -1)
    {
        nuevoID++;
        this->idCliente = nuevoID;
        retorno = 1;
    }
    else if(id > nuevoID)
    {
        nuevoID = id;
        this->idCliente = nuevoID;
        retorno = 1;
    }
    return retorno;
}

int venta_getIdCliente(eVenta *this, int *id)
{
    int retorno = -1;

    if(this != NULL)
    {
        *id = this->idCliente;
        retorno = 1;
    }
    return retorno;
}

int venta_setPrecio(eVenta *this, float precio)
{
    int retorno = -1;
    int nuevoPrecio = -1;

    if(this != NULL && precio == -1)
    {
        nuevoPrecio++;
        this->precio = nuevoPrecio;
        retorno = 1;
    }
    else if(precio > nuevoPrecio)
    {
        nuevoPrecio = precio;
        this->precio = nuevoPrecio;
        retorno = 1;
    }
    return retorno;
}

int venta_getPrecio(eVenta *this, float *precio)
{
    int retorno = -1;

    if(this != NULL)
    {
        *precio = this->precio;
        retorno = 1;
    }
    return retorno;
}

eVenta* venta_newParametros(char* idVentaStr, char* idClienteStr, char* precioStr)
{
    int auxIdVenta;
    int auxIdCliente;
    float auxPrecio;
    eVenta* this;

    this = venta_new();

    auxIdVenta = atoi(idVentaStr);
    auxIdCliente = atoi(idClienteStr);
    auxPrecio = atof(precioStr);

    if(venta_setIdVenta(this,auxIdVenta) && venta_setIdCliente(this, auxIdCliente) && venta_setPrecio(this, auxPrecio))
    {
        return this;
    }
    else
    {
        venta_delete(this);
        return 0;
    }

}

void venta_delete(eVenta *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

eVenta* venta_searchIDVenta(LinkedList* pArrayListEmployee, int IdVentaABuscar)
{
    eVenta* venta = NULL;
    int i;
    int cant;
    int flag;

    venta = venta_new();
    cant = ll_len(pArrayListEmployee);

    for(i = 0 ; i < cant ; i++)
    {
        venta = (eVenta*) ll_get(pArrayListEmployee, i);

        if(venta->idVenta == IdVentaABuscar)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = -1;
        }
    }

    if(flag == -1)
    {
        venta = NULL;
    }

    return venta;
}
