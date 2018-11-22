#include <stdio.h>
#include <string.h>
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}

void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Angel"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario usuarios[], int cant)
{
    int i;

    printf("\n\nID      USUARIOS   IDSERIE\n");
    for(i = 0 ; i < cant ; i++)
    {
        if(usuarios[i].estado == 1)
        {
            printf("\n%d  %8s  %7d", usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].idSerie);
        }
    }
    printf("\n\n");
}

void mostrarUsuarioConSuSerie(eUsuario usuarios[], int cantU, eSerie series[], int cantS)
{
    int i, j;

    printf("NOMBRE  SERIE\n");
    for(i = 0 ; i < cantU ; i++)
    {
        if(usuarios[i].estado == 1)
        {

            for(j = 0 ; j < cantS ; j++)
            {
                if(series[j].estado == 1 && usuarios[i].idSerie == series[j].idSerie)
                {
                    printf("\n%s - %s", usuarios[i].nombre, series[j].nombre);
                    break;
                }

            }
        }

    }
    printf("\n\n");
}

void mostrarSerieConCadaUsuario(eSerie series[], int cantS, eUsuario usuarios[], int cantU)
{
    int i, j;

    for(i = 0 ; i < cantS ; i++)
    {
        if(series[i].estado == 1)
        {
            printf("\n%s: ", series[i].nombre);
            for(j = 0 ; j < cantU ; j++)
            {
                if(usuarios[j].estado == 1 && series[i].idSerie == usuarios[j].idSerie)
                {
                    printf("%5s ", usuarios[j].nombre);
                }
            }
        }

    }
    printf("\n\n");
}
