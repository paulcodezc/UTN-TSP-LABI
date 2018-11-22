#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define MAXCARACTERES 1024
#define ASC 1
#define DES 0

Persona* Persona_new()
{
    Persona* this;
    this = (Persona*) malloc(sizeof(Persona));

    if(this != NULL)
    {
        strcpy(this->nombre, "");
        strcpy(this->apellido, "");
        this->edad = 0;
        this->dni = 0;
        this->sexo = 'm';
    }
    return this;
}

int employee_setId(Employee *this, int id)
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

int employee_getId(Employee *this, int *id)
{
    int retorno = -1;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee *this, float sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee *this, float *sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

Employee* employee_newParametros(char *id, char *nombre, char *horasTrabajadas, char *sueldo)
{
    int auxId;
    int auxHT;
    float auxSueldo;
    Employee* this;

    this = employee_new();

    auxId = atoi(id);
    auxHT = atoi(horasTrabajadas);
    auxSueldo = atof(sueldo);

    if(employee_setId(this,auxId) && employee_setNombre(this,nombre) && employee_setHorasTrabajadas(this,auxHT)&& employee_setSueldo(this,auxSueldo))
    {
        return this;
    }
    else
    {
        employee_delete(this);
        return 0;
    }

}

void employee_delete(Employee *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

Employee* employee_searchID(LinkedList* pArrayListEmployee, int IdABuscar)
{
    Employee* employee = NULL;
    int i;
    int cant;
    int flag;

    employee= employee_new();
    cant = ll_len(pArrayListEmployee);

    for(i = 0 ; i < cant ; i++)
    {
        employee = (Employee*) ll_get(pArrayListEmployee, i);

        if( employee->id == IdABuscar)
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
        employee = NULL;
    }

    return employee;
}


int employee_sortById(void* employeeA, void* employeeB)
{
    int idA;
    int idB;
    int retorno = 0;

    employee_getId(employeeA,&idA);
    employee_getId(employeeB,&idB);

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


int employee_sortByNombre(void* employeeA, void* employeeB)
{
    char nombreA[MAXCARACTERES];
    char nombreB[MAXCARACTERES];
    int retorno = 0;

    employee_getNombre(employeeA,nombreA);
    employee_getNombre(employeeB,nombreB);

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


int employee_sortByHorasTrabajadas(void* employeeA, void* employeeB)
{
    int hsTrabajadasA;
    int hsTrabajadasB;
    int retorno = 0;

    employee_getHorasTrabajadas(employeeA,&hsTrabajadasA);
    employee_getHorasTrabajadas(employeeB,&hsTrabajadasB);

    if(hsTrabajadasA > hsTrabajadasB)
    {
        retorno = 1;
    }
    else if(hsTrabajadasB > hsTrabajadasA)
    {
        retorno = -1;
    }
    return retorno;
}


int employee_sortBySueldo(void* employeeA, void* employeeB)
{
    float sueldoA;
    float sueldoB;
    int retorno = 0;

    employee_getSueldo(employeeA, &sueldoA);
    employee_getSueldo(employeeB, &sueldoB);

    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoB > sueldoA)
    {
        retorno = -1;
    }
    return retorno;
}
