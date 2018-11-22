#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    int cant, retorno = 1;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);

        if(cant == 4)
        {
            if((auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo)) != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
        else if(cant != 4)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("\nNo se pudo leer el ultimo archivo\n");
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cant;
    char auxId[8];
    char auxNombre[128];
    char auxHT[8];
    char auxSalario[8];

    Employee* employee;
    Employee newEmployeeParam;

    while(!feof(pFile))
    {
        cant = fread(&newEmployeeParam, sizeof(Employee), 1, pFile);

        if(cant == 1)
        {
            sprintf(auxId, "%d", newEmployeeParam.id);
            strncpy(auxNombre, newEmployeeParam.nombre, sizeof(auxNombre));
            sprintf(auxHT, "%d", newEmployeeParam.horasTrabajadas);
            sprintf(auxSalario, "%f", newEmployeeParam.sueldo);

            employee = employee_newParametros(auxId, auxNombre, auxHT, auxSalario);

            ll_add(pArrayListEmployee, employee);

        }
        else if (cant != 1)
        {
            if(!feof(pFile))
            {
                printf("\n>>> No se puede leer el ultimo registro\n");
                system("pause");
                break;
            }
            else
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}
