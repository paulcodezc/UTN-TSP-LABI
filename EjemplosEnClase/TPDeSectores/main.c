#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"
#include "empleados.h"
#include "sectores.h"
#include "almuerzos.h"

#define CANT_EMPLEADOS 10
#define CANT_ALMUERZOS 5
#define CANT_MENUS 10
#define CANT_SECTORES 5


int main()
{
    char seguir = 's';

    eMenu menus[CANT_MENUS];
    eEmpleado empleados[CANT_EMPLEADOS];
    eSector sectores[CANT_SECTORES];
    eAlmuerzo almuerzos[CANT_ALMUERZOS];


    initMenu(menus, CANT_MENUS);
    initEmpleados(empleados, CANT_EMPLEADOS);
    initAlmuerzos(almuerzos, CANT_ALMUERZOS);


    hardcodeoMenus(menus, CANT_MENUS);
    hardcodeoSectores(sectores, CANT_SECTORES);
    hardcodeoEmpleados(empleados, CANT_EMPLEADOS);



    do
    {
        system("cls");
        // Para test
        //mostrarInitMenu(menus,CANT_MENUS);
        //mostrarInitEmpleados(empleados, CANT_EMPLEADOS);
        //mostrarInitSectores(sectores, CANT_SECTORES);
        printf("\tADMINISTRAR\n\n");
        switch(menu())
        {
        case 1:
            if(altaMenus(menus, CANT_MENUS) == 0)
            {
                printf("\n>>> Menu agregado!");
                wait();
                system("cls");
            }
            break;
        case 2:
            if(bajaMenus(menus, CANT_MENUS) == 0)
            {
                printf("\n>>> Menu dado de baja!");
                wait();
                system("cls");
            }
            break;
        case 3:
            modificarMenus(menus, CANT_MENUS);
            break;
        case 4:
            listarMenus(menus, CANT_MENUS);
            break;
        case 5:
            if(altaEmpleado(empleados, CANT_EMPLEADOS, sectores, CANT_SECTORES) == 0)
            {
                printf("\n>>> Empleado agregado!");
                wait();
                system("cls");
            }
            break;
        case 6:
            if(bajaEmpleado(empleados, CANT_EMPLEADOS) == 0)
            {
                printf("\n>>> Empleado dado de baja!");
                wait();
                system("cls");
            }
            break;
        case 7:
            if(modificarEmpleados(empleados, CANT_EMPLEADOS, sectores, CANT_SECTORES) == 0)
            {
                printf("\n>>> Empleado fue modificado!");
                wait();
                system("cls");
            }
            break;
        case 8:
            listarEmpleados(empleados, CANT_EMPLEADOS);
            break;
        case 9:
            if(altaAlmuerzos(empleados, CANT_EMPLEADOS, menus, CANT_MENUS, almuerzos, CANT_ALMUERZOS) == 0)
            {
                printf("\n\n\n>>> Almuerzo agregado!");
                wait();
                system("cls");
            }
            break;
        case 10:
            seguir = 'n';
            break;
        default:
            printf("\n>>> Opcion inexistente!");
            break;
        }
    }
    while(seguir == 's');

    wait();
    return 0;
}
