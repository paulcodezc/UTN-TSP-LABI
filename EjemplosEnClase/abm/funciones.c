#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0

void clear()
{
    system("cls");
}

void inicializar(int estado[], int tam)
{
    int i;
    for(i = 0 ; i < tam ; i++)
    {
        estado[i] = LIBRE;
    }
}

int altaUsuarios(char nombre[][20], char apellido[][20], int edad[], int cantidad, int estado[])
{
    int i, lugar, string;

    // Limpiamos la pantalla
    clear();
    printf("\tALTA DE USUARIO\n");

    lugar = buscarEspacio(estado, cantidad);

    mostrarUsuarios(nombre,apellido,edad,cantidad,estado);

    if(lugar != -1)
    {
        for(i = 0 ; i < cantidad ; i++)
        {
            if(estado[i] == estado[lugar])
            {
                // Toma de datos: Nombre
            printf("\nIngresa nombre: ");
            fflush(stdin);
            fgets(nombre[i], sizeof(nombre[i])-2, stdin);
            string = strlen(nombre[i]);
            nombre[i][string-1] = '\0';

            // Toma de datos: Apellido
            printf("Ingresa apellido: ");
            fflush(stdin);
            fgets(apellido[i], sizeof(apellido[i])-2, stdin);
            string = strlen(apellido[i]);
            apellido[i][string-1] = '\0';

            // Toma de datos: Edad
            printf("Ingresa edad: ");
            fflush(stdin);
            scanf("%d",&edad[i]);

            estado[i] = OCUPADO;

            break;
            }

        }
    }
    else
    {
        printf("Memoria llena!...");
    }



    return 0;
}

int buscarEspacio(int estado[], int tam)
{
    int i, libre = -1;

    for(i = 0 ; i < tam ; i++)
    {
        if(estado[i] == LIBRE)
        {
            libre = i;
            return libre;
        }
    }

    return libre;
}

void mostrarUsuarios(char nombre[][20], char apellido[][20], int edad[], int cantidad, int estado[])
{

    int i;

    for(i = 0 ; i < cantidad ; i++)
    {
            if(estado[i] != 1)
        {
            printf("\n%s\t%s\t%d\t%d",nombre[i],apellido[i],edad[i], estado[i]);
        }

    }
    printf("\n");

}


int bajaUsuarios(char nombre[][20], char apellido[][20], int edad[], int cantidad, int estado[])
{
    int i;

    printf("\nIngresa el nombre para dar de ")

    return 0;
}
