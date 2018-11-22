#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


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
