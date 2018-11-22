#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "sectores.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    float salary;
    eFecha fIngreso;
    int idSector;
    int isEmpty;

}eEmpleado;



void initEmpleados(eEmpleado lista[], int limite);


void mostrarInitEmpleados(eEmpleado lista[], int limite);


void hardcodeoEmpleados(eEmpleado lista[], int limite);


int mostrarEmpleados(eEmpleado lista[], int limite);

int altaEmpleado(eEmpleado lista[], int limite, eSector sectores[], int limiteS);

int buscarPorLegajo(eEmpleado lista[], int limite, int legajo);

int modificarEmpleados(eEmpleado lista[], int limite, eSector sectores[], int limiteS);

void mostrarUnEmpleado(eEmpleado lista[], int i);

int ordenarXApellidoYNombre(eEmpleado lista[], int limite);

void listarEmpleados(eEmpleado lista[], int limite);

int bajaEmpleado(eEmpleado lista[], int limite);

int getFecha(int* inputD, int* inputM, int* inputA, char messageD[], char messageM[], char messageA[]);



#endif // EMPLEADO_H_INCLUDED
