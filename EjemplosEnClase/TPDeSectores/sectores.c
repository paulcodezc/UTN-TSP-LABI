#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"
#include "sectores.h"

#define LIBRE 0
#define OCUPADO 1


void initSectores(eSector lista[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        lista[i].isEmpty = LIBRE;
    }

}


void hardcodeoSectores(eSector lista[], int limite)
{
    int i;
    eSector nuevo[10] =
    {
        {1,"Finanzas", 1},
        {2,"Administracion", 1},
        {3,"Logistica", 1},
        {4,"Marketing", 1},
        {5,"Sistemas", 1}
    };

    for(i = 0 ; i < limite ; i++)
    {
        lista[i] = nuevo[i];
    }
}


void mostrarInitSectores(eSector lista[], int limite)
{
    int i;

    printf("\tInicializacion de Sectores\n");

    for(i = 0 ; i < limite ; i++)
    {
        printf("\n#%d ---> %d",i+1,lista[i].isEmpty);
    }

    wait();
    system("cls");
}


int buscarEspacioLibreS(eSector lista[], int limite)
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


int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\n>>> Sectores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}


// Devuelve 0 si lo encontró el ID, osea que existe -1 si no lo encontro
int buscarPorSector(eSector lista[], int limite, int sector)
{
    int i;
    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].id == sector && lista[i].id == OCUPADO)
        {
            return 0;
        }
    }
    return -1;
}
