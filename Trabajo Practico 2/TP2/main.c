#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define ELEMENTS 5

int main()
{
    char rta = 's';
    Employee arrayEmployees[ELEMENTS];

    initEmployees(arrayEmployees, ELEMENTS);
    hardcodeo(arrayEmployees, ELEMENTS);

    do
    {
        switch(menu())
        {
        case 1:
                alta(arrayEmployees,ELEMENTS);
                wait();
                system("cls");
            break;
        case 2:
                baja(arrayEmployees,ELEMENTS);
            break;
        case 3:
                modificar(arrayEmployees,ELEMENTS);
            break;
        case 4:
                informarOPC(arrayEmployees, ELEMENTS);
            break;
        case 5:
            rta = 'n';
            break;

        default:
            printf("\n\n>>> Opcion inexistente");
            wait();
            break;
        }

    }
    while(rta == 's');

    return 0;
}
