#ifndef ALMUERZOS_H_INCLUDED
#define ALMUERZOS_H_INCLUDED

#include "empleados.h"
#include "menu.h"

typedef struct
{
    int codigoAlmuerzo;
    int codigoMenu;
    int codigoEmpleado;
    eFecha fechaAlmuerzo;
    int isEmpty;

}eAlmuerzo;

void initAlmuerzos(eAlmuerzo lista[], int limite);
int buscarEspacioLibreA(eAlmuerzo lista[], int limite);
int buscarAlgunEmpleadoCargado(eEmpleado lista[], int limite);
int buscarAlgunMenuCargado(eMenu lista[], int limite);
int mostrarAlmuezos(eAlmuerzo lista[], int limite);
int hayAlmuerzos(eEmpleado listaE[], int limiteE, eMenu listaM[], int limiteM);
int altaAlmuerzos(eEmpleado listaE[], int limiteE, eMenu listaM[], int limiteM, eAlmuerzo listaA[], int limiteA);




#endif // ALMUERZOS_H_INCLUDED
