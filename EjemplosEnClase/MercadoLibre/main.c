#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#define MAX 11
#define MAXP 12

int main()
{
    eUsuario listadoUsuarios[MAX];
    eProducto listadoProductos[MAXP];
    eUsuario_init(listadoUsuarios, MAX);
    eProducto_init(listadoProductos, MAXP);
    //hardcodeUsuarios(listadoUsuarios, MAX);
    //hardcodeProductos(listadoProductos, MAXP);
    int opcion, resp;

    do
    {
        menu();
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            resp = eUsuario_alta(listadoUsuarios, MAX);
            if(resp == 0)
            {
                printf("\n>>> Usuario agregado con exito!\n\n");
            }
            else if(resp == -1)
            {
                printf("\n>>> Usuario NO agregado, reintente.\n\n");
            }
            break;
        case 2:
            eUsuario_modificar(listadoUsuarios, MAX);
            break;
        case 3:
            resp = eUsuario_baja(listadoUsuarios, MAX);
            if(resp == 0)
            {
                printf("\n\n>>> Usuario borrado con exito!\n\n\n");
            }
            break;
        case 4:
            resp = eProducto_publicarProducto(listadoUsuarios, MAX, listadoProductos, MAXP);
            if(resp == 0)
            {
                printf("\n>>> Producto Publicado con exito!\n\n");
            }

            break;
        case 5:
            resp = eProducto_modificarPublicacion(listadoProductos, MAXP, listadoUsuarios, MAX);
            if(resp == 0)
            {
                printf("\n>>> Publicacion Modificado con exito!\n\n");
            }
            break;
        case 6:
            resp = eProducto_cancelarPublicacion(listadoProductos, MAXP, listadoUsuarios, MAX);
            if(resp == 0)
            {
                printf("\n>>> Publicacion cancelada con exito!\n\n");
            }
            break;
        case 7:
            printf("COMPRAR PRODUCTO\n");


            break;
        case 8:
            printf("LISTAR PUBLICACION DE USUARIO\n");


            break;
        case 9:
            printf("LISTAR PUBLICACIONES\n");


            break;
        case 10:
            printf("\nLISTAR USUARIOS\n");

            eProducto_mostrarLista(listadoProductos, MAXP);

            break;
        }

        system("pause");
        system("cls");
    }
    while(opcion!=11);


    return 0;
}
