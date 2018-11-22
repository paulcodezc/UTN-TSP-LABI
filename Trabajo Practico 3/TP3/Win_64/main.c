#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo databin.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo databin.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    int flag = 1;
    int flag2 = 1;
    char confirma;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        option = fMenu();
        switch(option)
        {
        case 1:
            if(flag)
            {
                flag = 0;
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\n\n>>> Datos cargados correctamente (modo texto)\n");
                wait();
            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO TEXTO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(listaEmpleados);
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromText("data.csv",listaEmpleados);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de los empleados!");
                    wait();
                }
            }
            break;
        case 2:
            if(flag2)
            {
                if(!(controller_loadFromBinary("dataBin.csv",listaEmpleados)))
                {
                    printf("\n>>> No existe el archivo!\n");
                    wait();
                }
                else
                {
                    flag2 = 0;
                    printf("\n\n\n>>> Datos cargados correctamente (modo binario)\n");
                    wait();
                }
            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO BINARIO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(listaEmpleados);
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromBinary("dataBin.csv",listaEmpleados);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de los empleados!");
                    wait();
                }
            }
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados) == 1)
            {
                printf("\n\n>>> El empleado fue dado de alta correctamente.");
                wait();
            }
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados) == 1)
            {
                printf("\n\n>>> El empleado fue modificado correctamente.");
                wait();
            }
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados) == 1)
            {
                printf("\n\n>>> El empleado fue dado de baja correctamente.");
                wait();
            }
            break;
        case 6:
            if(controller_ListEmployee(listaEmpleados))
            {
                wait();
            }
            break;
        case 7:
            if(controller_sortEmployee(listaEmpleados) == 1)
            {
                printf("\n\n>>> Se ordeno correctamente.");
                wait();
            }
            break;
        case 8:
            if(flag == 0 || flag2 == 0)
            {
                if(controller_saveAsText("data.csv",listaEmpleados) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo texto).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }
            break;
        case 9:
            if(flag == 0 || flag2 == 0)
            {
                if(controller_saveAsBinary("dataBin.csv",listaEmpleados) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo binario).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }
            break;
        case 10:
            printf("\n\n>>> Saliendo del sistema...\n\n");
            break;
        default:
            printf("\n\n>>> Opcion inexistente!\n");
            wait();
            break;
        }
    }
    while(option != 10);
    return 0;
}
