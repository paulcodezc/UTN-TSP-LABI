#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM 5

int main()
{
    char seguir = 'S';
    eEmpleado empleados[TAM];


    init(empleados, TAM);


    do
    {
        mostrarInit(empleados, TAM);
        switch(menu())
        {
        case 1:
            if(alta(empleados, TAM))
            {
                printf("\n>>> Empleado agregado!");
                esperar();
            }else
            {
                printf("\nAlgo salio mal");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            seguir = 'N';
            break;
        default:
                printf("\nOpcion incorrecta!");
            break;
        }


    }while(seguir == 'S');



    printf("\n\n");
    system("pause");
    return 0;
}
