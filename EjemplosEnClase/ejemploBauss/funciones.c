#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void init(eEmpleado lista[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        lista[i].isEmpty = LIBRE;
    }

}


void mostrarInit(eEmpleado lista[], int limite)
{
    int i;

    printf("\tInicializacion\n");

    for(i = 0 ; i < limite ; i++)
    {
        printf("\n#%d ---> %d",i+1,lista[i].isEmpty);
    }

    printf("\n\n");
    system("pause");
    system("cls");
}

int buscarEspacioLibre(eEmpleado lista[], int limite)
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


int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 1;
        i++;
    }
    return 0;
}

int getString(char mensaje[], char string[])
{
    int retorno = -1;

    printf(mensaje);
    fflush(stdin);
    gets(string);

    retorno = esSoloLetras(string);

    return retorno;
}


void esperar()
{
    printf("\n\n\n");
    system("pause");
    system("cls");
}

void getInt(char mensaje[], int numero)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&numero);
}

int alta(eEmpleado lista[], int limite)
{
    int index;
    int comprobacion;
    int retorno = -1;
    int fallo = 1;
    char auxNombre[30];
    int auxLegajo;


    system("cls");
    printf("\tALTA DE EMPLEADO\n\n");

    index = buscarEspacioLibre(lista, limite);

    if(index != -1)
    {
        comprobacion = getString("Ingresa nombre: ",auxNombre);

            while(comprobacion == 1)
            {
                printf(">>> Error!... Solo se permiten letras\n");
                comprobacion = getString("Reingresa nombre: ",auxNombre);
            }

        /*comprobacion =*/ getInt("Ingresa legajo: ",auxLegajo);

            while(comprobacion == 1)
            {
                printf(">>> Error!... Solo se permiten numeros\n");
                comprobacion = getInt("Reingresa legajo: ",auxNombre);
            }




    }


    else
    {
        system("cls");
        printf("\tALTA DE PERSONA\n\n");
        printf("\n>>> NO HAY ESPACIO DISPONIBLE\n");
        system("pause");
        system("cls");
    }

    return retorno;
}
