#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define MAXCARACTERES 1024
#define ASC 1
#define DES 0

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArch;
    int retorno = -1;

    if((pArch = fopen(path,"r")) == NULL)
    {
        printf("\n>>> Hubo un error al abrir el archivo!\n");
        wait();
        return retorno;
    }
    else
    {
        parser_EmployeeFromText(pArch,pArrayListEmployee);
        retorno = 1;

    }
    fclose(pArch);
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArch;
    int retorno;
    int cant;

    cant = ll_len(pArrayListEmployee);

    if((pArch = fopen(path,"rb")) == NULL)
    {
        retorno = 0;
        return retorno;
    }

    if( cant > 0)
    {
        ll_clear(pArrayListEmployee);
    }

    if(parser_EmployeeFromBinary(pArch,pArrayListEmployee)==1)
    {
        retorno = 1;
    }
    else
    {
        printf("Error de Archivo");
    }
    fclose(pArch);

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int retorno = 1;
    int auxId, auxHT;
    char bufferId[MAXCARACTERES];
    char bufferNombre[MAXCARACTERES];
    char bufferHorasTrabajadas[MAXCARACTERES];
    char bufferSueldo[MAXCARACTERES];

    system("cls");
    printf("\tALTA DE EMPLEADO\n\n");

    // Pedimos todos datos del empleado a dar de alta
    auxId = getIDV(pArrayListEmployee, "ingresa ID: ");
    itoa(auxId,bufferId,10);

    if(retorno)
    {
        if((retorno = getStringV(bufferNombre,"ingresa nombre: ","hubo un error",0, MAXCARACTERES)) != -1)
        {
            auxHT = getHorasTrabajadasV(pArrayListEmployee, "ingresa horas trabajadas: ");
            itoa(auxHT,bufferHorasTrabajadas,10);

            if((retorno = getFlotanteV(bufferSueldo,"ingresa sueldo: ")) == 0)
            {
                if((employee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo)) != NULL)
                {
                    ll_add(pArrayListEmployee, employee);
                    retorno = 1;
                }
            }
            else
            {
                retorno = 0;
            }
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int retorno = -1;
    int cant;
    int i;

    system("cls");
    printf("\t\tLISTA DE EMPLEADOS\n\n");

    cant = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && cant > 0)
    {
        printf("%5s %15s %15s %10s \n", "ID","NOMBRE","HS TRABAJADAS","SUELDO");
        for(i=0; i < cant; i++)
        {
            employee= ll_get(pArrayListEmployee, i);
            printf("%4d %15s %10d %17.2f \n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        }
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\t\tLISTA DE EMPLEADOS\n\n");
        printf(">>> No hay ningun archivo cargado!");

    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idBaja;
    int cant, posicion, retorno = -1;
    char confirma;
    Employee *employeeEncontrado;

    employeeEncontrado = employee_new();
    cant = ll_len(pArrayListEmployee);

    system("cls");
    printf("\t\tBAJA DE EMPLEADO\n");

    if(pArrayListEmployee != NULL && cant > 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el id del empleado a dar de baja: ");
        scanf("%d",&idBaja);

        // Buscamos si existe
        if((employeeEncontrado = employee_searchID(pArrayListEmployee, idBaja)) != NULL)
        {
            system("cls");
            printf("\t\tBAJA EMPLEADO\n\n");
            printf("Empleado encontrado: \n\n");
            printf("%5s %15s %15s %8s \n", "ID","NOMBRE","HSTRABAJADAS","SUELDO");
            printf("%4d %16s %10d %14.2f", employeeEncontrado->id, employeeEncontrado->nombre, employeeEncontrado->horasTrabajadas, employeeEncontrado->sueldo);

            do
            {
                printf("\n\nConfirma Baja? [S|N]: ");
                fflush(stdin);
                confirma = getche();
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                posicion = ll_indexOf(pArrayListEmployee, employeeEncontrado);
                ll_remove(pArrayListEmployee, posicion);
                retorno = 1;
            }
            else
            {
                printf("\n\n>>> Cancelaste el dado de baja!");
                retorno = -1;
                wait();
                return retorno;
            }

        }
        else
        {
            system("cls");
            printf("\t\tBAJA EMPLEADO\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tBAJA EMPLEADO\n\n");
        printf(">>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idModificar;
    int opc, auxId, cant, auxHT, retorno;
    float auxSueldo;
    char bufferNombre[MAXCARACTERES];
    char bufferSueldo[MAXCARACTERES];

    Employee *employeeEncontrado;
    employeeEncontrado = employee_new();

    cant = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tMODIFICAR EMPLEADO\n");

        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el id del empleado a modificar: ");
        scanf("%d",&idModificar);

        // Buscamos si existe
        if((employeeEncontrado = employee_searchID(pArrayListEmployee, idModificar)) != NULL)
        {
            system("cls");
            printf("\t\tMODIFICAR EMPLEADO\n\n");
            printf("Empleado encontrado: \n\n");
            printf("%5s %15s %15s %8s \n", "ID","NOMBRE","HSTRABAJADAS","SUELDO");
            printf("%4d %16s %10d %14.2f", employeeEncontrado->id, employeeEncontrado->nombre, employeeEncontrado->horasTrabajadas, employeeEncontrado->sueldo);
            printf("\n\n\n1- Modificar ID");
            printf("\n2- Modificar Nombre");
            printf("\n3- Modificar Horas Trabajadas");
            printf("\n4- Modificar Sueldo");
            printf("\n5- Volver al menu");
            printf("\n\nIngrese opcion: ");
            scanf("%d",&opc);
            fflush(stdin);
            printf("\n*********************************************************************\n\n");

            switch(opc)
            {
            case 1:
                auxId = getIDV(pArrayListEmployee, "ingresa nuevo ID: ");
                employee_setId(employeeEncontrado, auxId);
                retorno = 1;
                break;
            case 2:
                getStringV(bufferNombre,"ingresa nuevo nombre: ","hubo un error",0, MAXCARACTERES);
                employee_setNombre(employeeEncontrado, bufferNombre);
                retorno = 1;
                break;
            case 3:
                auxHT = getHorasTrabajadasV(pArrayListEmployee, "ingresa nuevas horas trabajadas: ");
                employee_setHorasTrabajadas(employeeEncontrado, auxHT);
                retorno = 1;
                break;
            case 4:
                getFlotanteV(bufferSueldo,"ingresa nuevo sueldo: ");
                auxSueldo = atof(bufferSueldo);
                employee_setSueldo(employeeEncontrado, auxSueldo);
                retorno = 1;
                break;
            case 5:
                printf("\n>>> Volviendo al menu principal!");
                retorno = 0;
                wait();
                break;
            default:
                printf("\n>>> Opcion inexistente!\n");
                break;
            }
        }
        else
        {
            system("cls");
            printf("\t\tMODIFICAR EMPLEADO\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tMODIFICAR EMPLEADOS\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opc = 0, cant;

    cant = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tORDENAR EMPLEADOS\n");
        printf("\n1- Ordenar por Id(Creciente)");
        printf("\n2- Ordenar por Id(Decreciente)");
        printf("\n\n3- Ordenar por Nombre(Creciente)");
        printf("\n4- Ordenar por Nombre(Decreciente)");
        printf("\n\n5- Ordenar por Horas Trabajadas (Creciente)");
        printf("\n6- Ordenar por Horas Trabajadas (Decreciente)");
        printf("\n\n7- Ordenar por Sueldo(Creciente)");
        printf("\n8- Ordenar por Sueldo(Decreciente)");
        printf("\n\n9- Volver al menu principal\n");
        printf("\nIngrese opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_sortById, ASC);
            retorno = 1;
            break;
        case 2:
            ll_sort(pArrayListEmployee, employee_sortById, DES);
            retorno = 1;
            break;
        case 3:
            ll_sort(pArrayListEmployee, employee_sortByNombre, ASC);
            retorno = 1;
            break;
        case 4:
            ll_sort(pArrayListEmployee, employee_sortByNombre, DES);
            retorno = 1;
            break;
        case 5:
            ll_sort(pArrayListEmployee, employee_sortByHorasTrabajadas, ASC);
            retorno = 1;
            break;
        case 6:
            ll_sort(pArrayListEmployee, employee_sortByHorasTrabajadas, DES);
            retorno = 1;
            break;
        case 7:
            ll_sort(pArrayListEmployee,employee_sortBySueldo,ASC);
            retorno = 1;
            break;
        case 8:
            ll_sort(pArrayListEmployee,employee_sortBySueldo,DES);
            retorno = 1;
            break;
        case 9:
            printf("\n\n>>> Volviendo al menu princiapl...\n\n");
            wait();
            break;
        default:
            printf("\n>>> Opcion inexistente!\n");
            break;
        }
    }
    else
    {
        system("cls");
        printf("\t\tORDENAR EMPLEADOS\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArch;
    Employee* auxEmpleado;
    int i, cant;

    cant = ll_len(pArrayListEmployee);
    pArch = fopen(path,"w");

    if(pArch != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArch);
        fprintf(pArch,"id,nombre,horasTrabajadas,sueldo\n");

        for(i = 0 ; i < cant; i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            fprintf(pArch,"%d,%s,%d,%f\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado-> horasTrabajadas, auxEmpleado->sueldo);
        }

    }
    fclose(pArch);
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArch;
    Employee *employee;
    int i, cant, retorno = 1;

    cant = ll_len(pArrayListEmployee);
    pArch = fopen(path, "wb");

    if(pArch != NULL)
    {
        for(i = 0 ; i < cant ; i++)
        {
            employee = (Employee*)ll_get(pArrayListEmployee, i);

            fwrite(employee, sizeof(Employee), 1, pArch);
        }
    }

    fclose(pArch);

    return retorno;
}

int fMenu()
{
    int option;

    fflush(stdin);
    printf("\t\t>>> Administrar Nominas de Empleados >>>\n\n\n");
    printf("1. Cargar datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar datos de los empleados desde el archivo databin.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar datos de los empleados en el archivo databin.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("\nIngresa una opcion: ");
    scanf("%d", &option);

    return option;
}
