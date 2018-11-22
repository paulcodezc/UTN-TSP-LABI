#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define DIM 5


int main()
{
    char nombre[DIM][20];
    char apellido[DIM][20];
    int edad[DIM];
    int estado[DIM];
    int opc;

    inicializar(estado, DIM);


    do
    {
        printf("\n\nABM - Microsoft");
        printf("\n1- Alta\n2- Baja\n3- Modificar\n4- Ordenar\n5- Listar\n6- Salir");
        printf("\n\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
                altaUsuarios(nombre,apellido,edad,DIM, estado);
            break;
        case 2:
                bajaUsuarios(nombre,apellido,edad,DIM, estado);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 's':
            break;
        default:
            break;
        }
    printf("\n\n\n");
    system("pause");
    clear();
    }
    while(opc != 6);

    return 0;
}
