#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"
#include "empleados.h"
#include "almuerzos.h"

#define LIBRE 0
#define OCUPADO 1


void initAlmuerzos(eAlmuerzo lista[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        lista[i].isEmpty = LIBRE;
    }

}

int buscarEspacioLibreA(eAlmuerzo lista[], int limite)
{
    int i;
    int retorno = -1; // Retorta -1 si no encontró un espacio

    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



int buscarAlgunEmpleadoCargado(eEmpleado lista[], int limite)
{
    int i, retorno = 0;

    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}


int buscarAlgunMenuCargado(eMenu lista[], int limite)
{
    int i, retorno = 0;

    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}


int hayAlmuerzos(eEmpleado listaE[], int limiteE, eMenu listaM[], int limiteM)
{
    int retorno = 0;
    int espacioE, espacioM;

    espacioE = buscarAlgunEmpleadoCargado(listaE, limiteE);
    espacioM = buscarAlgunMenuCargado(listaM, limiteM);

    if(espacioE == 0 && espacioM == 0)
    {
        system("cls");
        printf("\tALTA DE ALMUERZOS\n\n");
        printf("\n>>> NO HAY EMPLEADOS NI MENUS CARGADOS\n");
        retorno = -1;
        wait();
        return retorno;
    }


    if(espacioE == 0)
    {
        system("cls");
        printf("\tALTA DE ALMUERZOS\n\n");
        printf("\n>>> AUN NO HAY UN EMPLEADO CARGADO\n");
        retorno = -1;
        wait();
        return retorno;
    }

    if(espacioM == 0)
    {
        system("cls");
        printf("\tALTA DE ALMUERZOS\n\n");
        printf("\n>>> AUN NO HAY UN MENU CARGADO\n");
        retorno = -1;
        wait();
        return retorno;
    }

    return retorno;
}


int mostrarAlmuezos(eAlmuerzo lista[], int limite)
{
    int i, vacio = -1;
    int titulo = 0;


    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(titulo == 0)
            {
                printf("\n\nCODIGOMENU   CODIGOEMPLEADO      CODIGOALMUERZO    FECHA");
                titulo = -1;
            }
            printf("\n     %d     \t    %d\t\t\t%d    \t %d/%d/%d",lista[i].codigoMenu, lista[i].codigoEmpleado, lista[i].codigoAlmuerzo, lista[i].fechaAlmuerzo.dia, lista[i].fechaAlmuerzo.mes, lista[i].fechaAlmuerzo.anio);
            vacio = 0;
        }
    }

    if(vacio == -1)
    {
        printf(">>> NADA QUE MOSTRAR.\n\n");
        system("pause");
        system("cls");
    }

    return vacio;
}

int altaAlmuerzos(eEmpleado listaE[], int limiteE, eMenu listaM[], int limiteM, eAlmuerzo listaA[], int limiteA)
{
    int r, retorno = -1;
    int auxCodigoMenu;
    int auxLegajoEmpleado;
    int encontrado;
    eAlmuerzo aux;


    r = hayAlmuerzos(listaE, limiteE, listaM, limiteM);

    if(r == 0)
    {
        system("cls");
        printf("\tALTA DE ALMUERZOS\n\n");

        printf(">>> MENUS\n\n");
        mostrarMenus(listaM, limiteM);
        printf("\n\nIngrese Codigo del Menu: ");
        scanf("%d",&auxCodigoMenu);

        encontrado = buscarPorCodigo(listaM, limiteM, auxCodigoMenu);

        if(encontrado != -1)
        {
            system("cls");
            printf("\tALTA DE ALMUERZOS\n\n");
            printf(">>> EMPLEADOS\n\n");
            mostrarEmpleados(listaE, limiteE);
            printf("\n\nIngrese Legajo del Empleado: ");
            scanf("%d",&auxLegajoEmpleado);

            encontrado = buscarPorLegajo(listaE, limiteE, auxLegajoEmpleado);

           if(encontrado != -1)
           {
            system("cls");
            printf("\tALTA DE ALMUERZOS\n\n");
            printf(" >>> Fecha del Almuerzo\n\n");
            r = getFecha(&aux.fechaAlmuerzo.dia, &aux.fechaAlmuerzo.mes, &aux.fechaAlmuerzo.anio, "ingresa dia: ", "ingresa mes ", "ingresa anio: " );

            if (r == 0)
            {
                aux.codigoMenu = auxCodigoMenu;
                aux.codigoEmpleado = auxLegajoEmpleado;
                aux.codigoAlmuerzo = buscarEspacioLibreA(listaA, limiteA);
                aux.codigoAlmuerzo++;
                aux.isEmpty = OCUPADO;

                listaA[encontrado] = aux;
                retorno = 0;
                mostrarAlmuezos(listaA, limiteA);
            }
           }
           else
           {
            system("cls");
            printf("\tALTA DE ALMUERZOS\n\n");
            printf("\n>>> LEGAJO NO ENCONTRADO EN EL SISTEMA\n");
            retorno = -1;
            wait();
           }

        }
        else
        {
        system("cls");
        printf("\tALTA DE ALMUERZOS\n\n");
        printf("\n>>> CODIGO NO ENCONTRADO EN EL SISTEMA\n");
        retorno = -1;
        wait();
        }

    }

    return retorno;
}
